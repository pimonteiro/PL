%option noyywrap
%{
#include <iostream>
#include "include/article.h"

Article* article;
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

<INITIAL>{
"<title>"             { BEGIN TITLE; }
"{Info/"              { BEGIN INFO; }
"'''"                 { BEGIN ABSTRACT; }
\[\["Categoria:"\]\]  { BEGIN CATEGORY; }

}

<TITLE>{
{wordPT}(?=<\/title>) {add_title(article, yytex, yylen); }
"\n"                  { BEGIN INITIAL; }
}

<CATEGORY>{
{wordPT}              { add_category(article, yytext, yylen); }
"\n"                  { BEGIN INITIAL; }
}

<ABSTRACT>{
&.*;                   { ; }
{wordPT}(),\.          { add_category(article, yytex, yylen); }
"\n"                   { BEGIN INITIAL; }
}

<INFO>{
{word}"="{silence}    {add_info(article, yytex, yylen);}
"}}"                  {BEGIN INITIAL;} // falta verificar o que esta dentro de parenteses retos na infobox 
}