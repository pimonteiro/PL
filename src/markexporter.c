#include "include/article.h"
#include "include/vector.h"
#include "include/auxFunc.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


static void print_info_table(FILE* f, Article a){
    for(int i = 1; i < a->n_info; i++){
        char delim[] = "=";
        char *ptr = strtok(a->info[i], delim);
        fprintf(f, "| %s | ", ptr);
        ptr = strtok(NULL, delim);
        if(ptr == NULL){
            fprintf(f," |\n");
        } else if(strstr(ptr,".png") || strstr(ptr,".jpg") || strstr(ptr,".jpeg")){
            fprintf(f, "![Pic](%s/", a->url);
            char br[] = " ";
            char* save;
            char* pp = __strtok_r(a->title, br, &save);
            fprintf(f,"%s", pp);
            while((pp = __strtok_r(save, br, &save)) != NULL){
                fprintf(f,"_%s", pp);
            }
            fprintf(f,"/%s%s) |\n", IMG_URL, ptr);
        }
        else
            fprintf(f,"%s |\n",ptr);
    }
}

static void print_article(Article a, FILE* f){
    fprintf(f,"## %s\n", a->title);
    fprintf(f,"### [Artigo Original](%s/", a->url);
    char br[] = " ";
    char* pp = strtok(a->title, br);
    fprintf(f,"%s", pp);
    while((pp = strtok(NULL,br)) != NULL){
        fprintf(f,"_%s", pp);
    }
    fprintf(f,"\n");
    fprintf(f,"Categorias:\n");
    for(int i = 0; i < a->n_category; i++){
        fprintf(f,"- %s;\n", a->category[i]);
    }
    fprintf(f,"#### Abstract\n\n");
    fprintf(f,"| Informação | Extra |\n| ---- | ---- |\n");
    print_info_table(f, a);

    for(int i = 0; i < a->n_words; i++){
        char* word = a->abstract[i];
        if(strstr(word,"[[") && strstr(word,"]]")){
            int size = strlen(word);
            char w[size-3];
            for(int j = 2; j < size-2; j++)
                w[j-2] = word[j];

            w[size-4] = '\0';
            fprintf(f,"**%s** ", w);
        }
        else
            fprintf(f,"%s ", word);

    }
    fprintf(f,"\n___\n___\n___\n___\n___\n");
}

void markdown_export(char* name, Vector v, char* category){
    char* filename = malloc(sizeof(name) + 3);
    strcat(filename,name);
    strcat(filename,".md");

    FILE* f = fopen(filename, "w");
    if(f == NULL){
        printf("Error opening file.\n");
        return;
    }

    // Write beginning of markdown
    fprintf(f,"# Artigos Wikipedia\n");
    fprintf(f,"### %s ", category);
    fprintf(f,"\n___\n___\n___\n");

    // Write articles
    int i;
    for(i = 0; i < v->used; i++){
        Article a = v->vector[i];
        for(int j = 0; j < a->n_category; j++){
            if(strcmp(a->category[i], category) == 0){
                print_article(a,f);
                break;
            }
        }
        fclose(f);
    }
}