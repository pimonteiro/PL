#include<stdio.h>
#include <stdlib.h>
#include "include/evento.h"

typedef struct evento
{
    char* data; //data do evento
    char* descricao;

};

Evento create_evento(char* data, char* desc){
    Evento e = (Evento) malloc(sizeof(struct evento));
    e->data = data;
    e->descricao = desc;
    return e;
}
