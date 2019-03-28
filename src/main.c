#include "include/htmlexporter.h"  
#include "include/latexexporter.h"


#include <stdlib.h>
#include <stdio.h>


int main(){
    Article a = new_article();
    add_title(a, "Como reinar Portugal", 50);
    add_info(a, "ainda vai ser definido isto mas é pra cagar",200);
    add_url(a,"www.google.pt", 50);
    add_category(a,"Historia",20);
    add_category(a,"Cultura",20);
    //add_abstract(a,"Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nulla condimentum ultrices luctus. Donec ut est et tellus viverra volutpat. Cras ut quam magna. Cras id semper leo. Suspendisse consequat sodales justo non euismod. Maecenas mattis fringilla dolor ut tempor. Duis eu mauris vehicula metus dignissim rutrum. Quisque ut metus magna. Morbi sagittis eros vitae metus imperdiet, a tempor augue vulputate. Fusce egestas nisl quis erat blandit, eu scelerisque nisl dapibus. Sed nibh lacus, varius sed. ", 550);
    add_abstract(a,"ola",3);
    add_abstract(a,"tudo",4);
    add_abstract(a,"bem?",4);
    Vector v = new_vector();
    add_article(v,a);
    char* cat[2];
    cat[0] = "Historia";
    cat[1] = "Cultura";
    latex_export("test1",v,cat,2);
    return 0;
}