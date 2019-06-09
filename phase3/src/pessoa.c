#include<stdio.h>
#include <glib.h>

typedef struct Pessoa
{
    int id;
    char* nome;
    char* apelido;
    char* nasceu;
    char* morte;
    char* foto;
    int idPai;
    int idMae;
    int idCasado;
    char* dataCasado;
    GList* filhos; //id dos filhos
    GList* eventos;
    char* historia; //char* as historias
 
}Pessoa;

Pessoa create(int id){
    Pessoa p = (Pessoa*) malloc(sizeof(Pessoa));
    p->id = id;
    return p;
}
