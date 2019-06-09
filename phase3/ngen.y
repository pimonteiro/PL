%{
#define _GNU_SOURCE
#include <stdio.h>
#include "include/pessoa.h"

Pessoa p;
%}
%union {
    int num;
    char* str;
}

%token FOTO HIST NASCEU NASCEUAPROX MORREU MORREUAPROX CASAMENTO EVENTO
%token <num> NUM
%token <str> STRING NOME

%type <str> Nomes ID Identificacao
%%

Ngen : Acao
     | Acao Ngen
     ;

Acao : Parentesco
     | Nomes ID         {printf("%d - %s\n",atoi($2), $1);}
     | Nomes            {printf("%s\n", $1);}
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


Nomes : NOME                   {$$=$1;}
      | NOME '/' NOME          {asprintf(&$$,"%s%s",$1,$3);}
      | NOME '%' NUM           {} /*Might fail here*/
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

Identificacao : ID              {$$ = $1;}
              | Nomes           {asprintf(&$$,"%s", $1);}
              ;

Dados_Extra : FOTO STRING
            | HIST STRING
            ;

ID : '[' NUM ']'                {$$ = $2;}
   ;
%%

int yyerror(char* s){
    printf("Error: %s\n", s);
    return 0;
}

int main(){
    p = create(-1);
    yyparse();
    return 0;
}
