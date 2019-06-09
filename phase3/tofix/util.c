#include <stdlib.h>
#include "util.h"
#include "../src/include/pessoa.h"
#include "../src/include/evento.h"


void factos_base(Pessoa p, FILE* f){

    if(f == NULL){
        printf("Ficheiro não existe");
        exit(1);
    }
    if(p->nome != NULL)
        fprintf(f, "#I%d nome %s\n", p->id, p->nome);

    if(p->nasceu != 0)
        fprintf(f, "#I%d data-nascimento %d\n", p->id, p->nasceu);

    if(p->morte != 0)
        fprintf(f, "#I%d data-falecimento %d\n", p->id, p->morte);

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
    if(p->idMae != 0){
        fprintf(f, "#I%d tem-como-mae #aut%d\n", p->id, p->idMae);
        if(!imprimido(imp, p->idMae)){
            Pessoa mae = (Pessoa)g_hash_table_lookup(hash, &(p->idMae));
            factos_base(mae, f);
        }
    }
    if(p->idPai != 0){
        fprintf(f, "#I%d tem-como-pai #aut%d\n", p->id, p->idPai);
        if(!imprimido(imp, p->idPai)){
            Pessoa pai = (Pessoa)g_hash_table_lookup(hash, &(p->idPai));
            factos_base(pai, f);
        }
    }
    //imprime avos
    if(p->idMae != 0){
        Pessoa p1 = g_hash_table_lookup(hash, &p->idMae);
        if(p1->idMae != 0){
            fprintf(f, "#I%d tem-como-MM #aut%d\n", p->id, p1->idMae);
            if(!imprimido(imp, p->idMae))
                factos_base(g_hash_table_lookup(hash, &p1->idMae), f);
        }
    }
    if(p->idMae != 0){
        Pessoa p1 = g_hash_table_lookup(hash, &p->idMae);
        if(p1->idMae != 0){
            fprintf(f, "#I%d tem-como-PM #aut%d\n", p->id, p1->idPai);
            if(!imprimido(imp, p->idMae))
                factos_base(g_hash_table_lookup(hash, &p1->idMae), f);
        }
    }
    if(p->idPai != 0){
        Pessoa p1 = g_hash_table_lookup(hash, &p->idPai);
        if(p1->idMae != 0){
            fprintf(f, "#I%d tem-como-MP #aut%d\n", p->id, p1->idMae);
            if(!imprimido(imp, p1->idMae))
                factos_base(g_hash_table_lookup(hash, &p1->idMae), f);
        }
    }
    if(p->idPai != 0){
        Pessoa p1 = g_hash_table_lookup(hash, &p->idPai);
        if(p1->idPai != 0){
            fprintf(f, "#I%d tem-como-PP #aut%d\n", p->id, p1->idPai);
            if(!imprimido(imp, p1->idPai))
                factos_base(g_hash_table_lookup(hash, &p->idPai), f);
        }
    }

    //imprime casamento
    if(p->idCasado != 0){
        int num_f = (int) g_list_length(p->filhos);
        fprintf(f, "#F%d = #I%d #I%d \n", num_f, p->id, p->idCasado);
        fprintf(f, "#F%d data-casamento %d\n", num_f, p->dataCasado);
        factos_base(g_hash_table_lookup(hash, &p->idCasado), f);
    }

    //imprime filhos
    if(p->filhos != NULL){
        for(GList* l = p->filhos; l != NULL; l = l->next ){
            factos_base(g_hash_table_lookup(hash, &l->data), f);
        }
    }

    //imprime eventos eventos
    if(p->eventos != NULL){
        int j = 0;
        for(Evento e = g_list_nth_data(p->eventos, j) ; e; e = g_list_nth_data(p->eventos, j) ){
            fprintf(f, "#I%d %s em %s", p->id, e->descricao, e->data);
            j++;
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

int main(){
    FILE *fp;
    Pessoa p = (Pessoa)malloc(sizeof(struct pessoa));
    p->id = 1;
    p-> nome = "Bruno";
    p->nasceu = 123;
    p->idMae = 2;
    p->idPai = 3;
    p->dataCasado = 1999;
    p->idCasado = 9;
    p->foto = "ola";
    p->historia = "olas";
    p->eventos = NULL; 
    Pessoa pai = (Pessoa)malloc(sizeof(struct pessoa));
    pai->id = 3;
    pai-> nome = "Pai";
    pai->nasceu = 1234;
    pai->idMae = 0;
    pai->idPai = 0;
    pai->foto = "ola";
    pai->historia = "olas";
    pai->filhos = NULL;
    pai->eventos = NULL; 
    Pessoa mae = (Pessoa)malloc(sizeof(struct pessoa));
    mae->id = 2;
    mae->nome = "Mae";
    mae->nasceu = 1235;
    mae->idMae = 0;
    mae->idPai = 0;
    mae->foto = "ola";
    mae->historia = "olas";
    mae->filhos = NULL;
    mae->eventos = NULL; 
    Pessoa filho = (Pessoa)malloc(sizeof(struct pessoa));
    filho->id = 6;
    filho->nome = "Filho";
    filho->nasceu = 1235;
    filho->idMae = 0;
    filho->idPai = 1;
    filho->foto = "ola";
    filho->historia = "olas";
    filho->filhos = NULL;
    filho->eventos = NULL; 
    Pessoa c = (Pessoa)malloc(sizeof(struct pessoa));
    c->id = 9;
    c->nome = "CAsado";
    c->nasceu = 1235324;
    c->idMae = 0;
    c->idPai = 0;
    c->filhos = NULL;
    c->eventos = NULL;
    p->filhos = g_list_append(p->filhos,  GINT_TO_POINTER(filho->id));
    GHashTable *table = g_hash_table_new_full (g_int_hash, g_int_equal, NULL, NULL);
    g_hash_table_insert(table, &(p->id), p); 
    g_hash_table_insert(table, &(mae->id), mae);
    g_hash_table_insert(table, &(pai->id), pai);
    g_hash_table_insert(table, &(filho->id), filho);
    g_hash_table_insert(table, &c->id, c);

    GList* list = NULL;
    fp = fopen("test.txt", "w+");
    imprime_pessoa(p, fp, table, list);
    fclose(fp);
}