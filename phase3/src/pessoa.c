#include<stdio.h>
#include <stdlib.h>
#include <glib.h>
#include "include/pessoa.h"


Pessoa create(int id){
    Pessoa p = (Pessoa) malloc(sizeof(struct pessoa));
    p->id = id;
    p->flagMorteAprox = 0;
    p->flagNasceAprox = 0;
    return p;
}


void copy_pessoa(Pessoa tmp, Pessoa p){
    p->id = tmp->id;
    p->repetido = tmp->id;
    p->nome = tmp->nome;
    p->apelido = tmp->apelido;
    p->nasceu = tmp->nasceu;
    p->morte = tmp->morte;
    p->foto = tmp->foto;
    p->idPai = tmp->idPai;
    p->idCasado = tmp->idCasado;
    p->dataCasado = tmp->dataCasado;
    p->filhos = tmp->filhos;
    p->eventos = tmp->eventos;
    p->historia = tmp->historia;
}
