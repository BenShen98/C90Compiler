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

#line 67 "src/C90_parser.tab.cpp" /* yacc.c:339  */

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
   by #include "C90_parser.tab.hpp".  */
#ifndef YY_YY_SRC_C90_PARSER_TAB_HPP_INCLUDED
# define YY_YY_SRC_C90_PARSER_TAB_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 1 "src/C90.y" /* yacc.c:355  */

  #include "ast.hpp"

  #include <cassert>

  extern const ast_abs * g_root; // A way of getting the AST out

  //! This is to fix problems when generating C++
  // We are declaring the functions provided by Flex, so
  // that Bison generated code can call them.
  int yylex(void);
  void yyerror(const char *);


#line 112 "src/C90_parser.tab.cpp" /* yacc.c:355  */

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    IDENTIFIER = 258,
    CONSTANT = 259,
    STRING_LITERAL = 260,
    SIZEOF = 261,
    PTR_OP = 262,
    INC_OP = 263,
    DEC_OP = 264,
    LEFT_OP = 265,
    RIGHT_OP = 266,
    LE_OP = 267,
    GE_OP = 268,
    EQ_OP = 269,
    NE_OP = 270,
    AND_OP = 271,
    OR_OP = 272,
    MUL_ASSIGN = 273,
    DIV_ASSIGN = 274,
    MOD_ASSIGN = 275,
    ADD_ASSIGN = 276,
    SUB_ASSIGN = 277,
    LEFT_ASSIGN = 278,
    RIGHT_ASSIGN = 279,
    AND_ASSIGN = 280,
    XOR_ASSIGN = 281,
    OR_ASSIGN = 282,
    TYPE_NAME = 283,
    TYPEDEF = 284,
    EXTERN = 285,
    STATIC = 286,
    AUTO = 287,
    REGISTER = 288,
    CHAR = 289,
    SHORT = 290,
    INT = 291,
    LONG = 292,
    SIGNED = 293,
    UNSIGNED = 294,
    FLOAT = 295,
    DOUBLE = 296,
    CONST = 297,
    VOLATILE = 298,
    VOID = 299,
    STRUCT = 300,
    UNION = 301,
    ENUM = 302,
    ELLIPSIS = 303,
    CASE = 304,
    DEFAULT = 305,
    IF = 306,
    ELSE = 307,
    SWITCH = 308,
    WHILE = 309,
    DO = 310,
    FOR = 311,
    GOTO = 312,
    CONTINUE = 313,
    BREAK = 314,
    RETURN = 315
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 16 "src/C90.y" /* yacc.c:355  */

  const ast_abs * expr;
  std::string *str;
  int i;
  enum_assignment en_ass;

#line 192 "src/C90_parser.tab.cpp" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SRC_C90_PARSER_TAB_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 209 "src/C90_parser.tab.cpp" /* yacc.c:358  */

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
#define YYFINAL  34
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   574

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  85
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  45
/* YYNRULES -- Number of rules.  */
#define YYNRULES  141
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  238

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   315

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    72,     2,     2,     2,    74,    67,     2,
      61,    62,    68,    69,    66,    70,    65,    73,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    80,    82,
      75,    81,    76,    79,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    63,     2,    64,    77,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    83,    78,    84,    71,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    51,    51,    52,    53,    54,    58,    59,    60,    61,
      62,    63,    64,    65,    69,    70,    74,    75,    76,    77,
      83,    84,    85,    86,    87,    88,    92,    97,    98,    99,
     100,   104,   105,   106,   110,   111,   112,   116,   117,   118,
     119,   120,   124,   125,   126,   130,   131,   135,   136,   140,
     141,   145,   146,   150,   151,   155,   156,   160,   161,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     179,   180,   184,   188,   189,   193,   194,   195,   202,   203,
     207,   208,   212,   213,   220,   221,   222,   223,   224,   225,
     226,   227,   228,   294,   299,   300,   301,   302,   305,   366,
     367,   368,   372,   373,   377,   378,   379,   380,   381,   382,
     386,   387,   388,   392,   393,   394,   395,   399,   400,   404,
     405,   409,   410,   414,   415,   416,   420,   421,   422,   423,
     427,   428,   429,   430,   431,   435,   438,   439,   443,   444,
     448,   449
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "CONSTANT",
  "STRING_LITERAL", "SIZEOF", "PTR_OP", "INC_OP", "DEC_OP", "LEFT_OP",
  "RIGHT_OP", "LE_OP", "GE_OP", "EQ_OP", "NE_OP", "AND_OP", "OR_OP",
  "MUL_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN", "ADD_ASSIGN", "SUB_ASSIGN",
  "LEFT_ASSIGN", "RIGHT_ASSIGN", "AND_ASSIGN", "XOR_ASSIGN", "OR_ASSIGN",
  "TYPE_NAME", "TYPEDEF", "EXTERN", "STATIC", "AUTO", "REGISTER", "CHAR",
  "SHORT", "INT", "LONG", "SIGNED", "UNSIGNED", "FLOAT", "DOUBLE", "CONST",
  "VOLATILE", "VOID", "STRUCT", "UNION", "ENUM", "ELLIPSIS", "CASE",
  "DEFAULT", "IF", "ELSE", "SWITCH", "WHILE", "DO", "FOR", "GOTO",
  "CONTINUE", "BREAK", "RETURN", "'('", "')'", "'['", "']'", "'.'", "','",
  "'&'", "'*'", "'+'", "'-'", "'~'", "'!'", "'/'", "'%'", "'<'", "'>'",
  "'^'", "'|'", "'?'", "':'", "'='", "';'", "'{'", "'}'", "$accept",
  "primary_expression", "postfix_expression", "argument_expression_list",
  "unary_expression", "unary_operator", "cast_expression",
  "multiplicative_expression", "additive_expression", "shift_expression",
  "relational_expression", "equality_expression", "and_expression",
  "exclusive_or_expression", "inclusive_or_expression",
  "logical_and_expression", "logical_or_expression",
  "conditional_expression", "assignment_expression", "assignment_operator",
  "expression", "constant_expression", "declaration",
  "declaration_specifiers", "init_declarator_list", "init_declarator",
  "storage_class_specifier", "type_specifier", "declarator",
  "direct_declarator", "initializer", "initializer_list", "statement",
  "labeled_statement", "compound_statement", "declaration_list",
  "statement_list", "expression_statement", "selection_statement",
  "iteration_statement", "jump_statement", "top", "translation_unit",
  "external_declaration", "function_definition", YY_NULLPTR
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,    40,    41,    91,    93,    46,    44,    38,    42,    43,
      45,   126,    33,    47,    37,    60,    62,    94,   124,    63,
      58,    61,    59,   123,   125
};
# endif

#define YYPACT_NINF -107

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-107)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     513,  -107,  -107,  -107,  -107,  -107,  -107,  -107,  -107,  -107,
    -107,  -107,  -107,     4,  -107,     5,  -107,   526,   -28,   129,
      76,   513,  -107,  -107,    27,  -107,   -56,  -107,   113,  -107,
     177,  -107,    42,   423,  -107,  -107,  -107,     4,  -107,   266,
    -107,    51,  -107,  -107,   469,   469,   469,    84,    46,    94,
     118,   353,   122,   186,   111,   115,    14,   469,  -107,  -107,
    -107,  -107,  -107,  -107,  -107,  -107,  -107,   159,    22,   469,
    -107,   -11,   -45,    40,    26,    18,   142,   146,   141,   209,
     -15,  -107,  -107,   -10,  -107,     5,  -107,  -107,  -107,   247,
      89,  -107,  -107,  -107,  -107,  -107,  -107,  -107,  -107,  -107,
     165,  -107,   160,   266,  -107,  -107,   353,  -107,  -107,   162,
     353,   469,   469,   469,   189,   387,   171,  -107,  -107,  -107,
      -5,    33,   251,  -107,  -107,   435,   469,   255,  -107,  -107,
    -107,  -107,  -107,  -107,  -107,  -107,  -107,  -107,  -107,   469,
    -107,   469,   469,   469,   469,   469,   469,   469,   469,   469,
     469,   469,   469,   469,   469,   469,   469,   469,   469,   469,
     469,  -107,  -107,  -107,   317,  -107,  -107,  -107,  -107,   -31,
    -107,   353,  -107,    67,    68,    70,   201,   387,  -107,  -107,
    -107,  -107,  -107,    75,  -107,   144,  -107,  -107,  -107,  -107,
    -107,   -11,   -11,   -45,   -45,    40,    40,    40,    40,    26,
      26,    18,   142,   146,   141,   209,   -46,  -107,  -107,   196,
    -107,  -107,   353,   353,   353,   469,   457,  -107,   469,  -107,
     469,  -107,  -107,   220,  -107,  -107,   103,   353,   108,  -107,
    -107,   353,   191,  -107,   353,  -107,  -107,  -107
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    94,    82,    83,    85,    86,    87,    88,    91,    92,
      89,    90,    84,     0,   139,     0,    77,    75,     0,    93,
       0,   135,   136,   138,     0,    73,     0,    78,    80,    76,
       0,   141,     0,     0,     1,   137,    95,     0,    74,     0,
     140,     2,     3,     4,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    20,    21,
      22,    23,    24,    25,   121,   113,     6,    16,    26,     0,
      27,    31,    34,    37,    42,    45,    47,    49,    51,    53,
      55,    57,    70,     0,   117,     0,   119,   104,   105,     0,
       0,   106,   107,   108,   109,    98,     2,    97,    26,    72,
       0,    79,    80,     0,    99,    81,     0,    17,    18,     0,
       0,     0,     0,     0,     0,     0,     0,   131,   132,   133,
       0,     0,     0,    12,    13,     0,     0,     0,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    59,     0,
      19,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   122,   115,   118,     0,   114,   120,    96,   102,     0,
     110,     0,   112,     0,     0,     0,     0,     0,   130,   134,
       5,    11,     8,     0,    14,     0,    10,    58,    28,    29,
      30,    32,    33,    35,    36,    40,    41,    38,    39,    43,
      44,    46,    48,    50,    52,    54,     0,    71,   116,     0,
     100,   111,     0,     0,     0,     0,     0,     9,     0,     7,
       0,   101,   103,   123,   125,   126,     0,     0,     0,    15,
      56,     0,     0,   128,     0,   124,   127,   129
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -107,  -107,  -107,  -107,   -33,  -107,   -63,   -77,    56,     3,
      87,   124,   134,   136,   133,   135,  -107,   -32,   -34,  -107,
     -53,   248,     1,    -1,  -107,   258,  -107,  -107,    15,  -107,
     -82,  -107,   -36,  -107,     9,  -107,   210,  -106,  -107,  -107,
    -107,  -107,  -107,   288,  -107
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    66,    67,   183,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,   139,
      83,   100,    14,    15,    26,    27,    16,    17,    18,    19,
     105,   169,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    20,    21,    22,    23
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      98,    99,   158,   120,   121,   104,   140,     1,     1,   177,
      37,   107,   108,    98,    99,   114,    29,    96,    42,    43,
     160,   168,    44,    45,   144,   145,    38,    31,    24,    85,
      28,    84,   152,   153,   220,   209,    98,    40,   148,   149,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     146,   147,   102,   210,   166,    30,   160,   141,   173,   174,
     175,   160,   142,   143,   159,    13,    13,   191,   192,   104,
     170,   216,   161,   185,   172,    57,    34,   179,   188,   189,
     190,    58,    59,    60,    61,    62,    63,    25,    85,    36,
     163,   184,    41,    42,    43,   180,   119,    44,    45,   160,
     102,   150,   151,   138,    95,   187,   206,   111,    98,    98,
      98,    98,    98,    98,    98,    98,    98,    98,    98,    98,
      98,    98,    98,    98,    98,    98,   207,   222,   166,   212,
     213,   106,   214,   160,   160,   211,   160,   217,    46,    47,
      48,   218,    49,    50,    51,    52,    53,    54,    55,    56,
      57,   195,   196,   197,   198,   112,    58,    59,    60,    61,
      62,    63,   226,   228,   110,   232,   122,   123,   124,   160,
     234,    64,    30,   165,   160,   104,   223,   224,   225,   113,
      41,    42,    43,   115,   229,    44,    45,    98,   230,   116,
      32,   233,    33,   117,    39,   235,    30,   118,   237,    96,
      42,    43,   193,   194,    44,    45,     2,     3,   219,   154,
     160,     4,     5,     6,     7,     8,     9,    10,    11,   156,
     125,    12,   126,   155,   127,   157,    46,    47,    48,   167,
      49,    50,    51,    52,    53,    54,    55,    56,    57,   199,
     200,    39,   171,   176,    58,    59,    60,    61,    62,    63,
      41,    42,    43,   178,   181,    44,    45,    57,   186,    64,
      30,    65,   215,    58,    59,    60,    61,    62,    63,    96,
      42,    43,   231,   236,    44,    45,     2,     3,   201,   103,
     221,     4,     5,     6,     7,     8,     9,    10,    11,   202,
     204,    12,   203,   205,   109,   101,    46,    47,    48,   164,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    35,
       0,     0,     0,     0,    58,    59,    60,    61,    62,    63,
      41,    42,    43,     0,     0,    44,    45,    57,     0,    64,
      30,   162,     0,    58,    59,    60,    61,    62,    63,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   103,
       0,     0,     0,     0,     0,     0,    41,    42,    43,     0,
       0,    44,    45,     0,     0,     0,    46,    47,    48,     0,
      49,    50,    51,    52,    53,    54,    55,    56,    57,     0,
       0,     0,     0,     0,    58,    59,    60,    61,    62,    63,
      96,    42,    43,     0,     0,    44,    45,     0,     0,    64,
      30,   208,    46,    47,    48,     0,    49,    50,    51,    52,
      53,    54,    55,    56,    57,     0,     0,     0,     0,     0,
      58,    59,    60,    61,    62,    63,    96,    42,    43,     0,
       0,    44,    45,     0,     0,    64,    30,     0,    96,    42,
      43,     0,     0,    44,    45,     0,     0,     0,    57,     0,
       0,     0,     0,     0,    58,    59,    60,    61,    62,    63,
      96,    42,    43,     0,     0,    44,    45,     0,     0,    64,
       0,     0,    96,    42,    43,     0,     0,    44,    45,     0,
       0,     0,     0,     0,    57,     0,     0,    97,     0,     0,
      58,    59,    60,    61,    62,    63,    57,   182,     0,     0,
       0,     0,    58,    59,    60,    61,    62,    63,     0,     0,
       0,     0,     0,     0,     0,     0,     1,     0,    57,   227,
       0,     0,     0,     0,    58,    59,    60,    61,    62,    63,
      57,     0,     0,     0,     0,     0,    58,    59,    60,    61,
      62,    63,     2,     3,     0,     0,     0,     4,     5,     6,
       7,     8,     9,    10,    11,     2,     3,    12,     0,     0,
       4,     5,     6,     7,     8,     9,    10,    11,     0,     0,
      12,     0,     0,     0,    13
};

static const yytype_int16 yycheck[] =
{
      33,    33,    17,    56,    57,    39,    69,     3,     3,   115,
      66,    44,    45,    46,    46,    51,    17,     3,     4,     5,
      66,   103,     8,     9,    69,    70,    82,    18,    13,    30,
      15,    30,    14,    15,    80,    66,    69,    28,    12,    13,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      10,    11,    37,    84,    90,    83,    66,    68,   111,   112,
     113,    66,    73,    74,    79,    61,    61,   144,   145,   103,
     106,   177,    82,   126,   110,    61,     0,    82,   141,   142,
     143,    67,    68,    69,    70,    71,    72,    82,    89,    62,
      89,   125,     3,     4,     5,    62,    82,     8,     9,    66,
      85,    75,    76,    81,    62,   139,   159,    61,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   160,   209,   164,    62,
      62,    80,    62,    66,    66,   171,    66,    62,    49,    50,
      51,    66,    53,    54,    55,    56,    57,    58,    59,    60,
      61,   148,   149,   150,   151,    61,    67,    68,    69,    70,
      71,    72,   215,   216,    80,    62,     7,     8,     9,    66,
      62,    82,    83,    84,    66,   209,   212,   213,   214,    61,
       3,     4,     5,    61,   218,     8,     9,   220,   220,     3,
      61,   227,    63,    82,    81,   231,    83,    82,   234,     3,
       4,     5,   146,   147,     8,     9,    29,    30,    64,    67,
      66,    34,    35,    36,    37,    38,    39,    40,    41,    78,
      61,    44,    63,    77,    65,    16,    49,    50,    51,    64,
      53,    54,    55,    56,    57,    58,    59,    60,    61,   152,
     153,    81,    80,    54,    67,    68,    69,    70,    71,    72,
       3,     4,     5,    82,     3,     8,     9,    61,     3,    82,
      83,    84,    61,    67,    68,    69,    70,    71,    72,     3,
       4,     5,    52,    82,     8,     9,    29,    30,   154,    83,
      84,    34,    35,    36,    37,    38,    39,    40,    41,   155,
     157,    44,   156,   158,    46,    37,    49,    50,    51,    89,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    21,
      -1,    -1,    -1,    -1,    67,    68,    69,    70,    71,    72,
       3,     4,     5,    -1,    -1,     8,     9,    61,    -1,    82,
      83,    84,    -1,    67,    68,    69,    70,    71,    72,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    83,
      -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,    -1,
      -1,     8,     9,    -1,    -1,    -1,    49,    50,    51,    -1,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    -1,
      -1,    -1,    -1,    -1,    67,    68,    69,    70,    71,    72,
       3,     4,     5,    -1,    -1,     8,     9,    -1,    -1,    82,
      83,    84,    49,    50,    51,    -1,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    -1,    -1,    -1,    -1,    -1,
      67,    68,    69,    70,    71,    72,     3,     4,     5,    -1,
      -1,     8,     9,    -1,    -1,    82,    83,    -1,     3,     4,
       5,    -1,    -1,     8,     9,    -1,    -1,    -1,    61,    -1,
      -1,    -1,    -1,    -1,    67,    68,    69,    70,    71,    72,
       3,     4,     5,    -1,    -1,     8,     9,    -1,    -1,    82,
      -1,    -1,     3,     4,     5,    -1,    -1,     8,     9,    -1,
      -1,    -1,    -1,    -1,    61,    -1,    -1,    64,    -1,    -1,
      67,    68,    69,    70,    71,    72,    61,    62,    -1,    -1,
      -1,    -1,    67,    68,    69,    70,    71,    72,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,     3,    -1,    61,    62,
      -1,    -1,    -1,    -1,    67,    68,    69,    70,    71,    72,
      61,    -1,    -1,    -1,    -1,    -1,    67,    68,    69,    70,
      71,    72,    29,    30,    -1,    -1,    -1,    34,    35,    36,
      37,    38,    39,    40,    41,    29,    30,    44,    -1,    -1,
      34,    35,    36,    37,    38,    39,    40,    41,    -1,    -1,
      44,    -1,    -1,    -1,    61
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    29,    30,    34,    35,    36,    37,    38,    39,
      40,    41,    44,    61,   107,   108,   111,   112,   113,   114,
     126,   127,   128,   129,   113,    82,   109,   110,   113,   108,
      83,   119,    61,    63,     0,   128,    62,    66,    82,    81,
     119,     3,     4,     5,     8,     9,    49,    50,    51,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    67,    68,
      69,    70,    71,    72,    82,    84,    86,    87,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   105,   107,   108,   117,   118,   119,   120,
     121,   122,   123,   124,   125,    62,     3,    64,    89,   102,
     106,   110,   113,    83,   103,   115,    80,    89,    89,   106,
      80,    61,    61,    61,   117,    61,     3,    82,    82,    82,
     105,   105,     7,     8,     9,    61,    63,    65,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    81,   104,
      91,    68,    73,    74,    69,    70,    10,    11,    12,    13,
      75,    76,    14,    15,    67,    77,    78,    16,    17,    79,
      66,    82,    84,   107,   121,    84,   117,    64,   115,   116,
     117,    80,   117,   105,   105,   105,    54,   122,    82,    82,
      62,     3,    62,    88,   103,   105,     3,   103,    91,    91,
      91,    92,    92,    93,    93,    94,    94,    94,    94,    95,
      95,    96,    97,    98,    99,   100,   105,   103,    84,    66,
      84,   117,    62,    62,    62,    61,   122,    62,    66,    64,
      80,    84,   115,   117,   117,   117,   105,    62,   105,   103,
     102,    52,    62,   117,    62,   117,    82,   117
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    85,    86,    86,    86,    86,    87,    87,    87,    87,
      87,    87,    87,    87,    88,    88,    89,    89,    89,    89,
      90,    90,    90,    90,    90,    90,    91,    92,    92,    92,
      92,    93,    93,    93,    94,    94,    94,    95,    95,    95,
      95,    95,    96,    96,    96,    97,    97,    98,    98,    99,
      99,   100,   100,   101,   101,   102,   102,   103,   103,   104,
     104,   104,   104,   104,   104,   104,   104,   104,   104,   104,
     105,   105,   106,   107,   107,   108,   108,   108,   109,   109,
     110,   110,   111,   111,   112,   112,   112,   112,   112,   112,
     112,   112,   112,   113,   114,   114,   114,   114,   114,   115,
     115,   115,   116,   116,   117,   117,   117,   117,   117,   117,
     118,   118,   118,   119,   119,   119,   119,   120,   120,   121,
     121,   122,   122,   123,   123,   123,   124,   124,   124,   124,
     125,   125,   125,   125,   125,   126,   127,   127,   128,   128,
     129,   129
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     3,     1,     4,     3,     4,
       3,     3,     2,     2,     1,     3,     1,     2,     2,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     3,
       3,     1,     3,     3,     1,     3,     3,     1,     3,     3,
       3,     3,     1,     3,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     5,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     1,     2,     3,     1,     2,     1,     1,     3,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     4,     3,     3,     1,
       3,     4,     1,     3,     1,     1,     1,     1,     1,     1,
       3,     4,     3,     2,     3,     3,     4,     1,     2,     1,
       2,     1,     2,     5,     7,     5,     5,     7,     6,     7,
       3,     2,     2,     2,     3,     1,     1,     2,     1,     1,
       3,     2
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
#line 51 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new primary_expression(0, (yyvsp[0].str)); }
#line 1546 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 52 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new primary_expression(1, (yyvsp[0].str)); }
#line 1552 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 53 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new primary_expression(2, (yyvsp[0].str)); }
#line 1558 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 54 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new primary_expression(3, (yyvsp[-1].expr)); }
#line 1564 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 58 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new postfix_expression(0, (yyvsp[0].expr)); }
#line 1570 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 59 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new postfix_expression(1, (yyvsp[-3].expr), (yyvsp[-1].expr)); }
#line 1576 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 60 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new postfix_expression(2, (yyvsp[-2].expr)); }
#line 1582 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 61 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new postfix_expression(3, (yyvsp[-3].expr), (yyvsp[-1].expr)); }
#line 1588 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 62 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new postfix_expression(4, (yyvsp[-2].expr), (yyvsp[0].str)); }
#line 1594 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 63 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new postfix_expression(5, (yyvsp[-2].expr), (yyvsp[0].str)); }
#line 1600 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 64 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new postfix_expression(6, (yyvsp[-1].expr)); }
#line 1606 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 65 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new postfix_expression(7, (yyvsp[-1].expr)); }
#line 1612 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 69 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new argument_expression_list((yyvsp[0].expr)); }
#line 1618 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 70 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new argument_expression_list((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1624 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 74 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new unary_expression(0, (yyvsp[0].expr)); }
#line 1630 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 75 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new unary_expression(1, (yyvsp[0].expr)); }
#line 1636 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 76 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new unary_expression(2, (yyvsp[0].expr)); }
#line 1642 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 77 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new unary_expression((yyvsp[-1].i), (yyvsp[0].expr)); }
#line 1648 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 83 "src/C90.y" /* yacc.c:1646  */
    { (yyval.i) = '&'; }
#line 1654 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 84 "src/C90.y" /* yacc.c:1646  */
    { (yyval.i) = '*'; }
#line 1660 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 85 "src/C90.y" /* yacc.c:1646  */
    { (yyval.i) = '+'; }
#line 1666 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 86 "src/C90.y" /* yacc.c:1646  */
    { (yyval.i) = '-'; }
#line 1672 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 87 "src/C90.y" /* yacc.c:1646  */
    { (yyval.i) = '~'; }
#line 1678 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 88 "src/C90.y" /* yacc.c:1646  */
    { (yyval.i) = '!'; }
#line 1684 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 92 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new cast_expression((yyvsp[0].expr)); }
#line 1690 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 97 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1696 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 98 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new algebra(MUL, (yyvsp[-2].expr), (yyvsp[0].expr) ); }
#line 1702 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 99 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new algebra(DIV, (yyvsp[-2].expr), (yyvsp[0].expr) ); }
#line 1708 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 100 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new algebra(MOD, (yyvsp[-2].expr), (yyvsp[0].expr) ); }
#line 1714 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 104 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1720 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 105 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new algebra(ADD, (yyvsp[-2].expr), (yyvsp[0].expr) ); }
#line 1726 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 106 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new algebra(SUB, (yyvsp[-2].expr), (yyvsp[0].expr) ); }
#line 1732 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 110 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1738 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 111 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new algebra(LEFT_, (yyvsp[-2].expr), (yyvsp[0].expr) ); }
#line 1744 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 112 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new algebra(RIGHT_, (yyvsp[-2].expr), (yyvsp[0].expr) ); }
#line 1750 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 116 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1756 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 117 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new algebra(SMALLER, (yyvsp[-2].expr), (yyvsp[0].expr) ); }
#line 1762 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 118 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new algebra(GREATER, (yyvsp[-2].expr), (yyvsp[0].expr) ); }
#line 1768 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 119 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new algebra(LE_, (yyvsp[-2].expr), (yyvsp[0].expr) ); }
#line 1774 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 120 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new algebra(GE_, (yyvsp[-2].expr), (yyvsp[0].expr) ); }
#line 1780 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 124 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1786 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 125 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new algebra(EQ_, (yyvsp[-2].expr), (yyvsp[0].expr) ); }
#line 1792 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 126 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new algebra(NE_, (yyvsp[-2].expr), (yyvsp[0].expr) ); }
#line 1798 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 130 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1804 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 131 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new algebra(AND, (yyvsp[-2].expr), (yyvsp[0].expr) ); }
#line 1810 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 135 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1816 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 136 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new algebra(XOR, (yyvsp[-2].expr), (yyvsp[0].expr) ); }
#line 1822 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 140 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1828 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 141 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new algebra(OR, (yyvsp[-2].expr), (yyvsp[0].expr) ); }
#line 1834 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 145 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1840 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 146 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new algebra(AND_, (yyvsp[-2].expr), (yyvsp[0].expr) ); }
#line 1846 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 150 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1852 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 151 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new algebra(OR_, (yyvsp[-2].expr), (yyvsp[0].expr) ); }
#line 1858 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 155 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new conditional_expression((yyvsp[0].expr)); }
#line 1864 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 156 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new conditional_expression((yyvsp[-4].expr), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1870 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 160 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new assignment_expression((yyvsp[0].expr)); }
#line 1876 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 161 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new assignment_expression((yyvsp[-2].expr), (yyvsp[-1].en_ass), (yyvsp[0].expr)); }
#line 1882 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 165 "src/C90.y" /* yacc.c:1646  */
    { (yyval.en_ass) = ASSIGN; }
#line 1888 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 166 "src/C90.y" /* yacc.c:1646  */
    { (yyval.en_ass) = MULA; }
#line 1894 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 167 "src/C90.y" /* yacc.c:1646  */
    { (yyval.en_ass) = DIVA; }
#line 1900 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 168 "src/C90.y" /* yacc.c:1646  */
    { (yyval.en_ass) = MODA; }
#line 1906 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 169 "src/C90.y" /* yacc.c:1646  */
    { (yyval.en_ass) = ADDA; }
#line 1912 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 170 "src/C90.y" /* yacc.c:1646  */
    { (yyval.en_ass) = SUBA; }
#line 1918 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 171 "src/C90.y" /* yacc.c:1646  */
    { (yyval.en_ass) = LEFTA; }
#line 1924 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 172 "src/C90.y" /* yacc.c:1646  */
    { (yyval.en_ass) = RIGHTA; }
#line 1930 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 173 "src/C90.y" /* yacc.c:1646  */
    { (yyval.en_ass) = ANDA; }
#line 1936 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 174 "src/C90.y" /* yacc.c:1646  */
    { (yyval.en_ass) = XORA; }
#line 1942 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 175 "src/C90.y" /* yacc.c:1646  */
    { (yyval.en_ass) = ORA; }
#line 1948 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 179 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new expression((yyvsp[0].expr)); }
#line 1954 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 180 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new expression((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1960 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 184 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1966 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 188 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new declaration_specifiers((yyvsp[-1].expr)); }
#line 1972 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 189 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new declaration_specifiers((yyvsp[-2].expr), (yyvsp[-1].expr)); }
#line 1978 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 193 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new declaration_specifiers((yyvsp[0].expr)); }
#line 1984 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 194 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new declaration_specifiers((yyvsp[-1].expr),(yyvsp[0].expr)); }
#line 1990 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 195 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new declaration_specifiers((yyvsp[0].expr)); }
#line 1996 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 202 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new init_declarator_list((yyvsp[0].expr)); }
#line 2002 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 203 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new init_declarator_list((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2008 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 207 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new init_declarator((yyvsp[0].expr)); }
#line 2014 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 208 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new init_declarator((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2020 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 212 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new storage_class_specifier(0); }
#line 2026 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 213 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new storage_class_specifier(1); }
#line 2032 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 220 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new type_specifier(0); }
#line 2038 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 221 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new type_specifier(1); }
#line 2044 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 222 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new type_specifier(2); }
#line 2050 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 223 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new type_specifier(3); }
#line 2056 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 224 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new type_specifier(4); }
#line 2062 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 225 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new type_specifier(5); }
#line 2068 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 226 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new type_specifier(5); }
#line 2074 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 227 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new type_specifier(7); }
#line 2080 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 228 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new type_specifier(8); }
#line 2086 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 294 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new declarator((yyvsp[0].expr)); }
#line 2092 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 299 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new direct_declarator(((yyvsp[0].str))); }
#line 2098 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 300 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new direct_declarator(1, (yyvsp[-1].expr)); }
#line 2104 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 301 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new direct_declarator(2, (yyvsp[-3].expr), (yyvsp[-1].expr)); }
#line 2110 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 302 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new direct_declarator(3, (yyvsp[-2].expr)); }
#line 2116 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 305 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new direct_declarator(5, (yyvsp[-2].expr)); }
#line 2122 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 99:
#line 366 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new initializer(0, (yyvsp[0].expr)); }
#line 2128 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 100:
#line 367 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new initializer(1, (yyvsp[-1].expr)); }
#line 2134 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 101:
#line 368 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new initializer(1, (yyvsp[-2].expr)); }
#line 2140 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 102:
#line 372 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new initializer_list((yyvsp[0].expr)); }
#line 2146 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 103:
#line 373 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new initializer_list((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2152 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 104:
#line 377 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 2158 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 105:
#line 378 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 2164 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 106:
#line 379 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 2170 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 107:
#line 380 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 2176 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 108:
#line 381 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 2182 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 110:
#line 386 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new labeled_statement(0, (yyvsp[0].expr)); }
#line 2188 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 111:
#line 387 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new labeled_statement((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2194 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 112:
#line 388 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new labeled_statement(2, (yyvsp[0].expr)); }
#line 2200 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 113:
#line 392 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new compound_statement(NULL, NULL);}
#line 2206 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 114:
#line 393 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new compound_statement(NULL, (yyvsp[-1].expr));}
#line 2212 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 115:
#line 394 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new compound_statement((yyvsp[-1].expr), NULL);}
#line 2218 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 116:
#line 395 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new compound_statement((yyvsp[-2].expr), (yyvsp[-1].expr));}
#line 2224 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 117:
#line 399 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new declaration_list((yyvsp[0].expr)); }
#line 2230 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 118:
#line 400 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new declaration_list((yyvsp[-1].expr), (yyvsp[0].expr)); }
#line 2236 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 119:
#line 404 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new statement_list((yyvsp[0].expr)); }
#line 2242 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 120:
#line 405 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new statement_list((yyvsp[-1].expr), (yyvsp[0].expr)); }
#line 2248 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 121:
#line 409 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new expression_statement(); }
#line 2254 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 122:
#line 410 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new expression_statement((yyvsp[-1].expr)); }
#line 2260 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 123:
#line 414 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new selection_statement(0, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2266 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 124:
#line 415 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new selection_statement((yyvsp[-4].expr), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2272 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 125:
#line 416 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new selection_statement(2, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2278 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 126:
#line 420 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new iteration_statement(0, (yyvsp[-2].expr), (yyvsp[0].expr) ); }
#line 2284 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 127:
#line 421 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new iteration_statement(1, (yyvsp[-5].expr), (yyvsp[-2].expr) ); }
#line 2290 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 128:
#line 422 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new iteration_statement((yyvsp[-3].expr), (yyvsp[-2].expr), (yyvsp[0].expr) ); }
#line 2296 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 129:
#line 423 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new iteration_statement((yyvsp[-4].expr), (yyvsp[-3].expr), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2302 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 130:
#line 427 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new jump_statement(0); }
#line 2308 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 131:
#line 428 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new jump_statement(1); }
#line 2314 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 132:
#line 429 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new jump_statement(2); }
#line 2320 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 133:
#line 430 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new jump_statement(3); }
#line 2326 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 134:
#line 431 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new jump_statement(4, (yyvsp[-1].expr)); }
#line 2332 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 135:
#line 435 "src/C90.y" /* yacc.c:1646  */
    { g_root=(yyvsp[0].expr); }
#line 2338 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 136:
#line 438 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new translation_unit((yyvsp[0].expr)); }
#line 2344 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 137:
#line 439 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new translation_unit((yyvsp[-1].expr), (yyvsp[0].expr)); }
#line 2350 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 138:
#line 443 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new external_declaration(0, (yyvsp[0].expr)); }
#line 2356 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 139:
#line 444 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new external_declaration(1, (yyvsp[0].expr)); }
#line 2362 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 140:
#line 448 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new function_definition((yyvsp[-2].expr),(yyvsp[-1].expr),(yyvsp[0].expr)); }
#line 2368 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 141:
#line 449 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new function_definition((yyvsp[-1].expr),(yyvsp[0].expr)); }
#line 2374 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;


#line 2378 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
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
#line 454 "src/C90.y" /* yacc.c:1906  */


const ast_abs * g_root;

const ast_abs * parseAST(void)
{
  g_root=0;
  yyparse();
  return g_root;
}
