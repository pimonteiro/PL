%option noyywrap
%{
#include <stdio.h>
//#include "include/article.h"
//#include "include/vector.h"
// Vector vector = new_vector();
int c = 0;
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
teste   ([&\n])
%%
<INITIAL>"<title>"             { BEGIN TITLE; }
<INITIAL>"{Info/"              { BEGIN INFO; }
<INITIAL>"'''"                 {if(c==0) BEGIN ABSTRACT; }
<INITIAL>^\[\["Categoria:"      { BEGIN CATEGORY; }


<TITLE>({wordPT}" "?)+/"<\/title>" {//Article article = new_article(); 
                       //add_article(vector, article); 
                       //add_title(article, yytex, yylen); 
                       printf("%s", yytext); BEGIN INITIAL; }

<CATEGORY>.*/"]]"              { //add_category(article, yytext, yylen); 
                       printf("%s\n", yytext); BEGIN INITIAL;}


<ABSTRACT>&[^;]*;[^;]*;                { ; }
<ABSTRACT>"({{"[^\}]*"}})"                { ; }
<ABSTRACT>[^('''|\(\{\{|\n)]*     {// add_abstract(article, yytex, yylen);
                                     printf("%s", yytext); c=1;}

<ABSTRACT>"\n"                   { BEGIN INITIAL; }


<INFO>&.*;.*;         { ; }
<INFO>"|"[^=]+=.+"\n" { yytext = (yytext + 1); printf("%s", yytext); }
<INFO>^"}}"                 { BEGIN INITIAL;}

<*>{silence}

%%

int main() {
  yylex();
}
