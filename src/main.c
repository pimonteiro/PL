#include "include/htmlexporter.h"  
#include "include/latexexporter.h"


#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int main(){
    Article a = new_article();
    add_title(a, "Astronomia_Em_Portugal", 22);
    add_info(a,"coracao =chocapic.png", 21);
    add_info(a,"pais =grecia", 12);
    //char str[] = "nome_divindade =Aquiles\n        imagem   =Achilles Statue 2.jpg\n    pais=Tétis e Peleu";
	//int init_size = strlen(str);

    //add_info(a, str, init_size);
    add_url(a,"www.google.pt", 13);
    add_category(a,"Historia",8);
    add_category(a,"Cultura",7);
    add_abstract(a,"ola",3);
    add_abstract(a,"[[tudo]]",8);
    add_abstract(a,"bem?",4);
    add_abstract(a,"[[Cuidado!]]",12);
    Vector v = new_vector();
    add_article(v,a);
    char* cat[2];
    cat[0] = "Historia";
    cat[1] = "Cultura";
    //latex_export("teste1", v,cat,2);
    html_export(v,cat,2);
    return 0;
}