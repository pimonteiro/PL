#ifndef _PESSOA_H_
#define _PESSOA_H_
#include <glib.h>
#include <stdio.h> 

typedef struct pessoa
{
    int id;
    int repetido;
    char* nome;
    char* apelido;
    int nasceu;
    int morte;
    char* foto;
    int idPai;
    int idMae;
    int idCasado;
    int dataCasado;
    GList* filhos; //id dos filhos
    GList* eventos;
    char* historia; //char* as historias

}*Pessoa;

Pessoa create_p(int id);

#endif
