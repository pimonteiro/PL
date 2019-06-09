/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20170709

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "ngen.y"
#define _GNU_SOURCE
#include <stdio.h>
#include "include/pessoa.h"

Pessoa p;
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#line 8 "ngen.y"
typedef union {
    int num;
    char* str;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 39 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define FOTO 257
#define HIST 258
#define NASCEU 259
#define NASCEUAPROX 260
#define MORREU 261
#define MORREUAPROX 262
#define CASAMENTO 263
#define EVENTO 264
#define NUM 265
#define STRING 266
#define NOME 267
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    0,    4,    4,    4,    4,    4,    5,    5,    5,
    5,    5,    5,    5,    5,    5,    5,    5,    5,    5,
    9,    9,    9,    1,    1,    1,    8,    8,    8,    8,
    8,    8,    8,    8,    7,    3,    3,    6,    6,    2,
};
static const YYINT yylen[] = {                            2,
    1,    2,    1,    2,    1,    1,    1,    3,    2,    3,
    2,    1,    4,    3,    4,    3,    3,    3,    2,    2,
    6,    3,    2,    1,    3,    3,    2,    2,    2,    2,
    4,    4,    4,    4,    3,    1,    1,    2,    2,    3,
};
static const YYINT yydefred[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    3,    6,    7,   12,   38,   39,    0,    0,    0,
    0,   37,   36,    0,   19,    0,   20,    0,    0,    0,
    4,    2,   35,   25,   26,    0,    0,    0,    0,    0,
    0,    8,   10,    0,   17,    0,   18,    0,   40,   27,
   28,   29,   30,    0,   13,   15,    0,    0,    0,   32,
   34,   31,   33,   21,
};
static const YYINT yydgoto[] = {                          9,
   22,   23,   24,   11,   12,   13,   14,   42,   15,
};
static const YYINT yysindex[] = {                       -42,
 -261, -255, -252,  -35,  -30,  -30,  -58,  -91,    0,  -71,
  -42,    0,    0,    0,    0,    0,    0,  -91, -238, -232,
 -229,    0,    0, -204,    0, -204,    0,  -30,  -30, -204,
    0,    0,    0,    0,    0,  -48, -217, -216, -213, -206,
 -202,    0,    0, -204,    0, -204,    0,  -59,    0,    0,
    0,    0,    0,    7,    0,    0, -234, -218,  -57,    0,
    0,    0,    0,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    0,    1,    0,    0,    0,    0,    0,    9,
   66,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   17,    0,   25,    0,    0,    0,   37,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   39,    0,   51,    0,   53,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,
};
static const YYINT yygindex[] = {                        56,
   10,   59,   -2,    0,    2,   15,    0,  -12,    0,
};
#define YYTABLESIZE 320
static const YYINT yytable[] = {                         21,
   24,   20,    7,   26,   16,   30,   25,   27,    5,   10,
   17,   19,   18,   43,    7,   33,    9,   48,   29,   21,
   10,   28,    1,    2,   11,   44,   46,    8,   34,   45,
   47,   55,   35,   56,    6,   36,   23,    5,   14,    8,
   60,   61,   62,   63,   49,   24,    6,   50,   51,    5,
   16,   52,   22,    5,   37,   38,   39,   40,   53,   41,
   21,    9,   54,   57,   58,    1,   32,   64,   31,   11,
   24,   59,    0,    0,    0,    0,    0,   24,    5,    0,
   24,   23,    0,   14,    0,    5,    9,    0,    5,    0,
    0,   24,    0,    9,   11,   16,    9,   22,    0,    0,
    0,   11,    0,    0,   11,    0,   23,    0,   14,    0,
    0,    0,    0,   23,    0,   14,   23,    0,   14,    0,
   16,    0,   22,    0,    0,    0,    0,   16,    0,   22,
   16,    0,   22,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    4,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    1,    2,    0,    0,    0,    0,
    3,    0,    0,    0,    4,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    4,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   24,   24,   24,
   24,   24,   24,   24,   24,    5,    5,   24,    0,    0,
    0,    5,    0,    9,    9,    5,    0,    0,    0,    9,
    0,   11,   11,    9,    0,    0,    0,   11,    0,    0,
    0,   11,    0,   23,   23,   14,   14,    0,    0,   23,
    0,   14,    0,   23,    0,   14,    0,   16,   16,   22,
   22,    0,    0,   16,    0,   22,    0,   16,    0,   22,
};
static const YYINT yycheck[] = {                         91,
    0,   37,   45,    6,  266,    8,    5,    6,    0,    0,
  266,   47,  265,   26,   45,   18,    0,   30,   77,   91,
   11,   80,  257,  258,    0,   28,   29,   70,  267,   28,
   29,   44,  265,   46,   77,  265,    0,   80,    0,   70,
  259,  260,  261,  262,   93,   45,   77,  265,  265,   80,
    0,  265,    0,   45,  259,  260,  261,  262,  265,  264,
   91,   45,  265,  123,   58,    0,   11,  125,   10,   45,
   70,   57,   -1,   -1,   -1,   -1,   -1,   77,   70,   -1,
   80,   45,   -1,   45,   -1,   77,   70,   -1,   80,   -1,
   -1,   91,   -1,   77,   70,   45,   80,   45,   -1,   -1,
   -1,   77,   -1,   -1,   80,   -1,   70,   -1,   70,   -1,
   -1,   -1,   -1,   77,   -1,   77,   80,   -1,   80,   -1,
   70,   -1,   70,   -1,   -1,   -1,   -1,   77,   -1,   77,
   80,   -1,   80,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  267,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  257,  258,   -1,   -1,   -1,   -1,
  263,   -1,   -1,   -1,  267,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  267,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  257,  258,  259,
  260,  261,  262,  263,  264,  257,  258,  267,   -1,   -1,
   -1,  263,   -1,  257,  258,  267,   -1,   -1,   -1,  263,
   -1,  257,  258,  267,   -1,   -1,   -1,  263,   -1,   -1,
   -1,  267,   -1,  257,  258,  257,  258,   -1,   -1,  263,
   -1,  263,   -1,  267,   -1,  267,   -1,  257,  258,  257,
  258,   -1,   -1,  263,   -1,  263,   -1,  267,   -1,  267,
};
#define YYFINAL 9
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 267
#define YYUNDFTOKEN 279
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,"'%'",0,0,0,0,0,0,0,"'-'",0,"'/'",0,0,0,0,0,0,0,0,0,0,"':'",0,0,0,0,0,0,0,
0,0,0,0,"'F'",0,0,0,0,0,0,"'M'",0,0,"'P'",0,0,0,0,0,0,0,0,0,0,"'['",0,"']'",0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'{'",0,"'}'",0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,"FOTO","HIST","NASCEU","NASCEUAPROX","MORREU","MORREUAPROX",
"CASAMENTO","EVENTO","NUM","STRING","NOME",0,0,0,0,0,0,0,0,0,0,0,
"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : Ngen",
"Ngen : Acao",
"Ngen : Acao Ngen",
"Acao : Parentesco",
"Acao : Nomes ID",
"Acao : Nomes",
"Acao : Dados_Extra",
"Acao : Casamento",
"Parentesco : 'P' Identificacao Evento",
"Parentesco : 'P' Identificacao",
"Parentesco : 'M' Identificacao Evento",
"Parentesco : 'M' Identificacao",
"Parentesco : Filho",
"Parentesco : '-' 'P' Identificacao Evento",
"Parentesco : '-' 'P' Identificacao",
"Parentesco : '-' 'M' Identificacao Evento",
"Parentesco : '-' 'M' Identificacao",
"Parentesco : '-' 'P' Parentesco",
"Parentesco : '-' 'M' Parentesco",
"Parentesco : 'P' Parentesco",
"Parentesco : 'M' Parentesco",
"Filho : 'F' Identificacao Evento '{' Dados_Extra '}'",
"Filho : 'F' Identificacao Evento",
"Filho : 'F' Identificacao",
"Nomes : NOME",
"Nomes : NOME '/' NOME",
"Nomes : NOME '%' NUM",
"Evento : NASCEU NUM",
"Evento : NASCEUAPROX NUM",
"Evento : MORREU NUM",
"Evento : MORREUAPROX NUM",
"Evento : EVENTO NUM ':' MORREU",
"Evento : EVENTO NUM ':' NASCEU",
"Evento : EVENTO NUM ':' MORREUAPROX",
"Evento : EVENTO NUM ':' NASCEUAPROX",
"Casamento : CASAMENTO NUM Identificacao",
"Identificacao : ID",
"Identificacao : Nomes",
"Dados_Extra : FOTO STRING",
"Dados_Extra : HIST STRING",
"ID : '[' NUM ']'",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 200

typedef struct {
    unsigned stacksize;
    YYINT    *s_base;
    YYINT    *s_mark;
    YYINT    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 82 "ngen.y"

int yyerror(char* s){
    printf("Error: %s\n", s);
    return 0;
}

int main(){
    p = create(-1);
    yyparse();
    return 0;
}
#line 311 "y.tab.c"

#if YYDEBUG
#include <stdio.h>	/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    YYINT *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return YYENOMEM;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (YYINT *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return YYENOMEM;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return YYENOMEM;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yym = 0;
    yyn = 0;
    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        yychar = YYLEX;
        if (yychar < 0) yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if (((yyn = yysindex[yystate]) != 0) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if (((yyn = yyrindex[yystate]) != 0) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag != 0) goto yyinrecovery;

    YYERROR_CALL("syntax error");

    goto yyerrlab; /* redundant goto avoids 'unused label' warning */
yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if (((yyn = yysindex[*yystack.s_mark]) != 0) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == YYEOF) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym > 0)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);

    switch (yyn)
    {
case 4:
#line 25 "ngen.y"
	{printf("%d - %s\n",atoi(yystack.l_mark[0].str), yystack.l_mark[-1].str);}
break;
case 5:
#line 26 "ngen.y"
	{printf("%s\n", yystack.l_mark[0].str);}
break;
case 24:
#line 52 "ngen.y"
	{yyval.str=yystack.l_mark[0].str;}
break;
case 25:
#line 53 "ngen.y"
	{asprintf(&yyval.str,"%s%s",yystack.l_mark[-2].str,yystack.l_mark[0].str);}
break;
case 26:
#line 54 "ngen.y"
	{}
break;
case 36:
#line 71 "ngen.y"
	{yyval.str = yystack.l_mark[0].str;}
break;
case 37:
#line 72 "ngen.y"
	{asprintf(&yyval.str,"%s", yystack.l_mark[0].str);}
break;
case 40:
#line 79 "ngen.y"
	{yyval.str = yystack.l_mark[-1].num;}
break;
#line 542 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            yychar = YYLEX;
            if (yychar < 0) yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF) goto yyaccept;
        goto yyloop;
    }
    if (((yyn = yygindex[yym]) != 0) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    *++yystack.s_mark = (YYINT) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    YYERROR_CALL("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
