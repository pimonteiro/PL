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

int index = 0;

// Further testing needed
static void print_info_table(Article a, FILE* f){
    fprintf(f,"<table class=\"blueTable\">\n\t<tbody>\n");
	char delim[] = "=";
    char *ptr = strtok(a->info, delim);

	while(ptr != NULL)
	{
        fprintf(f,"\t\t<tr>\n");
        for(int i = 0; i < 2; i++){
            fprintf(f, "\t\t\t<td>%s</td>\n", ptr);
            ptr = strtok(NULL, delim); // Sei que existirá
        }
        fprintf(f,"\t\t</tr>\n");
	}
    fprintf(f,"\t</tbody>\n</table>\n");
}

static void print_index(char* title, FILE* f){
    fprintf(f, "<li><a href=\"%d.html\">%s</a></li>\n", index, title);
}

static void print_article(Article  a){
    char* title;
    sprintf(title,"%d.html",index);

    FILE* f = fopen(title,"w");
    if(f == NULL){
        printf("Error opening file.");
        exit(1);
    }
    START_HTML(f);
    HEAD_BODY_HTML(f,a->title);
    fprintf(f,"<p><a href=\"index.html\"><img class=\"back\" src=\"../assets/back.png\">Voltar ao início...</a></p>\n");
    fprintf(f,"<div class=\"articles\">\n<h1 class=\"articles\"><u>%s</u></h1>\n", a->title);
    fprintf(f,"<p><small><a href=\"http://%s\">Artigo Original</a></small></p>\n</div>\n", a->url);
    fprintf(f,"<h2>Categorias:</h2>\n<ul>\n");
    for(int i = 0; i < a->n_category; i++){
        fprintf(f, "<li>%s</li>\n",a->category[i]);
    }
    fprintf(f,"</ul>\n<h2>Abstract:</h2>\n");
    print_info_table(a, f);
    fprintf(f,"<p>");
    for(int i = 0; i < a->n_words; i++){
        fprintf(f,"%s ", a->abstract[i]);
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
                index++;
            }
        }
    }

    fprintf(homepage,"</ul>\n");
    END_HTML(homepage);
    fclose(homepage);
}