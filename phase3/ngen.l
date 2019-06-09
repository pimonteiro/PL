%option noyywrap
%option noinput nounput
%{
#include "y.tab.h"

%}

%%

(FOTO)          { return FOTO; }
(HIST)          { return HIST; }
(\*)            { return NASCEU; }
(\*C)           { return NASCEUAPROX; }
(\+)            { return MORREU; }
(\+C)           { return MORREUAPROX; }
(CC)            { return CASAMENTO; }
(EV)            { return EVENTO; }
(F|M|P)         { return yytext[0]; }
[A-Z][-A-Za-z ]* { yylval.str=strdup(yytext);return NOME;}

[\[\]:{}/%-]                  { return yytext[0]; }
[0-9]+                        { yylval.num = atoi(yytext); return NUM; }
[a-zA-Z]+(\.[a-zA-Z]+)?       { yylval.str = strdip(yytext); return STRING; }
(.|\n)                        {}
%%
