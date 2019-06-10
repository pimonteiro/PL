%{
#define _GNU_SOURCE
#include <stdio.h>
#include <glib.h>
#include "include/pessoa.h"
#include "include/evento.h"

GHashTable* table;

int user;

int id = 0; //ID geral
char* foto;
char* histo;
int flagExtra = 0; //0 -> historia | 1 -> foto

%}
%code requires {
    #include "include/pessoa.h"
    #include "include/evento.h"
    #include <glib.h>
}

%union {
    int num;
    char* str;
    Pessoa p;
    Evento ev;
    GList* list;
}

%token FOTO HIST NASCEU NASCEUAPROX MORREU MORREUAPROX CASAMENTO EVENTO
%token <num> NUM
%token <str> STRING NOME

%type <str> Dado
%type <num> ID
%type <p> Pessoa Nomes Identificacao
%type <list> Eventos
%type <ev> Evento
%%

Ngen : Pessoa '\n' Acoes    {gint* k = g_new(gint,1); *k = $1->id; g_hash_table_insert(table, k, (gpointer)$1); user = $1->id;}
     | Pessoa               {gint* k = g_new(gint,1); *k = $1->id; g_hash_table_insert(table, k, (gpointer)$1); user = $1->id;}
     ;

Acoes : Acao
      | Acoes '\n' Acao
      ;

Acao : Parentesco               {/*DUNNO*/}
     | Dados_Extra              {gint* k = g_new(gint,1); *k = user;
                                 Pessoa a = g_hash_table_lookup(table, k);
                                 if(a == NULL){
                                     printf("Error Dados_Extra\n");
                                 }
                                 else{
                                     a->historia = histo;
                                     a->foto = foto;
                                 }
                                 }
     | Casamento                {}
     ;

Pessoa : Nomes Eventos ID        {Pessoa p = $1;
                                 p->eventos = $2;
                                 p->id = $3;
                                 $$ = p;
                                }
       | Nomes Eventos           {Pessoa p = $1;
                                  p->eventos = $2;
                                  id++;
                                  $$ = p;
                                }
       | Nomes ID               {Pessoa p = $1;
                                 p->id = $2;
                                 $$ = p;
                                }
       | Nomes                  {Pessoa p = $1;
                                 id++;
                                 $$ = p;
                                }
       ;


Parentesco : "P" Info
           | "P" Parentesco
           | "M" Info
           | "M" Parentesco
           | Filho
           ;

Info : Identificacao Eventos
     | Identificacao
     ;

Filho : 'F' Identificacao Evento '{' Dados_Extra '}'
   | 'F' Identificacao Evento
   | 'F' Identificacao
   ;

Eventos : Evento                {GList* evs = NULL; evs = g_list_append(evs,(gpointer)$1); $$ = evs;}
        | Eventos Evento        {GList* evs = NULL; evs = g_list_append(evs,(gpointer)$2); evs = g_list_concat($1,evs); $$ = evs;}
        ;


Nomes : NOME                   {Pessoa a = create(id); a->nome = $1; $$ = a;}
      | NOME '/' NOME          {Pessoa a = create(id); a->nome = $1; a->apelido = $3; $$ = a;}
      | NOME '%' NUM           {Pessoa a = create(id); a->nome = $1; a->repetido = $3; $$ = a;} /*Might fail here*/
      ;


Evento : NASCEU NUM                     {$$ = create_evento($2,N);}
       | NASCEUAPROX NUM                {$$ = create_evento($2,NA);}
       | MORREU NUM                     {$$ = create_evento($2,M);}
       | MORREUAPROX NUM                {$$ = create_evento($2,MA);}
       | EVENTO NUM ':' MORREU          {$$ = create_evento($2,M);}
       | EVENTO NUM ':' NASCEU          {$$ = create_evento($2,N);}
       | EVENTO NUM ':' MORREUAPROX     {$$ = create_evento($2,MA);}
       | EVENTO NUM ':' NASCEUAPROX     {$$ = create_evento($2,NA);}
       ;

Casamento : CASAMENTO NUM Identificacao {   gint* k = g_new(gint,1); *k = user;
                                            Pessoa a = g_hash_table_lookup(table, k);
                                            if(a == NULL){
                                                printf("Error casamento!\n");
                                            }
                                            else{
                                                a->dataCasado = $2;
                                                Pessoa p = $3;
                                                if(p->id == id) id++;
                                                p->idCasado = a->id;
                                                p->dataCasado = $2;
                                                gint* k2 = g_new(gint,1); *k2 = p->id;
                                                g_hash_table_insert(table,k2,(gpointer)p);
                                            }
                                        }
          ;

Identificacao : ID              { $$ = create($1); }
              | Nomes           { $$ = $1; }
              ;

Dados_Extra : Dado              {if(flagExtra == 1)
                                    foto = $1;
                                 else
                                    histo = $1;
                                }
            | Dados_Extra Dado  {if(flagExtra == 1)
                                    foto = $2;
                                 else
                                    histo = $2;
                                }
            ;

Dado : FOTO STRING              {flagExtra = 1; $$ = $2;}
     | HIST STRING              {flagExtra = 0; $$ = $2;}
     ;

ID : '[' NUM ']'                {$$ = $2;}
   ;
%%

int yyerror(char* s){
    printf("Error: %s\n", s);
    return 0;
}

int main(){
    table = g_hash_table_new (g_int_hash, g_int_equal);

    yyparse();

    gint* k = g_new(gint,1); *k = 3;
    Pessoa p = g_hash_table_lookup(table, k);
    Evento e1 = (Evento)g_list_nth(p->eventos,0)->data;
    printf("%s %s -> %d\n%d",p->nome,p->apelido, p->id, id);
    return 0;
}
