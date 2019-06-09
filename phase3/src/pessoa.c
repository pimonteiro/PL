#include<stdio.h>
#include <stdlib.h>
#include <glib.h>
#include "include/pessoa.h"


Pessoa create(int id){
    Pessoa p = (Pessoa) malloc(sizeof(struct pessoa));
    p->id = id;
    return p;
}
