/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 19 "ngen.y" /* yacc.c:1909  */

    #include "include/pessoa.h"
    #include "include/evento.h"
    #include <glib.h>

    void add_eventos(Pessoa p, GList* evs);

    struct parenting{
        Pessoa pessoa;
        int path[4];            //Max 4 generations
        int i;
        int inv;
    }parenting;

#line 59 "y.tab.h" /* yacc.c:1909  */

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    FOTO = 258,
    HIST = 259,
    NASCEU = 260,
    NASCEUAPROX = 261,
    MORREU = 262,
    MORREUAPROX = 263,
    CASAMENTO = 264,
    EVENTO = 265,
    NUM = 266,
    STRING = 267
  };
#endif
/* Tokens.  */
#define FOTO 258
#define HIST 259
#define NASCEU 260
#define NASCEUAPROX 261
#define MORREU 262
#define MORREUAPROX 263
#define CASAMENTO 264
#define EVENTO 265
#define NUM 266
#define STRING 267

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 34 "ngen.y" /* yacc.c:1909  */

    int num;
    char* str;
    Pessoa p;
    Evento ev;
    GList* list;
    struct parenting rela;

#line 104 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
