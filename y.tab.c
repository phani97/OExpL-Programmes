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
#line 1 "abstree.y" /* yacc.c:339  */

	#include<stdio.h>
	#include <stdlib.h>
    #include <string.h>
    #include "abstree.h"
    #include "symboltable.h"
    #include "symboltable.c"
    #include "abstree.c"
    #include "codegen.c"
    int yylex();
    void yyerror(char const *s);
    struct Tnode *root,*head;
    int result,is_classdef;
    FILE * fp;
    extern FILE *yyin;
    struct Typetable* declarationtype,*Ttemp ;
    struct Gsymbol *Gtemp;
    struct Argstruct *Atemp1,*Atemp2;	
    struct Lsymbol *Ltemp;
	struct Argstruct *Atemp;
	struct Fieldlist *Ftemp;
	struct Memberfunclist *Mtemp;
	struct Tnode* Temp;
	struct Classtable *Ctemp,*declarationctype;

#line 92 "y.tab.c" /* yacc.c:339  */

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

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    TYPE = 258,
    ENDTYPE = 259,
    ID = 260,
    NUM = 261,
    DECL = 262,
    ENDDECL = 263,
    START = 264,
    END = 265,
    RETURN = 266,
    ASGN = 267,
    ALLOC = 268,
    FREE = 269,
    READ = 270,
    WRITE = 271,
    IF = 272,
    THEN = 273,
    ELSE = 274,
    ENDIF = 275,
    WHILE = 276,
    DO = 277,
    ENDWHILE = 278,
    INITIALISE = 279,
    PLUS = 280,
    SUB = 281,
    MUL = 282,
    DIV = 283,
    MOD = 284,
    NE = 285,
    EQ = 286,
    GT = 287,
    GE = 288,
    LT = 289,
    LE = 290,
    T = 291,
    F = 292,
    MAIN = 293,
    EQNUL = 294,
    NENUL = 295,
    NUL = 296,
    SELF = 297,
    CLASS = 298,
    ENDCLASS = 299,
    NEW = 300,
    DELETE = 301,
    STRVAL = 302,
    EXTENDS = 303
  };
#endif
/* Tokens.  */
#define TYPE 258
#define ENDTYPE 259
#define ID 260
#define NUM 261
#define DECL 262
#define ENDDECL 263
#define START 264
#define END 265
#define RETURN 266
#define ASGN 267
#define ALLOC 268
#define FREE 269
#define READ 270
#define WRITE 271
#define IF 272
#define THEN 273
#define ELSE 274
#define ENDIF 275
#define WHILE 276
#define DO 277
#define ENDWHILE 278
#define INITIALISE 279
#define PLUS 280
#define SUB 281
#define MUL 282
#define DIV 283
#define MOD 284
#define NE 285
#define EQ 286
#define GT 287
#define GE 288
#define LT 289
#define LE 290
#define T 291
#define F 292
#define MAIN 293
#define EQNUL 294
#define NENUL 295
#define NUL 296
#define SELF 297
#define CLASS 298
#define ENDCLASS 299
#define NEW 300
#define DELETE 301
#define STRVAL 302
#define EXTENDS 303

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 27 "abstree.y" /* yacc.c:355  */

	struct Tnode* nptr;
	struct Typetable *type;
	struct Argstruct *arg;

#line 234 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 251 "y.tab.c" /* yacc.c:358  */

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
#define YYLAST   441

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  58
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  40
/* YYNRULES -- Number of rules.  */
#define YYNRULES  115
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  287

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   303

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      52,    53,     2,     2,    54,     2,    57,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    51,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    55,     2,    56,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    49,     2,    50,     2,     2,     2,     2,
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
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    43,    43,    46,    47,    49,    50,    53,    64,    65,
      67,    81,    85,    90,    91,    93,    98,   110,   127,   128,
     130,   139,   140,   142,   149,   150,   154,   155,   157,   158,
     160,   162,   171,   179,   191,   202,   211,   222,   235,   244,
     245,   247,   259,   260,   264,   353,   363,   364,   366,   386,
     387,   389,   390,   392,   394,   403,   411,   420,   448,   459,
     461,   468,   503,   527,   541,   566,   580,   587,   605,   639,
     650,   679,   686,   715,   747,   801,   830,   855,   862,   869,
     876,   883,   892,   928,   939,   952,   979,  1004,  1044,  1053,
    1084,  1115,  1123,  1131,  1140,  1149,  1158,  1167,  1176,  1185,
    1194,  1203,  1212,  1221,  1222,  1226,  1252,  1276,  1277,  1310,
    1311,  1312,  1313,  1315,  1324,  1325
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TYPE", "ENDTYPE", "ID", "NUM", "DECL",
  "ENDDECL", "START", "END", "RETURN", "ASGN", "ALLOC", "FREE", "READ",
  "WRITE", "IF", "THEN", "ELSE", "ENDIF", "WHILE", "DO", "ENDWHILE",
  "INITIALISE", "PLUS", "SUB", "MUL", "DIV", "MOD", "NE", "EQ", "GT", "GE",
  "LT", "LE", "T", "F", "MAIN", "EQNUL", "NENUL", "NUL", "SELF", "CLASS",
  "ENDCLASS", "NEW", "DELETE", "STRVAL", "EXTENDS", "'{'", "'}'", "';'",
  "'('", "')'", "','", "'['", "']'", "'.'", "$accept", "Program",
  "Typedefblock", "Typedeflist", "Typedef", "Fieldlist", "Flds",
  "Classdefblock", "Classdeflist", "Classdef", "Cname", "Fieldlists",
  "Fld", "MethodDecl", "MDecl", "MethodDefns", "Gdeclblock", "Gdecllist",
  "Gdecl", "Type", "Varlist", "Paramlist", "Param", "Fdefblock", "Fdef",
  "Arglists", "Arg", "Ldeclblock", "Ldecllist", "Ldecl", "Type_func",
  "Idlist", "Mainblock", "Slist", "Restmt", "Stmt", "Field",
  "FieldFunction", "Expr", "Argalist", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   123,
     125,    59,    40,    41,    44,    91,    93,    46
};
# endif

#define YYPACT_NINF -109

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-109)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-1)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      23,    33,     5,    16,    34,    73,  -109,  -109,   103,    91,
     112,  -109,  -109,    83,    -1,  -109,    78,   114,  -109,   145,
      -2,  -109,   150,  -109,  -109,   166,  -109,   141,  -109,   196,
     202,   193,  -109,  -109,  -109,  -109,  -109,  -109,    99,   105,
      20,  -109,  -109,  -109,   240,   241,   165,  -109,   242,   197,
     198,   243,  -109,   161,  -109,   247,    39,  -109,   199,   120,
     248,   201,    93,   251,   252,  -109,  -109,  -109,   241,  -109,
     241,   276,   253,   108,  -109,   234,  -109,   241,   232,   280,
       2,  -109,  -109,   156,   230,  -109,   238,   248,   282,   158,
    -109,  -109,  -109,  -109,   282,  -109,  -109,   281,   244,   283,
     194,  -109,  -109,  -109,  -109,  -109,  -109,   288,   118,   118,
    -109,   149,    25,     4,   239,   245,   270,   271,   237,   272,
     315,  -109,     0,   316,  -109,   291,     8,     4,   293,   113,
    -109,  -109,  -109,   273,  -109,     4,   -10,  -109,   286,    37,
       4,     4,     4,   322,    98,   279,    68,   326,   284,  -109,
     308,   309,   310,   285,   311,   313,   152,  -109,  -109,  -109,
       4,     4,   327,   328,   206,  -109,  -109,   330,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,  -109,
      44,   -30,   235,   246,   275,  -109,    19,    54,  -109,   314,
     317,   318,   324,  -109,  -109,   312,   101,   319,  -109,   364,
    -109,   355,   362,   160,   163,   321,   346,  -109,   347,   -12,
     -12,  -109,  -109,  -109,   378,   378,   378,   378,   378,   378,
     320,     4,   323,   349,   383,   392,   365,   366,   367,  -109,
     410,  -109,   368,    65,    71,   370,   369,     4,  -109,     4,
    -109,     4,     4,     4,  -109,   195,  -109,  -109,  -109,  -109,
    -109,  -109,   372,   371,  -109,   374,   375,  -109,   376,   351,
     362,   162,   164,   189,   377,    70,    79,  -109,   380,  -109,
    -109,  -109,  -109,  -109,  -109,  -109,   381,  -109,   382,   384,
    -109,  -109,   121,  -109,  -109,   385,  -109
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     0,    12,     0,     0,     6,     1,     0,    27,
       0,     3,     5,    16,     0,    14,     0,     0,    43,     0,
       0,     9,     0,    11,    13,     0,    31,     0,    29,     0,
       0,     0,     7,     8,    17,    19,    26,    28,    35,     0,
       0,    42,     2,    10,     0,    40,     0,    30,     0,     0,
       0,     0,    18,     0,    22,     0,     0,    39,     0,    32,
      47,     0,     0,     0,     0,    21,    41,    37,     0,    36,
      40,     0,     0,     0,    46,     0,    20,    40,     0,     0,
       0,    25,    38,     0,     0,    48,     0,     0,    50,     0,
      15,    24,    34,    33,    50,    45,    52,     0,     0,     0,
       0,    59,    23,    59,    54,    49,    51,     0,     0,     0,
      56,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    58,     0,     0,    53,     0,     0,     0,     0,   105,
     104,   109,   110,     0,   112,     0,   107,   111,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    55,
       0,     0,     0,     0,     0,     0,     0,    82,    89,    90,
     115,     0,     0,     0,     0,    91,    92,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    60,
       0,     0,     0,     0,     0,    84,     0,     0,    57,     0,
       0,     0,     0,    83,    44,     0,     0,     0,    68,     0,
      61,     0,   114,     0,     0,    82,    84,   103,    83,    88,
      93,    94,    95,    96,    97,    98,   101,   102,    99,   100,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    69,
       0,    63,     0,     0,     0,     0,     0,     0,   108,     0,
     106,   115,   115,   115,    75,     0,    77,    78,    59,    59,
      67,    66,     0,     0,    72,     0,     0,    70,     0,     0,
     113,     0,     0,     0,     0,     0,     0,    71,     0,    74,
      73,    64,    62,    87,    86,    85,     0,    59,     0,     0,
      65,    76,     0,    79,    81,     0,    80
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -109,  -109,  -109,  -109,   413,  -109,   408,  -109,  -109,   415,
    -109,  -109,  -109,  -109,   386,  -109,  -109,  -109,   407,  -109,
    -109,   -59,   373,  -109,   -56,  -109,   350,   344,  -109,  -109,
    -109,  -109,  -109,  -101,   331,  -109,  -108,  -109,  -107,   -37
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     5,     6,    20,    21,     9,    14,    15,
      16,    44,    52,    53,    54,    80,    18,    27,    28,    29,
      39,    56,    57,    30,    41,    73,    74,    97,   100,   106,
     107,   111,    42,   108,   120,   121,   136,   137,   202,   203
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     122,   122,   109,    19,    13,     7,   138,    79,    81,   129,
     130,    83,   146,   129,   130,   170,   171,   172,    89,   155,
     156,   150,   151,   222,    91,    49,     1,   147,   164,   165,
     166,   181,   152,   182,   183,   184,   187,   126,     4,   192,
     131,   132,   180,    23,   131,   132,   133,   167,    32,   153,
     133,   134,    90,   154,   204,   134,   135,   147,    50,     8,
     135,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   226,   129,   130,   112,   128,    11,     4,   118,
     127,   189,   128,    10,   112,   114,   115,   116,   234,   277,
     278,   117,    67,    68,   114,   115,   116,   220,    17,   221,
     117,   128,   279,   186,   131,   132,   233,   227,    13,   190,
     133,   147,   118,   191,   245,   134,   119,    19,   255,    26,
     135,   118,   128,   112,   256,   119,   112,    25,   147,   113,
     259,    22,   260,   114,   115,   116,   114,   115,   116,   117,
     118,   285,   117,   118,    76,    77,    26,   265,   266,    36,
      31,    45,   158,   159,    46,    34,    47,   122,   122,    48,
     118,    86,    87,   118,   119,   160,    63,   119,   161,    64,
     162,    58,    70,    35,   122,    71,   282,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   104,
     124,    38,   105,   125,   261,   262,   263,    40,   201,    92,
      68,    98,    68,   238,   239,   273,   239,   274,   239,   240,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   275,   239,    43,    51,    55,    59,    62,    60,
      61,   264,    66,    72,    75,    69,    78,    79,    85,   207,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,    84,    88,    77,    49,    93,    94,   223,    96,
     101,   139,   103,   110,   143,   102,   149,   140,   157,   224,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   141,   142,   144,   145,   148,   185,   225,   188,
     163,   193,   205,   206,   194,   208,   198,   179,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     195,   196,   197,   199,   200,   232,   228,   237,   229,   236,
     230,   244,   235,   241,   246,   231,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   242,   243,
     247,   248,   272,   168,   169,   170,   171,   172,    -1,    -1,
      -1,    -1,    -1,    -1,   249,   253,   250,   251,    12,   254,
     252,   257,   258,   267,   268,   269,   270,   271,    33,    24,
     276,   280,   281,   283,    37,   284,   286,    95,    99,    65,
     123,    82
};

static const yytype_uint16 yycheck[] =
{
     108,   109,   103,     5,     5,     0,   113,     5,    64,     5,
       6,    70,    12,     5,     6,    27,    28,    29,    77,   126,
     127,    13,    14,    53,    80,     5,     3,    57,   135,    39,
      40,   139,    24,   140,   141,   142,   144,    12,     5,   146,
      36,    37,     5,    44,    36,    37,    42,    57,    50,    41,
      42,    47,    50,    45,   161,    47,    52,    57,    38,    43,
      52,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,    53,     5,     6,     5,    57,     4,     5,    42,
      55,    13,    57,    49,     5,    15,    16,    17,   196,    19,
      20,    21,    53,    54,    15,    16,    17,    53,     7,    55,
      21,    57,    23,     5,    36,    37,     5,    53,     5,    41,
      42,    57,    42,    45,   221,    47,    46,     5,    53,     5,
      52,    42,    57,     5,    53,    46,     5,    49,    57,    11,
     237,    48,   239,    15,    16,    17,    15,    16,    17,    21,
      42,    20,    21,    42,    51,    52,     5,   248,   249,     8,
       5,    52,    39,    40,    55,     5,    51,   265,   266,    54,
      42,    53,    54,    42,    46,    52,     5,    46,    55,     8,
      57,     6,    52,     7,   282,    55,   277,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,     5,
      51,     5,     8,    54,   241,   242,   243,     5,    56,    53,
      54,    53,    54,    53,    54,    53,    54,    53,    54,    56,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    53,    54,    51,     5,     5,     5,     5,    52,
      52,    56,     5,     5,    53,    56,     5,     5,     5,    53,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,     6,    49,    52,     5,    56,    49,    53,     7,
       9,    52,     9,     5,    57,    51,     5,    52,     5,    53,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    52,    52,    52,    10,    10,     5,    53,    50,
      57,     5,     5,     5,    50,     5,    51,    51,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      52,    52,    52,    52,    51,    53,    52,    12,    51,     5,
      52,    51,    53,    52,    51,    51,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    52,    52,
      51,    18,    51,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    22,     5,    51,    51,     5,    51,
      53,    51,    53,    51,    53,    51,    51,    51,    20,    14,
      53,    51,    51,    51,    27,    51,    51,    87,    94,    53,
     109,    68
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    59,    60,     5,    61,    62,     0,    43,    65,
      49,     4,    62,     5,    66,    67,    68,     7,    74,     5,
      63,    64,    48,    44,    67,    49,     5,    75,    76,    77,
      81,     5,    50,    64,     5,     7,     8,    76,     5,    78,
       5,    82,    90,    51,    69,    52,    55,    51,    54,     5,
      38,     5,    70,    71,    72,     5,    79,    80,     6,     5,
      52,    52,     5,     5,     8,    72,     5,    53,    54,    56,
      52,    55,     5,    83,    84,    53,    51,    52,     5,     5,
      73,    82,    80,    79,     6,     5,    53,    54,    49,    79,
      50,    82,    53,    56,    49,    84,     7,    85,    53,    85,
      86,     9,    51,     9,     5,     8,    87,    88,    91,    91,
       5,    89,     5,    11,    15,    16,    17,    21,    42,    46,
      92,    93,    94,    92,    51,    54,    12,    55,    57,     5,
       6,    36,    37,    42,    47,    52,    94,    95,    96,    52,
      52,    52,    52,    57,    52,    10,    12,    57,    10,     5,
      13,    14,    24,    41,    45,    96,    96,     5,    39,    40,
      52,    55,    57,    57,    96,    39,    40,    57,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    51,
       5,    94,    96,    96,    96,     5,     5,    94,    50,    13,
      41,    45,    96,     5,    50,    52,    52,    52,    51,    52,
      51,    56,    96,    97,    96,     5,     5,    53,     5,    96,
      96,    96,    96,    96,    96,    96,    96,    96,    96,    96,
      53,    55,    53,    53,    53,    53,    53,    53,    52,    51,
      52,    51,    53,     5,    94,    53,     5,    12,    53,    54,
      56,    52,    52,    52,    51,    96,    51,    51,    18,    22,
      51,    51,    53,     5,    51,    53,    53,    51,    53,    96,
      96,    97,    97,    97,    56,    91,    91,    51,    53,    51,
      51,    51,    51,    53,    53,    53,    53,    19,    20,    23,
      51,    51,    91,    51,    51,    20,    51
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    58,    59,    60,    60,    61,    61,    62,    63,    63,
      64,    65,    65,    66,    66,    67,    68,    68,    69,    69,
      70,    71,    71,    72,    73,    73,    74,    74,    75,    75,
      76,    77,    78,    78,    78,    78,    78,    78,    79,    79,
      79,    80,    81,    81,    82,    83,    83,    83,    84,    85,
      85,    86,    86,    87,    88,    89,    89,    90,    91,    91,
      92,    93,    93,    93,    93,    93,    93,    93,    93,    93,
      93,    93,    93,    93,    93,    93,    93,    93,    93,    93,
      93,    93,    94,    94,    94,    95,    95,    95,    96,    96,
      96,    96,    96,    96,    96,    96,    96,    96,    96,    96,
      96,    96,    96,    96,    96,    96,    96,    96,    96,    96,
      96,    96,    96,    97,    97,    97
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     3,     0,     2,     1,     4,     2,     1,
       3,     3,     0,     2,     1,     8,     1,     3,     2,     0,
       3,     2,     1,     6,     2,     1,     3,     0,     2,     1,
       3,     1,     3,     6,     6,     1,     4,     4,     3,     1,
       0,     2,     2,     0,    12,     3,     1,     0,     2,     3,
       0,     2,     0,     3,     1,     3,     1,    11,     2,     0,
       3,     4,     7,     4,     7,     7,     5,     5,     4,     4,
       6,     6,     6,     7,     7,     5,     8,     5,     5,     8,
      10,     8,     3,     3,     3,     6,     6,     6,     3,     2,
       2,     2,     2,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     1,     1,     4,     1,     4,     1,
       1,     1,     1,     3,     1,     0
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
        case 2:
#line 43 "abstree.y" /* yacc.c:1646  */
    {exit(0);}
#line 1549 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 46 "abstree.y" /* yacc.c:1646  */
    {Initialise_Codegen();Fieldset();is_classdef=1;}
#line 1555 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 47 "abstree.y" /* yacc.c:1646  */
    {Initialise_Codegen();is_classdef=1;}
#line 1561 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 49 "abstree.y" /* yacc.c:1646  */
    {}
#line 1567 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 50 "abstree.y" /* yacc.c:1646  */
    {}
#line 1573 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 53 "abstree.y" /* yacc.c:1646  */
    {
									Ttemp=Tlookup((yyvsp[-3].nptr)->Name);
									if(Ttemp!=NULL){
										printf("Re-declaration of type\n");
										exit(0);
									}
									Tinstall((yyvsp[-3].nptr)->Name,Fhead);
									Fieldposition=0;
									Fhead=NULL;Ftail=NULL;
								}
#line 1588 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 64 "abstree.y" /* yacc.c:1646  */
    {}
#line 1594 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 65 "abstree.y" /* yacc.c:1646  */
    {}
#line 1600 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 68 "abstree.y" /* yacc.c:1646  */
    { 
							Ftemp=Fhead;
							while(Ftemp!=NULL){
								if(strcmp((yyvsp[-1].nptr)->Name,Ftemp->Name)==0){
									printf("Re-declaration of field\n");
									exit(0);
								}
								Ftemp=Ftemp->Next;
							}
							Finstall((yyvsp[-2].nptr)->Name,(yyvsp[-1].nptr)->Name);
						}
#line 1616 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 81 "abstree.y" /* yacc.c:1646  */
    { 
													Install_Vfuntable();
													is_classdef=0;
												}
#line 1625 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 85 "abstree.y" /* yacc.c:1646  */
    {
						Install_Vfuntable();
						is_classdef=0;
					}
#line 1634 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 93 "abstree.y" /* yacc.c:1646  */
    {
														Cptr=NULL;
													}
#line 1642 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 98 "abstree.y" /* yacc.c:1646  */
    {
					Ttemp = Tlookup((yyvsp[0].nptr)->Name);
					if(Ttemp!=NULL){
						printf("ALready declared as Type\n");exit(0);
					}
					Ctemp = Clookup((yyvsp[0].nptr)->Name);
					if(Ctemp!=NULL){
						printf("Already declared as class\n");exit(0);
					}
					Cptr = Cinstall((yyvsp[0].nptr)->Name,NULL);
					
				}
#line 1659 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 111 "abstree.y" /* yacc.c:1646  */
    {
					Ttemp = Tlookup((yyvsp[-2].nptr)->Name);
					if(Ttemp!=NULL){
						printf("ALready declared as Type\n");exit(0);
					}
					Ctemp = Clookup((yyvsp[-2].nptr)->Name);
					if(Ctemp!=NULL){
						printf("Already declared as class\n");exit(0);
					}
					Ctemp = Clookup((yyvsp[0].nptr)->Name);
					if(Ctemp==NULL){
						printf("Extended class is not defined\n");exit(0);
					}
					Cptr = Cinstall((yyvsp[-2].nptr)->Name,(yyvsp[0].nptr)->Name);
				}
#line 1679 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 131 "abstree.y" /* yacc.c:1646  */
    { 
				Ftemp=Class_Flookup(Cptr,(yyvsp[-1].nptr)->Name);
				if(Ftemp!=NULL){
					printf("Re-declaration of Field");exit(0);
				}
				Class_Finstall(Cptr,(yyvsp[-2].nptr)->Name,(yyvsp[-1].nptr)->Name);
			}
#line 1691 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 139 "abstree.y" /* yacc.c:1646  */
    {}
#line 1697 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 140 "abstree.y" /* yacc.c:1646  */
    {}
#line 1703 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 142 "abstree.y" /* yacc.c:1646  */
    { Ttemp=Tlookup((yyvsp[-5].nptr)->Name);
									if(Ttemp==NULL){
									printf("Undeclared type\n");exit(0);
									}
									Class_Minstall(Cptr,(yyvsp[-4].nptr)->Name,Ttemp,(yyvsp[-2].arg));
								 }
#line 1714 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 149 "abstree.y" /* yacc.c:1646  */
    {}
#line 1720 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 150 "abstree.y" /* yacc.c:1646  */
    {}
#line 1726 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 154 "abstree.y" /* yacc.c:1646  */
    {Initialise_Global();}
#line 1732 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 155 "abstree.y" /* yacc.c:1646  */
    {Initialise_Global();}
#line 1738 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 157 "abstree.y" /* yacc.c:1646  */
    {}
#line 1744 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 158 "abstree.y" /* yacc.c:1646  */
    {}
#line 1750 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 160 "abstree.y" /* yacc.c:1646  */
    {}
#line 1756 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 162 "abstree.y" /* yacc.c:1646  */
    {
				declarationtype=Tlookup((yyvsp[0].nptr)->Name);
				declarationctype=Clookup((yyvsp[0].nptr)->Name);
				if(declarationctype==NULL && declarationtype==NULL){
					printf("Un-declared Type/Class\n");
					exit(0);
				}
			}
#line 1769 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 171 "abstree.y" /* yacc.c:1646  */
    {
								Gtemp=Glookup((yyvsp[0].nptr)->Name);
								if(Gtemp!=NULL){
									printf("Re-declaration of global variable\n");
									exit(0);
								}
								Ginstall(declarationtype,declarationctype,NODE_VAR,(yyvsp[0].nptr)->Name,1,NULL);
							}
#line 1782 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 179 "abstree.y" /* yacc.c:1646  */
    {
											Gtemp=Glookup((yyvsp[-3].nptr)->Name);
											if(Gtemp!=NULL){
												printf("Re-declaration of global variable\n");
												exit(0);
											}
											if(declarationctype!=NULL){
												printf("Arrays are not allowed of class type\n");exit(0);
											}
											Ginstall(declarationtype,NULL,NODE_ARR,(yyvsp[-3].nptr)->Name,(yyvsp[-1].nptr)->Value->intval,NULL);
										}
#line 1798 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 191 "abstree.y" /* yacc.c:1646  */
    {
												Gtemp=Glookup((yyvsp[-3].nptr)->Name);
												if(Gtemp!=NULL){
													printf("Re-declaration of global variable\n");
													exit(0);
												}
												if(declarationctype!=NULL){
													printf("Function  arenot allowed of class as return type\n");exit(0);
												}
												Ginstall(declarationtype,NULL,NODE_FUN,(yyvsp[-3].nptr)->Name,-1,(yyvsp[-1].arg));
											}
#line 1814 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 202 "abstree.y" /* yacc.c:1646  */
    {
				Gtemp=Glookup((yyvsp[0].nptr)->Name);
				if(Gtemp!=NULL){
					printf("Re-declaration of global variable\n");
					exit(0);
				}
				Ginstall(declarationtype,declarationctype,NODE_VAR,(yyvsp[0].nptr)->Name,1,NULL);

			}
#line 1828 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 211 "abstree.y" /* yacc.c:1646  */
    {
							Gtemp=Glookup((yyvsp[-3].nptr)->Name);
							if(Gtemp!=NULL){
								printf("Re-declaration of global variable\n");
								exit(0);
							}
							if(declarationctype!=NULL){
								printf("Arrays arenot allowed of class type\n");exit(0);
							}
							Ginstall(declarationtype,NULL,NODE_ARR,(yyvsp[-3].nptr)->Name,(yyvsp[-1].nptr)->Value->intval,NULL);
						}
#line 1844 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 222 "abstree.y" /* yacc.c:1646  */
    {
									Gtemp=Glookup((yyvsp[-3].nptr)->Name);
									if(Gtemp!=NULL){
										printf("Re-declaration of global variable\n");
										exit(0);
									}
									if(declarationctype!=NULL){
										printf("Arrays arenot allowed of class type\n");exit(0);
									}
									Ginstall(declarationtype,NULL,NODE_FUN,(yyvsp[-3].nptr)->Name,-1,(yyvsp[-1].arg));
								}
#line 1860 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 235 "abstree.y" /* yacc.c:1646  */
    {
									if((yyvsp[-2].arg)!=NULL){
										(yyval.arg)=(yyvsp[0].arg);
										(yyval.arg)->Next=(yyvsp[-2].arg);
									}
									else {
										(yyval.arg)=(yyvsp[0].arg);
									}
								}
#line 1874 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 244 "abstree.y" /* yacc.c:1646  */
    { (yyval.arg)=(yyvsp[0].arg);}
#line 1880 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 245 "abstree.y" /* yacc.c:1646  */
    { (yyval.arg)=NULL;}
#line 1886 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 247 "abstree.y" /* yacc.c:1646  */
    {
					(yyval.arg)=(struct Argstruct*)malloc(sizeof(struct Argstruct));
					Ttemp=Tlookup((yyvsp[-1].nptr)->Name);
					if(Ttemp==NULL){
						printf("Un-declared Type in Parameters\n");
						exit(0);
					}
					(yyval.arg)->Type=Ttemp;
					(yyval.arg)->Name=(yyvsp[0].nptr)->Name;
					(yyval.arg)->Next=NULL;
				}
#line 1902 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 259 "abstree.y" /* yacc.c:1646  */
    {}
#line 1908 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 265 "abstree.y" /* yacc.c:1646  */
    {
							
							Ttemp=Tlookup((yyvsp[-11].nptr)->Name);
							if(Ttemp==NULL){
									printf("Un-defined Type\n");
									exit(0);
								}
							if(is_classdef == 0){
								Gtemp=Glookup((yyvsp[-10].nptr)->Name);
								if(Gtemp==NULL){
									printf("Un-declared function");
									exit(0);
								}
								if(Gtemp->Node!=NODE_FUN){
									printf("Expected Function\n");
									exit(0);
								}
								(yyvsp[-10].nptr)->Gentry=Gtemp;
								Atemp1=(yyvsp[-8].arg);
								Atemp2=Gtemp->Arglist;
							
								while(Atemp1!=NULL && Atemp2!=NULL){
									if(Atemp1->Type!=Atemp2->Type){
										printf("Mismatch in type of arguments\n");
										exit(0);
									}
									Atemp1=Atemp1->Next;
									Atemp2=Atemp2->Next;
								}
								if(Atemp1!=NULL || Atemp2!=NULL){
									printf("Mismatch in type of arguments\n");
									exit(0);
								}
								if(Ttemp!=(yyvsp[-2].nptr)->Ptr1->Type || Ttemp!=Gtemp->Type){
									printf("Mismatch in Type of Functions\n");
									exit(0);
								}
								if((yyvsp[-3].nptr)!=NULL){
									Temp=(struct Tnode*)malloc(sizeof(struct Tnode));
									Temp->Node=NODE_VOID;
									Temp->Ptr1=(yyvsp[-3].nptr);
									Temp->Ptr2=(yyvsp[-2].nptr);
								}
								else{
									Temp=(yyvsp[-2].nptr);
								}
								Codegen_func(Gtemp->Flabel,Temp);
							}
							else{

								Mtemp=Mlookup(Cptr,(yyvsp[-10].nptr)->Name);
								if(Mtemp==NULL){
									printf("Un-declared Method\n");
									exit(0);
								}
								Atemp1=(yyvsp[-8].arg);
								Atemp2=Mtemp->Arglist;
							
								while(Atemp1!=NULL && Atemp2!=NULL){
									if(Atemp1->Type!=Atemp2->Type){
										printf("Mismatch in type of arguments\n");
										exit(0);
									}
									Atemp1=Atemp1->Next;
									Atemp2=Atemp2->Next;
								}
								if(Atemp1!=NULL || Atemp2!=NULL){
									printf("Mismatch in type of arguments\n");
									exit(0);
								}
								if(Ttemp!=(yyvsp[-2].nptr)->Ptr1->Type || Ttemp!=Mtemp->Type){
									printf("Mismatch in Type of Functions\n");
									exit(0);
								}
								if((yyvsp[-3].nptr)!=NULL){
									Temp=(struct Tnode*)malloc(sizeof(struct Tnode));
									Temp->Node=NODE_VOID;
									Temp->Ptr1=(yyvsp[-3].nptr);
									Temp->Ptr2=(yyvsp[-2].nptr);
								}
								else{
									Temp=(yyvsp[-2].nptr);
								}
								Codegen_func(Mtemp->Flabel,Temp);
							}
							Final_setup();
						}
#line 2000 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 353 "abstree.y" /* yacc.c:1646  */
    {
								if((yyvsp[-2].arg)!=NULL){
									(yyval.arg)=(yyvsp[0].arg);
									(yyval.arg)->Next=(yyvsp[-2].arg);
								}
								else{
									(yyval.arg)=(yyvsp[0].arg);
								}

							}
#line 2015 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 363 "abstree.y" /* yacc.c:1646  */
    {(yyval.arg)=(yyvsp[0].arg);}
#line 2021 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 364 "abstree.y" /* yacc.c:1646  */
    {(yyval.arg)=NULL;}
#line 2027 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 366 "abstree.y" /* yacc.c:1646  */
    {

				(yyval.arg)=(struct Argstruct*)malloc(sizeof(struct Argstruct));
				Ttemp=Tlookup((yyvsp[-1].nptr)->Name);
				if(Ttemp==NULL){
					printf("Un-declared Type in Parameters\n");
					exit(0);
				}
				Ltemp=Llookup((yyvsp[0].nptr)->Name);
				if(Ltemp!=NULL){
					printf("Re-declaration of Variable\n");
					exit(0);
				}
				(yyval.arg)->Type=Ttemp;
				(yyval.arg)->Name=(yyvsp[0].nptr)->Name;
				(yyval.arg)->Next=NULL;
				Linstall_arg(Ttemp,(yyvsp[0].nptr)->Name);

			}
#line 2051 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 386 "abstree.y" /* yacc.c:1646  */
    {}
#line 2057 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 387 "abstree.y" /* yacc.c:1646  */
    {}
#line 2063 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 389 "abstree.y" /* yacc.c:1646  */
    {}
#line 2069 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 390 "abstree.y" /* yacc.c:1646  */
    {}
#line 2075 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 392 "abstree.y" /* yacc.c:1646  */
    {}
#line 2081 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 394 "abstree.y" /* yacc.c:1646  */
    {
					(yyval.type)=Tlookup((yyvsp[0].nptr)->Name);
					declarationtype=(yyval.type);
					if((yyval.type)==NULL){
						printf("Un-declared Type\n");
						exit(0);
					}
				}
#line 2094 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 403 "abstree.y" /* yacc.c:1646  */
    {
							Ltemp=Llookup((yyvsp[0].nptr)->Name);
							if(Ltemp!=NULL){
								printf("Re-declaration of Variable\n");
								exit(0);
							}
							Linstall_var(declarationtype,(yyvsp[0].nptr)->Name);
						}
#line 2107 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 411 "abstree.y" /* yacc.c:1646  */
    {
					Ltemp=Llookup((yyvsp[0].nptr)->Name);
					if(Ltemp!=NULL){
						printf("Re-declaration of Variable\n");
						exit(0);
					}
					Linstall_var(declarationtype,(yyvsp[0].nptr)->Name);
				}
#line 2120 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 421 "abstree.y" /* yacc.c:1646  */
    {
							Ttemp=Tlookup((yyvsp[-10].nptr)->Name);
							if(Ttemp==NULL){
								printf("Un-defined Type\n");
								exit(0);
							}
							if(strcmp(Ttemp->Name,"int")!=0){
								printf("Needs an int");
								exit(0);
							}
							if(Ttemp!=(yyvsp[-2].nptr)->Ptr1->Type){
								printf("Mismatch in Type of Functions\n");
								exit(0);
							}
							if((yyvsp[-3].nptr)!=NULL){
								Temp=(struct Tnode*)malloc(sizeof(struct Tnode));
								Temp->Node=NODE_VOID;
								Temp->Ptr1=(yyvsp[-3].nptr);
								Temp->Ptr2=(yyvsp[-2].nptr);
							}
							else{
								Temp=(yyvsp[-2].nptr);
							}
							Codegen_func(0,Temp);
							Final_setup();
						}
#line 2151 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 448 "abstree.y" /* yacc.c:1646  */
    {
						if((yyvsp[-1].nptr)==NULL){
							(yyval.nptr)=(yyvsp[0].nptr);
						}
						else{
							(yyval.nptr)=(struct Tnode*)malloc(sizeof(struct Tnode));
							(yyval.nptr)->Node=NODE_VOID;
							(yyval.nptr)->Ptr1=(yyvsp[-1].nptr);
							(yyval.nptr)->Ptr2=(yyvsp[0].nptr);
						}
					}
#line 2167 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 459 "abstree.y" /* yacc.c:1646  */
    { (yyval.nptr)=NULL; }
#line 2173 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 461 "abstree.y" /* yacc.c:1646  */
    {
								(yyval.nptr)=(struct Tnode*)malloc(sizeof(struct Tnode));
								(yyval.nptr)->Node=NODE_RET;
								(yyval.nptr)->Ptr1=(yyvsp[-1].nptr);
							}
#line 2183 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 468 "abstree.y" /* yacc.c:1646  */
    {
							Ltemp=Llookup((yyvsp[-3].nptr)->Name);
							if(Ltemp!=NULL){
								(yyvsp[-3].nptr)->Type=Ltemp->Type;
								(yyvsp[-3].nptr)->Lentry=Ltemp;
							}
							else if (is_classdef == 1){
								printf("Un-declared Variable or Accessing of mem fields is different %s\n",(yyvsp[-3].nptr)->Name);
								exit(0);
							}
							else{
								Gtemp=Glookup((yyvsp[-3].nptr)->Name);
								if(Gtemp==NULL){
									printf("Un-declared Variable\n");
									exit(0);
								}
								if(Gtemp->Node!=NODE_VAR){
									printf("Expected Var\n");
									exit(0);
								}
								(yyvsp[-3].nptr)->Gentry=Gtemp;
								(yyvsp[-3].nptr)->Type=Gtemp->Type;
								(yyvsp[-3].nptr)->Ctype=Gtemp->Ctype;
							}
							if((yyvsp[-3].nptr)->Type!=NULL){
								if((yyvsp[-3].nptr)->Type!=(yyvsp[-1].nptr)->Type){
									printf("Conflicting types in asgn\n");exit(0);
								}
								(yyval.nptr)=Treecreate(NULL,NULL,NODE_ID_ASGN,NULL,NULL,NULL,(yyvsp[-3].nptr),NULL,(yyvsp[-1].nptr));
							}
							else{
								type_comp((yyvsp[-3].nptr)->Ctype,(yyvsp[-1].nptr)->Ctype);
								(yyval.nptr)=Treecreate(NULL,NULL,NODE_ID_ASGN_CLASS,NULL,NULL,NULL,(yyvsp[-3].nptr),NULL,(yyvsp[-1].nptr));
							}
						}
#line 2223 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 504 "abstree.y" /* yacc.c:1646  */
    {
						if (is_classdef == 1){
							printf("Arrays are not permitted in classes\n");
							exit(0);
						}
						Gtemp=Glookup((yyvsp[-6].nptr)->Name);
						if(Gtemp==NULL){
							printf("Un-declared Variable\n");
							exit(0);
						}
						if(Gtemp->Node!=NODE_ARR){
							printf("Expected Arr\n");exit(0);
						}
						if((yyvsp[-4].nptr)->Type!=Tlookup("int")){
							printf("index must be int\n");exit(0);
						}
						(yyvsp[-6].nptr)->Type=Gtemp->Type;
						(yyvsp[-6].nptr)->Gentry=Gtemp;
						if((yyvsp[-6].nptr)->Type!=(yyvsp[-1].nptr)->Type){
							printf("conflicting types in asgn\n");exit(0);
						}
						(yyval.nptr)=Treecreate(NULL,NULL,NODE_ARR_ASGN,NULL,NULL,NULL,(yyvsp[-6].nptr),(yyvsp[-4].nptr),(yyvsp[-1].nptr));
					}
#line 2251 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 527 "abstree.y" /* yacc.c:1646  */
    {
								if((yyvsp[-3].nptr)->Type!=NULL){
									if((yyvsp[-3].nptr)->Type!=(yyvsp[-1].nptr)->Type){
										printf("Conflicting types in asgn\n");exit(0);
									}
									(yyval.nptr)=Treecreate(NULL,NULL,NODE_FIELD_ASGN,NULL,NULL,NULL,(yyvsp[-3].nptr),NULL,(yyvsp[-1].nptr));
								}
								else{
									if((yyvsp[-3].nptr)->Ctype!=(yyvsp[-1].nptr)->Ctype){
										printf("Conflicting types by class in asgn\n");exit(0);
									}
									(yyval.nptr)=Treecreate(NULL,NULL,NODE_FIELD_ASGN_CLASS,NULL,NULL,NULL,(yyvsp[-3].nptr),NULL,(yyvsp[-1].nptr));
								}
							}
#line 2270 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 541 "abstree.y" /* yacc.c:1646  */
    {
										if(is_classdef == 1){
											printf("Accessing of Mem fields is wrong\n");
											exit(0);
										}
										Gtemp = Glookup((yyvsp[-6].nptr)->Name);
										if(Gtemp == NULL){
											printf("Un-declared Variable\n");
											exit(0);
										}
										(yyvsp[-6].nptr)->Gentry=Gtemp;
										(yyvsp[-6].nptr)->Ctype=Gtemp->Ctype;
										if((yyvsp[-6].nptr)->Ctype == NULL){
											printf("Variable is not of class type %s\n",(yyvsp[-6].nptr)->Type->Name);
											exit(0);
										}
										Ctemp = Clookup((yyvsp[-2].nptr)->Name);
										if(Ctemp == NULL){
											printf("CLass Un-declared\n");
											exit(0);
										}
										type_comp((yyvsp[-6].nptr)->Ctype,Ctemp);
										(yyvsp[-2].nptr)->Ctype=Ctemp;
										(yyval.nptr)=Treecreate(NULL,NULL,NODE_OBJID_NEW,NULL,NULL,NULL,(yyvsp[-6].nptr),(yyvsp[-2].nptr),NULL);
									}
#line 2300 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 566 "abstree.y" /* yacc.c:1646  */
    {
											Ctemp = Clookup((yyvsp[-2].nptr)->Name);
											if(Ctemp == NULL){
												printf("Class Un-declared\n");
												exit(0);
											}
											if((yyvsp[-6].nptr)->Ctype == NULL){
												printf("Field is not of class type\n");
												exit(0);
											}
											type_comp((yyvsp[-6].nptr)->Ctype,Ctemp);
											(yyvsp[-2].nptr)->Ctype=Ctemp;
											(yyval.nptr)=Treecreate(NULL,NULL,NODE_OBJFIELD_NEW,NULL,NULL,NULL,(yyvsp[-6].nptr),(yyvsp[-2].nptr),NULL);
										}
#line 2319 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 580 "abstree.y" /* yacc.c:1646  */
    {
										if((yyvsp[-2].nptr)->Ctype == NULL){
											printf("Field is not of class type\n");
											exit(0);
										}
										(yyval.nptr)=Treecreate(NULL,NULL,NODE_OBJFIELD_DELETE,NULL,NULL,NULL,(yyvsp[-2].nptr),NULL,NULL);
									}
#line 2331 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 587 "abstree.y" /* yacc.c:1646  */
    {
										if(is_classdef == 1){
											printf("Accessing of Mem fields is wrong\n");
											exit(0);
										}
										Gtemp = Glookup((yyvsp[-2].nptr)->Name);
										if(Gtemp == NULL){
											printf("Un-declared Variable\n");
											exit(0);
										}
										(yyvsp[-2].nptr)->Gentry=Gtemp;
										(yyvsp[-2].nptr)->Ctype=Gtemp->Ctype;
										if((yyvsp[-2].nptr)->Ctype == NULL){
											printf("Variable is not of class type\n");
											exit(0);
										}
									(yyval.nptr)=Treecreate(NULL,NULL,NODE_OBJID_DELETE,NULL,NULL,NULL,(yyvsp[-2].nptr),NULL,NULL);
									}
#line 2354 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 605 "abstree.y" /* yacc.c:1646  */
    {
							Ltemp=Llookup((yyvsp[-3].nptr)->Name);
							if(Ltemp!=NULL){
								(yyvsp[-3].nptr)->Type=Ltemp->Type;
								(yyvsp[-3].nptr)->Lentry=Ltemp;
							}
							else if (is_classdef == 1){
								printf("Un-declared Variable\n");
								exit(0);
							}
							else{
								Gtemp=Glookup((yyvsp[-3].nptr)->Name);
								if(Gtemp==NULL){
									printf("Un-declared Variable\n");
									exit(0);
								}
								if(Gtemp->Node!=NODE_VAR){
									printf("Expected Var\n");
									exit(0);
								}
								(yyvsp[-3].nptr)->Gentry=Gtemp;
								(yyvsp[-3].nptr)->Type=Gtemp->Type;
								(yyvsp[-3].nptr)->Ctype=Gtemp->Ctype;
							}
							if((yyvsp[-3].nptr)->Type==Tlookup("int") || (yyvsp[-3].nptr)->Type==Tlookup("bool") || (yyvsp[-3].nptr)->Type==Tlookup("str")){
								printf("can't make it NULL\n");exit(0);
							}
							if((yyvsp[-3].nptr)->Type != NULL){
								(yyval.nptr)=Treecreate(NULL,NULL,NODE_ID_NULL,NULL,NULL,NULL,(yyvsp[-3].nptr),NULL,NULL);
							}
							else{
								(yyval.nptr)=Treecreate(NULL,NULL,NODE_ID_NULL_CLASS,NULL,NULL,NULL,(yyvsp[-3].nptr),NULL,NULL);
							}
						}
#line 2393 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 639 "abstree.y" /* yacc.c:1646  */
    {
							if((yyvsp[-3].nptr)->Type==Tlookup("int") || (yyvsp[-3].nptr)->Type==Tlookup("bool") || (yyvsp[-3].nptr)->Type==Tlookup("str")){
								printf("can't make it NULL\n");exit(0);
							}
							if((yyvsp[-3].nptr)->Type != NULL){
								(yyval.nptr)=Treecreate(NULL,NULL,NODE_FIELD_NULL,NULL,NULL,NULL,(yyvsp[-3].nptr),NULL,NULL);
							}
							else{
								(yyval.nptr)=Treecreate(NULL,NULL,NODE_FIELD_NULL_CLASS,NULL,NULL,NULL,(yyvsp[-3].nptr),NULL,NULL);
							}
						}
#line 2409 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 651 "abstree.y" /* yacc.c:1646  */
    {
							Ltemp=Llookup((yyvsp[-5].nptr)->Name);
							if(Ltemp!=NULL){
								(yyvsp[-5].nptr)->Type=Ltemp->Type;
								(yyvsp[-5].nptr)->Lentry=Ltemp;
							}
							else if (is_classdef == 1){
								printf("Un-declared Variable or Accessing of mem fields is different2\n");
								exit(0);
							}
							else{
								Gtemp=Glookup((yyvsp[-5].nptr)->Name);
								if(Gtemp==NULL){
									printf("Un-declared Variable\n");
									exit(0);
								}
								if(Gtemp->Node!=NODE_VAR){
									printf("Expected Var\n");
									exit(0);
								}
								(yyvsp[-5].nptr)->Gentry=Gtemp;
								(yyvsp[-5].nptr)->Type=Gtemp->Type;
							}
							if((yyvsp[-5].nptr)->Type!=Tlookup("int")){
								printf("Return type of initialise is INT\n");exit(0);
							}
							(yyval.nptr)=Treecreate(NULL,NULL,NODE_INITIALIZE,NULL,NULL,NULL,(yyvsp[-5].nptr),NULL,NULL);
						}
#line 2442 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 680 "abstree.y" /* yacc.c:1646  */
    {
							if((yyvsp[-5].nptr)->Type==Tlookup("int") || (yyvsp[-5].nptr)->Type==Tlookup("bool") || (yyvsp[-5].nptr)->Type==NULL || (yyvsp[-5].nptr)->Type==Tlookup("str")){
								printf("can't give memory for int and bool or giving memory for classes is diff\n");exit(0);
							}
							(yyval.nptr)=Treecreate(NULL,NULL,NODE_FIELD_ALLOC,NULL,NULL,NULL,(yyvsp[-5].nptr),NULL,NULL);
						}
#line 2453 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 687 "abstree.y" /* yacc.c:1646  */
    {
							Ltemp=Llookup((yyvsp[-5].nptr)->Name);
							if(Ltemp!=NULL){
								(yyvsp[-5].nptr)->Type=Ltemp->Type;
								(yyvsp[-5].nptr)->Lentry=Ltemp;
							}
							else if (is_classdef == 1){
								printf("Un-declared Variable\n");
								exit(0);
							}
							else{
								Gtemp=Glookup((yyvsp[-5].nptr)->Name);
								if(Gtemp==NULL){
									printf("Un-declared Variable\n");
									exit(0);
								}
								if(Gtemp->Node!=NODE_VAR){
									printf("Expected Var\n");
									exit(0);
								}
								(yyvsp[-5].nptr)->Gentry=Gtemp;
								(yyvsp[-5].nptr)->Type=Gtemp->Type;
							}
							if((yyvsp[-5].nptr)->Type==Tlookup("int") || (yyvsp[-5].nptr)->Type==Tlookup("bool") || (yyvsp[-5].nptr)->Type==NULL || (yyvsp[-5].nptr)->Type==Tlookup("str")){
								printf("can't give memory for int and bool\n");exit(0);
							}
							(yyval.nptr)=Treecreate(NULL,NULL,NODE_ID_ALLOC,NULL,NULL,NULL,(yyvsp[-5].nptr),NULL,NULL);
						}
#line 2486 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 716 "abstree.y" /* yacc.c:1646  */
    {
							Ltemp=Llookup((yyvsp[-6].nptr)->Name);
							if(Ltemp!=NULL){
								(yyvsp[-6].nptr)->Type=Ltemp->Type;
								(yyvsp[-6].nptr)->Lentry=Ltemp;
							}
							else if (is_classdef == 1){
								printf("Un-declared Variable or Accessing of mem fields is different3\n");
								exit(0);
							}
							else{
								Gtemp=Glookup((yyvsp[-6].nptr)->Name);
								if(Gtemp==NULL){
									printf("Un-declared Variable\n");
									exit(0);
								}
								if(Gtemp->Node!=NODE_VAR){
									printf("Expected Var\n");
									exit(0);
								}
								(yyvsp[-6].nptr)->Gentry=Gtemp;
								(yyvsp[-6].nptr)->Type=Gtemp->Type;
							}
							if((yyvsp[-6].nptr)->Type!=Tlookup("int")){
								printf("Return type of free is INT\n");exit(0);
							}
							if((yyvsp[-2].nptr)->Type==Tlookup("int") || (yyvsp[-2].nptr)->Type==Tlookup("bool") || (yyvsp[-2].nptr)->Type==NULL || (yyvsp[-2].nptr)->Type==Tlookup("str")){
								printf("WE can't free variables of int and bool types or making variables of class type is diff\n");exit(0);
							}
							(yyval.nptr)=Treecreate(NULL,NULL,NODE_FIELD_FREE,NULL,NULL,NULL,(yyvsp[-6].nptr),(yyvsp[-2].nptr),NULL);
						}
#line 2522 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 748 "abstree.y" /* yacc.c:1646  */
    {
							Ltemp=Llookup((yyvsp[-6].nptr)->Name);
							if(Ltemp!=NULL){
								(yyvsp[-6].nptr)->Type=Ltemp->Type;
								(yyvsp[-6].nptr)->Lentry=Ltemp;
							}
							else if (is_classdef == 1){
								printf("Un-declared Variable or Accessing of mem fields is different4\n");
								exit(0);
							}
							else{
								Gtemp=Glookup((yyvsp[-6].nptr)->Name);
								if(Gtemp==NULL){
									printf("Un-declared Variable\n");
									exit(0);
								}
								if(Gtemp->Node!=NODE_VAR){
									printf("Expected Var\n");
									exit(0);
								}
								(yyvsp[-6].nptr)->Gentry=Gtemp;
								(yyvsp[-6].nptr)->Type=Gtemp->Type;
							}
							if((yyvsp[-6].nptr)->Type!=Tlookup("int")){
								printf("Return type of free is INT\n");exit(0);
							}
							Ltemp=Llookup((yyvsp[-2].nptr)->Name);
							if(Ltemp!=NULL){
								(yyvsp[-2].nptr)->Type=Ltemp->Type;
								(yyvsp[-2].nptr)->Lentry=Ltemp;
							}
							else if (is_classdef == 1){
								printf("Un-declared Variable or Accessing of mem fields is different5\n");
								exit(0);
							}
							else{
								Gtemp=Glookup((yyvsp[-2].nptr)->Name);
								if(Gtemp==NULL){
									printf("Un-declared Variable\n");
									exit(0);
								}
								if(Gtemp->Node!=NODE_VAR){
									printf("Expected Var\n");
									exit(0);
								}
								(yyvsp[-2].nptr)->Gentry=Gtemp;
								(yyvsp[-2].nptr)->Type=Gtemp->Type;
							}
							if((yyvsp[-2].nptr)->Type==Tlookup("int") || (yyvsp[-2].nptr)->Type==Tlookup("bool") || (yyvsp[-2].nptr)->Type==NULL || (yyvsp[-2].nptr)->Type==Tlookup("str")){
								printf("WE can't free variables of int and bool types\n");exit(0);
							}
							(yyval.nptr)=Treecreate(NULL,NULL,NODE_ID_FREE,NULL,NULL,NULL,(yyvsp[-6].nptr),(yyvsp[-2].nptr),NULL);
						}
#line 2580 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 802 "abstree.y" /* yacc.c:1646  */
    {
							Ltemp=Llookup((yyvsp[-2].nptr)->Name);
							if(Ltemp!=NULL){
								(yyvsp[-2].nptr)->Type=Ltemp->Type;
								(yyvsp[-2].nptr)->Lentry=Ltemp;
							}
							else if (is_classdef == 1){
								printf("Un-declared Variable or Accessing of mem fields is different6\n");
								exit(0);
							}
							else{
								Gtemp=Glookup((yyvsp[-2].nptr)->Name);
								if(Gtemp==NULL){
									printf("Un-declared Variable\n");
									exit(0);
								}
								if(Gtemp->Node!=NODE_VAR){
									printf("Expected Var\n");
									exit(0);
								}
								(yyvsp[-2].nptr)->Gentry=Gtemp;
								(yyvsp[-2].nptr)->Type=Gtemp->Type;
							}
							if((yyvsp[-2].nptr)->Type!=Tlookup("int")&&(yyvsp[-2].nptr)->Type!=Tlookup("str")){
								printf("Reading only int type variable\n");exit(0);
							}
							(yyval.nptr)=Treecreate(NULL,NULL,NODE_ID_READ,NULL,NULL,NULL,(yyvsp[-2].nptr),NULL,NULL);
						}
#line 2613 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 831 "abstree.y" /* yacc.c:1646  */
    {
							if (is_classdef == 1){
								printf("Arrays are not included in classes\n");
								exit(0);
							}
							Gtemp=Glookup((yyvsp[-5].nptr)->Name);
							if(Gtemp==NULL){
								printf("Un-declared Variable\n");
								exit(0);
							}
							if(Gtemp->Node!=NODE_ARR){
								printf("Expected Array\n");
								exit(0);
							}
							(yyvsp[-5].nptr)->Gentry=Gtemp;
							(yyvsp[-5].nptr)->Type=Gtemp->Type;
							if((yyvsp[-3].nptr)->Type!=Tlookup("int")){
								printf("Index must be integer\n");exit(0);
							}
							if((yyvsp[-5].nptr)->Type!=Tlookup("int")){
								printf("Reading only int type var\n");exit(0);
							}
							(yyval.nptr)=Treecreate(NULL,NULL,NODE_ARR_READ,NULL,NULL,NULL,(yyvsp[-5].nptr),(yyvsp[-3].nptr),NULL);
						}
#line 2642 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 856 "abstree.y" /* yacc.c:1646  */
    {
							if((yyvsp[-2].nptr)->Type!=Tlookup("int")&&(yyvsp[-2].nptr)->Type!=Tlookup("str")){
								printf("Reading only int type var\n");exit(0);
							}
							(yyval.nptr)=Treecreate(NULL,NULL,NODE_FIELD_READ,NULL,NULL,NULL,(yyvsp[-2].nptr),NULL,NULL);
						}
#line 2653 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 863 "abstree.y" /* yacc.c:1646  */
    {
							if((yyvsp[-2].nptr)->Type!=Tlookup("int")&&(yyvsp[-2].nptr)->Type!=Tlookup("str")){
								printf("Printing only int type var\n");exit(0);
							}
							(yyval.nptr)=Treecreate(NULL,NULL,NODE_WRITE,NULL,NULL,NULL,(yyvsp[-2].nptr),NULL,NULL);
						}
#line 2664 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 870 "abstree.y" /* yacc.c:1646  */
    {
							if((yyvsp[-5].nptr)->Type!=Tlookup("bool")){
								printf("Conditions only bool type \n");exit(0);
							}
							(yyval.nptr)=Treecreate(NULL,NULL,NODE_IF,NULL,NULL,NULL,(yyvsp[-5].nptr),(yyvsp[-2].nptr),NULL);
						}
#line 2675 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 877 "abstree.y" /* yacc.c:1646  */
    {
							if((yyvsp[-7].nptr)->Type!=Tlookup("bool")){
								printf("Conditions only bool type \n");exit(0);
							}
							(yyval.nptr)=Treecreate(NULL,NULL,NODE_IF_ELSE,NULL,NULL,NULL,(yyvsp[-7].nptr),(yyvsp[-4].nptr),(yyvsp[-2].nptr));
						}
#line 2686 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 884 "abstree.y" /* yacc.c:1646  */
    {
							if((yyvsp[-5].nptr)->Type!=Tlookup("bool")){
								printf("Conditions only bool type \n");exit(0);
							}
							(yyval.nptr)=Treecreate(NULL,NULL,NODE_WHILE,NULL,NULL,NULL,(yyvsp[-5].nptr),(yyvsp[-2].nptr),NULL);
						}
#line 2697 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 893 "abstree.y" /* yacc.c:1646  */
    {
						Ltemp=Llookup((yyvsp[-2].nptr)->Name);
						if(Ltemp!=NULL){
							(yyvsp[-2].nptr)->Lentry=Ltemp;
							(yyvsp[-2].nptr)->Type=Ltemp->Type;
							Ftemp=Flookup(Ltemp->Type,(yyvsp[0].nptr)->Name);
						}
						else if (is_classdef == 1){
							printf("Un-declared Variable or Accessing of mem fields is different7\n");
							exit(0);
						}
						else{
							Gtemp=Glookup((yyvsp[-2].nptr)->Name);
							if(Gtemp==NULL){
								printf("Variable not declared\n");
								exit(0);
							}
							if(Gtemp->Type==NULL){
								printf("Mem fields of class are of private type\n");exit(0);
							}
							if(Gtemp->Node!=NODE_VAR){
								printf("Expected Var,Found something\n");
								exit(0);
							}
							(yyvsp[-2].nptr)->Gentry=Gtemp;
							(yyvsp[-2].nptr)->Type=Gtemp->Type;
							Ftemp=Flookup(Gtemp->Type,(yyvsp[0].nptr)->Name);
							}
						if(Ftemp==NULL){
							printf("It is not a field in that type\n");
							exit(0);
						}
						(yyvsp[0].nptr)->Type=Ftemp->Type;
						(yyval.nptr)=Treecreate((yyvsp[0].nptr)->Type,NULL,NODE_FIELD_ID,NULL,NULL,NULL,(yyvsp[-2].nptr),(yyvsp[0].nptr),NULL);
					}
#line 2737 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 928 "abstree.y" /* yacc.c:1646  */
    {
							if((yyvsp[-2].nptr)->Type==NULL){
								printf("Member fields of class are of private type\n");exit(0);
							}
							Ftemp= Flookup((yyvsp[-2].nptr)->Type,(yyvsp[0].nptr)->Name);
							if(Ftemp == NULL){
								printf("It is not a field in that type/ class");exit(0);
							}
							(yyvsp[0].nptr)->Type=Ftemp->Type;
							(yyval.nptr)=Treecreate((yyvsp[0].nptr)->Type,NULL,NODE_FIELD,NULL,NULL,NULL,(yyvsp[-2].nptr),(yyvsp[0].nptr),NULL);
						}
#line 2753 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 939 "abstree.y" /* yacc.c:1646  */
    {	
							Ftemp= Class_Flookup(Cptr,(yyvsp[0].nptr)->Name);
							if(Ftemp == NULL){
								printf("It is not a field in that type/class");
								exit(0);
							}
							(yyvsp[0].nptr)->Type=Ftemp->Type;
							(yyvsp[0].nptr)->Ctype=Ftemp->Ctype;
							(yyvsp[-2].nptr)->Ctype=Cptr;
							(yyval.nptr)=Treecreate((yyvsp[0].nptr)->Type,(yyvsp[0].nptr)->Ctype,NODE_SELF_ID,NULL,NULL,NULL,(yyvsp[-2].nptr),(yyvsp[0].nptr),NULL);
						}
#line 2769 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 953 "abstree.y" /* yacc.c:1646  */
    {
								if((yyvsp[-5].nptr)->Ctype == NULL){
									printf("Calling reference is not an obj\n");exit(0);
								}
								Mtemp = Mlookup((yyvsp[-5].nptr)->Ctype,(yyvsp[-3].nptr)->Name);
								if(Mtemp == NULL){
									printf("Method doesn't exist\n");exit(0);
								}
								Temp=(yyvsp[-1].nptr);
								Atemp=Mtemp->Arglist;
								while(Temp!=NULL && Atemp!=NULL){
									
									if(Temp->Type!=Atemp->Type){
										printf("Confilcts in arguments\n");
										exit(0);
									}
									Temp=Temp->Next;
									Atemp=Atemp->Next;
								}
								if(Temp!=NULL || Atemp!=NULL){
									printf("Confilcts in arguments\n");
									exit(0);
								}
								(yyval.nptr)=Treecreate(Mtemp->Type,NULL,NODE_FIELD_METHOD,NULL,NULL,(yyvsp[-1].nptr),(yyvsp[-3].nptr),NULL,NULL);
								(yyval.nptr)->Obj = (yyvsp[-5].nptr);
							}
#line 2800 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 980 "abstree.y" /* yacc.c:1646  */
    {
								Mtemp=Mlookup(Cptr,(yyvsp[-3].nptr)->Name);
								if(Mtemp == NULL){
									printf("Method doesn't exist\n");exit(0);
								}
								Temp=(yyvsp[-1].nptr);
								Atemp=Mtemp->Arglist;
								while(Temp!=NULL && Atemp!=NULL){
									
									if(Temp->Type!=Atemp->Type){
										printf("Confilcts in arguments\n");
										exit(0);
									}
									Temp=Temp->Next;
									Atemp=Atemp->Next;
								}
								if(Temp!=NULL || Atemp!=NULL){
									printf("Confilcts in arguments\n");
									exit(0);
								}
								(yyvsp[-5].nptr)->Ctype=Cptr;
								(yyval.nptr)=Treecreate(Mtemp->Type,NULL,NODE_SELF_METHOD,NULL,NULL,(yyvsp[-1].nptr),(yyvsp[-3].nptr),NULL,NULL);
								(yyval.nptr)->Obj = (yyvsp[-5].nptr);
							}
#line 2829 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 1005 "abstree.y" /* yacc.c:1646  */
    {
								if(is_classdef==1){
									printf("Accessing of mem field is wrong\n");exit(0);
								}
								Gtemp=Glookup((yyvsp[-5].nptr)->Name);
								if(Gtemp==NULL){
									printf("Un-declared Variable\n");
									exit(0);
								}
								if(Gtemp->Ctype==NULL){
									printf("Variable is not of class type\n");
									exit(0);
								}
								(yyvsp[-5].nptr)->Gentry=Gtemp;
								(yyvsp[-5].nptr)->Ctype=Gtemp->Ctype;
								Mtemp=Mlookup(Gtemp->Ctype,(yyvsp[-3].nptr)->Name);
								if(Mtemp == NULL){
									printf("Method doesn't exist\n");exit(0);
								}
								Temp=(yyvsp[-1].nptr);
								Atemp=Mtemp->Arglist;
								while(Temp!=NULL && Atemp!=NULL){
									
									if(Temp->Type!=Atemp->Type){
										printf("Confilcts in arguments\n");
										exit(0);
									}
									Temp=Temp->Next;
									Atemp=Atemp->Next;
								}
								if(Temp!=NULL || Atemp!=NULL){
									printf("Confilcts in arguments\n");
									exit(0);
								}
								(yyval.nptr)=Treecreate(Mtemp->Type,NULL,NODE_ID_METHOD,NULL,NULL,(yyvsp[-1].nptr),(yyvsp[-3].nptr),NULL,NULL);
								(yyval.nptr)->Obj = (yyvsp[-5].nptr);
							}
#line 2871 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 1044 "abstree.y" /* yacc.c:1646  */
    {
							Ttemp=Tlookup("int");
							if((yyvsp[-2].nptr)->Type==Ttemp && (yyvsp[0].nptr)->Type==Ttemp){
								(yyval.nptr)=Treecreate(Ttemp,NULL,NODE_PLUS,NULL,NULL,NULL,(yyvsp[-2].nptr),(yyvsp[0].nptr),NULL);
							}
							else {
								printf("Conflicting types in PLUS\n");exit(0);
							}
						}
#line 2885 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 1053 "abstree.y" /* yacc.c:1646  */
    {
						Ltemp=Llookup((yyvsp[-1].nptr)->Name);
						if(Ltemp!=NULL){
							(yyvsp[-1].nptr)->Lentry=Ltemp;
							(yyvsp[-1].nptr)->Type=Ltemp->Type;
						}
						else if (is_classdef == 1){
							printf("Un-declared Variable or Accessing of mem fields is different8\n");
							exit(0);
						}
						else{
							Gtemp=Glookup((yyvsp[-1].nptr)->Name);
							if(Gtemp==NULL){
								printf("Not declared variable\n");
								exit(0);
							}
							if(Gtemp->Node!=NODE_VAR){
								printf("Expected Var,Found something\n");
								exit(0);
							}
							(yyvsp[-1].nptr)->Gentry=Gtemp;
							(yyvsp[-1].nptr)->Type=Gtemp->Type;
							(yyvsp[-1].nptr)->Ctype=Gtemp->Ctype;
						}
						if((yyvsp[-1].nptr)->Type==Tlookup("int") || (yyvsp[-1].nptr)->Type==Tlookup("bool")||
						(yyvsp[-1].nptr)->Type==Tlookup("str")){
							printf("Can't compare null\n");
							exit(0);
						}
						(yyval.nptr)=Treecreate(Tlookup("bool"),NULL,NODE_ID_EQ,NULL,NULL,NULL,(yyvsp[-1].nptr),NULL,NULL);
					}
#line 2921 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 1084 "abstree.y" /* yacc.c:1646  */
    {
						Ltemp=Llookup((yyvsp[-1].nptr)->Name);
						if(Ltemp!=NULL){
							(yyvsp[-1].nptr)->Lentry=Ltemp;
							(yyvsp[-1].nptr)->Type=Ltemp->Type;
						}
						else if (is_classdef == 1){
							printf("Un-declared Variable or Accessing of mem fields is different9\n");
							exit(0);
						}
						else{
							Gtemp=Glookup((yyvsp[-1].nptr)->Name);
							if(Gtemp==NULL){
								printf("Not declared variable\n");
								exit(0);
							}
							if(Gtemp->Node!=NODE_VAR){
								printf("Expected Var,Found something\n");
								exit(0);
							}
							(yyvsp[-1].nptr)->Gentry=Gtemp;
							(yyvsp[-1].nptr)->Type=Gtemp->Type;
							(yyvsp[-1].nptr)->Ctype=Gtemp->Ctype;
						}
						if((yyvsp[-1].nptr)->Type==Tlookup("int") || (yyvsp[-1].nptr)->Type==Tlookup("bool")|| 
						(yyvsp[-1].nptr)->Type==Tlookup("str")){
							printf("Can't Compare null\n");
							exit(0);
						}
						(yyval.nptr)=Treecreate(Tlookup("bool"),NULL,NODE_ID_NE,NULL,NULL,NULL,(yyvsp[-1].nptr),NULL,NULL);
					}
#line 2957 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 1115 "abstree.y" /* yacc.c:1646  */
    {
							if((yyvsp[-1].nptr)->Type==Tlookup("int") || (yyvsp[-1].nptr)->Type==Tlookup("bool")|| 
							(yyvsp[-1].nptr)->Type==Tlookup("str")){
								printf("Can't make null\n");
								exit(0);
							}
							(yyval.nptr)=Treecreate(Tlookup("bool"),NULL,NODE_FIELD_EQ,NULL,NULL,NULL,(yyvsp[-1].nptr),NULL,NULL);
						}
#line 2970 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 1123 "abstree.y" /* yacc.c:1646  */
    {
							if((yyvsp[-1].nptr)->Type==Tlookup("int") || (yyvsp[-1].nptr)->Type==Tlookup("bool")|| 
							(yyvsp[-1].nptr)->Type==Tlookup("str")){
								printf("Can't make null\n");
								exit(0);
							}
							(yyval.nptr)=Treecreate(Tlookup("bool"),NULL,NODE_FIELD_NE,NULL,NULL,NULL,(yyvsp[-1].nptr),NULL,NULL);
						}
#line 2983 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 1131 "abstree.y" /* yacc.c:1646  */
    {
							Ttemp=Tlookup("int");
							if((yyvsp[-2].nptr)->Type==Ttemp && (yyvsp[0].nptr)->Type==Ttemp){
								(yyval.nptr)=Treecreate(Ttemp,NULL,NODE_SUB,NULL,NULL,NULL,(yyvsp[-2].nptr),(yyvsp[0].nptr),NULL);
							}
							else {
								printf("Conflicting types in SUB\n");exit(0);
							}
						}
#line 2997 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 1140 "abstree.y" /* yacc.c:1646  */
    {
							Ttemp=Tlookup("int");
							if((yyvsp[-2].nptr)->Type==Ttemp && (yyvsp[0].nptr)->Type==Ttemp){
								(yyval.nptr)=Treecreate(Ttemp,NULL,NODE_MUL,NULL,NULL,NULL,(yyvsp[-2].nptr),(yyvsp[0].nptr),NULL);
							}
							else {
								printf("Conflicting types in MUL\n");exit(0);
							}
						}
#line 3011 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 1149 "abstree.y" /* yacc.c:1646  */
    {
							Ttemp=Tlookup("int");
							if((yyvsp[-2].nptr)->Type==Ttemp && (yyvsp[0].nptr)->Type==Ttemp){
								(yyval.nptr)=Treecreate(Ttemp,NULL,NODE_DIV,NULL,NULL,NULL,(yyvsp[-2].nptr),(yyvsp[0].nptr),NULL);
							}
							else {
								printf("Conflicting types in DIV\n");exit(0);
							}
						}
#line 3025 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 1158 "abstree.y" /* yacc.c:1646  */
    {
							Ttemp=Tlookup("int");
							if((yyvsp[-2].nptr)->Type==Ttemp && (yyvsp[0].nptr)->Type==Ttemp){
								(yyval.nptr)=Treecreate(Ttemp,NULL,NODE_MOD,NULL,NULL,NULL,(yyvsp[-2].nptr),(yyvsp[0].nptr),NULL);
							}
							else {
								printf("Conflicting types in MOD\n");exit(0);
							}
						}
#line 3039 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 1167 "abstree.y" /* yacc.c:1646  */
    {
							Ttemp=Tlookup("int");
							if((yyvsp[-2].nptr)->Type==Ttemp && (yyvsp[0].nptr)->Type==Ttemp){
								(yyval.nptr)=Treecreate(Tlookup("bool"),NULL,NODE_NE,NULL,NULL,NULL,(yyvsp[-2].nptr),(yyvsp[0].nptr),NULL);
							}
							else {
								printf("Conflicting types in NE\n");exit(0);
							}
						}
#line 3053 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 1176 "abstree.y" /* yacc.c:1646  */
    {
							Ttemp=Tlookup("int");
							if((yyvsp[-2].nptr)->Type==Ttemp && (yyvsp[0].nptr)->Type==Ttemp){
								(yyval.nptr)=Treecreate(Tlookup("bool"),NULL,NODE_EQ,NULL,NULL,NULL,(yyvsp[-2].nptr),(yyvsp[0].nptr),NULL);
							}
							else {
								printf("Conflicting types in EQ\n");exit(0);
							}
						}
#line 3067 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 1185 "abstree.y" /* yacc.c:1646  */
    {
							Ttemp=Tlookup("int");
							if((yyvsp[-2].nptr)->Type==Ttemp && (yyvsp[0].nptr)->Type==Ttemp){
								(yyval.nptr)=Treecreate(Tlookup("bool"),NULL,NODE_LT,NULL,NULL,NULL,(yyvsp[-2].nptr),(yyvsp[0].nptr),NULL);
							}
							else {
								printf("Conflicting types in LT\n");exit(0);
							}
						}
#line 3081 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 1194 "abstree.y" /* yacc.c:1646  */
    {
							Ttemp=Tlookup("int");
							if((yyvsp[-2].nptr)->Type==Ttemp && (yyvsp[0].nptr)->Type==Ttemp){
								(yyval.nptr)=Treecreate(Tlookup("bool"),NULL,NODE_LE,NULL,NULL,NULL,(yyvsp[-2].nptr),(yyvsp[0].nptr),NULL);
							}
							else {
								printf("Conflicting types in LE\n");exit(0);
							}
						}
#line 3095 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 1203 "abstree.y" /* yacc.c:1646  */
    {
							Ttemp=Tlookup("int");
							if((yyvsp[-2].nptr)->Type==Ttemp && (yyvsp[0].nptr)->Type==Ttemp){
								(yyval.nptr)=Treecreate(Tlookup("bool"),NULL,NODE_GT,NULL,NULL,NULL,(yyvsp[-2].nptr),(yyvsp[0].nptr),NULL);
							}
							else {
								printf("Conflicting types in GT\n");exit(0);
							}
						}
#line 3109 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 1212 "abstree.y" /* yacc.c:1646  */
    {
							Ttemp=Tlookup("int");
							if((yyvsp[-2].nptr)->Type==Ttemp && (yyvsp[0].nptr)->Type==Ttemp){
								(yyval.nptr)=Treecreate(Tlookup("bool"),NULL,NODE_GE,NULL,NULL,NULL,(yyvsp[-2].nptr),(yyvsp[0].nptr),NULL);
							}
							else {
								printf("Conflicting types in GE\n");exit(0);
							}
						}
#line 3123 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 1221 "abstree.y" /* yacc.c:1646  */
    {(yyval.nptr)=(yyvsp[-1].nptr);}
#line 3129 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 1222 "abstree.y" /* yacc.c:1646  */
    { 
					(yyval.nptr)=(yyvsp[0].nptr);
					(yyval.nptr)->Type=Tlookup("int");
				}
#line 3138 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 1226 "abstree.y" /* yacc.c:1646  */
    {
					Ltemp=Llookup((yyvsp[0].nptr)->Name);
					if(Ltemp!=NULL){
						(yyvsp[0].nptr)->Type=Ltemp->Type;
						(yyvsp[0].nptr)->Lentry=Ltemp;
						(yyval.nptr)=(yyvsp[0].nptr);
					}
					else if(is_classdef == 1){
						printf("Un-declared Variable or Accessing of mem fields is different10\n");
						exit(0);
					}
					else{
						Gtemp=Glookup((yyvsp[0].nptr)->Name);
						if(Gtemp==NULL){
							printf("Not Declared %s\n",(yyvsp[0].nptr)->Name);
							exit(0);
						}
						if(Gtemp->Node!=NODE_VAR){
							printf("Expected Var,Found something\n");exit(0);
						}
						(yyvsp[0].nptr)->Type=Gtemp->Type;
						(yyvsp[0].nptr)->Ctype=Gtemp->Ctype;
						(yyvsp[0].nptr)->Gentry=Gtemp;
						(yyval.nptr)=(yyvsp[0].nptr);
					}
			}
#line 3169 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 1252 "abstree.y" /* yacc.c:1646  */
    {
								if(is_classdef == 1){
									printf(" Arrays are not supported in classes\n");
									exit(0);
								}
								Gtemp=Glookup((yyvsp[-3].nptr)->Name);
								if(Gtemp==NULL){
									printf("Not Declared \n");
									exit(0);
								}
								if(Gtemp->Node!=NODE_ARR){
									printf("Expected Arr,Found something\n");exit(0);
								}
								if(Gtemp->Ctype!=NULL){
									printf("Arrays of class type won't exist\n");exit(0);
								}
								(yyvsp[-3].nptr)->Type=Gtemp->Type;
								(yyvsp[-3].nptr)->Gentry=Gtemp;
								if((yyvsp[-1].nptr)->Type!=Tlookup("int")){
									printf("Index must be integer\n");
									exit(0);
								}
								(yyval.nptr)=Treecreate((yyvsp[-3].nptr)->Type,NULL,NODE_ARR_EXPR,NULL,NULL,NULL,(yyvsp[-3].nptr),(yyvsp[-1].nptr),NULL);
							}
#line 3198 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 1276 "abstree.y" /* yacc.c:1646  */
    {(yyval.nptr)=Treecreate((yyvsp[0].nptr)->Type,(yyvsp[0].nptr)->Ctype,NODE_FIELD_EXPR,NULL,NULL,NULL,(yyvsp[0].nptr),NULL,NULL);}
#line 3204 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 1277 "abstree.y" /* yacc.c:1646  */
    {
									if(is_classdef == 1){
										printf("Method calling is wrong in classes\n");
										exit(0);
									}
									Gtemp=Glookup((yyvsp[-3].nptr)->Name);
									if(Gtemp==NULL){
										printf("Not Declared %s\n",(yyvsp[-3].nptr)->Name);
										exit(0);
									}
									if(Gtemp->Node!=NODE_FUN){
										printf("Expected FUNC,Found something\n");exit(0);
									}
									Temp=(yyvsp[-1].nptr);
									Atemp=Gtemp->Arglist;
									while(Temp!=NULL && Atemp!=NULL){
										
										if(Temp->Type!=Atemp->Type){
											printf("Confilcts in arguments\n");
											exit(0);
										}
										Temp=Temp->Next;
										Atemp=Atemp->Next;
									}
									if(Temp!=NULL || Atemp!=NULL){
										printf("Conflicts in arguments\n");
										exit(0);
									}
									(yyvsp[-3].nptr)->Gentry=Gtemp;
									(yyvsp[-3].nptr)->Type=Gtemp->Type;
									(yyval.nptr)=Treecreate(Gtemp->Type,NULL,NODE_FUNC,NULL,NULL,(yyvsp[-1].nptr),(yyvsp[-3].nptr),NULL,NULL);

								}
#line 3242 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 1310 "abstree.y" /* yacc.c:1646  */
    {(yyval.nptr)=(yyvsp[0].nptr);}
#line 3248 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 1311 "abstree.y" /* yacc.c:1646  */
    {(yyval.nptr)=(yyvsp[0].nptr);}
#line 3254 "y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 1312 "abstree.y" /* yacc.c:1646  */
    {(yyval.nptr)=(yyvsp[0].nptr);}
#line 3260 "y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 1313 "abstree.y" /* yacc.c:1646  */
    {(yyval.nptr)=(yyvsp[0].nptr);(yyval.nptr)->Type=Tlookup("str");}
#line 3266 "y.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 1315 "abstree.y" /* yacc.c:1646  */
    {
								if((yyvsp[-2].nptr)!=NULL){
									(yyval.nptr)=(yyvsp[0].nptr);
									(yyval.nptr)->Next=(yyvsp[-2].nptr);
								}
								else{
									(yyval.nptr)=(yyvsp[0].nptr);
								}
							}
#line 3280 "y.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 1324 "abstree.y" /* yacc.c:1646  */
    {(yyval.nptr)=(yyvsp[0].nptr);}
#line 3286 "y.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 1325 "abstree.y" /* yacc.c:1646  */
    {(yyval.nptr)=NULL;}
#line 3292 "y.tab.c" /* yacc.c:1646  */
    break;


#line 3296 "y.tab.c" /* yacc.c:1646  */
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
#line 1327 "abstree.y" /* yacc.c:1906  */



void yyerror(char const *s) 
{ 
     printf("yyerror - %s\n",s); exit(0);
    return ;
} 

int main(int argc,char* argv[]) 
{ 
	char* typename=(char*) malloc(sizeof(char)*10);
	strcpy(typename,"int");
	Tinstall(typename,NULL);
	typename=(char*) malloc(sizeof(char)*10);
	strcpy(typename,"bool");
	Tinstall(typename,NULL);
	typename=(char*) malloc(sizeof(char)*10);
	strcpy(typename,"str");
	Tinstall(typename,NULL);
    if(argc > 1)
    {
        fp = fopen(argv[1],"r");
        if(fp)
            yyin = fp;
    } 
    is_classdef=1; 
    yyparse(); 
    return 1; 
}
