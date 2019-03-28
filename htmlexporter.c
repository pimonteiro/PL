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

int index = 0;


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
//TODO
void print_info_table(Article a, FILE* f){
    fprintf(f,"<table classe=\"tg\">\n");
}

void print_article(Article a, FILE* f){
    fprintf(f,"<h1 id=\"%d\">%s</h1>\n", index, a->title);
    fprintf(f,"<p><small><a href=\"%s\">Artigo Original</a></small></p>\n", a->url); // TODO mudar para uma hiperligaçao
    fprintf(f,"<h2>Categorias:</h2>\n<ul>\n");
    for(int i = 0; i < a->n_category; i++){
        fprintf(f, "<li>%s</li>\n",a->category[i]); // TODO verificar maiusculas?
    }
    fprintf(f,"</ul>\n<h2>Abstract:</h2>\n");
    print_info_table(a, f);
    fprintf(f,"<p>%s</p>\n", a->abstract);
    fprintf(f,"<br><hr><br>\n");
}

void print_index(char* title, FILE* f){
    fprintf(f, "<li><a href=\"%d\">%s</a></li>", index, title);
}

void html_export(char* filename, Vector v, char** categories){
    strcat(filename,".html");

    FILE* text = fopen("text.txt", "w");
    if(text == NULL){
        printf("Error opening the file.\n");
    }
    
    START_HTML(text);
    HEAD_BODY_HTML(text,"Artigos Wikipedia");
    FILE* p_index = fopen("index.txt","w");
    fprintf(p_index, "<h1>Index</h1><ul>\n");

    int i;
    for(i = 0; i < v->used; i++){
        Article a = v->vector[i];
        for(int j = 0; j < a->n_category; j++){
            int c = is_category(a->category[j],categories);
            if(c){
                print_article(a,text);
                print_index(a->title, p_index);
                index++;
            }
        }
    }

    fprintf(p_index,"</ul>\n");
    END_HTML(text);
    FILE* final = fopen(filename, "w");

    char c;
    while((c = fgetc(p_index)) != EOF){
        fputc(c,final);
    }
    while((c = fgetc(text)) != EOF){
        fputc(c,final);
    }

    fclose(final);
    fclose(text);
    fclose(p_index);
    remove("index.txt");
    remove("text,txt");
}