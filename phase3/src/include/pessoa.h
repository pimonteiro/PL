#ifndef _PESSOA_H_
#define _PESSOA_H_
#include <glib.h>

struct pessoa
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

};

typedef struct pessoa* Pessoa;

Pessoa create(int id);
void copy_pessoa(Pessoa tmp, Pessoa p);
#endif
