#include <string.h>


int is_category(char* cat, char** categories, int n){
    int i;
    for(i = 0; i < n; i++){
        if(strcmp(categories[i],cat) == 0)           // Talvez seja preciso fazer alguma coisa, caso por exemplo um esteja minusculas e outro maiusculas
            return 1;
    }
    return 0;
}
