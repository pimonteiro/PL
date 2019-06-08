#include<stdio.h>

typedef struct Evento
{
    char* data; //data do evento
    char* descricao; 
    
}Evento;

Evento create_evento(char* data, char* desc){
    Evento e = (Evento*) malloc(sizeof(Evento));
    e->data = data;
    e->descricao = desc;
    return e;
}