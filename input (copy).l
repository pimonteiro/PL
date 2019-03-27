%option noyywrap
%{
#include <stdio.h>
//#include "include/article.h"
//#include "include/vector.h"
// Vector vector = new_vector();
%}

%x LINK
%x TITLE
%x CATEGORY
%x INFO
%x ABSTRACT 

word    ([a-zA-Z]+)
marks   (à|á|â|ã|é|è|ê|ẽ|í|ì|î|ĩ|ó|ò|ô|õ|ú|ù|û|ũ)
wordPT  ({word}+{marks}*{word}*)
silence (.|\n)

%%
"<title>"                      { BEGIN TITLE; }
<INITIAL>"{{Info/"             { BEGIN INFO; }
<INITIAL>"'''"                 { BEGIN ABSTRACT; }
<INITIAL>\[\["Categoria:"\]\]  { BEGIN CATEGORY; }

<TITLE><\/title>        { ; }
<TITLE>{wordPT}         { printf("%s", yytext); BEGIN INITIAL;}                                                                                      


<CATEGORY>wordPT              { printf("%s", yytext); BEGIN INITIAL;}



<ABSTRACT>&.*;.*;                   { ; }
<ABSTRACT>wordPT\(\)\,\./\n          {printf("%s", yytext); BEGIN INITIAL; }
 


<INFO>\{\{(.*)\}\}        { ; }
<INFO>&.*;.*;               { ; }
<INFO>word+silence    {printf("%s", yytext);BEGIN INITIAL;}
<INFO>\}\}               {;}


<*>{silence}


%%

int main() {
  yylex();
}
