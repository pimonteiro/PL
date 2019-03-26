#include "include/vector.h"
#include "include/article.h"

#include <stdlib.h>

struct vector{
  Article* vector;
  int size;
  int used;
};

Vector new_vector(){
    Vector v = (Vector) malloc(sizeof(struct vector));
    v->size = 4; //Stock value
    v->used = 0;

    v->vector = malloc(sizeof(struct article)*v->size);
    return v;
}


void add_article(Vector v, Article a){
    if(v->used == v->size){
        v->size = 2*v->size; // Duplico o tamanho
        Article newVec[v->size];
        int i;
        for(i = 0; i < v->used; i++){
            newVec[i] = v->vector[i];
        }
        v->vector = newVec;
        v->used++;
    }
    else {
        v->vector[v->used++] = a; //Acho que nao vale a pena fazer uma cópia
    }
}