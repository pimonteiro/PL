#include "include/vector.h"
#include "include/article.h"

#include <stdio.h>
#include <string.h>


#define START_HTML(f)       fprintf(f,"<!DOCTYPE html>\
                                        <html>\n")
#define HEAD_BODY_HTML(f,s)      fprintf(f,"<head>\
                                                <title>%s</title>\n\
                                                <link rel=\"stylesheet\" type=\"text/css\" href=\"styles.css\">\n\
                                            </head>\
                                            <body>\n", s);
#define END_HTML(f)     fprintf(f,"</body></html>");


int is_category(char* cat, char** categories){
    int i;
    for(i = 0; categories[i] != NULL; i++){
        if(strcmp(categories[i],cat))           // Talvez seja preciso fazer alguma coisa, caso por exemplo um esteja minusculas e outro maiusculas
            return 1;
    }
    return 0;
}

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
void print_info_table(Article a, FILE* f){
    fprintf(f,"<table classe=\"tg\">\n");
}

void print_article(Article a, FILE* f){
    fprintf(f,"<h1>%s</h1>\n", a->title);
    fprintf(f,"<p><small>%s</small></p>\n", a->url); // TODO mudar para uma hiperligaçao
    fprintf(f,"<h2>Categorias:</h2>\n<ul>\n");
    for(int i = 0; i < a->n_category; i++){
        fprintf(f, "<li>%s</li>\n",a->category[i]); // TODO verificar maiusculas?
    }
    fprintf(f,"</ul>\n<h2>Abstract:</h2>\n");
    print_info_table(a, f);
    fprintf(f,"<p>%s</p>\n", a->abstract);
    fprintf(f,"<br><hr><br>\n");
}

void html_export(char* filename, Vector v, char** categories){
    strcat(filename,".html");

    FILE* f = fopen(filename, "w");
    if(f == NULL){
        printf("Error opening the file.\n");
    }
    
    START_HTML(f);
    HEAD_BODY_HTML(f,"Artigos Wikipedia");

    int i;
    for(i = 0; i < v->used; i++){
        Article a = v->vector[i];
        for(int j = 0; j < a->n_category; j++){
            int c = is_category(a->category[j],categories);
            if(c)
                print_article(a,f);
        }
    }

    END_HTML(f);
    fclose(f);
}