#include <stdlib.h>
#include <string.h>
#include "include/article.h"

#include <stdio.h>

Article new_article(){
    Article a = (Article) malloc(sizeof(struct article));
    a->n_category = 0;
    a->n_words = 0;
    a->n_info = 0;
    a->url = "https://pt.wikipedia.org/wiki/Wikip%C3%A9dia:P%C3%A1gina_principal";
    return a;
}

void add_title(Article a, char* t, int size){
    a->title = strdup(t);
}

void add_info(Article a, char* t, int size){
    char** new_info = malloc(sizeof(new_info) * (a->n_info + 1));
    int i;
    for(i = 0; i < a->n_info; i++){
        new_info[i] = strdup(a->info[i]);
    }
    new_info[i] = strdup(t);
    a->n_info++;
    a->info = new_info;
}

void add_abstract(Article a, char* t, int size){
    char** new = malloc(sizeof(char*) * (a->n_words + 1));
    int i;
    for(i = 0; i < a->n_words; i++){
        new[i] = strdup(a->abstract[i]);
    }
    new[i] = strdup(t);
    a->n_words++;
    a->abstract = new;
}

void add_category(Article a, char* t, int size){
    char** new_category = malloc(sizeof(new_category) * (a->n_category + 1));
    int i;
    for(i = 0; i < a->n_category; i++){
        new_category[i] = strdup(a->category[i]);
    }
    new_category[i] = strdup(t);
    a->n_category++;
    a->category = new_category;
}
