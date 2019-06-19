#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include/evento.h"


Evento create_evento(int data, char* desc){
    Evento e = (Evento) malloc(sizeof(struct evento));
    e->data = data;
    e->descricao = strdup(desc);

    return e;
}
