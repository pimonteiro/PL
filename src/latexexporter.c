#include "include/article.h"
#include "include/vector.h"
#include "include/auxFunc.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



static void print_article(Article a, FILE* f){
    fprintf(f,"\\section{%s \\\\\n\\ 
            \\href{%s}{\\normalsize{\\textit{Artigo Original}}}\n", a->title, a->url);
    fprintf(f,"\\textbf{Categorias:}\n\\begin{itemize}\n");
    for(int i = 0; i < a->n_category; i++){
        fprintf(f,"\t\\item %s;\n", a->category[i]);
    }
    fprintf(f,"\\end{itemize}\n");
    fprintf(f,"\\subsection{Abstract}\n\n");
    for(int i = 0; i < a->n_words; i++){
        fprintf(f,"%s ", a->abstract[i]);
    }
    fprintf(f,"\n\\newpage\n");
}



void latex_export(char* name, Vector v, char** categories, int n_categories){
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
            \\large ");
    for(int i = 0; i < n_categories; i++)
        fprintf(f,"%s ", categories[i]);
    fprintf(f,"}\n");
    fprintf(f,"\\maketitle\n\\author{Wikipedia}\n\\date{\\today}\n\\setcounter{tocdepth}{1}\n\\tableofcontents\n\n\\newpage\n");

    // Write articles
    int i;
    for(i = 0; i < v->used; i++){
    Article a = v->vector[i];
    for(int j = 0; j < a->n_category; j++){
        int c = is_category(a->category[j],categories, n_categories);
        if(c)
            print_article(a,f);
    }
    fprintf(f,"\\end{document}\n");

    fclose(f);
}

}