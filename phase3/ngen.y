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

    void add_eventos(Pessoa p, GList* evs);

    struct parenting{
        Pessoa pessoa;
        int path[4];
        int i;
    }parenting;
}

%union {
    int num;
    char* str;
    Pessoa p;
    Evento ev;
    GList* list;
    struct parenting rela;
}

%token FOTO HIST NASCEU NASCEUAPROX MORREU MORREUAPROX CASAMENTO EVENTO
%token <num> NUM
%token <str> STRING

%type <str> Dados_Extra
%type <num> ID
%type <p> Pessoa Nomes Identificacao Info
%type <list> Eventos
%type <ev> Evento
%type <rela> Parentesco
%%

Ngen : Pessoa
     | Pessoa '\n' Acoes
     ;

Acoes : Acao '\n'
      | Acoes Acao '\n'
      ;

Acao : Parentesco               {
                                struct parenting pop = $1;
                                if(pop.pessoa != NULL){
                                    gint* k = g_new(gint,1); *k = user;
                                    Pessoa a = g_hash_table_lookup(table,k);
                                    int path = pop.path[0];
                                    for(int i = 1; i < pop.i; i++){
                                        if(pop.path[i] == 0){
                                            path = 0;
                                            *k = a->idPai;
                                            a = g_hash_table_lookup(table,k);
                                        }
                                        else{
                                            path = 1;
                                            *k = a->idMae;
                                            a = g_hash_table_lookup(table,k);
                                        }
                                    }
                                    Pessoa p = pop.pessoa;
                                    gint* k2 = g_new(gint,1);
                                    if(path == 0){
                                        a->idPai = p->id;
                                        p->filhos = g_list_append(p->filhos, GINT_TO_POINTER(a->id));
                                        *k2 = p->id;
                                        g_hash_table_insert(table, (gpointer)k2, (gpointer)p);
                                    }
                                    else{
                                        a->idMae = p->id;
                                        p->filhos = g_list_append(p->filhos, GINT_TO_POINTER(a->id));
                                        *k2 = p->id;
                                        g_hash_table_insert(table, (gpointer)k2, (gpointer)p);
                                    }
                                }
                                }
     | Dados_Extra              {gint* k = g_new(gint,1); *k = user;
                                 Pessoa a = g_hash_table_lookup(table, k);
                                 if(a == NULL){
                                     printf("Error Dados_Extra\n");
                                 }
                                 else{
                                     if(flagExtra == 0)
                                        a->historia = $1;
                                    else
                                        a->foto = $1;
                                 }
                                 }
     | Casamento                {}
     | Evento                   {Evento e = $1;
                                 gint* k = g_new(gint,1); *k = user;
                                 Pessoa a = g_hash_table_lookup(table, k);
                                 GList* evs = NULL; evs = g_list_append(evs, (gpointer)e);
                                 add_eventos(a,evs);
                                }
     ;

Pessoa : Nomes Eventos ID        {Pessoa p = $1;
                                 add_eventos(p,$2);
                                 p->id = $3;
                                 gint* k = g_new(gint,1);
                                 *k = $1->id;
                                 g_hash_table_insert(table, k, (gpointer)p);
                                 user = $1->id;
                                }
       | Nomes Eventos           {Pessoa p = $1;
                                  add_eventos(p,$2);
                                  id++;
                                  gint* k = g_new(gint,1);
                                  *k = $1->id;
                                  g_hash_table_insert(table, k, (gpointer)p);
                                  user = $1->id;
                                }
       | Nomes ID               {Pessoa p = $1;
                                 p->id = $2;
                                 gint* k = g_new(gint,1);
                                 *k = $1->id;
                                 g_hash_table_insert(table, k, (gpointer)p);
                                 user = $1->id;
                                }
       | Nomes                  {Pessoa p = $1;
                                 id++;
                                 gint* k = g_new(gint,1);
                                 *k = $1->id;
                                 g_hash_table_insert(table, k, (gpointer)p);
                                 user = $1->id;
                                }
       ;


Parentesco : 'P' Info               {
                                    struct parenting pop;
                                    pop.pessoa = $2;
                                    pop.path[0] = 0;
                                    pop.i = 1;
                                    $$ = pop;
                                    }
           | 'P' Parentesco         {
                                    struct parenting pop = $2;
                                    pop.path[1] = 0;
                                    pop.i++;
                                    $$ = pop;
                                    }
           | 'M' Info               {
                                    struct parenting pop;
                                    pop.pessoa = $2;
                                    pop.path[0] = 1;
                                    pop.i = 1;
                                    $$ = pop;
                                    }
           | 'M' Parentesco         {
                                    struct parenting pop = $2;
                                    pop.path[1] = 1;
                                    pop.i++;
                                    $$ = pop;
                                    }
           | Filho                  {struct parenting pop;pop.pessoa = NULL; $$ = pop;}
           ;


Filho : 'F' Identificacao Eventos '{' Dados_Extra '}'    {Pessoa f = $2;
                                                         add_eventos(f,$3);
                                                         if(flagExtra == 0)
                                                            f->historia = $5;
                                                         else
                                                            f->foto = $5;
                                                         gint* k = g_new(gint,1); *k = user;
                                                         Pessoa a = g_hash_table_lookup(table, k);

                                                         a->filhos = g_list_append(a->filhos,GINT_TO_POINTER(f->id));
                                                         gint* k2 = g_new(gint,1); *k2 = f->id;
                                                         g_hash_table_insert(table,k2,(gpointer)f);
                                                         if(a->idCasado != -1){
                                                             *k = a->idCasado;
                                                             Pessoa p = g_hash_table_lookup(table, k);
                                                             p->filhos = g_list_append(p->filhos, GINT_TO_POINTER(f->id));
                                                         }
                                                         }
   | 'F' Identificacao Eventos       {Pessoa f = $2;
                                    add_eventos(f,$3);
                                    gint* k = g_new(gint,1); *k = user;
                                    Pessoa a = g_hash_table_lookup(table, k);

                                    a->filhos = g_list_append(a->filhos,GINT_TO_POINTER(f->id));
                                    gint* k2 = g_new(gint,1); *k2 = f->id;
                                    g_hash_table_insert(table,k2,(gpointer)f);
                                    if(a->idCasado != -1){
                                        *k = a->idCasado;
                                        Pessoa p = g_hash_table_lookup(table, k);
                                        p->filhos = g_list_append(p->filhos, GINT_TO_POINTER(f->id));
                                    }
                                    }
   | 'F' Identificacao              {Pessoa f = $2;
                                    gint* k = g_new(gint,1); *k = user;
                                    Pessoa a = g_hash_table_lookup(table, k);

                                    a->filhos = g_list_append(a->filhos,GINT_TO_POINTER(f->id));
                                    gint* k2 = g_new(gint,1); *k2 = f->id;
                                    g_hash_table_insert(table,k2,(gpointer)f);
                                    if(a->idCasado != -1){
                                        *k = a->idCasado;
                                        Pessoa p = g_hash_table_lookup(table, k);
                                        p->filhos = g_list_append(p->filhos, GINT_TO_POINTER(f->id));
                                    }
                                    }
   ;

Info : Identificacao Eventos        {Pessoa p = $1;
                                    if(p->id == id) id++;
                                    add_eventos(p,$2);
                                    $$ = p;
                                    }
     | Identificacao                {Pessoa p = $1;
                                    if(p->id == id) id++;
                                    $$ = p;
                                    }
     ;

Eventos : Evento                {GList* evs = NULL; evs = g_list_append(evs,(gpointer)$1); $$ = evs;}
        | Eventos Evento        {GList* evs = NULL; evs = g_list_append(evs,(gpointer)$2); evs = g_list_concat($1,evs); $$ = evs;}
        ;


Nomes : STRING                   {Pessoa a = create(id); a->nome = $1; $$ = a;}
      | STRING STRING            {Pessoa a = create(id); a->nome = $1; a->apelido = $2; $$ = a;}
      | STRING '/' STRING        {Pessoa a = create(id); a->nome = $1; a->apelido = $3; $$ = a;}
      | STRING '%' NUM           {Pessoa a = create(id); a->nome = $1; a->repetido = $3; $$ = a;} /*Might fail here*/
      ;


Evento : NASCEU NUM                     {$$ = create_evento($2,N);}
       | NASCEUAPROX NUM                {$$ = create_evento($2,NA);}
       | MORREU NUM                     {$$ = create_evento($2,M);}
       | MORREUAPROX NUM                {$$ = create_evento($2,MA);}
       | EVENTO NUM ':' STRING          {$$ = create_evento($2,$4);}
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
                                                a->idCasado = p->id;
                                                p->idCasado = a->id;
                                                p->dataCasado = $2;
                                                gint* k2 = g_new(gint,1); *k2 = p->id;
                                                g_hash_table_insert(table,k2,(gpointer)p);
                                            }
                                        }
          ;

Identificacao : ID                { $$ = create($1); }
              | Nomes ID          { Pessoa p = $1; p->id = $2; $$ = p;}
              | Nomes             { $$ = $1; }
              ;

Dados_Extra : FOTO STRING              {flagExtra = 1; $$ = $2;}
            | HIST STRING              {flagExtra = 0; $$ = $2;}


ID : '[' NUM ']'                {$$ = $2;}
   ;
%%

int yyerror(char* s){
    printf("Error: %s\n", s);
    return 0;
}

void add_eventos(Pessoa p, GList* evs){
    int n = g_list_length(evs);
    for(int i = 0; i < n; i++){
        Evento e = (Evento) g_list_nth_data(evs,i);
        if(strcmp(e->descricao,N) == 0){
            p->nasceu = e->data;
        }
        else if(strcmp(e->descricao,M) == 0){
            p->morte = e->data;
        }
        else if(strcmp(e->descricao,NA) == 0){
            p->nasceu = e->data;
            p->flagNasceAprox = 1;
        }
        else if(strcmp(e->descricao,MA) == 0){
            p->morte = e->data;
            p->flagMorteAprox = 1;
        }
        else
            p->eventos = g_list_append(p->eventos, (gpointer)e);
    }
}

int main(){
    table = g_hash_table_new (g_int_hash, g_int_equal);

    yyparse();

    gint* k = g_new(gint,1); *k = 3;
    Pessoa p1 = g_hash_table_lookup(table, k);
    *k = 0;
    Pessoa p2 = g_hash_table_lookup(table, k);
    *k = 1;
    Pessoa p3 = g_hash_table_lookup(table, k);
    *k = 2;
    Pessoa p4 = g_hash_table_lookup(table, k);
    *k = 4;
    Pessoa p5 = g_hash_table_lookup(table, k);
    *k = 5;
    Pessoa p6 = g_hash_table_lookup(table, k);
    return 0;
}
