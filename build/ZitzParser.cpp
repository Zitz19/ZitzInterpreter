/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "ZitzParser.y"

    #include <string>
    #include <variant>
    #include <iostream>
    #include <stdio.h>
    #include <unordered_map>
    #include <set>
    #include <algorithm>
    #include <iterator>
    #include <fstream>
    #include "ZitzInterpreter.h"

    int yylex(void);
    void yyerror(const char *);
    extern FILE * yyin;

    std::unordered_map<std::string, int> sym;

#line 90 "/home/zitz/Labs/ZitzInterpreter/build/ZitzParser.cpp"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "ZitzParser.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_NUMBER = 3,                     /* NUMBER  */
  YYSYMBOL_VARIABLE = 4,                   /* VARIABLE  */
  YYSYMBOL_TINY = 5,                       /* TINY  */
  YYSYMBOL_SMALL = 6,                      /* SMALL  */
  YYSYMBOL_NORMAL = 7,                     /* NORMAL  */
  YYSYMBOL_BIG = 8,                        /* BIG  */
  YYSYMBOL_FIELD = 9,                      /* FIELD  */
  YYSYMBOL_UNTIL = 10,                     /* UNTIL  */
  YYSYMBOL_CHECK = 11,                     /* CHECK  */
  YYSYMBOL_GO = 12,                        /* GO  */
  YYSYMBOL_RL = 13,                        /* RL  */
  YYSYMBOL_RR = 14,                        /* RR  */
  YYSYMBOL_SONAR = 15,                     /* SONAR  */
  YYSYMBOL_COMPASS = 16,                   /* COMPASS  */
  YYSYMBOL_PRINT = 17,                     /* PRINT  */
  YYSYMBOL_RETURN = 18,                    /* RETURN  */
  YYSYMBOL_ASGL = 19,                      /* ASGL  */
  YYSYMBOL_ASGR = 20,                      /* ASGR  */
  YYSYMBOL_LE = 21,                        /* LE  */
  YYSYMBOL_GE = 22,                        /* GE  */
  YYSYMBOL_NEQ = 23,                       /* NEQ  */
  YYSYMBOL_24_ = 24,                       /* '('  */
  YYSYMBOL_25_ = 25,                       /* ')'  */
  YYSYMBOL_26_ = 26,                       /* '{'  */
  YYSYMBOL_27_ = 27,                       /* '}'  */
  YYSYMBOL_28_ = 28,                       /* ','  */
  YYSYMBOL_29_ = 29,                       /* '.'  */
  YYSYMBOL_30_ = 30,                       /* '['  */
  YYSYMBOL_31_ = 31,                       /* ']'  */
  YYSYMBOL_32_ = 32,                       /* '<'  */
  YYSYMBOL_33_ = 33,                       /* '>'  */
  YYSYMBOL_34_ = 34,                       /* '='  */
  YYSYMBOL_35_ = 35,                       /* '+'  */
  YYSYMBOL_36_ = 36,                       /* '-'  */
  YYSYMBOL_37_ = 37,                       /* '*'  */
  YYSYMBOL_38_ = 38,                       /* '/'  */
  YYSYMBOL_YYACCEPT = 39,                  /* $accept  */
  YYSYMBOL_program = 40,                   /* program  */
  YYSYMBOL_function_define_field = 41,     /* function_define_field  */
  YYSYMBOL_function_define_variable = 42,  /* function_define_variable  */
  YYSYMBOL_function_define = 43,           /* function_define  */
  YYSYMBOL_function_defines = 44,          /* function_defines  */
  YYSYMBOL_parameter = 45,                 /* parameter  */
  YYSYMBOL_parameters = 46,                /* parameters  */
  YYSYMBOL_function_parameters = 47,       /* function_parameters  */
  YYSYMBOL_parameter_variable = 48,        /* parameter_variable  */
  YYSYMBOL_parameter_field = 49,           /* parameter_field  */
  YYSYMBOL_statement = 50,                 /* statement  */
  YYSYMBOL_statements = 51,                /* statements  */
  YYSYMBOL_statement_list = 52,            /* statement_list  */
  YYSYMBOL_check = 53,                     /* check  */
  YYSYMBOL_until = 54,                     /* until  */
  YYSYMBOL_variable_type = 55,             /* variable_type  */
  YYSYMBOL_function_call = 56,             /* function_call  */
  YYSYMBOL_function_call_args = 57,        /* function_call_args  */
  YYSYMBOL_exp_list = 58,                  /* exp_list  */
  YYSYMBOL_indexator = 59,                 /* indexator  */
  YYSYMBOL_variable_init = 60,             /* variable_init  */
  YYSYMBOL_variable_list = 61,             /* variable_list  */
  YYSYMBOL_field_init = 62,                /* field_init  */
  YYSYMBOL_exp_atom = 63,                  /* exp_atom  */
  YYSYMBOL_exp_bracket = 64,               /* exp_bracket  */
  YYSYMBOL_exp = 65,                       /* exp  */
  YYSYMBOL_exp_assign_left = 66,           /* exp_assign_left  */
  YYSYMBOL_exp_assign_right = 67,          /* exp_assign_right  */
  YYSYMBOL_exp_compare = 68,               /* exp_compare  */
  YYSYMBOL_exp_term = 69,                  /* exp_term  */
  YYSYMBOL_exp_factor = 70,                /* exp_factor  */
  YYSYMBOL_exp_resatom = 71                /* exp_resatom  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;


/* Second part of user prologue.  */
#line 34 "ZitzParser.y"

    ZitzInterpreter interpreter;

#line 199 "/home/zitz/Labs/ZitzInterpreter/build/ZitzParser.cpp"


#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  13
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   161

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  39
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  33
/* YYNRULES -- Number of rules.  */
#define YYNRULES  75
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  135

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   278


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      24,    25,    37,    35,    28,    36,    29,    38,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      32,    34,    33,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    30,     2,    31,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    26,     2,    27,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22,    23
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    40,    40,    50,    58,    66,    67,    71,    74,    81,
      82,    86,    87,    91,    92,    96,   104,   112,   113,   114,
     115,   116,   117,   118,   122,   123,   127,   128,   132,   136,
     140,   141,   142,   143,   147,   154,   158,   159,   163,   170,
     179,   184,   192,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   216,   220,   221,   225,   226,   230,   231,
     235,   236,   237,   238,   239,   240,   241,   245,   246,   247,
     251,   252,   253,   257,   258,   259
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "NUMBER", "VARIABLE",
  "TINY", "SMALL", "NORMAL", "BIG", "FIELD", "UNTIL", "CHECK", "GO", "RL",
  "RR", "SONAR", "COMPASS", "PRINT", "RETURN", "ASGL", "ASGR", "LE", "GE",
  "NEQ", "'('", "')'", "'{'", "'}'", "','", "'.'", "'['", "']'", "'<'",
  "'>'", "'='", "'+'", "'-'", "'*'", "'/'", "$accept", "program",
  "function_define_field", "function_define_variable", "function_define",
  "function_defines", "parameter", "parameters", "function_parameters",
  "parameter_variable", "parameter_field", "statement", "statements",
  "statement_list", "check", "until", "variable_type", "function_call",
  "function_call_args", "exp_list", "indexator", "variable_init",
  "variable_list", "field_init", "exp_atom", "exp_bracket", "exp",
  "exp_assign_left", "exp_assign_right", "exp_compare", "exp_term",
  "exp_factor", "exp_resatom", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-42)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-14)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     135,   -42,   -42,   -42,   -42,    19,     1,   -42,   -42,   -42,
     135,    14,    19,   -42,   -42,    -4,    26,     8,    11,   140,
      36,     8,    19,    50,   -42,   -42,    80,    63,    68,    19,
     -42,   -42,    65,    75,   102,   -42,    40,    91,    65,   -42,
     -42,    -7,    19,    84,    84,   -42,   -42,   -42,   -42,   -42,
      84,    84,    84,   101,   101,     3,   -42,   -42,   103,   -42,
     -42,   -42,   -42,   -42,   -42,   -42,   -42,   116,    89,     5,
      22,   -42,   -42,    97,   -42,    84,   -42,    19,   110,   124,
     -42,   -42,   126,   -42,   -42,   -42,   -42,   -42,   -42,     2,
      84,    84,    84,    84,    84,    84,    84,    84,    84,    84,
      84,    84,   -42,    67,    84,   103,    65,    65,   -42,   -42,
      84,   -42,   105,     5,     5,     5,     5,     5,     5,    22,
      22,   -42,   -42,   -42,   -42,   121,     9,   127,   128,   -42,
     -42,    84,   -42,   -42,   -42
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    30,    31,    32,    33,     0,     0,     5,     6,     7,
       2,     0,     0,     1,     8,     0,     0,    11,     0,     0,
       0,    11,     0,    14,     9,    10,     0,     0,     0,     0,
      12,    15,    24,     0,     0,    26,     0,     0,    24,    16,
      43,    44,     0,     0,     0,    48,    51,    50,    47,    49,
       0,     0,     0,     0,     0,     0,    22,    23,     0,    46,
      52,    19,    20,    73,    45,    18,    54,    56,    58,    60,
      67,    70,     4,     0,    36,     0,    34,     0,     0,     0,
      21,    17,     0,    46,    75,    74,    25,    27,    41,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     3,     0,     0,     0,    24,    24,    53,    40,
       0,    57,    59,    63,    64,    66,    61,    62,    65,    68,
      69,    71,    72,    35,    37,     0,     0,     0,     0,    39,
      38,     0,    29,    28,    42
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -42,   -42,   -42,   -42,   143,   -42,   -42,   -42,   136,   -42,
     -42,   -42,   -42,   -34,   -42,   -42,     0,   -36,   -42,   -42,
     -42,   -42,    51,   -42,   -16,   -42,   -41,   -42,    69,    70,
      37,   -33,   -15
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     6,     7,     8,     9,    10,    23,    19,    20,    24,
      25,    55,    36,    37,    56,    57,    11,    83,    76,   103,
      60,    61,    89,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      59,    13,    78,    79,    73,    12,   109,    59,    59,    80,
      81,    82,    16,   109,    59,    59,    59,    74,    15,    26,
      17,   110,    29,    75,     1,     2,     3,     4,   131,    34,
      18,    86,    87,   -13,   104,    21,    58,    84,    85,    59,
      98,    99,    77,    40,    41,     1,     2,     3,     4,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,   100,
     101,    27,   124,   125,    52,   119,   120,    59,    59,   129,
      40,    41,   127,   128,    59,    53,    54,   105,    30,    45,
      46,    47,    48,    49,    31,   121,   122,    40,    41,    32,
     134,    52,   123,    33,    35,    59,    45,    46,    47,    48,
      49,    38,    53,    54,    40,    41,    39,    88,    52,    91,
      92,    93,    94,    45,    46,    47,    48,    49,    72,    53,
      54,    95,    96,    97,   102,    52,    92,    93,    94,   113,
     114,   115,   116,   117,   118,    90,   106,    95,    96,    97,
       1,     2,     3,     4,     5,     1,     2,     3,     4,    22,
     107,   108,   130,    14,   132,   133,   126,    28,     0,   111,
       0,   112
};

static const yytype_int16 yycheck[] =
{
      36,     0,    43,    44,    38,     5,     4,    43,    44,    50,
      51,    52,    12,     4,    50,    51,    52,    24,     4,    19,
      24,    19,    22,    30,     5,     6,     7,     8,    19,    29,
       4,    28,    29,    25,    75,    24,    36,    53,    54,    75,
      35,    36,    42,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    37,
      38,    25,   103,   104,    24,    98,    99,   103,   104,   110,
       3,     4,   106,   107,   110,    35,    36,    77,    28,    12,
      13,    14,    15,    16,     4,   100,   101,     3,     4,    26,
     131,    24,    25,    25,    29,   131,    12,    13,    14,    15,
      16,    26,    35,    36,     3,     4,     4,     4,    24,    20,
      21,    22,    23,    12,    13,    14,    15,    16,    27,    35,
      36,    32,    33,    34,    27,    24,    21,    22,    23,    92,
      93,    94,    95,    96,    97,    19,    26,    32,    33,    34,
       5,     6,     7,     8,     9,     5,     6,     7,     8,     9,
      26,    25,    31,    10,    27,    27,   105,    21,    -1,    90,
      -1,    91
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     5,     6,     7,     8,     9,    40,    41,    42,    43,
      44,    55,    55,     0,    43,     4,    55,    24,     4,    46,
      47,    24,     9,    45,    48,    49,    55,    25,    47,    55,
      28,     4,    26,    25,    55,    29,    51,    52,    26,     4,
       3,     4,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    24,    35,    36,    50,    53,    54,    55,    56,
      59,    60,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    27,    52,    24,    30,    57,    55,    65,    65,
      65,    65,    65,    56,    63,    63,    28,    29,     4,    61,
      19,    20,    21,    22,    23,    32,    33,    34,    35,    36,
      37,    38,    27,    58,    65,    55,    26,    26,    25,     4,
      19,    67,    68,    69,    69,    69,    69,    69,    69,    70,
      70,    71,    71,    25,    65,    65,    61,    52,    52,    65,
      31,    19,    27,    27,    65
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    39,    40,    41,    42,    43,    43,    44,    44,    45,
      45,    46,    46,    47,    47,    48,    49,    50,    50,    50,
      50,    50,    50,    50,    51,    51,    52,    52,    53,    54,
      55,    55,    55,    55,    56,    57,    58,    58,    59,    60,
      61,    61,    62,    63,    63,    63,    63,    63,    63,    63,
      63,    63,    63,    64,    65,    65,    66,    66,    67,    67,
      68,    68,    68,    68,    68,    68,    68,    69,    69,    69,
      70,    70,    70,    71,    71,    71
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,    10,     8,     1,     1,     1,     2,     1,
       1,     0,     3,     0,     2,     2,     4,     2,     1,     1,
       1,     2,     1,     1,     0,     3,     1,     3,     5,     5,
       1,     1,     1,     1,     2,     3,     0,     2,     5,     4,
       2,     1,     6,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     1,     1,     1,     3,     1,     3,
       1,     3,     3,     3,     3,     3,     3,     1,     3,     3,
       1,     3,     3,     1,     2,     2
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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
  case 2: /* program: function_defines  */
#line 40 "ZitzParser.y"
                     { 
        interpreter.Process((yyvsp[0].nPtr)); 
        //std::vector<bool> crossings {};
        //std::cout << "\n\n";
        //ZitzInterpreter::Print($1, crossings);
        (yyval.nPtr) = (yyvsp[0].nPtr);
    }
#line 1257 "/home/zitz/Labs/ZitzInterpreter/build/ZitzParser.cpp"
    break;

  case 3: /* function_define_field: FIELD variable_type variable_type VARIABLE '(' function_parameters ')' '{' statement_list '}'  */
#line 51 "ZitzParser.y"
    {
        Node_t *var = new IdNode_t(NodeSymbol::variable, (yyvsp[-6].str));
        (yyval.nPtr) = (Node_t*) new SymNode_t(NodeSymbol::function_define_field, {(yyvsp[-8].nPtr), (yyvsp[-7].nPtr), var, (yyvsp[-4].nPtr), (yyvsp[-1].nPtr)});
    }
#line 1266 "/home/zitz/Labs/ZitzInterpreter/build/ZitzParser.cpp"
    break;

  case 4: /* function_define_variable: variable_type VARIABLE '(' function_parameters ')' '{' statement_list '}'  */
#line 59 "ZitzParser.y"
    {
        Node_t *var = new IdNode_t(NodeSymbol::variable, (yyvsp[-6].str));
        (yyval.nPtr) = (Node_t*) new SymNode_t(NodeSymbol::function_define_variable, {(yyvsp[-7].nPtr), var, (yyvsp[-4].nPtr), (yyvsp[-1].nPtr)}); 
    }
#line 1275 "/home/zitz/Labs/ZitzInterpreter/build/ZitzParser.cpp"
    break;

  case 5: /* function_define: function_define_field  */
#line 66 "ZitzParser.y"
                          { (yyval.nPtr) = (yyvsp[0].nPtr); }
#line 1281 "/home/zitz/Labs/ZitzInterpreter/build/ZitzParser.cpp"
    break;

  case 6: /* function_define: function_define_variable  */
#line 67 "ZitzParser.y"
                               { (yyval.nPtr) = (yyvsp[0].nPtr); }
#line 1287 "/home/zitz/Labs/ZitzInterpreter/build/ZitzParser.cpp"
    break;

  case 7: /* function_defines: function_define  */
#line 71 "ZitzParser.y"
                    {
        (yyval.nPtr) = (Node_t*) new SymNode_t(NodeSymbol::program, {(yyvsp[0].nPtr)});
    }
#line 1295 "/home/zitz/Labs/ZitzInterpreter/build/ZitzParser.cpp"
    break;

  case 8: /* function_defines: function_defines function_define  */
#line 74 "ZitzParser.y"
                                       { 
        (yyvsp[-1].nPtr)->ch.push_back((yyvsp[0].nPtr));
        (yyval.nPtr) = (yyvsp[-1].nPtr);
    }
#line 1304 "/home/zitz/Labs/ZitzInterpreter/build/ZitzParser.cpp"
    break;

  case 9: /* parameter: parameter_variable  */
#line 81 "ZitzParser.y"
                       { (yyval.nPtr) = (yyvsp[0].nPtr); }
#line 1310 "/home/zitz/Labs/ZitzInterpreter/build/ZitzParser.cpp"
    break;

  case 10: /* parameter: parameter_field  */
#line 82 "ZitzParser.y"
                      { (yyval.nPtr) = (yyvsp[0].nPtr); }
#line 1316 "/home/zitz/Labs/ZitzInterpreter/build/ZitzParser.cpp"
    break;

  case 11: /* parameters: %empty  */
#line 86 "ZitzParser.y"
                { (yyval.nPtr) = (Node_t*) new SymNode_t(NodeSymbol::function_parameters, {}); }
#line 1322 "/home/zitz/Labs/ZitzInterpreter/build/ZitzParser.cpp"
    break;

  case 12: /* parameters: parameters parameter ','  */
#line 87 "ZitzParser.y"
                               { (yyvsp[-2].nPtr)->ch.push_back((yyvsp[-1].nPtr)); (yyval.nPtr) = (yyvsp[-2].nPtr); }
#line 1328 "/home/zitz/Labs/ZitzInterpreter/build/ZitzParser.cpp"
    break;

  case 13: /* function_parameters: %empty  */
#line 91 "ZitzParser.y"
                { (yyval.nPtr) = (Node_t*) new SymNode_t(NodeSymbol::function_parameters, {}); }
#line 1334 "/home/zitz/Labs/ZitzInterpreter/build/ZitzParser.cpp"
    break;

  case 14: /* function_parameters: parameters parameter  */
#line 92 "ZitzParser.y"
                           { (yyvsp[-1].nPtr)->ch.push_back((yyvsp[0].nPtr)); (yyval.nPtr) = (yyvsp[-1].nPtr); }
#line 1340 "/home/zitz/Labs/ZitzInterpreter/build/ZitzParser.cpp"
    break;

  case 15: /* parameter_variable: variable_type VARIABLE  */
#line 97 "ZitzParser.y"
    {
        Node_t *var = (Node_t*) new IdNode_t(NodeSymbol::variable, (yyvsp[0].str));
        (yyval.nPtr) = (Node_t*) new SymNode_t(NodeSymbol::parameter_variable, {(yyvsp[-1].nPtr), var});
    }
#line 1349 "/home/zitz/Labs/ZitzInterpreter/build/ZitzParser.cpp"
    break;

  case 16: /* parameter_field: FIELD variable_type variable_type VARIABLE  */
#line 105 "ZitzParser.y"
    {
        Node_t *var = (Node_t*) new IdNode_t(NodeSymbol::variable, (yyvsp[0].str));
        (yyval.nPtr) = (Node_t*) new SymNode_t(NodeSymbol::parameter_field, {(yyvsp[-2].nPtr), (yyvsp[-1].nPtr), var});
    }
#line 1358 "/home/zitz/Labs/ZitzInterpreter/build/ZitzParser.cpp"
    break;

  case 17: /* statement: RETURN exp  */
#line 112 "ZitzParser.y"
               { (yyval.nPtr) = new OperNode_t(NodeSymbol::ret, RETURN, {(yyvsp[0].nPtr)}); }
#line 1364 "/home/zitz/Labs/ZitzInterpreter/build/ZitzParser.cpp"
    break;

  case 18: /* statement: exp  */
#line 113 "ZitzParser.y"
          { (yyval.nPtr) = (yyvsp[0].nPtr); }
#line 1370 "/home/zitz/Labs/ZitzInterpreter/build/ZitzParser.cpp"
    break;

  case 19: /* statement: variable_init  */
#line 114 "ZitzParser.y"
                    { (yyval.nPtr) = (yyvsp[0].nPtr); }
#line 1376 "/home/zitz/Labs/ZitzInterpreter/build/ZitzParser.cpp"
    break;

  case 20: /* statement: field_init  */
#line 115 "ZitzParser.y"
                 { (yyval.nPtr) = (yyvsp[0].nPtr); }
#line 1382 "/home/zitz/Labs/ZitzInterpreter/build/ZitzParser.cpp"
    break;

  case 21: /* statement: PRINT exp  */
#line 116 "ZitzParser.y"
                { (yyval.nPtr) = new OperNode_t(NodeSymbol::print, PRINT, {(yyvsp[0].nPtr)}); }
#line 1388 "/home/zitz/Labs/ZitzInterpreter/build/ZitzParser.cpp"
    break;

  case 22: /* statement: check  */
#line 117 "ZitzParser.y"
            { (yyval.nPtr) = (yyvsp[0].nPtr); }
#line 1394 "/home/zitz/Labs/ZitzInterpreter/build/ZitzParser.cpp"
    break;

  case 23: /* statement: until  */
#line 118 "ZitzParser.y"
            { (yyval.nPtr) = (yyvsp[0].nPtr); }
#line 1400 "/home/zitz/Labs/ZitzInterpreter/build/ZitzParser.cpp"
    break;

  case 24: /* statements: %empty  */
#line 122 "ZitzParser.y"
                { (yyval.nPtr) = (Node_t*) new SymNode_t(NodeSymbol::statement_list, {}); }
#line 1406 "/home/zitz/Labs/ZitzInterpreter/build/ZitzParser.cpp"
    break;

  case 25: /* statements: statements statement ','  */
#line 123 "ZitzParser.y"
                               { (yyvsp[-2].nPtr)->ch.push_back((yyvsp[-1].nPtr)); (yyval.nPtr) = (yyvsp[-2].nPtr); }
#line 1412 "/home/zitz/Labs/ZitzInterpreter/build/ZitzParser.cpp"
    break;

  case 26: /* statement_list: '.'  */
#line 127 "ZitzParser.y"
        { (yyval.nPtr) = (Node_t*) new SymNode_t(NodeSymbol::statement_list, {}); }
#line 1418 "/home/zitz/Labs/ZitzInterpreter/build/ZitzParser.cpp"
    break;

  case 27: /* statement_list: statements statement '.'  */
#line 128 "ZitzParser.y"
                               { (yyvsp[-2].nPtr)->ch.push_back((yyvsp[-1].nPtr)); (yyval.nPtr) = (yyvsp[-2].nPtr); }
#line 1424 "/home/zitz/Labs/ZitzInterpreter/build/ZitzParser.cpp"
    break;

  case 28: /* check: CHECK exp '{' statement_list '}'  */
#line 132 "ZitzParser.y"
                                     { (yyval.nPtr) = (Node_t*) new OperNode_t(NodeSymbol::check, CHECK, {(yyvsp[-3].nPtr), (yyvsp[-1].nPtr)}); }
#line 1430 "/home/zitz/Labs/ZitzInterpreter/build/ZitzParser.cpp"
    break;

  case 29: /* until: UNTIL exp '{' statement_list '}'  */
#line 136 "ZitzParser.y"
                                     { (yyval.nPtr) = (Node_t*) new OperNode_t(NodeSymbol::until, UNTIL, {(yyvsp[-3].nPtr), (yyvsp[-1].nPtr)}); }
#line 1436 "/home/zitz/Labs/ZitzInterpreter/build/ZitzParser.cpp"
    break;

  case 30: /* variable_type: TINY  */
#line 140 "ZitzParser.y"
         { (yyval.nPtr) = (Node_t*) new SymNode_t(NodeSymbol::tiny, {}); }
#line 1442 "/home/zitz/Labs/ZitzInterpreter/build/ZitzParser.cpp"
    break;

  case 31: /* variable_type: SMALL  */
#line 141 "ZitzParser.y"
            { (yyval.nPtr) = (Node_t*) new SymNode_t(NodeSymbol::small, {}); }
#line 1448 "/home/zitz/Labs/ZitzInterpreter/build/ZitzParser.cpp"
    break;

  case 32: /* variable_type: NORMAL  */
#line 142 "ZitzParser.y"
             { (yyval.nPtr) = (Node_t*) new SymNode_t(NodeSymbol::normal, {}); }
#line 1454 "/home/zitz/Labs/ZitzInterpreter/build/ZitzParser.cpp"
    break;

  case 33: /* variable_type: BIG  */
#line 143 "ZitzParser.y"
          { (yyval.nPtr) = (Node_t*) new SymNode_t(NodeSymbol::big, {}); }
#line 1460 "/home/zitz/Labs/ZitzInterpreter/build/ZitzParser.cpp"
    break;

  case 34: /* function_call: VARIABLE function_call_args  */
#line 147 "ZitzParser.y"
                                {
        Node_t *var = (Node_t*) new IdNode_t(NodeSymbol::variable, (yyvsp[-1].str));
        (yyval.nPtr) = (Node_t*) new SymNode_t(NodeSymbol::function_call, {var, (yyvsp[0].nPtr)});
    }
#line 1469 "/home/zitz/Labs/ZitzInterpreter/build/ZitzParser.cpp"
    break;

  case 35: /* function_call_args: '(' exp_list ')'  */
#line 154 "ZitzParser.y"
                     { (yyval.nPtr) = (yyvsp[-1].nPtr); }
#line 1475 "/home/zitz/Labs/ZitzInterpreter/build/ZitzParser.cpp"
    break;

  case 36: /* exp_list: %empty  */
#line 158 "ZitzParser.y"
                { (yyval.nPtr) = (Node_t*) new SymNode_t(NodeSymbol::function_call_args, {}); }
#line 1481 "/home/zitz/Labs/ZitzInterpreter/build/ZitzParser.cpp"
    break;

  case 37: /* exp_list: exp_list exp  */
#line 159 "ZitzParser.y"
                   { (yyvsp[-1].nPtr)->ch.push_back((yyvsp[0].nPtr)); (yyval.nPtr) = (yyvsp[-1].nPtr); }
#line 1487 "/home/zitz/Labs/ZitzInterpreter/build/ZitzParser.cpp"
    break;

  case 38: /* indexator: VARIABLE '[' exp exp ']'  */
#line 163 "ZitzParser.y"
                             { 
        Node_t *var = new IdNode_t(NodeSymbol::variable, (yyvsp[-4].str));
        (yyval.nPtr) = (Node_t*) new SymNode_t(NodeSymbol::indexator, {var, (yyvsp[-2].nPtr), (yyvsp[-1].nPtr)}); 
    }
#line 1496 "/home/zitz/Labs/ZitzInterpreter/build/ZitzParser.cpp"
    break;

  case 39: /* variable_init: variable_type variable_list ASGL exp  */
#line 171 "ZitzParser.y"
    { 
        (yyvsp[-2].nPtr)->ch.insert((yyvsp[-2].nPtr)->ch.begin(), (yyvsp[-3].nPtr));
        (yyvsp[-2].nPtr)->ch.push_back((yyvsp[0].nPtr));
        (yyval.nPtr) = (yyvsp[-2].nPtr);
    }
#line 1506 "/home/zitz/Labs/ZitzInterpreter/build/ZitzParser.cpp"
    break;

  case 40: /* variable_list: variable_list VARIABLE  */
#line 180 "ZitzParser.y"
    { 
        Node_t *var = (Node_t*) new IdNode_t(NodeSymbol::variable, (yyvsp[0].str));
        (yyvsp[-1].nPtr)->ch.push_back(var); (yyval.nPtr) = (yyvsp[-1].nPtr); 
    }
#line 1515 "/home/zitz/Labs/ZitzInterpreter/build/ZitzParser.cpp"
    break;

  case 41: /* variable_list: VARIABLE  */
#line 185 "ZitzParser.y"
    { 
        Node_t *var = (Node_t*) new IdNode_t(NodeSymbol::variable, (yyvsp[0].str));
        (yyval.nPtr) = (Node_t*) new SymNode_t(NodeSymbol::variable_init, {var});
    }
#line 1524 "/home/zitz/Labs/ZitzInterpreter/build/ZitzParser.cpp"
    break;

  case 42: /* field_init: FIELD variable_type variable_type variable_list ASGL exp  */
#line 193 "ZitzParser.y"
    {
        (yyvsp[-2].nPtr)->symbol = NodeSymbol::field_init;
        (yyvsp[-2].nPtr)->ch.insert((yyvsp[-2].nPtr)->ch.begin(), (yyvsp[-3].nPtr));
        (yyvsp[-2].nPtr)->ch.insert((yyvsp[-2].nPtr)->ch.begin(), (yyvsp[-4].nPtr));
        (yyvsp[-2].nPtr)->ch.push_back((yyvsp[0].nPtr));
        (yyval.nPtr) = (yyvsp[-2].nPtr);
    }
#line 1536 "/home/zitz/Labs/ZitzInterpreter/build/ZitzParser.cpp"
    break;

  case 43: /* exp_atom: NUMBER  */
#line 203 "ZitzParser.y"
           { (yyval.nPtr) = (Node_t *) new ConNode_t(NodeSymbol::number, (yyvsp[0].str)); }
#line 1542 "/home/zitz/Labs/ZitzInterpreter/build/ZitzParser.cpp"
    break;

  case 44: /* exp_atom: VARIABLE  */
#line 204 "ZitzParser.y"
               { (yyval.nPtr) = (Node_t *) new IdNode_t(NodeSymbol::variable, (yyvsp[0].str)); }
#line 1548 "/home/zitz/Labs/ZitzInterpreter/build/ZitzParser.cpp"
    break;

  case 45: /* exp_atom: exp_bracket  */
#line 205 "ZitzParser.y"
                  { (yyval.nPtr) = (yyvsp[0].nPtr); }
#line 1554 "/home/zitz/Labs/ZitzInterpreter/build/ZitzParser.cpp"
    break;

  case 46: /* exp_atom: function_call  */
#line 206 "ZitzParser.y"
                    { (yyval.nPtr) = (yyvsp[0].nPtr); }
#line 1560 "/home/zitz/Labs/ZitzInterpreter/build/ZitzParser.cpp"
    break;

  case 47: /* exp_atom: SONAR  */
#line 207 "ZitzParser.y"
            { (yyval.nPtr) = (Node_t *) new OperNode_t(NodeSymbol::sonar, SONAR, {}); }
#line 1566 "/home/zitz/Labs/ZitzInterpreter/build/ZitzParser.cpp"
    break;

  case 48: /* exp_atom: GO  */
#line 208 "ZitzParser.y"
         { (yyval.nPtr) = (Node_t *) new OperNode_t(NodeSymbol::go, GO, {}); }
#line 1572 "/home/zitz/Labs/ZitzInterpreter/build/ZitzParser.cpp"
    break;

  case 49: /* exp_atom: COMPASS  */
#line 209 "ZitzParser.y"
              { (yyval.nPtr) = (Node_t *) new OperNode_t(NodeSymbol::compass, COMPASS, {}); }
#line 1578 "/home/zitz/Labs/ZitzInterpreter/build/ZitzParser.cpp"
    break;

  case 50: /* exp_atom: RR  */
#line 210 "ZitzParser.y"
         { (yyval.nPtr) = (Node_t *) new OperNode_t(NodeSymbol::rr, RR, {}); }
#line 1584 "/home/zitz/Labs/ZitzInterpreter/build/ZitzParser.cpp"
    break;

  case 51: /* exp_atom: RL  */
#line 211 "ZitzParser.y"
         { (yyval.nPtr) = (Node_t *) new OperNode_t(NodeSymbol::rl, RL, {}); }
#line 1590 "/home/zitz/Labs/ZitzInterpreter/build/ZitzParser.cpp"
    break;

  case 52: /* exp_atom: indexator  */
#line 212 "ZitzParser.y"
                { (yyval.nPtr) = (yyvsp[0].nPtr); }
#line 1596 "/home/zitz/Labs/ZitzInterpreter/build/ZitzParser.cpp"
    break;

  case 53: /* exp_bracket: '(' exp ')'  */
#line 216 "ZitzParser.y"
                { (yyval.nPtr) = (yyvsp[-1].nPtr); }
#line 1602 "/home/zitz/Labs/ZitzInterpreter/build/ZitzParser.cpp"
    break;

  case 54: /* exp: exp_assign_left  */
#line 220 "ZitzParser.y"
                    { (yyval.nPtr) = (yyvsp[0].nPtr); }
#line 1608 "/home/zitz/Labs/ZitzInterpreter/build/ZitzParser.cpp"
    break;

  case 55: /* exp: function_call  */
#line 221 "ZitzParser.y"
                    { (yyval.nPtr) = (yyvsp[0].nPtr); }
#line 1614 "/home/zitz/Labs/ZitzInterpreter/build/ZitzParser.cpp"
    break;

  case 56: /* exp_assign_left: exp_assign_right  */
#line 225 "ZitzParser.y"
                     { (yyval.nPtr) = (yyvsp[0].nPtr); }
#line 1620 "/home/zitz/Labs/ZitzInterpreter/build/ZitzParser.cpp"
    break;

  case 57: /* exp_assign_left: exp_assign_right ASGL exp_assign_right  */
#line 226 "ZitzParser.y"
                                             { (yyval.nPtr) = (Node_t*) new SymNode_t(NodeSymbol::exp_assign_left, {(yyvsp[-2].nPtr), (yyvsp[0].nPtr)}); }
#line 1626 "/home/zitz/Labs/ZitzInterpreter/build/ZitzParser.cpp"
    break;

  case 58: /* exp_assign_right: exp_compare  */
#line 230 "ZitzParser.y"
                { (yyval.nPtr) = (yyvsp[0].nPtr); }
#line 1632 "/home/zitz/Labs/ZitzInterpreter/build/ZitzParser.cpp"
    break;

  case 59: /* exp_assign_right: exp_compare ASGR exp_compare  */
#line 231 "ZitzParser.y"
                                   { (yyval.nPtr) = (Node_t*) new SymNode_t(NodeSymbol::exp_assign_right, {(yyvsp[-2].nPtr), (yyvsp[0].nPtr)}); }
#line 1638 "/home/zitz/Labs/ZitzInterpreter/build/ZitzParser.cpp"
    break;

  case 60: /* exp_compare: exp_term  */
#line 235 "ZitzParser.y"
             { (yyval.nPtr) = (yyvsp[0].nPtr); }
#line 1644 "/home/zitz/Labs/ZitzInterpreter/build/ZitzParser.cpp"
    break;

  case 61: /* exp_compare: exp_compare '<' exp_term  */
#line 236 "ZitzParser.y"
                               { (yyval.nPtr) = (Node_t*) new SymNode_t(NodeSymbol::lt, {(yyvsp[-2].nPtr), (yyvsp[0].nPtr)}); }
#line 1650 "/home/zitz/Labs/ZitzInterpreter/build/ZitzParser.cpp"
    break;

  case 62: /* exp_compare: exp_compare '>' exp_term  */
#line 237 "ZitzParser.y"
                               { (yyval.nPtr) = (Node_t*) new SymNode_t(NodeSymbol::gt, {(yyvsp[-2].nPtr), (yyvsp[0].nPtr)}); }
#line 1656 "/home/zitz/Labs/ZitzInterpreter/build/ZitzParser.cpp"
    break;

  case 63: /* exp_compare: exp_compare LE exp_term  */
#line 238 "ZitzParser.y"
                              { (yyval.nPtr) = (Node_t*) new SymNode_t(NodeSymbol::le, {(yyvsp[-2].nPtr), (yyvsp[0].nPtr)}); }
#line 1662 "/home/zitz/Labs/ZitzInterpreter/build/ZitzParser.cpp"
    break;

  case 64: /* exp_compare: exp_compare GE exp_term  */
#line 239 "ZitzParser.y"
                              { (yyval.nPtr) = (Node_t*) new SymNode_t(NodeSymbol::ge, {(yyvsp[-2].nPtr), (yyvsp[0].nPtr)}); }
#line 1668 "/home/zitz/Labs/ZitzInterpreter/build/ZitzParser.cpp"
    break;

  case 65: /* exp_compare: exp_compare '=' exp_term  */
#line 240 "ZitzParser.y"
                               { (yyval.nPtr) = (Node_t*) new SymNode_t(NodeSymbol::eq, {(yyvsp[-2].nPtr), (yyvsp[0].nPtr)}); }
#line 1674 "/home/zitz/Labs/ZitzInterpreter/build/ZitzParser.cpp"
    break;

  case 66: /* exp_compare: exp_compare NEQ exp_term  */
#line 241 "ZitzParser.y"
                               { (yyval.nPtr) = (Node_t*) new SymNode_t(NodeSymbol::neq, {(yyvsp[-2].nPtr), (yyvsp[0].nPtr)}); }
#line 1680 "/home/zitz/Labs/ZitzInterpreter/build/ZitzParser.cpp"
    break;

  case 67: /* exp_term: exp_factor  */
#line 245 "ZitzParser.y"
               { (yyval.nPtr) = (yyvsp[0].nPtr); }
#line 1686 "/home/zitz/Labs/ZitzInterpreter/build/ZitzParser.cpp"
    break;

  case 68: /* exp_term: exp_term '+' exp_factor  */
#line 246 "ZitzParser.y"
                              { (yyval.nPtr) = (Node_t*) new SymNode_t(NodeSymbol::plus, {(yyvsp[-2].nPtr), (yyvsp[0].nPtr)}); }
#line 1692 "/home/zitz/Labs/ZitzInterpreter/build/ZitzParser.cpp"
    break;

  case 69: /* exp_term: exp_term '-' exp_factor  */
#line 247 "ZitzParser.y"
                              { (yyval.nPtr) = (Node_t*) new SymNode_t(NodeSymbol::minus, {(yyvsp[-2].nPtr), (yyvsp[0].nPtr)}); }
#line 1698 "/home/zitz/Labs/ZitzInterpreter/build/ZitzParser.cpp"
    break;

  case 70: /* exp_factor: exp_resatom  */
#line 251 "ZitzParser.y"
                { (yyval.nPtr) = (yyvsp[0].nPtr); }
#line 1704 "/home/zitz/Labs/ZitzInterpreter/build/ZitzParser.cpp"
    break;

  case 71: /* exp_factor: exp_factor '*' exp_resatom  */
#line 252 "ZitzParser.y"
                                 { (yyval.nPtr) = (Node_t*) new SymNode_t(NodeSymbol::mult, {(yyvsp[-2].nPtr), (yyvsp[0].nPtr)}); }
#line 1710 "/home/zitz/Labs/ZitzInterpreter/build/ZitzParser.cpp"
    break;

  case 72: /* exp_factor: exp_factor '/' exp_resatom  */
#line 253 "ZitzParser.y"
                                 { (yyval.nPtr) = (Node_t*) new SymNode_t(NodeSymbol::div, {(yyvsp[-2].nPtr), (yyvsp[0].nPtr)}); }
#line 1716 "/home/zitz/Labs/ZitzInterpreter/build/ZitzParser.cpp"
    break;

  case 73: /* exp_resatom: exp_atom  */
#line 257 "ZitzParser.y"
             { (yyval.nPtr) = (yyvsp[0].nPtr); }
#line 1722 "/home/zitz/Labs/ZitzInterpreter/build/ZitzParser.cpp"
    break;

  case 74: /* exp_resatom: '-' exp_atom  */
#line 258 "ZitzParser.y"
                   { (yyval.nPtr) = (Node_t*) new SymNode_t(NodeSymbol::minus, {(yyvsp[0].nPtr)}); }
#line 1728 "/home/zitz/Labs/ZitzInterpreter/build/ZitzParser.cpp"
    break;

  case 75: /* exp_resatom: '+' exp_atom  */
#line 259 "ZitzParser.y"
                   { (yyval.nPtr) = (Node_t*) new SymNode_t(NodeSymbol::plus, {(yyvsp[0].nPtr)}); }
#line 1734 "/home/zitz/Labs/ZitzInterpreter/build/ZitzParser.cpp"
    break;


#line 1738 "/home/zitz/Labs/ZitzInterpreter/build/ZitzParser.cpp"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 262 "ZitzParser.y"

void yyerror(const char *s) {
    fprintf(stderr, "%s\n", s);
}

bool compareFiles(const std::string& p1, const std::string& p2) {
  std::ifstream f1(p1, std::ifstream::binary|std::ifstream::ate);
  std::ifstream f2(p2, std::ifstream::binary|std::ifstream::ate);

  if (f1.fail() || f2.fail()) {
    std::cout << "Files wasn't found\n";
    return false; //file problem
  }

  //seek back to beginning and use std::equal to compare contents
  f1.seekg(0, std::ifstream::beg);
  f2.seekg(0, std::ifstream::beg);
  return std::equal(std::istreambuf_iterator<char>(f1.rdbuf()),
                    std::istreambuf_iterator<char>(),
                    std::istreambuf_iterator<char>(f2.rdbuf()));
}

int main(int argc, char *argv[]) {
    std::set<std::string> flags;
    std::string filename;

    if (argc > 1)
    {
        for (int i = 1; i < argc; i++)
        {
            std::string flag(argv[i]);
            flags.insert(flag);
        }
    }

#ifdef YYDEBUG
    if (flags.find("--debug") != flags.end())
    {
        yydebug = 1;
    }
#endif

    if (flags.find("--test") != flags.end())
    {
        std::cout << "Hello, from ZitzInterpreter!\n\nPlease, enter the number of test: ";
        std::string test_number;
        std::cin >> test_number;
        filename = "../Programs/ParserTest_" + test_number + ".ztz";
        interpreter.robot.Initialize(0);
        interpreter.SetOutFile("../Programs/ParserResult_" + test_number + ".txt");
        yyin = fopen(filename.c_str(), "r");
        yyparse();
        fclose(yyin);
        if (compareFiles("../Programs/ParserResult_" + test_number + ".txt", "../Programs/ParserResult_" + test_number + "_TEST.txt"))
        {
            std::cout << "Successful testing!\n";
        }
        else
        {
            std::cout << "Something went wrong.\n";
        }
    }
    else {
        std::cout << "Hello, from ZitzInterpreter!\n\nPlease, enter the name of program: ";
        std::string progName;
        std::cin >> progName;
        filename = "../Programs/" + progName + ".ztz";
        std::cout << "\nPrint the maze number or print 'NO': ";
        std::string map_number;
        std::cin >> map_number;
        if (map_number != "NO")
        {
            interpreter.robot.Initialize(std::stoi(map_number));
        }
        yyin = fopen(filename.c_str(), "r");
        yyparse();
        fclose(yyin);
    }
    return 0;
} 
