#include "include/article.h"
#include "include/vector.h"
#include "include/auxFunc.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


static void print_info_table(FILE* f, Article a){
    fprintf(f, "\\hline\n");
    for(int i = 0; i < a->n_info; i++){
        char delim[] = "=";
        char *ptr = strtok(a->info[i], delim);
        fprintf(f,"%s & ", ptr);
        ptr = strtok(NULL, delim); // Sei que existirá
        if(ptr == NULL){
            printf("Something bad on xml format.\n");
            exit(1);
        }
        fprintf(f,"%s \\\\\n",ptr);
        fprintf(f,"\\hline\n");
    }
}

static void print_article(Article a, FILE* f){
    fprintf(f,"\\section{%s}\n", a->title);
    fprintf(f,"\\href{%s}{\\textit{Artigo Original}}\n\\newline\n", a->url);
    fprintf(f,"\\textbf{Categorias:}\n\\begin{itemize}\n");
    for(int i = 0; i < a->n_category; i++){
        fprintf(f,"\t\\item %s;\n", a->category[i]);
    }
    fprintf(f,"\\end{itemize}\n");
    fprintf(f,"\\subsection{Abstract}\n\n");
    fprintf(f,"\\begin{tabular}{|p{3cm}||p{3cm}|p{3cm}|p{3cm}|}\n\\hline\n\\multicolumn{2}{|c|}{Info} \\\\\n\\hline\n");
    print_info_table(f, a);
    fprintf(f,"\\end{tabular}\\newline\n\\vspace{2cm}\n\n\n");

    for(int i = 0; i < a->n_words; i++){
        char* word = a->abstract[i];
        if(strstr(word,"[[") && strstr(word,"]]")){
            int size = strlen(word);
            char w[size-3];
            for(int j = 2; j < size-2; j++)
                w[j-2] = word[j];

            w[size-4] = '\0';
            fprintf(f,"\\textbf{%s} ", w);
        }
        else
            fprintf(f,"%s ", word);

    }
    fprintf(f,"\n\\newpage\n");
}

void latex_export(char* name, Vector v, char* category){
    char* filename = malloc(sizeof(name) +4);
    strcat(filename,name);
    strcat(filename,".tex");

    FILE* f = fopen(filename, "w");
    if(f == NULL){
        printf("Error opening file.\n");
        return;
    }

    // Write beginning of latex
    fprintf(f,"\\documentclass[a4paper]{article}\n\\usepackage[pdftex]{hyperref}\n\\begin{document}\n\\title{Artigos Wikipedia \\\\\n\\
            \\large %s }\n", category);
    fprintf(f,"\\maketitle\n\\author{Wikipedia}\n\\date{\\today}\n\\setcounter{tocdepth}{1}\n\\tableofcontents\n\n\\newpage\n");

    // Write articles
    int i;
    for(i = 0; i < v->used; i++){
        Article a = v->vector[i];
        for(int j = 0; j < a->n_category; j++){
            if(strcmp(a->category[i], category)){
                print_article(a,f);
                break;
            }
        }
        fprintf(f,"\\end{document}\n");

        fclose(f);
    }   

}