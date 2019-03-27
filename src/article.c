#include <stdlib.h>
#include <string.h>
#include "include/article.h"


Article new_article(){
    Article a = (Article) malloc(sizeof(struct article));
    a->n_category = 0;
    return a;
}

void add_title(Article a, char* t, int size){
    a->title = malloc(sizeof(size));
    a->title = t;
}

void add_info(Article a, char* t, int size){
    a->info = malloc(sizeof(size));
    a->info = t;
}

void add_abstract(Article a, char* t, int size){
    a->abstract = malloc(sizeof(size));
    a->abstract = t;
}

void add_url(Article a, char* t, int size){
    a->url = malloc(sizeof(size));
    a->url = t;
}

void add_category(Article a, char* t, int size){
    char** new_category = malloc(sizeof(new_category) * (a->n_category + 1));
    int i;
    for(i = 0; i < a->n_category; i++){
        new_category[i] = malloc(sizeof(a->category[i]));
        new_category[i] = a->category[i];
    }
    new_category[i] = malloc(sizeof(size));
    new_category[i] = t;
    a->n_category++;

    a->category = new_category;
}
