#include "include/article.h"
#include "include/vector.h"
#include "include/auxFunc.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define START_HTML(f)       fprintf(f,"<!DOCTYPE html>\n<html>\n")
#define HEAD_BODY_HTML(f,s)      fprintf(f,"<head>\n\t<meta charset=\"utf-8\"/>\n\t<title>%s</title>\n\t\
                                        <link href=\"https://fonts.googleapis.com/css?family=Open+Sans\" rel=\"stylesheet\">\n\
                                        <link rel=\"stylesheet\" type=\"text/css\" href=\"../styles/styles.css\">\n</head>\n<body>\n", s);
#define END_HTML(f)     fprintf(f,"</body>\n</html>");
#define IMG_URL         "#/media/File:"


int ind = 0;

//FALTA SUBSTITUIR OS ESPAÇOS NO TITULO POR _ PARA OS LINKS
static void print_info_table(Article a, FILE* f){
    fprintf(f,"<table class=\"blueTable\">\n\t<tbody>\n");
    for(int i = 0; i < a->n_info; i++){
        char delim[] = "=";
        char *ptr = strtok(a->info[i], delim);
        fprintf(f,"\t\t<tr>\n");
        fprintf(f, "\t\t\t<td>%s</td>\n\t\t\t<td>", ptr);
        ptr = strtok(NULL, delim); // Sei que existirá
        if(ptr == NULL){
            printf("Something bad on xml format.\n");
            exit(1);
        }
        if(strstr(ptr,".png") || strstr(ptr,".jpg") || strstr(ptr,".jpeg"))
            fprintf(f,"<img src=\"%s/%s/%s%s\">", a->url, a->title, IMG_URL, ptr);
        else
            fprintf(f,"%s",ptr);
        fprintf(f,"</td>\n\t\t</tr>\n");
    }
    fprintf(f,"\t</tbody>\n</table>\n");
}

static void print_index(char* title, FILE* f){
    fprintf(f, "<li><a href=\"%d.html\">%s</a></li>\n", ind, title);
}

static void print_article(Article  a){
    char title[20];
    sprintf(title,"%d.html",ind);

    FILE* f = fopen(title,"w");
    if(f == NULL){
        printf("Error opening file.");
        exit(1);
    }
    START_HTML(f);
    HEAD_BODY_HTML(f,a->title);
    fprintf(f,"<p><a href=\"index.html\"><img class=\"back\" src=\"../assets/back.png\">Voltar ao início...</a></p>\n");
    fprintf(f,"<div class=\"articles\">\n<h1 class=\"articles\"><u>%s</u></h1>\n", a->title);
    fprintf(f,"<p><small><a href=\"%s/%s\">Artigo Original</a></small></p>\n</div>\n", a->url, a->title);
    fprintf(f,"<h2>Categorias:</h2>\n<ul>\n");
    for(int i = 0; i < a->n_category; i++){
        fprintf(f, "<li>%s</li>\n",a->category[i]);
    }
    fprintf(f,"</ul>\n<h2>Abstract:</h2>\n");
    print_info_table(a, f);
    fprintf(f,"<p>");
    for(int i = 0; i < a->n_words; i++){
        char* word = a->abstract[i];
        if(strstr(word,"[[") && strstr(word,"]]")){
            int size = strlen(word);
            char w[size-3];
            for(int j = 2; j < size-2; j++)
                w[j-2] = word[j];

            w[size-4] = '\0';
            fprintf(f,"<b>%s</b> ", w);
        }
        else
            fprintf(f,"%s ", word);
    }
    fprintf(f,"</p>\n<br>\n");
    END_HTML(f);
    fclose(f);
}

void html_export(Vector v, char** categories, int n_categories){
    FILE* homepage = fopen("index.html","w");
    if(homepage == NULL){
        printf("Error opening file.\n");
        return;
    }

    START_HTML(homepage);
    HEAD_BODY_HTML(homepage,"Artigos Wikipedia");
    fprintf(homepage,"<ul>\n");
    int i;
    for(i = 0; i < v->used; i++){
        Article a = v->vector[i];
        for(int j = 0; j < a->n_category; j++){
            int c = is_category(a->category[j],categories, n_categories);
            if(c){
                print_article(a);
                print_index(a->title, homepage);
                ind++;
                break;
            }
        }
    }

    fprintf(homepage,"</ul>\n");
    END_HTML(homepage);
    fclose(homepage);
}