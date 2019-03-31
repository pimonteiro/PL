%option noyywrap
%{
#include <stdio.h>
#include <string.h>
#include "include/article.h"
#include "include/vector.h"
#include "include/htmlexporter.h"
#include "include/latexexporter.h"
#include "include/markexporter.h"

Vector vector;
Article a;
int c = 0;
int v = 0;
%}

%x LINK
%x TITLE
%x CATEGORY
%x INFO
%x ABSTRACT 
%x REFS

word    ([a-zA-Z]+)
marks   (à|á|â|ã|é|è|ê|ẽ|í|ì|î|ĩ|ó|ò|ô|õ|ú|ù|û|ũ)
wordPT  ({word}+{marks}*{word}*)
silence (.|\n)
teste   (&[^;]*;) 
%%
<INITIAL>"<title>"             {if(v=0)vector = new_vector();
                                 v++;
                                 Article article = new_article();
                                 a = article; add_article(vector,a);
                                 BEGIN TITLE; }
<INITIAL>"{Info/"              { BEGIN INFO; }
<INITIAL>"'''"                 {if(c==0) BEGIN ABSTRACT; }
<INITIAL>^\[\["Categoria:"      { BEGIN CATEGORY; }


<TITLE>({wordPT}" "?)+/"<\/title>" { add_title(a, yytext, yyleng);
                                     BEGIN INITIAL; }

<INFO>&[^;]*;                            { ; }
<INFO>{wordPT}\n                  {add_info(a, yytext, yyleng);}
<INFO>"|"[^=]+=.+"\n"             {  add_info(a, yytext+1, yyleng-1); }
<INFO>^"}}"                       { BEGIN INITIAL; } 

<ABSTRACT>{teste}                      { ; }
<ABSTRACT>"({"[^\}]*"})"            { ; }
<ABSTRACT>"{{"[^\}]*"}}"         { ; }
<ABSTRACT>[^'''|\{\{|\n]*      { add_abstract(a, yytext, yyleng); }
<ABSTRACT>"\n"                     {c=1; BEGIN INITIAL; }

<CATEGORY>.*/"]]"                  { add_category(a, yytext, yyleng); BEGIN INITIAL;}


<*>{silence}

%%

void print_help(){
  printf("./prog <category> html \n");
  printf("./prog <category> latex <output file> < input\n");
  printf("./prog <category> markdown <output file> < input\n");
}

int main(int argc, char* argv[]) {
  if(argc < 3){
    print_help();
    return 1;
  }
  yylex();
  if(strcmp(argv[2],"html") == 0){
    html_export(vector, argv[1]);
  }
  else if(strcmp(argv[2],"latex") == 0){
    latex_export(argv[3], vector, argv[1]);
  } 
  else if(strcmp(argv[2],"markdown") == 0){
    markdown_export(argv[3], vector, argv[1]);
  }
  else {
    printf("Bad option.\n");
  }
  return 0;
}
    
