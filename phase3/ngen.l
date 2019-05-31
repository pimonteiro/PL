%option noyywrap
%{
#include "y.tab.h"
%}

%%

"FOTO"          { return FOTO; }
"HIST"          { return HIST; }
[FMP%/]         { return yytext[0]; }
[0-9]+          { return NUM; }
[a-zA-Z]+       { return STRING; }


%%
