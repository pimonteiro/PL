#include <stdio.h>
#include <stdlib.h>
#include "include/pessoa.h"
#include "include/evento.h"
#include "include/util.h"

void factos_base(Pessoa p, FILE* f){

    if(f == NULL){
        printf("Ficheiro não existe");
        exit(1);
    }
    if(p->nome != NULL && p->apelido != NULL)
        fprintf(f, "#I%d nome %s %s\n", p->id, p->nome, p->apelido);
    else  if(p->nome != NULL) fprintf(f, "#I%d nome %s\n", p->id, p->nome);


    if(p->nasceu != 0 && p->flagNasceAprox <= 0)
        fprintf(f, "#I%d data-nascimento %d\n", p->id, p->nasceu);
    if(p->nasceu <=0 && p->flagNasceAprox > 0)
        fprintf(f, "#I%d data-nascimento-aproximada %d\n", p->id, p->nasceu);
    if(p->morte != 0 && p->flagMorteAprox <= 0)
        fprintf(f, "#I%d data-falecimento %d\n", p->id, p->morte);
    if(p->morte <= 0 && p->flagMorteAprox > 0)
        fprintf(f, "#I%d data-falecimento-aproximada %d\n", p->id, p->morte);

    //imprime fotos e historia
    if(p->foto != NULL)
        fprintf(f, "#I%d FOTO %s\n", p->id, p->foto);
    if(p->historia != NULL)
        fprintf(f, "#I%d HISTORIA %s\n", p->id, p->historia);
}

//imp e a lista de pessoas que ja foram imprimidas, hash e a lista de todas as pessoas
void imprime_pessoa(Pessoa p, FILE* f, GHashTable* hash, GList* imp){

    factos_base(p, f);
    //imprime pais
    if(p->idMae != -1){
        fprintf(f, "#I%d tem-como-mae #aut%d\n", p->id, p->idMae);
        if(!imprimido(imp, p->idMae)){
            Pessoa mae = (Pessoa)g_hash_table_lookup(hash, &(p->idMae));
            factos_base(mae, f);
        }
    }
    if(p->idPai != -1){
        fprintf(f, "#I%d tem-como-pai #aut%d\n", p->id, p->idPai);
        if(!imprimido(imp, p->idPai)){
            Pessoa pai = (Pessoa)g_hash_table_lookup(hash, &(p->idPai));
            factos_base(pai, f);
        }
    }
    //imprime avos
    if(p->idMae != -1){
        Pessoa p1 = g_hash_table_lookup(hash, &p->idMae);
        if(p1->idMae != -1){
            fprintf(f, "#I%d tem-como-MM #aut%d\n", p->id, p1->idMae);
            if(!imprimido(imp, p->idMae))
                factos_base(g_hash_table_lookup(hash, &p1->idMae), f);
        }
    }
    if(p->idMae != -1){
        Pessoa p1 = g_hash_table_lookup(hash, &p->idMae);
        if(p1->idMae != -1){
            fprintf(f, "#I%d tem-como-PM #aut%d\n", p->id, p1->idPai);
            if(!imprimido(imp, p->idMae))
                factos_base(g_hash_table_lookup(hash, &p1->idMae), f);
        }
    }
    if(p->idPai != -1){
        Pessoa p1 = g_hash_table_lookup(hash, &p->idPai);
        if(p1->idMae != -1){
            fprintf(f, "#I%d tem-como-MP #aut%d\n", p->id, p1->idMae);
            if(!imprimido(imp, p1->idMae))
                factos_base(g_hash_table_lookup(hash, &p1->idMae), f);
        }
    }
    if(p->idPai != -1){
        Pessoa p1 = g_hash_table_lookup(hash, &p->idPai);
        if(p1->idPai != -1){
            fprintf(f, "#I%d tem-como-PP #aut%d\n", p->id, p1->idPai);
            if(!imprimido(imp, p1->idPai))
                factos_base(g_hash_table_lookup(hash, &p->idPai), f);
        }
    }

    //imprime casamento
    int num_f = 0;
    if(p->idCasado != -1){
        num_f = (int) g_list_length(p->filhos);
        fprintf(f, "#F%d = #I%d #I%d \n", num_f, p->id, p->idCasado);
        fprintf(f, "#F%d data-casamento %d\n", num_f, p->dataCasado);
        factos_base(g_hash_table_lookup(hash, &p->idCasado), f);
    }

    //imprime filhos
    if(p->filhos != NULL){
        for(GList* l = p->filhos; l != NULL; l = l->next ){
            int i = (int)l->data;
            fprintf(f, "#F%d tem-como-filho #aut%d", num_f, i);
            factos_base(g_hash_table_lookup(hash, &l->data), f);
        }
    }

    //imprime eventos eventos
    if(p->eventos != NULL){
        for(GList* l = p->eventos; l != NULL; l = l->next){
            Evento e = (Evento)l->data;
            fprintf(f, "#I%d %s em %d\n", p->id, e->descricao, e->data);
        }
    }

    //guarda que ja imprimiu esta pessoa
    g_list_append(imp, GINT_TO_POINTER(p->id));
}

int imprimido(GList* list, int id){
    int i = 0;
    for(int l = (int)g_list_nth_data(list, i) ; l; l = (int)g_list_nth_data(list, i) ){
        if(l == id) return 1;
    }
    return 0;
}

void imprime_prolog(Pessoa p, FILE* f, GHashTable* hash, GList* imp){

    if(p->idPai != -1){
        Pessoa pai = (Pessoa) g_hash_table_lookup(hash, &p->idPai);
        fprintf(f, "pai('%s','%s').\n", pai->nome, p->nome);
        fprintf(f, "filho('%s','%s').\n", p->nome, pai->nome);
    }

    if(p->idMae != -1){
        Pessoa mae = (Pessoa) g_hash_table_lookup(hash, &p->idMae);
        fprintf(f, "mae('%s','%s').\n", mae->nome, p->nome);
        fprintf(f, "filho('%s','%s').\n", p->nome, mae->nome);
    }

    //imprime avos
    if(p->idMae != -1){
        Pessoa p1 = (Pessoa)g_hash_table_lookup(hash, &p->idMae);
        if(p1->idMae != -1){
            Pessoa avo = (Pessoa)g_hash_table_lookup(hash, &p1->idMae);
            fprintf(f, "avo('%s','%s').\n", avo->nome, p->nome);
            fprintf(f, "neto('%s','%s').\n", p->nome, avo->nome);
        }
    }
    if(p->idMae != -1){
        Pessoa p1 = g_hash_table_lookup(hash, &p->idMae);
        if(p1->idPai != -1){
            Pessoa avo = (Pessoa)g_hash_table_lookup(hash, &p1->idPai);
            fprintf(f, "avo('%s','%s').\n", avo->nome, p->nome);
            fprintf(f, "neto('%s','%s').\n", p->nome, avo->nome);
        }
    }
    if(p->idPai != -1){
        Pessoa p1 = g_hash_table_lookup(hash, &p->idPai);
        if(p1->idMae != -1){
            Pessoa avo = (Pessoa)g_hash_table_lookup(hash, &p1->idMae);
            fprintf(f, "avo('%s','%s').\n", avo->nome, p->nome);
            fprintf(f, "neto('%s','%s').\n", p->nome, avo->nome);
        }
    }
    if(p->idPai != -1){
        Pessoa p1 = g_hash_table_lookup(hash, &p->idPai);
        if(p1->idPai != -1){
            Pessoa avo = (Pessoa)g_hash_table_lookup(hash, &p1->idPai);
            fprintf(f, "avo('%s','%s').\n", avo->nome, p->nome);
            fprintf(f, "neto('%s','%s').\n", p->nome, avo->nome);
        }
    }

    if(p->idCasado != -1){
        Pessoa p1 = g_hash_table_lookup(hash, &p->idCasado);
        fprintf(f, "casado('%s', '%s').\n", p->nome, p1->nome);
    }
    if(p->filhos != NULL){
        for(GList* elem = p->filhos; elem; elem = elem->next){
            Pessoa filho = g_hash_table_lookup(hash, &elem->data);
            fprintf(f, "filho('%s', '%s').\n", filho->nome, p->nome);
            fprintf(f, "pai('%s', '%s').\n", p->nome, filho->nome);
            if(p->idCasado != -1){
                Pessoa p1 = g_hash_table_lookup(hash, &p->idCasado);
                fprintf(f, "filho('%s','%s').\n",filho->nome , p1->nome);
                fprintf(f, "mae('%s', '%s').\n", p1->nome, filho->nome);
            }
        }
    }
}
