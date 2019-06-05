#include<stdio.h>

typedef struct Evento
{
    char* data; //data do evento
    char* descricao; //casamento...
    char* nome; //usado por exemplo no caso de cassamento para dizer com quem ou null se nao tiver ninguem associado
}Evento;

Evento create(char* data, char* desc){
    Evento e = (Evento*) malloc(sizeof(Evento));
    e->data = data;
    e->descricao = desc;
    return e;
}