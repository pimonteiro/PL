%option noyywrap
%{
#include <stdio.h>
//#include "include/article.h"
//#include "include/vector.h"
// Vector vector = new_vector();
%}


word    ([a-zA-Z]+)
marks   (à|á|â|ã|é|è|ê|ẽ|í|ì|î|ĩ|ó|ò|ô|õ|ú|ù|û|ũ)
wordPT  ({word}+{marks}*{word}*)
silence (.|\n)
teste   (&(.*)?;(.*)?;) 
%%
{teste}                             { ; }
"\n"                                { printf("%s", yytext); }




%%

int main() {
  yylex();
}
