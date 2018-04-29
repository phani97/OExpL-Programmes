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
#line 27 "abstree.y" /* yacc.c:1909  */

	struct Tnode* nptr;
	struct Typetable *type;
	struct Argstruct *arg;

#line 156 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
