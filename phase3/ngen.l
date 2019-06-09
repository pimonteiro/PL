%option noyywrap
%option noinput nounput
%{
#include "y.tab.h"

%}

%%

(FOTO)          { printf("FOTO\n");return FOTO; }
(HIST)          { printf("HIST\n");return HIST; }
(\*)            { printf("LI\n");return NASCEU; }
(\*C)           { printf("LI\n");return NASCEUAPROX; }
(\+)            { printf("LI\n");return MORREU; }
(\+C)           { printf("LI\n");return MORREUAPROX; }
(CC)            { printf("LI\n");return CASAMENTO; }
(EV)            { printf("LI\n");return EVENTO; }
(F|M|P)         { printf("LI\n");return yytext[0]; }


[\[\]:{}/%-]       { printf("SYMBOL - %s\n", yytext);return yytext[0]; }
[0-9]+          { printf("NUM\n");yylval.num = atoi(yytext); return NUM; }
[a-zA-Z]+(\.[a-zA-Z]+)?       { printf("STRING\n");yylval.str = yytext; return STRING; }
(.|\n)             {}
%%
