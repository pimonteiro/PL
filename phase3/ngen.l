%option noyywrap
%option noinput nounput
%{
#include "y.tab.h"

%}

%%

(FOTO)                              { return FOTO; }
(HIST)                              { return HIST; }
(\*)                                { return NASCEU; }
(\*C)                               { return NASCEUAPROX; }
(\+)                                { return MORREU; }
(\+C)                               { return MORREUAPROX; }
(CC)                                { return CASAMENTO; }
(EV)                                { return EVENTO; }
(F|M|P)                             { return yytext[0]; }
[a-zA-Z]+(\.[a-zA-Z]+)?             {yylval.str=strdup(yytext);return STRING;}
[\[\]:{}/%\n-]                      { return yytext[0]; }
[0-9]+                              { yylval.num = atoi(yytext); return NUM; }
%%
