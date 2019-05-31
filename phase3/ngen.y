%{
#include <stdio.h>
%}

%token FOTO HIST F M P STRING NUM

%%

Ngen : Acao
     | Acao Ngen
     ;

Acao : Parentesco
     | Nomes
     | Dados_Extra
     ;

Parentesco : P Nomes Evento
           | M Nomes Evento
           | Filho
           | "-" P Nomes Evento
           | "-" M Nomes Evento
           | "-" P Parentesco
           | "-" M Parentesco
           | P Parentesco
           | M Parentesco
           ;

Filho : F Nomes Evento
      | F Nomes Evento "{" Dados_Extra "}"
      ;

Nomes : STRING
      | STRING "%" NUM
      | STRING "/" Nomes
      | STRING " " Nomes
      ;


Evento : "*" NUM
       | "+" NUM
       | "+c" NUM
       | "cc(" NUM ")" Nomes
       | "ev(" NUM ":+)"
       | "ev(" NUM ":*)"
       | "ev(" NUM ":+c)"  /* Maybe missing cc(DATA) ? */
       ;

Dados_Extra : FOTO STRING
            | HIST STRING
            ;
%%
#include "lex.yy.c"

int yyerror(char* s){
    printf("Error: %s\n", s);
    return 0;
}

int main(){
    yyparse();
    return 0;
}
