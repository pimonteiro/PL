%option noyywrap
%{
#include <stdio.h>
#include <string.h>
//#include "include/article.h"
//#include "include/vector.h"
// Vector vector = new_vector();
int i = 0;
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
<INITIAL>"<title>"                 {i=0; BEGIN TITLE; }
<INITIAL>"{Info/"                  { BEGIN INFO; }
<INITIAL>"'''"                     {if(i==0) BEGIN ABSTRACT; }
<INITIAL>^\[\["Categoria:"         { BEGIN CATEGORY; }


<TITLE>({wordPT}" "?)+/"<\/title>" { printf("%s\n", yytext); BEGIN INITIAL; }

<INFO>{wordPT}\n                   {printf("%s", yytext);}
<INFO>"|"[^=]+=.+"\n"              {  printf("%s", yytext+1); }
<INFO>^"}}"                        { BEGIN INITIAL; } 

<ABSTRACT>"({"[^\}]*"})"           { ; }
<ABSTRACT>"{{"[^\}]*"}}"           { ; }
<ABSTRACT>[^'''|\{\}|\n]*      { printf("%s", yytext); }
<ABSTRACT>"\n"                     {i=1; BEGIN INITIAL; }

<CATEGORY>.*/"]]"                  { printf("\n%s", yytext); BEGIN INITIAL;}

<*>{silence}

%%

int main() {
  yylex();
}
