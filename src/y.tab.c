/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "ngen.y" /* yacc.c:339  */

#define _GNU_SOURCE
#include <stdio.h>
#include <glib.h>
#include "include/pessoa.h"
#include "include/evento.h"
#include "include/util.h"

GHashTable* table;

int user;

int id = 0; //ID geral
char* foto;
char* histo;
int flagExtra = 0; //0 -> historia | 1 -> foto


#line 85 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
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
#line 19 "ngen.y" /* yacc.c:355  */

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

#line 130 "y.tab.c" /* yacc.c:355  */

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
#line 34 "ngen.y" /* yacc.c:355  */

    int num;
    char* str;
    Pessoa p;
    Evento ev;
    GList* list;
    struct parenting rela;

#line 175 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 192 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  7
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   92

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  25
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  17
/* YYNRULES -- Number of rules.  */
#define YYNRULES  48
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  76

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   267

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      13,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    21,     2,     2,
       2,     2,     2,     2,     2,    15,     2,    20,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    22,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      17,     2,     2,     2,     2,     2,     2,    16,     2,     2,
      14,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    23,     2,    24,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    18,     2,    19,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    55,    55,    56,    59,    60,    63,    64,    67,   117,
     129,   130,   138,   147,   155,   163,   173,   181,   189,   196,
     203,   211,   219,   226,   233,   237,   261,   280,   301,   307,
     314,   315,   319,   320,   321,   324,   325,   327,   328,   329,
     330,   331,   334,   353,   358,   359,   362,   363,   366
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "FOTO", "HIST", "NASCEU", "NASCEUAPROX",
  "MORREU", "MORREUAPROX", "CASAMENTO", "EVENTO", "NUM", "STRING", "'\\n'",
  "'P'", "'-'", "'M'", "'F'", "'{'", "'}'", "'/'", "'%'", "':'", "'['",
  "']'", "$accept", "Ngen", "Facto", "Acoes", "Acao", "Pessoa",
  "Parentesco", "Filho", "Info", "Eventos", "Nomes", "Texto", "Evento",
  "Casamento", "Identificacao", "Dados_Extra", "ID", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,    10,    80,    45,    77,    70,   123,   125,
      47,    37,    58,    91,    93
};
# endif

#define YYPACT_NINF -31

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-31)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      -7,   -31,    18,   -31,     8,     3,    33,   -31,   -31,    34,
      14,    25,    35,    41,    61,    64,     3,   -31,   -31,   -31,
      17,    65,    66,    67,    71,    43,    54,    43,    12,    34,
      68,   -31,   -31,   -31,   -31,   -31,   -31,   -31,   -31,   -31,
      55,    56,   -31,   -31,   -31,   -31,   -31,   -31,    12,   -31,
     -31,    60,    57,   -31,    43,    43,   -31,   -31,    57,    72,
     -31,    -7,   -31,   -31,   -31,    57,   -31,   -31,   -31,   -31,
       9,   -31,    74,    70,    73,   -31
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    35,     0,     2,     0,    15,    32,     1,     3,     4,
       0,     0,     0,     0,     0,     0,    13,    30,    14,    36,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     5,
       0,     8,    24,    11,    10,     9,    37,    38,    39,    40,
       0,     0,    31,    12,    33,    34,    46,    47,     0,    18,
      16,    45,    29,    43,     0,     0,    22,    20,    27,     0,
       6,     0,    48,    42,    44,    28,    19,    17,    23,    21,
      26,     7,    41,     0,     0,    25
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -31,   -31,    82,   -31,    58,   -31,   -23,   -31,   -21,   -30,
      69,    27,    -9,   -31,   -25,    16,    -4
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,    29,    30,     4,    31,    32,    50,    16,
      51,     6,    17,    34,    52,    35,    53
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      33,    18,    49,    58,    56,     1,    57,    42,    10,    11,
      12,    13,    43,    14,    10,    11,    12,    13,     7,    14,
      33,     9,    65,    63,     1,    36,    15,    73,    70,    44,
       1,    66,    68,    67,    69,    15,    37,    22,    23,    10,
      11,    12,    13,    24,    14,    19,    38,    64,    25,    26,
      27,    28,    39,    20,    21,     1,    42,    25,    26,    27,
      28,    42,    10,    11,    12,    13,    15,    14,    54,     5,
      55,     5,    40,    22,    23,    41,    45,    61,    46,    47,
      62,    60,    48,    15,     8,    71,    19,    59,    72,    74,
       0,     0,    75
};

static const yytype_int8 yycheck[] =
{
       9,     5,    25,    28,    27,    12,    27,    16,     5,     6,
       7,     8,    16,    10,     5,     6,     7,     8,     0,    10,
      29,    13,    52,    48,    12,    11,    23,    18,    58,    12,
      12,    54,    55,    54,    55,    23,    11,     3,     4,     5,
       6,     7,     8,     9,    10,    12,    11,    51,    14,    15,
      16,    17,    11,    20,    21,    12,    65,    14,    15,    16,
      17,    70,     5,     6,     7,     8,    23,    10,    14,     0,
      16,     2,    11,     3,     4,    11,    11,    22,    12,    12,
      24,    13,    11,    23,     2,    13,    12,    29,    61,    73,
      -1,    -1,    19
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    12,    26,    27,    30,    35,    36,     0,    27,    13,
       5,     6,     7,     8,    10,    23,    34,    37,    41,    12,
      20,    21,     3,     4,     9,    14,    15,    16,    17,    28,
      29,    31,    32,    37,    38,    40,    11,    11,    11,    11,
      11,    11,    37,    41,    12,    11,    12,    12,    11,    31,
      33,    35,    39,    41,    14,    16,    31,    33,    39,    29,
      13,    22,    24,    39,    41,    34,    31,    33,    31,    33,
      34,    13,    36,    18,    40,    19
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    25,    26,    26,    27,    27,    28,    28,    29,    29,
      29,    29,    30,    30,    30,    30,    31,    31,    31,    31,
      31,    31,    31,    31,    31,    32,    32,    32,    33,    33,
      34,    34,    35,    35,    35,    36,    36,    37,    37,    37,
      37,    37,    38,    39,    39,    39,    40,    40,    41
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     2,     3,     2,     3,     1,     1,
       1,     1,     3,     2,     2,     1,     2,     3,     2,     3,
       2,     3,     2,     3,     1,     6,     3,     2,     2,     1,
       1,     2,     1,     3,     3,     1,     2,     2,     2,     2,
       2,     4,     3,     1,     2,     1,     2,     2,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 8:
#line 67 "ngen.y" /* yacc.c:1646  */
    {
                                struct parenting pop = (yyvsp[0].rela);
                                if(pop.pessoa != NULL){
                                    gint* k = g_new(gint,1); *k = user;
                                    Pessoa a = g_hash_table_lookup(table,k);
                                    int path = pop.path[pop.i - 1];
                                    for(int i = pop.i - 2; i >= 0; i--){
                                        if(pop.path[i] == 0){
                                            if(path) *k = a->idMae;
                                            else *k = a->idPai;
                                            a = g_hash_table_lookup(table,k);
                                            path = 0;
                                        }
                                        else{
                                            if(path) *k = a->idMae;
                                            else *k = a->idPai;
                                            a = g_hash_table_lookup(table,k);
                                            path = 1;
                                        }
                                    }
                                    Pessoa p = pop.pessoa;
                                    gint* k2 = g_new(gint,1);
                                    if(path == 0){
                                        if(pop.inv == 0){
                                            a->idPai = p->id;
                                            p->filhos = g_list_append(p->filhos, GINT_TO_POINTER(a->id));
                                            *k2 = p->id;
                                            g_hash_table_insert(table, (gpointer)k2, (gpointer)p);
                                        } else {
                                            p->idPai = a->id;
                                            a->filhos = g_list_append(a->filhos, GINT_TO_POINTER(p->id));
                                            *k2 = p->id;
                                            g_hash_table_insert(table, (gpointer)k2, (gpointer)p);
                                        }
                                    }
                                    else{
                                        if(pop.inv == 0){
                                            a->idMae = p->id;
                                            p->filhos = g_list_append(p->filhos, GINT_TO_POINTER(a->id));
                                            *k2 = p->id;
                                            g_hash_table_insert(table, (gpointer)k2, (gpointer)p);
                                        } else {
                                            p->idMae = a->id;
                                            a->filhos = g_list_append(a->filhos, GINT_TO_POINTER(p->id));
                                            *k2 = p->id;
                                            g_hash_table_insert(table, (gpointer)k2, (gpointer)p);
                                        }
                                    }
                                }
                                }
#line 1366 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 117 "ngen.y" /* yacc.c:1646  */
    {gint* k = g_new(gint,1); *k = user;
                                 Pessoa a = g_hash_table_lookup(table, k);
                                 if(a == NULL){
                                     printf("Error Dados_Extra\n");
                                 }
                                 else{
                                     if(flagExtra == 0)
                                        a->historia = (yyvsp[0].str);
                                    else
                                        a->foto = (yyvsp[0].str);
                                 }
                                 }
#line 1383 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 129 "ngen.y" /* yacc.c:1646  */
    {}
#line 1389 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 130 "ngen.y" /* yacc.c:1646  */
    {Evento e = (yyvsp[0].ev);
                                 gint* k = g_new(gint,1); *k = user;
                                 Pessoa a = g_hash_table_lookup(table, k);
                                 GList* evs = NULL; evs = g_list_append(evs, (gpointer)e);
                                 add_eventos(a,evs);
                                }
#line 1400 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 138 "ngen.y" /* yacc.c:1646  */
    {Pessoa p = (yyvsp[-2].p);
                                 add_eventos(p,(yyvsp[-1].list));
                                 p->id = (yyvsp[0].num);
                                 gint* k = g_new(gint,1);
                                 *k = p->id;
                                 g_hash_table_insert(table, k, (gpointer)p);
                                 user = p->id;
                                 id = user + 1;
                                }
#line 1414 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 147 "ngen.y" /* yacc.c:1646  */
    {Pessoa p = (yyvsp[-1].p);
                                  add_eventos(p,(yyvsp[0].list));
                                  id++;
                                  gint* k = g_new(gint,1);
                                  *k = p->id;
                                  g_hash_table_insert(table, k, (gpointer)p);
                                  user = p->id;
                                }
#line 1427 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 155 "ngen.y" /* yacc.c:1646  */
    {Pessoa p = (yyvsp[-1].p);
                                 p->id = (yyvsp[0].num);
                                 gint* k = g_new(gint,1);
                                 *k = p->id;
                                 g_hash_table_insert(table, k, (gpointer)p);
                                 user = p->id;
                                 id = user + 1;
                                }
#line 1440 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 163 "ngen.y" /* yacc.c:1646  */
    {Pessoa p = (yyvsp[0].p);
                                 id++;
                                 gint* k = g_new(gint,1);
                                 *k = p->id;
                                 g_hash_table_insert(table, k, (gpointer)p);
                                 user = p->id;
                                }
#line 1452 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 173 "ngen.y" /* yacc.c:1646  */
    {
                                    struct parenting pop;
                                    pop.pessoa = (yyvsp[0].p);
                                    pop.path[0] = 0;
                                    pop.i = 1;
                                    pop.inv = 0;
                                    (yyval.rela) = pop;
                                    }
#line 1465 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 181 "ngen.y" /* yacc.c:1646  */
    {
                                    struct parenting pop;
                                    pop.pessoa = (yyvsp[0].p);
                                    pop.path[0] = 0;
                                    pop.i = 1;
                                    pop.inv = 1;
                                    (yyval.rela) = pop;
                                    }
#line 1478 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 189 "ngen.y" /* yacc.c:1646  */
    {
                                    struct parenting pop = (yyvsp[0].rela);
                                    pop.path[pop.i] = 0;
                                    pop.i++;
                                    pop.inv = 0;
                                    (yyval.rela) = pop;
                                    }
#line 1490 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 196 "ngen.y" /* yacc.c:1646  */
    {
                                    struct parenting pop = (yyvsp[0].rela);
                                    pop.path[pop.i] = 0;
                                    pop.i++;
                                    pop.inv = 1;
                                    (yyval.rela) = pop;
                                    }
#line 1502 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 203 "ngen.y" /* yacc.c:1646  */
    {
                                    struct parenting pop;
                                    pop.pessoa = (yyvsp[0].p);
                                    pop.path[0] = 1;
                                    pop.i = 1;
                                    pop.inv = 0;
                                    (yyval.rela) = pop;
                                    }
#line 1515 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 211 "ngen.y" /* yacc.c:1646  */
    {
                                    struct parenting pop;
                                    pop.pessoa = (yyvsp[0].p);
                                    pop.path[0] = 1;
                                    pop.i = 1;
                                    pop.inv = 1;
                                    (yyval.rela) = pop;
                                    }
#line 1528 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 219 "ngen.y" /* yacc.c:1646  */
    {
                                    struct parenting pop = (yyvsp[0].rela);
                                    pop.path[pop.i] = 1;
                                    pop.i++;
                                    pop.inv = 0;
                                    (yyval.rela) = pop;
                                    }
#line 1540 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 226 "ngen.y" /* yacc.c:1646  */
    {
                                    struct parenting pop = (yyvsp[0].rela);
                                    pop.path[pop.i] = 1;
                                    pop.i++;
                                    pop.inv = 1;
                                    (yyval.rela) = pop;
                                    }
#line 1552 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 233 "ngen.y" /* yacc.c:1646  */
    {struct parenting pop;pop.pessoa = NULL; (yyval.rela) = pop;}
#line 1558 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 237 "ngen.y" /* yacc.c:1646  */
    {Pessoa f = (yyvsp[-4].p);
                                                         add_eventos(f,(yyvsp[-3].list));

                                                         if(f->id == id) id++;
                                                         else id = f->id + 1;

                                                         if(flagExtra == 0)
                                                            f->historia = (yyvsp[-1].str);
                                                         else
                                                            f->foto = (yyvsp[-1].str);
                                                         gint* k = g_new(gint,1); *k = user;
                                                         Pessoa a = g_hash_table_lookup(table, k);
                                                         f->idPai = a->id;

                                                         a->filhos = g_list_append(a->filhos,GINT_TO_POINTER(f->id));
                                                         gint* k2 = g_new(gint,1); *k2 = f->id;
                                                         g_hash_table_insert(table,k2,(gpointer)f);
                                                         if(a->idCasado != -1){
                                                             *k = a->idCasado;
                                                             f->idMae = a->idCasado;
                                                             Pessoa p = g_hash_table_lookup(table, k);
                                                             p->filhos = g_list_append(p->filhos, GINT_TO_POINTER(f->id));
                                                         }
                                                         }
#line 1587 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 261 "ngen.y" /* yacc.c:1646  */
    {Pessoa f = (yyvsp[-1].p);
                                    add_eventos(f,(yyvsp[0].list));
                                    if(f->id == id) id++;
                                    else id = f->id + 1;

                                    gint* k = g_new(gint,1); *k = user;
                                    Pessoa a = g_hash_table_lookup(table, k);
                                    f->idPai = a->id;

                                    a->filhos = g_list_append(a->filhos,GINT_TO_POINTER(f->id));
                                    gint* k2 = g_new(gint,1); *k2 = f->id;
                                    g_hash_table_insert(table,k2,(gpointer)f);
                                    if(a->idCasado != -1){
                                        *k = a->idCasado;
                                        f->idMae = a->idCasado;
                                        Pessoa p = g_hash_table_lookup(table, k);
                                        p->filhos = g_list_append(p->filhos, GINT_TO_POINTER(f->id));
                                    }
                                    }
#line 1611 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 280 "ngen.y" /* yacc.c:1646  */
    {Pessoa f = (yyvsp[0].p);

                                    if(f->id == id) id++;
                                    else id = f->id + 1;

                                    gint* k = g_new(gint,1); *k = user;
                                    Pessoa a = g_hash_table_lookup(table, k);
                                    f->idPai = a->id;

                                    a->filhos = g_list_append(a->filhos,GINT_TO_POINTER(f->id));
                                    gint* k2 = g_new(gint,1); *k2 = f->id;
                                    g_hash_table_insert(table,k2,(gpointer)f);
                                    if(a->idCasado != -1){
                                        *k = a->idCasado;
                                        f->idMae = a->idCasado;
                                        Pessoa p = g_hash_table_lookup(table, k);
                                        p->filhos = g_list_append(p->filhos, GINT_TO_POINTER(f->id));
                                    }
                                    }
#line 1635 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 301 "ngen.y" /* yacc.c:1646  */
    {Pessoa p = (yyvsp[-1].p);
                                    if(p->id == id) id++;
                                    else id = p->id + 1;
                                    add_eventos(p,(yyvsp[0].list));
                                    (yyval.p) = p;
                                    }
#line 1646 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 307 "ngen.y" /* yacc.c:1646  */
    {Pessoa p = (yyvsp[0].p);
                                    if(p->id == id) id++;
                                    else id = p->id + 1;
                                    (yyval.p) = p;
                                    }
#line 1656 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 314 "ngen.y" /* yacc.c:1646  */
    {GList* evs = NULL; evs = g_list_append(evs,(gpointer)(yyvsp[0].ev)); (yyval.list) = evs;}
#line 1662 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 315 "ngen.y" /* yacc.c:1646  */
    {GList* evs = NULL; evs = g_list_append(evs,(gpointer)(yyvsp[0].ev)); evs = g_list_concat((yyvsp[-1].list),evs); (yyval.list) = evs;}
#line 1668 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 319 "ngen.y" /* yacc.c:1646  */
    {Pessoa a = create(id); a->nome = (yyvsp[0].str); (yyval.p) = a;}
#line 1674 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 320 "ngen.y" /* yacc.c:1646  */
    {Pessoa a = create(id); a->nome = (yyvsp[-2].str); a->apelido = (yyvsp[0].str); (yyval.p) = a;}
#line 1680 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 321 "ngen.y" /* yacc.c:1646  */
    {Pessoa a = create(id); a->nome = (yyvsp[-2].str); a->repetido = (yyvsp[0].num); (yyval.p) = a;}
#line 1686 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 324 "ngen.y" /* yacc.c:1646  */
    {(yyval.str) = (yyvsp[0].str);}
#line 1692 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 325 "ngen.y" /* yacc.c:1646  */
    {asprintf(&(yyval.str),"%s %s",(yyvsp[-1].str),(yyvsp[0].str));}
#line 1698 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 327 "ngen.y" /* yacc.c:1646  */
    {(yyval.ev) = create_evento((yyvsp[0].num),N);}
#line 1704 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 328 "ngen.y" /* yacc.c:1646  */
    {(yyval.ev) = create_evento((yyvsp[0].num),NA);}
#line 1710 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 329 "ngen.y" /* yacc.c:1646  */
    {(yyval.ev) = create_evento((yyvsp[0].num),M);}
#line 1716 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 330 "ngen.y" /* yacc.c:1646  */
    {(yyval.ev) = create_evento((yyvsp[0].num),MA);}
#line 1722 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 331 "ngen.y" /* yacc.c:1646  */
    {(yyval.ev) = create_evento((yyvsp[-2].num),(yyvsp[0].str));}
#line 1728 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 334 "ngen.y" /* yacc.c:1646  */
    {   gint* k = g_new(gint,1); *k = user;
                                            Pessoa a = g_hash_table_lookup(table, k);
                                            if(a == NULL){
                                                printf("Error casamento!\n");
                                            }
                                            else{
                                                a->dataCasado = (yyvsp[-1].num);
                                                Pessoa p = (yyvsp[0].p);
                                                if(p->id == id) id++;
                                                else id = p->id + 1;
                                                a->idCasado = p->id;
                                                p->idCasado = a->id;
                                                p->dataCasado = (yyvsp[-1].num);
                                                gint* k2 = g_new(gint,1); *k2 = p->id;
                                                g_hash_table_insert(table,k2,(gpointer)p);
                                            }
                                        }
#line 1750 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 353 "ngen.y" /* yacc.c:1646  */
    { gint* k = g_new(gint,1); *k = (yyvsp[0].num);
                                    Pessoa p = g_hash_table_lookup(table,k);
                                    if(p == NULL) (yyval.p) = create((yyvsp[0].num));
                                    else (yyval.p) = p;
                                  }
#line 1760 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 358 "ngen.y" /* yacc.c:1646  */
    { Pessoa p = (yyvsp[-1].p); p->id = (yyvsp[0].num); (yyval.p) = p;}
#line 1766 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 359 "ngen.y" /* yacc.c:1646  */
    { (yyval.p) = (yyvsp[0].p); }
#line 1772 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 362 "ngen.y" /* yacc.c:1646  */
    {flagExtra = 1; (yyval.str) = (yyvsp[0].str);}
#line 1778 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 363 "ngen.y" /* yacc.c:1646  */
    {flagExtra = 0; (yyval.str) = (yyvsp[0].str);}
#line 1784 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 366 "ngen.y" /* yacc.c:1646  */
    {(yyval.num) = (yyvsp[-1].num);}
#line 1790 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1794 "y.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 368 "ngen.y" /* yacc.c:1906  */


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

guint compare(Pessoa a, Pessoa b){
    if(a->id > b->id) return 1;
    if(a->id < b->id) return -1;
    return 0;
}

int main(){
    table = g_hash_table_new (g_int_hash, g_int_equal);

    yyparse();

    gint* k1 = g_new(gint,1); *k1 = 3;
    Pessoa p1 = g_hash_table_lookup(table,k1);
    *k1 = 0;
    Pessoa p2 = g_hash_table_lookup(table,k1);
    *k1 = 1;
    Pessoa p3 = g_hash_table_lookup(table,k1);
    *k1 = 2;
    Pessoa p4 = g_hash_table_lookup(table,k1);
    *k1 = 4;
    Pessoa p5 = g_hash_table_lookup(table,k1);
    *k1 = 5;
    Pessoa p6 = g_hash_table_lookup(table,k1);
    *k1 = 6;
    Pessoa p7 = g_hash_table_lookup(table,k1);
    *k1 = 7;
    Pessoa p8 = g_hash_table_lookup(table,k1);
    *k1 = 8;
    Pessoa p9 = g_hash_table_lookup(table,k1);
    *k1 = 9;
    Pessoa p10 = g_hash_table_lookup(table,k1);
    *k1 = 10;
    Pessoa p11 = g_hash_table_lookup(table,k1);



    GList* list = NULL;
    GList* lst = g_hash_table_get_values(table);
    FILE* fp = fopen("ngen.txt", "w+");
    FILE* fp1 = fopen("ngen.pl", "w+");
    gint* k = g_new(gint,1); *k = 3;
    GList* lista = g_list_sort(lst, (GCompareFunc)compare);
    for(GList* l= lista; l; l = l->next){
        Pessoa p = (Pessoa)l->data;
        if(!imprimido(list, p->id)){
            list = imprime_pessoa(p, fp, table, list);
            imprime_prolog(p,fp1, table, list);
        }
    }
    fclose(fp);
    fclose(fp1);
    return 0;
}
