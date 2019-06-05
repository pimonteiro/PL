#include <stdio.h>
#include <stdlib.h>
#include "pessoa.h"

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
}

//funçao get_pessoa nao esta feita(deve ir a hashtable buscar a pessoa com o id)
void imprime_pessoa(Pessoa p, FILE* f){

    factos_base(p, f);
    //imprime pais
    if(p->idMae != NULL){
        fprintf(f, "#I%d tem-como-mae #aut%c\n", p->id, p->idMae);
        factos_base(get_pessoa(p->idMae), f);
    }
    if(p->idPai != NULL){
        fprintf(f, "#I%d tem-como-pai #aut%c\n", p->id, p->idPai);
        factos_base(get_pessoa(p->idPai), f);
    }

    //imprime avos
    if(p->idMae != NULL)
        Pessoa p1 = get_pessoa(p->idMae);
        if(p1->idMae != NULL)
            fprintf(f, "#I%d tem-como-MM #aut%d\n", p->id, p1->idMae);
            factos_base(get_pessoa(p1->idMae), f);
    if(p->idMae != NULL)
        Pessoa p1 = get_pessoa(p->idMae);
        if(p1->idMae != NULL)
            fprintf(f, "#I%d tem-como-PM #aut%d\n", p->id, p1->idPai);
            factos_base(get_pessoa(p1->idMae), f);
    if(p->idPai != NULL)
        Pessoa p1 = get_pessoa(p->idPai);
        if(p1->idMae != NULL)
            fprintf(f, "#I%d tem-como-MP #aut%d\n", p->id, p1->idMae);
            factos_base(get_pessoa(p1->idMae), f);
    if(p->idPai != NULL)
        Pessoa p1 = get_pessoa(p->idPai);
        if(p1->idMae != NULL)
            fprintf(f, "#I%d tem-como-PP #aut%d\n", p->id, p1->idPai);
            factos_base(get_pessoa(p->idMae), f);
    
    //imprime fotos e historia
    if(p->foto != NULL)
        fprintf(f, "#I%d FOTO %c\n", p->id, p->foto);
    if(p->historia != NULL)
        fprintf(f, "#I%d HISTORIA %c\n", p->id, p->historia);

    //imprime casamento
    if(p->idCasado != NULL){
        int num_f = (int) g_list_length(p->filhos);
        fprintf(f, "#F%d = #I%d #%d \n", num_f, p->id, p->idCasado);
        fprintf(f, "#F%d data-casamento %d\n", num_f, p->id, p->dataCasado);
        factos_base(get_pessoa(p->idCasado));
    }

}