#include <stdio.h>
#include <stdlib.h>
#include "pessoa.h"
#include "evento.h"

void factos_base(Pessoa p, FILE* f){
    
    if(f == NULL){
        printf("Ficheiro não existe");
        exit(1);
    }
    if(p->apelido == NULL && p->nome != NULL)
        fprintf(f, "#I%d nome %c\n", p->id, p->nome);
    else  fprintf(f, "#I%d nome %c %c\n", p->id, p->nome, p->apelido);
    
    if(p->nasceu != NULL)
        fprintf(f, "#I%d data-nascimento %c\n", p->id, p->nasceu);

    if(p->morreu != NULL)
        fprintf(f, "#I%d data-falecimento %c\n", p->id, p->morte);
    
    //imprime fotos e historia
    if(p->foto != NULL)
        fprintf(f, "#I%d FOTO %c\n", p->id, p->foto);
    if(p->historia != NULL)
        fprintf(f, "#I%d HISTORIA %c\n", p->id, p->historia);
}

//imp e a lista de pessoas que ja foram imprimidas, hash e a lista de todas as pessoas
void imprime_pessoa(Pessoa p, FILE* f, GHashTable* hash, GList* imp){

    factos_base(p, f);
    //imprime pais
    int num_p = 1;
    if(p->idMae != NULL){
        fprintf(f, "#I%d tem-como-mae #aut%c\n", p->id, num_p);
        num_p++;
        if(!imprimido(imp, p->idMae))
            factos_base(g_hash_table_lookup(hash, p->idMae), f);
    }
    if(p->idPai != NULL){
        fprintf(f, "#I%d tem-como-pai #aut%c\n", p->id, num_p);
        if(!imprimido(imp, p->idMae))
            factos_base(g_hash_table_lookup(hash, p->idPai), f);
        num_p++;
    }

    //imprime avos
    if(p->idMae != NULL){
        Pessoa p1 = g_hash_table_lookup(p->idMae);
        if(p1->idMae != NULL)
            fprintf(f, "#I%d tem-como-MM #aut%d\n", p->id, p1->idMae);
            if(!imprimido(imp, p->idMae))
                factos_base(g_hash_table_lookup(hash, p1->idMae), f);
    }
    if(p->idMae != NULL){
        Pessoa p1 = g_hash_table_lookup(p->idMae);
        if(p1->idMae != NULL)
            fprintf(f, "#I%d tem-como-PM #aut%d\n", p->id, p1->idPai);
            if(!imprimido(imp, p->idMae))
                factos_base(g_hash_table_lookup(hash, p1->idMae), f);
    }
    if(p->idPai != NULL){
        Pessoa p1 = g_hash_table_lookup(p->idPai);
        if(p1->idMae != NULL)
            fprintf(f, "#I%d tem-como-MP #aut%d\n", p->id, p1->idMae);
            if(!imprimido(imp, p1->idMae))
                factos_base(g_hash_table_lookup(hash, p1->idMae), f);
    }
    if(p->idPai != NULL){
        Pessoa p1 = g_hash_table_lookup(p->idPai);
        if(p1->idPai != NULL)
            fprintf(f, "#I%d tem-como-PP #aut%d\n", p->id, p1->idPai);
            if(!imprimido(imp, p1->idPai))
                factos_base(g_hash_table_lookup(hash, p->idPai), f);
    }
    
    //imprime casamento
    if(p->idCasado != NULL){
        int num_f = (int) g_list_length(p->filhos);
        fprintf(f, "#F%d = #I%d #%d \n", num_f, p->id, p->idCasado);
        fprintf(f, "#F%d data-casamento %d\n", num_f, p->id, p->dataCasado);
        factos_base(g_hash_table_lookup(hash, p->idCasado));
    }

    //imprime filhos
    if(p->filhos != NULL){
        for(GList* elem = p->filhos; elem; elem = elem->next){
            factos_base(elem, f);
        }
    }

    //imprime eventos eventos
    for(GList* elem = p->eventos; elem; elem = elem->next){
        fprintf(f, "#I%d %s em %s\n", p->id, elem->descricao, elem->data);
    }

    //guarda que ja imprimiu esta pessoa
    g_list_append(imp, p->id);
}

int imprimido(GList* list, int id){
    for(GList* elem = list; elem; elem = elem->next){
        if(elem == id){
            return 1;
        }
    }
    return 0;
}

void imprime_prolog(Pessoa p, FILE* f, GHashTable* hash, GList* imp){

    if(p->idPai != NULL){
        Pessoa pai = (Pessoa) g_hash_table_lookup(hash, &p->idPai);
        fprintf(f, "pai(%d,%d).\n", pai->nome, p->nome);
        fprintf(f, "filho(%d,%d).\n", p->nome, pai->nome);
    }

    if(p->idMae != NULL){
        Pessoa mae = (Pessoa) g_hash_table_lookup(hash, &p->idMae);
        fprintf(f, "mae(%d,%d).\n", mae->nome, p->nome);
        fprintf(f, "filho(%d,%d).\n", p->nome, mae->nome);
    }

    //imprime avos
    if(p->idMae != NULL){
        Pessoa p1 = (Pessoa)g_hash_table_lookup(hash, &p->idMae);
        if(p1->idMae != NULL){
            Pessoa avo = (Pessoa)g_hash_table_lookup(hash, &p1->idMae);
            fprintf(f, "avo(%d,%d).\n", avo->nome, p->nome);
            fprintf(f, "neto(%d,%d).\n", p->id, avo->nome);
        } 
    }
    if(p->idMae != NULL){
        Pessoa p1 = g_hash_table_lookup(hash, &p->idMae);
        if(p1->idPai != NULL){
            Pessoa avo = (Pessoa)g_hash_table_lookup(hash, &p1->idPai);
            fprintf(f, "avo(%d,%d).\n", avo->nome, p->nome);
            fprintf(f, "neto(%d,%d).\n", p->nome, avo->nome);
        }
    }
    if(p->idPai != NULL){
        Pessoa p1 = g_hash_table_lookup(hash, &p->idPai);
        if(p1->idMae != NULL){
            Pessoa avo = (Pessoa)g_hash_table_lookup(hash, &p1->idMae);
            fprintf(f, "avo(%d,%d).\n", avo->nome, p->nome);
            fprintf(f, "neto(%d,%d).\n", p->nome, avo->nome);
        } 
    }
    if(p->idPai != NULL){
        Pessoa p1 = g_hash_table_lookup(hash, &p->idPai);
        if(p1->idPai != NULL){
            Pessoa avo = (Pessoa)g_hash_table_lookup(hash, &p1->idPai);
            fprintf(f, "avo(%d,%d).\n", avo->nome, p->nome);
            fprintf(f, "neto(%d,%d).\n", p->nome, avo->nome);
        }
    }

    if(p->idCasado != NULL){
        Pessoa p1 = g_hash_table_lookup(hash, &p->idCasado);
        fprintf(f, "casado(%d, %d).\n", p->nome, p1->nome);
    }
    if(p->filhos != NULL){
        for(GList* elem = p->filhos; elem; elem = elem->next){
            Pessoa filho = g_hash_table_lookup(hash, &elem->data);
            fprintf(f, "filho(%d, %d).\n", filho->nome, p->nome);
            fprintf(f, "pai(%d, %d).\n", p->nome, filho->nome);
            if(p->idCasado != NULL){
                Pessoa p1 = g_hash_table_lookup(hash, &p->idCasado);
                fprintf(f, "filho(%d,%d).\n",filho->nome , p1->Nome);
                fprintf(f, "mae(%d, %d).\n", p1->nome, filho->nome);
            }
        }
    }

}