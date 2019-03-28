#include "include/article.h"
#include "include/vector.h"
#include "include/auxFunc.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define START_HTML(f)       fprintf(f,"<!DOCTYPE html>\n<html>\n")
#define HEAD_BODY_HTML(f,s)      fprintf(f,"<head>\n\t<title>%s</title>\n\t\
                                        <link href=\"https://fonts.googleapis.com/css?family=Open+Sans\" rel=\"stylesheet\">\n\
                                        <link rel=\"stylesheet\" type=\"text/css\" href=\"../styles/styles.css\">\n</head>\n<body>\n", s);
#define END_HTML(f)     fprintf(f,"</body>\n</html>");

int index = 0;


/*
<table class="tg">
  <tr>
    <td class="tg-c3ow">ola1</td>
    <td class="tg-c3ow">ola2</td>
  </tr>
  <tr>
    <td class="tg-0pky">ola3</td>
    <td class="tg-0pky">ola4</td>
  </tr>
*/
//TODO
static void print_info_table(Article a, FILE* f){
    //fprintf(f,"<table classe=\"tg\">\n");
}

static void print_index(char* title, FILE* f){
    fprintf(f, "<li><a href=\"#C%d\">%s</a></li>", index, title);
}

static void print_article(Article  a, FILE* f){
    fprintf(f,"<div class=\"articles\">\n<h1 class=\"articles\" id=\"C%d\"><u>%s</u></h1>\n", index, a->title);
    fprintf(f,"<p><small><a href=\"%s\">Artigo Original</a></small></p>\n</div>", a->url);
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
    fprintf(f,"</p>\n");
    fprintf(f,"<br><hr><br>\n");
}

void html_export(char* name, Vector v, char** categories, int n_categories){
    char* filename = malloc(sizeof(name) + 5);
    strcat(filename,name);
    strcat(filename,".html");


    FILE* text = fopen("text.txt", "w");
    if(text == NULL){
        printf("Error opening first file.\n");
        return;
    }
    FILE* p_index = fopen("index.txt","w");
    if(p_index == NULL){
        printf("Error opening second file.\n");
        return;
    }

    START_HTML(p_index);
    HEAD_BODY_HTML(p_index,"Artigos Wikipedia");
    fprintf(p_index, "<h1>Index</h1><ul>\n");

    int i;
    for(i = 0; i < v->used; i++){
        Article a = v->vector[i];
        for(int j = 0; j < a->n_category; j++){
            int c = is_category(a->category[j],categories, n_categories);
            if(c){
                print_article(a,text);
                print_index(a->title, p_index);
                index++;
            }
        }
    }

    fprintf(p_index,"</ul>\n<br><hr class=\"style1\">\n");
    END_HTML(text);

    fclose(text);
    fclose(p_index);
    FILE* final = fopen(filename, "w");
    text = fopen("text.txt","r");
    p_index = fopen("index.txt","r");
    char c;

    while((c = fgetc(p_index)) != EOF){
        fputc(c,final);
    }
    while((c = fgetc(text)) != EOF){
        fputc(c,final);
    }

    fclose(p_index);
    remove("index.txt");
    remove("text.txt");
}