#include <stdlib.h>
#include <string.h>
#include "include/article.h"

#include <stdio.h>

Article new_article(){
    Article a = (Article) malloc(sizeof(struct article));
    a->n_category = 0;
    a->n_words = 0;
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

void add_url(Article a, char* t, int size){
    int length = size + strlen(a->title);
    a->url = malloc(sizeof(length+1));
    int i;
    for(i = 0; i < size; i++){
        a->url[i] = t[i];
    }
    for(i = size; i < length; i++){
        a->url[i] = a->title[i - size];
        
    }
    a->url[i] = '\0';
}

void add_abstract(Article a, char* t, int size){
    char** new = malloc(sizeof(new) * (a->n_words + 1));
    int i;
    for(i = 0; i < a->n_words; i++){
        new[i] = malloc(sizeof(a->abstract[i]));
        new[i] = a->abstract[i];
    }
    new[i] = malloc(sizeof(size));
    new[i] = t;
    a->n_words++;
    a->abstract = new;
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
