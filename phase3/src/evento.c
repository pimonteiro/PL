#include<stdio.h>
#include <stdlib.h>
#include "include/evento.h"



Evento create_evento(char* data, char* desc){
    Evento e = (Evento) malloc(sizeof(struct evento));
    e->data = data;
    e->descricao = desc;
    return e;
}
