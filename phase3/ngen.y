%{
#include <stdio.h>
%}
%union {
    int num;
    char* str;
}

%token FOTO HIST NASCEU NASCEUAPROX MORREU MORREUAPROX CASAMENTO EVENTO
%token <num> NUM
%token <str> STRING
%%

Ngen : Acao
     | Acao Ngen
     ;

Acao : Parentesco
     | Nomes ID
     | Dados_Extra
     | Casamento
     ;

Parentesco : 'P' Identificacao Evento
           | 'P' Identificacao
           | 'M' Identificacao Evento
           | 'M' Identificacao
           | Filho
           | '-' 'P' Identificacao Evento
           | '-' 'P' Identificacao
           | '-' 'M' Identificacao Evento
           | '-' 'M' Identificacao
           | '-' 'P' Parentesco
           | '-' 'M' Parentesco
           | 'P' Parentesco
           | 'M' Parentesco
           ;

Filho : 'F' Identificacao Evento '{' Dados_Extra '}'
      | 'F' Identificacao Evento
      | 'F' Identificacao
      ;

Nomes : Nomes1
      | Nomes1 '/' Nomes1
      | Nomes '%' NUM
      ;

Nomes1 : STRING
       | STRING Nomes1
       ;

Evento : NASCEU NUM
       | NASCEUAPROX NUM
       | MORREU NUM
       | MORREUAPROX NUM
       | EVENTO NUM ':' MORREU
       | EVENTO NUM ':' NASCEU
       | EVENTO NUM ':' MORREUAPROX
       | EVENTO NUM ':' NASCEUAPROX
       ;

Casamento : CASAMENTO NUM Identificacao
          ;

Identificacao : ID
              | Nomes
              ;

Dados_Extra : FOTO STRING
            | HIST STRING
            ;

ID : '[' NUM ']'
   ;
%%

int yyerror(char* s){
    printf("Error: %s\n", s);
    return 0;
}

int main(){
    yyparse();
    return 0;
}
