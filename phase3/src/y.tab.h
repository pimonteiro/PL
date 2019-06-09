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
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
    int num;
    char* str;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
extern YYSTYPE yylval;
