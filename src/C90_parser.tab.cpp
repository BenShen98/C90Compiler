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
#define YYFINAL  39
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   705

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  85
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  53
/* YYNRULES -- Number of rules.  */
#define YYNRULES  163
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  272

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
      78,    79,    83,    84,    85,    86,    87,    88,    92,    97,
      98,    99,   100,   104,   105,   106,   110,   111,   112,   116,
     117,   118,   119,   120,   124,   125,   126,   130,   131,   135,
     136,   140,   141,   145,   146,   150,   151,   155,   156,   160,
     161,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   179,   180,   184,   188,   189,   193,   194,   195,
     196,   202,   203,   207,   208,   212,   213,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   255,   256,   294,   295,
     299,   300,   301,   302,   303,   305,   309,   311,   322,   327,
     328,   332,   334,   344,   345,   348,   349,   350,   354,   356,
     358,   366,   367,   368,   372,   373,   377,   378,   379,   380,
     381,   382,   386,   387,   388,   392,   393,   394,   395,   399,
     400,   404,   405,   409,   410,   414,   415,   416,   420,   421,
     422,   423,   427,   428,   429,   430,   431,   435,   438,   439,
     443,   444,   448,   449
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
  "storage_class_specifier", "type_specifier", "specifier_qualifier_list",
  "declarator", "direct_declarator", "pointer", "parameter_type_list",
  "parameter_list", "parameter_declaration", "type_name",
  "abstract_declarator", "direct_abstract_declarator", "initializer",
  "initializer_list", "statement", "labeled_statement",
  "compound_statement", "declaration_list", "statement_list",
  "expression_statement", "selection_statement", "iteration_statement",
  "jump_statement", "top", "translation_unit", "external_declaration",
  "function_definition", YY_NULLPTR
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

#define YYPACT_NINF -117

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-117)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       7,  -117,  -117,  -117,  -117,  -117,  -117,  -117,  -117,  -117,
    -117,  -117,  -117,    25,   -16,  -117,    24,   661,   661,   -53,
       8,    30,    59,     7,  -117,  -117,   -22,  -117,  -117,    -9,
    -117,   -58,  -117,  -117,   219,  -117,   141,   535,     8,  -117,
    -117,  -117,    25,  -117,   308,  -117,    -8,  -117,  -117,   605,
     617,   617,   617,    14,    44,    55,   111,   431,   113,   194,
     117,   129,   465,   617,  -117,  -117,  -117,  -117,  -117,  -117,
    -117,  -117,  -117,    46,   134,   617,  -117,    71,    96,   184,
      37,   191,   165,   156,   157,   218,     9,  -117,  -117,    33,
    -117,    24,  -117,  -117,  -117,   289,   359,  -117,  -117,  -117,
    -117,  -117,    25,   174,   171,  -117,  -117,  -117,  -117,  -117,
     175,  -117,   159,   308,  -117,  -117,   431,   519,  -117,  -117,
    -117,   158,   431,   617,   617,   617,   196,   501,   163,  -117,
    -117,  -117,    80,    75,   248,  -117,  -117,   573,   617,   249,
    -117,  -117,  -117,  -117,  -117,  -117,  -117,  -117,  -117,  -117,
    -117,   617,  -117,   617,   617,   617,   617,   617,   617,   617,
     617,   617,   617,   617,   617,   617,   617,   617,   617,   617,
     617,   617,   617,  -117,  -117,  -117,   395,  -117,  -117,  -117,
    -117,   661,  -117,  -117,   -10,  -117,    26,    40,   199,   431,
    -117,   101,   102,   121,   201,   501,  -117,  -117,  -117,  -117,
    -117,   124,  -117,    38,  -117,  -117,  -117,  -117,  -117,    71,
      71,    96,    96,   184,   184,   184,   184,    37,    37,   191,
     165,   156,   157,   218,   -49,  -117,  -117,  -117,   238,  -117,
    -117,    40,   617,    79,  -117,   202,  -117,  -117,   431,   431,
     431,   617,   589,  -117,   617,  -117,   617,  -117,  -117,   204,
     200,   202,   617,   215,  -117,  -117,   126,   431,   127,  -117,
    -117,  -117,  -117,   207,   431,   203,  -117,   431,  -117,  -117,
    -117,  -117
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   100,    85,    86,    88,    89,    90,    91,    94,    95,
      92,    93,    87,     0,   106,   161,     0,    79,    77,     0,
      98,     0,     0,   157,   158,   160,     0,   107,    75,     0,
      81,    83,    80,    78,     0,   163,     0,     0,    99,     1,
     159,   101,     0,    76,     0,   162,     2,     3,     4,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    22,    23,    24,    25,    26,    27,
     143,   135,     6,    16,    28,     0,    29,    33,    36,    39,
      44,    47,    49,    51,    53,    55,    57,    59,    72,     0,
     139,     0,   141,   126,   127,     0,     0,   128,   129,   130,
     131,   105,   112,     0,   108,   109,     2,   103,    28,    74,
       0,    82,    83,     0,   121,    84,     0,     0,    20,    17,
      18,     0,     0,     0,     0,     0,     0,     0,     0,   153,
     154,   155,     0,     0,     0,    12,    13,     0,     0,     0,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      61,     0,    19,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   144,   137,   140,     0,   136,   142,   111,
     104,     0,   102,   124,     0,   132,    97,   113,     0,     0,
     134,     0,     0,     0,     0,     0,   152,   156,     5,    11,
       8,     0,    14,     0,    10,    60,    30,    31,    32,    34,
      35,    37,    38,    42,    43,    40,    41,    45,    46,    48,
      50,    52,    54,    56,     0,    73,   138,   110,     0,   122,
      96,     0,     0,   115,   114,   116,    21,   133,     0,     0,
       0,     0,     0,     9,     0,     7,     0,   123,   125,     0,
       0,   117,     0,   145,   147,   148,     0,     0,     0,    15,
      58,   118,   119,     0,     0,     0,   150,     0,   120,   146,
     149,   151
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -117,  -117,  -117,  -117,   -36,  -117,   -73,    52,    62,   -13,
      66,   115,   116,   114,   131,   145,  -117,   -34,   -37,  -117,
     -28,   -48,    -5,   -12,  -117,   242,  -117,  -109,   110,    -4,
     283,   -14,  -117,  -117,   139,  -117,   100,    99,   -92,  -117,
     -38,  -117,     1,  -117,   239,  -116,  -117,  -117,  -117,  -117,
    -117,   312,  -117
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    72,    73,   201,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,   151,
      89,   110,    15,    16,    29,    30,    17,    18,   187,    19,
      20,    21,   103,   104,   105,   188,   234,   235,   115,   184,
      92,    93,    94,    95,    96,    97,    98,    99,   100,    22,
      23,    24,    25
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
      27,   108,   152,   109,   121,    32,    33,   114,   186,    26,
       1,   195,    31,   118,   119,   120,   108,   172,   109,   126,
      35,   183,    91,    44,   102,    34,   170,     1,     1,    90,
      34,   246,    45,     1,   132,   133,     2,     3,   112,   108,
      41,     4,     5,     6,     7,     8,     9,    10,    11,   160,
     161,    12,    14,   134,   135,   136,   228,    42,   178,    39,
       4,     5,     6,     7,     8,     9,    10,    11,    13,    36,
      12,    37,   116,    43,   229,    14,   114,   186,   185,   242,
     206,   207,   208,    91,   190,    13,    13,   112,   171,   133,
     175,    13,    14,    14,   122,   191,   192,   193,   179,   172,
     202,   231,   245,   232,   172,   123,    28,   137,    14,   138,
     203,   139,   162,   163,   205,   173,   124,   108,   108,   108,
     108,   108,   108,   108,   108,   108,   108,   108,   108,   108,
     108,   108,   108,   108,   108,   225,   248,   198,   178,   153,
     231,   172,   232,   224,   154,   155,   172,   213,   214,   215,
     216,   237,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   197,   238,   239,   156,   157,   172,   172,   102,
       2,     3,   125,   233,   127,     4,     5,     6,     7,     8,
       9,    10,    11,   240,   250,    12,   243,   172,   265,   267,
     244,   114,   172,   172,   158,   159,   108,   128,   109,   129,
     253,   254,   255,   101,   263,   164,   165,   259,   209,   210,
     108,   130,   260,   256,   258,   150,   108,   233,   109,   266,
     211,   212,    46,    47,    48,    49,   269,    50,    51,   271,
     217,   218,   166,   167,   169,   168,   180,   181,   189,   182,
      44,   106,    47,    48,    49,   196,    50,    51,     2,     3,
     194,   199,   204,     4,     5,     6,     7,     8,     9,    10,
      11,   236,   241,    12,   262,   252,   261,   264,    52,    53,
      54,   268,    55,    56,    57,    58,    59,    60,    61,    62,
      63,   219,   221,   220,   111,   270,    64,    65,    66,    67,
      68,    69,    46,    47,    48,    49,   230,    50,    51,    63,
     222,    70,    34,    71,    38,    64,    65,    66,    67,    68,
      69,   106,    47,    48,    49,   223,    50,    51,     2,     3,
     227,   113,   247,     4,     5,     6,     7,     8,     9,    10,
      11,   249,   251,    12,   176,    40,     0,     0,    52,    53,
      54,     0,    55,    56,    57,    58,    59,    60,    61,    62,
      63,     0,     0,     0,     0,     0,    64,    65,    66,    67,
      68,    69,    46,    47,    48,    49,     0,    50,    51,    63,
       0,    70,    34,   174,     0,    64,    65,    66,    67,    68,
      69,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   113,     0,     0,     0,     0,     0,     0,    46,    47,
      48,    49,     0,    50,    51,     0,     0,     0,    52,    53,
      54,     0,    55,    56,    57,    58,    59,    60,    61,    62,
      63,     0,     0,     0,     0,     0,    64,    65,    66,    67,
      68,    69,     0,     0,    46,    47,    48,    49,     0,    50,
      51,    70,    34,   177,    52,    53,    54,     0,    55,    56,
      57,    58,    59,    60,    61,    62,    63,     0,     0,     0,
       0,     0,    64,    65,    66,    67,    68,    69,   106,    47,
      48,    49,     0,    50,    51,     0,     0,    70,    34,   226,
      52,    53,    54,     0,    55,    56,    57,    58,    59,    60,
      61,    62,    63,     0,     0,     0,     0,     0,    64,    65,
      66,    67,    68,    69,   106,    47,    48,    49,     0,    50,
      51,     0,     0,    70,    34,     0,     0,     0,     0,     0,
       0,     0,   106,    47,    48,    49,    63,    50,    51,     0,
       0,     0,    64,    65,    66,    67,    68,    69,   106,    47,
      48,    49,     0,    50,    51,     0,     0,   131,     0,     0,
       0,     0,     0,     4,     5,     6,     7,     8,     9,    10,
      11,     0,    63,    12,     0,     0,     0,     0,    64,    65,
      66,    67,    68,    69,     0,     0,   106,    47,    48,    49,
      63,    50,    51,    70,     0,     0,    64,    65,    66,    67,
      68,    69,   106,    47,    48,    49,    63,    50,    51,   107,
       0,     0,    64,    65,    66,    67,    68,    69,   106,    47,
      48,    49,     0,    50,    51,     0,     0,     0,     0,     0,
     106,    47,    48,    49,     0,    50,    51,     0,     0,     0,
       0,     0,     0,     0,    63,   200,     0,     0,     0,     0,
      64,    65,    66,    67,    68,    69,     0,     0,     0,     0,
      63,   257,     0,     0,     0,     0,    64,    65,    66,    67,
      68,    69,     0,     0,     0,     0,   117,     0,     0,     0,
       0,     0,    64,    65,    66,    67,    68,    69,    63,     0,
       0,     0,     0,     0,    64,    65,    66,    67,    68,    69,
       2,     3,     0,     0,     0,     4,     5,     6,     7,     8,
       9,    10,    11,     0,     0,    12
};

static const yytype_int16 yycheck[] =
{
      14,    37,    75,    37,    52,    17,    18,    44,   117,    13,
       3,   127,    16,    49,    50,    51,    52,    66,    52,    57,
      19,   113,    34,    81,    36,    83,    17,     3,     3,    34,
      83,    80,    31,     3,    62,    63,    29,    30,    42,    75,
      62,    34,    35,    36,    37,    38,    39,    40,    41,    12,
      13,    44,    68,     7,     8,     9,    66,    66,    96,     0,
      34,    35,    36,    37,    38,    39,    40,    41,    61,    61,
      44,    63,    80,    82,    84,    68,   113,   186,   116,   195,
     153,   154,   155,    95,   122,    61,    61,    91,    79,   117,
      95,    61,    68,    68,    80,   123,   124,   125,   102,    66,
     137,    61,    64,    63,    66,    61,    82,    61,    68,    63,
     138,    65,    75,    76,   151,    82,    61,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   172,   228,    62,   176,    68,
      61,    66,    63,   171,    73,    74,    66,   160,   161,   162,
     163,   189,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    82,    62,    62,    69,    70,    66,    66,   181,
      29,    30,    61,   187,    61,    34,    35,    36,    37,    38,
      39,    40,    41,    62,   232,    44,    62,    66,    62,    62,
      66,   228,    66,    66,    10,    11,   232,     3,   232,    82,
     238,   239,   240,    62,   252,    14,    15,   244,   156,   157,
     246,    82,   246,   241,   242,    81,   252,   231,   252,   257,
     158,   159,     3,     4,     5,     6,   264,     8,     9,   267,
     164,   165,    67,    77,    16,    78,    62,    66,    80,    64,
      81,     3,     4,     5,     6,    82,     8,     9,    29,    30,
      54,     3,     3,    34,    35,    36,    37,    38,    39,    40,
      41,    62,    61,    44,    64,    63,    62,    52,    49,    50,
      51,    64,    53,    54,    55,    56,    57,    58,    59,    60,
      61,   166,   168,   167,    42,    82,    67,    68,    69,    70,
      71,    72,     3,     4,     5,     6,   186,     8,     9,    61,
     169,    82,    83,    84,    21,    67,    68,    69,    70,    71,
      72,     3,     4,     5,     6,   170,     8,     9,    29,    30,
     181,    83,    84,    34,    35,    36,    37,    38,    39,    40,
      41,   231,   233,    44,    95,    23,    -1,    -1,    49,    50,
      51,    -1,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    -1,    -1,    -1,    -1,    -1,    67,    68,    69,    70,
      71,    72,     3,     4,     5,     6,    -1,     8,     9,    61,
      -1,    82,    83,    84,    -1,    67,    68,    69,    70,    71,
      72,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    83,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,
       5,     6,    -1,     8,     9,    -1,    -1,    -1,    49,    50,
      51,    -1,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    -1,    -1,    -1,    -1,    -1,    67,    68,    69,    70,
      71,    72,    -1,    -1,     3,     4,     5,     6,    -1,     8,
       9,    82,    83,    84,    49,    50,    51,    -1,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    -1,    -1,    -1,
      -1,    -1,    67,    68,    69,    70,    71,    72,     3,     4,
       5,     6,    -1,     8,     9,    -1,    -1,    82,    83,    84,
      49,    50,    51,    -1,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    -1,    -1,    -1,    -1,    -1,    67,    68,
      69,    70,    71,    72,     3,     4,     5,     6,    -1,     8,
       9,    -1,    -1,    82,    83,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,     6,    61,     8,     9,    -1,
      -1,    -1,    67,    68,    69,    70,    71,    72,     3,     4,
       5,     6,    -1,     8,     9,    -1,    -1,    82,    -1,    -1,
      -1,    -1,    -1,    34,    35,    36,    37,    38,    39,    40,
      41,    -1,    61,    44,    -1,    -1,    -1,    -1,    67,    68,
      69,    70,    71,    72,    -1,    -1,     3,     4,     5,     6,
      61,     8,     9,    82,    -1,    -1,    67,    68,    69,    70,
      71,    72,     3,     4,     5,     6,    61,     8,     9,    64,
      -1,    -1,    67,    68,    69,    70,    71,    72,     3,     4,
       5,     6,    -1,     8,     9,    -1,    -1,    -1,    -1,    -1,
       3,     4,     5,     6,    -1,     8,     9,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    61,    62,    -1,    -1,    -1,    -1,
      67,    68,    69,    70,    71,    72,    -1,    -1,    -1,    -1,
      61,    62,    -1,    -1,    -1,    -1,    67,    68,    69,    70,
      71,    72,    -1,    -1,    -1,    -1,    61,    -1,    -1,    -1,
      -1,    -1,    67,    68,    69,    70,    71,    72,    61,    -1,
      -1,    -1,    -1,    -1,    67,    68,    69,    70,    71,    72,
      29,    30,    -1,    -1,    -1,    34,    35,    36,    37,    38,
      39,    40,    41,    -1,    -1,    44
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    29,    30,    34,    35,    36,    37,    38,    39,
      40,    41,    44,    61,    68,   107,   108,   111,   112,   114,
     115,   116,   134,   135,   136,   137,   114,   116,    82,   109,
     110,   114,   108,   108,    83,   127,    61,    63,   115,     0,
     136,    62,    66,    82,    81,   127,     3,     4,     5,     6,
       8,     9,    49,    50,    51,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    67,    68,    69,    70,    71,    72,
      82,    84,    86,    87,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   105,
     107,   108,   125,   126,   127,   128,   129,   130,   131,   132,
     133,    62,   108,   117,   118,   119,     3,    64,    89,   102,
     106,   110,   114,    83,   103,   123,    80,    61,    89,    89,
      89,   106,    80,    61,    61,    61,   125,    61,     3,    82,
      82,    82,   105,   105,     7,     8,     9,    61,    63,    65,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      81,   104,    91,    68,    73,    74,    69,    70,    10,    11,
      12,    13,    75,    76,    14,    15,    67,    77,    78,    16,
      17,    79,    66,    82,    84,   107,   129,    84,   125,   114,
      62,    66,    64,   123,   124,   125,   112,   113,   120,    80,
     125,   105,   105,   105,    54,   130,    82,    82,    62,     3,
      62,    88,   103,   105,     3,   103,    91,    91,    91,    92,
      92,    93,    93,    94,    94,    94,    94,    95,    95,    96,
      97,    98,    99,   100,   105,   103,    84,   119,    66,    84,
     113,    61,    63,   116,   121,   122,    62,   125,    62,    62,
      62,    61,   130,    62,    66,    64,    80,    84,   123,   121,
     106,   122,    63,   125,   125,   125,   105,    62,   105,   103,
     102,    62,    64,   106,    52,    62,   125,    62,    64,   125,
      82,   125
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    85,    86,    86,    86,    86,    87,    87,    87,    87,
      87,    87,    87,    87,    88,    88,    89,    89,    89,    89,
      89,    89,    90,    90,    90,    90,    90,    90,    91,    92,
      92,    92,    92,    93,    93,    93,    94,    94,    94,    95,
      95,    95,    95,    95,    96,    96,    96,    97,    97,    98,
      98,    99,    99,   100,   100,   101,   101,   102,   102,   103,
     103,   104,   104,   104,   104,   104,   104,   104,   104,   104,
     104,   104,   105,   105,   106,   107,   107,   108,   108,   108,
     108,   109,   109,   110,   110,   111,   111,   112,   112,   112,
     112,   112,   112,   112,   112,   112,   113,   113,   114,   114,
     115,   115,   115,   115,   115,   115,   116,   116,   117,   118,
     118,   119,   119,   120,   120,   121,   121,   121,   122,   122,
     122,   123,   123,   123,   124,   124,   125,   125,   125,   125,
     125,   125,   126,   126,   126,   127,   127,   127,   127,   128,
     128,   129,   129,   130,   130,   131,   131,   131,   132,   132,
     132,   132,   133,   133,   133,   133,   133,   134,   135,   135,
     136,   136,   137,   137
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     3,     1,     4,     3,     4,
       3,     3,     2,     2,     1,     3,     1,     2,     2,     2,
       2,     4,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     3,     3,     1,     3,     3,     1,     3,     3,     1,
       3,     3,     3,     3,     1,     3,     3,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     5,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     1,     2,     3,     1,     2,     1,
       2,     1,     3,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     1,     1,     2,
       1,     3,     4,     3,     4,     3,     1,     2,     1,     1,
       3,     2,     1,     1,     2,     1,     1,     2,     3,     3,
       4,     1,     3,     4,     1,     3,     1,     1,     1,     1,
       1,     1,     3,     4,     3,     2,     3,     3,     4,     1,
       2,     1,     2,     1,     2,     5,     7,     5,     5,     7,
       6,     7,     3,     2,     2,     2,     3,     1,     1,     2,
       1,     1,     3,     2
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
#line 1595 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 52 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new primary_expression(1, (yyvsp[0].str)); }
#line 1601 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 53 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new primary_expression(2, (yyvsp[0].str)); }
#line 1607 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 54 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new primary_expression(3, (yyvsp[-1].expr)); }
#line 1613 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 58 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1619 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 59 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new postfix_expression(1, (yyvsp[-3].expr), (yyvsp[-1].expr)); }
#line 1625 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 60 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new postfix_expression(2, (yyvsp[-2].expr)); }
#line 1631 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 61 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new postfix_expression(3, (yyvsp[-3].expr), (yyvsp[-1].expr)); }
#line 1637 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 62 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new postfix_expression(4, (yyvsp[-2].expr), (yyvsp[0].str)); }
#line 1643 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 63 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new postfix_expression(5, (yyvsp[-2].expr), (yyvsp[0].str)); }
#line 1649 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 64 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new postfix_expression(6, (yyvsp[-1].expr)); }
#line 1655 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 65 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new postfix_expression(7, (yyvsp[-1].expr)); }
#line 1661 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 69 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1667 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 70 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new argument_expression_list((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1673 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 74 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1679 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 75 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new unary_expression(1, (yyvsp[0].expr)); }
#line 1685 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 76 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new unary_expression(2, (yyvsp[0].expr)); }
#line 1691 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 77 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new unary_expression((yyvsp[-1].i), (yyvsp[0].expr)); }
#line 1697 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 78 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new unary_expression(3, (yyvsp[0].expr)); }
#line 1703 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 79 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new unary_expression(4, (yyvsp[-1].expr)); }
#line 1709 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 83 "src/C90.y" /* yacc.c:1646  */
    { (yyval.i) = '&'; }
#line 1715 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 84 "src/C90.y" /* yacc.c:1646  */
    { (yyval.i) = '*'; }
#line 1721 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 85 "src/C90.y" /* yacc.c:1646  */
    { (yyval.i) = '+'; }
#line 1727 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 86 "src/C90.y" /* yacc.c:1646  */
    { (yyval.i) = '-'; }
#line 1733 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 87 "src/C90.y" /* yacc.c:1646  */
    { (yyval.i) = '~'; }
#line 1739 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 88 "src/C90.y" /* yacc.c:1646  */
    { (yyval.i) = '!'; }
#line 1745 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 92 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new cast_expression((yyvsp[0].expr)); }
#line 1751 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 97 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1757 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 98 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new algebra(MUL, (yyvsp[-2].expr), (yyvsp[0].expr) ); }
#line 1763 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 99 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new algebra(DIV, (yyvsp[-2].expr), (yyvsp[0].expr) ); }
#line 1769 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 100 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new algebra(MOD, (yyvsp[-2].expr), (yyvsp[0].expr) ); }
#line 1775 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 104 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1781 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 105 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new algebra(ADD, (yyvsp[-2].expr), (yyvsp[0].expr) ); }
#line 1787 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 106 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new algebra(SUB, (yyvsp[-2].expr), (yyvsp[0].expr) ); }
#line 1793 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 110 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1799 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 111 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new algebra(LEFT_, (yyvsp[-2].expr), (yyvsp[0].expr) ); }
#line 1805 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 112 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new algebra(RIGHT_, (yyvsp[-2].expr), (yyvsp[0].expr) ); }
#line 1811 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 116 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1817 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 117 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new algebra(SMALLER, (yyvsp[-2].expr), (yyvsp[0].expr) ); }
#line 1823 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 118 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new algebra(GREATER, (yyvsp[-2].expr), (yyvsp[0].expr) ); }
#line 1829 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 119 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new algebra(LE_, (yyvsp[-2].expr), (yyvsp[0].expr) ); }
#line 1835 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 120 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new algebra(GE_, (yyvsp[-2].expr), (yyvsp[0].expr) ); }
#line 1841 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 124 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1847 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 125 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new algebra(EQ_, (yyvsp[-2].expr), (yyvsp[0].expr) ); }
#line 1853 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 126 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new algebra(NE_, (yyvsp[-2].expr), (yyvsp[0].expr) ); }
#line 1859 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 130 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1865 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 131 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new algebra(AND, (yyvsp[-2].expr), (yyvsp[0].expr) ); }
#line 1871 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 135 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1877 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 136 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new algebra(XOR, (yyvsp[-2].expr), (yyvsp[0].expr) ); }
#line 1883 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 140 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1889 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 141 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new algebra(OR, (yyvsp[-2].expr), (yyvsp[0].expr) ); }
#line 1895 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 145 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1901 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 146 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new algebra(AND_, (yyvsp[-2].expr), (yyvsp[0].expr) ); }
#line 1907 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 150 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1913 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 151 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new algebra(OR_, (yyvsp[-2].expr), (yyvsp[0].expr) ); }
#line 1919 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 155 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new conditional_expression((yyvsp[0].expr)); }
#line 1925 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 156 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new conditional_expression((yyvsp[-4].expr), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 1931 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 160 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new assignment_expression((yyvsp[0].expr)); }
#line 1937 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 161 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new assignment_expression((yyvsp[-2].expr), (yyvsp[-1].en_ass), (yyvsp[0].expr)); }
#line 1943 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 165 "src/C90.y" /* yacc.c:1646  */
    { (yyval.en_ass) = ASSIGN; }
#line 1949 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 166 "src/C90.y" /* yacc.c:1646  */
    { (yyval.en_ass) = MULA; }
#line 1955 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 167 "src/C90.y" /* yacc.c:1646  */
    { (yyval.en_ass) = DIVA; }
#line 1961 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 168 "src/C90.y" /* yacc.c:1646  */
    { (yyval.en_ass) = MODA; }
#line 1967 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 169 "src/C90.y" /* yacc.c:1646  */
    { (yyval.en_ass) = ADDA; }
#line 1973 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 170 "src/C90.y" /* yacc.c:1646  */
    { (yyval.en_ass) = SUBA; }
#line 1979 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 171 "src/C90.y" /* yacc.c:1646  */
    { (yyval.en_ass) = LEFTA; }
#line 1985 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 172 "src/C90.y" /* yacc.c:1646  */
    { (yyval.en_ass) = RIGHTA; }
#line 1991 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 173 "src/C90.y" /* yacc.c:1646  */
    { (yyval.en_ass) = ANDA; }
#line 1997 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 174 "src/C90.y" /* yacc.c:1646  */
    { (yyval.en_ass) = XORA; }
#line 2003 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 175 "src/C90.y" /* yacc.c:1646  */
    { (yyval.en_ass) = ORA; }
#line 2009 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 179 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 2015 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 180 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new expression((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2021 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 184 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new constant_expression((yyvsp[0].expr)); }
#line 2027 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 188 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new declaration((yyvsp[-1].expr)); }
#line 2033 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 189 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new declaration((yyvsp[-2].expr), (yyvsp[-1].expr)); }
#line 2039 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 193 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 2045 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 194 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new declaration_specifiers((yyvsp[-1].expr),(yyvsp[0].expr)); }
#line 2051 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 195 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 2057 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 196 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new declaration_specifiers((yyvsp[-1].expr),(yyvsp[0].expr)); }
#line 2063 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 202 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 2069 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 203 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new init_declarator_list((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2075 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 207 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new init_declarator((yyvsp[0].expr)); }
#line 2081 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 208 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new init_declarator((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2087 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 212 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new storage_class_specifier(0); }
#line 2093 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 213 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new storage_class_specifier(1); }
#line 2099 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 220 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new type_specifier(0); }
#line 2105 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 221 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new type_specifier(1); }
#line 2111 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 222 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new type_specifier(2); }
#line 2117 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 223 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new type_specifier(3); }
#line 2123 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 224 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new type_specifier(4); }
#line 2129 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 225 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new type_specifier(5); }
#line 2135 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 226 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new type_specifier(5); }
#line 2141 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 227 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new type_specifier(7); }
#line 2147 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 228 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new type_specifier(8); }
#line 2153 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 255 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new specifier_qualifier_list((yyvsp[-1].expr),(yyvsp[0].expr)); }
#line 2159 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 256 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new specifier_qualifier_list((yyvsp[0].expr)); }
#line 2165 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 294 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new declarator((yyvsp[0].expr)); }
#line 2171 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 99:
#line 295 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new declarator((yyvsp[-1].i), (yyvsp[0].expr)); }
#line 2177 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 100:
#line 299 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new direct_declarator((yyvsp[0].str)); }
#line 2183 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 101:
#line 300 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new direct_declarator(1, (yyvsp[-1].expr)); }
#line 2189 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 102:
#line 301 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new direct_declarator(2, (yyvsp[-3].expr), (yyvsp[-1].expr)); }
#line 2195 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 103:
#line 302 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new direct_declarator(3, (yyvsp[-2].expr)); }
#line 2201 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 104:
#line 303 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new direct_declarator(4, (yyvsp[-3].expr), (yyvsp[-1].expr)); }
#line 2207 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 105:
#line 305 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new direct_declarator(5, (yyvsp[-2].expr)); }
#line 2213 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 106:
#line 309 "src/C90.y" /* yacc.c:1646  */
    { (yyval.i) = 1; }
#line 2219 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 107:
#line 311 "src/C90.y" /* yacc.c:1646  */
    { (yyval.i) = 1 + (yyvsp[0].i);}
#line 2225 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 108:
#line 322 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr)=(yyvsp[0].expr); }
#line 2231 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 109:
#line 327 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 2237 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 110:
#line 328 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new parameter_list((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2243 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 111:
#line 332 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new parameter_declaration(0, (yyvsp[-1].expr), (yyvsp[0].expr)); }
#line 2249 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 112:
#line 334 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new parameter_declaration((yyvsp[0].expr)); }
#line 2255 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 113:
#line 344 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new type_name((yyvsp[0].expr)); }
#line 2261 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 114:
#line 345 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new type_name((yyvsp[-1].expr), (yyvsp[0].expr)); }
#line 2267 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 115:
#line 348 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new abstract_declarator(0); }
#line 2273 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 116:
#line 349 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new abstract_declarator(1, (yyvsp[0].expr)); }
#line 2279 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 117:
#line 350 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new abstract_declarator(2, (yyvsp[0].expr)); }
#line 2285 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 118:
#line 354 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[-1].expr); }
#line 2291 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 119:
#line 356 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new direct_abstract_declarator(2, (yyvsp[-1].expr)); }
#line 2297 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 120:
#line 358 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new direct_abstract_declarator(3, (yyvsp[-3].expr), (yyvsp[-1].expr)); }
#line 2303 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 121:
#line 366 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new initializer(0, (yyvsp[0].expr)); }
#line 2309 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 122:
#line 367 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new initializer(1, (yyvsp[-1].expr)); }
#line 2315 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 123:
#line 368 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new initializer(1, (yyvsp[-2].expr)); }
#line 2321 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 124:
#line 372 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 2327 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 125:
#line 373 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new initializer_list((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2333 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 126:
#line 377 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 2339 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 127:
#line 378 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 2345 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 128:
#line 379 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 2351 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 129:
#line 380 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 2357 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 130:
#line 381 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 2363 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 132:
#line 386 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new labeled_statement(0, (yyvsp[0].expr)); }
#line 2369 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 133:
#line 387 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new labeled_statement((yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2375 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 134:
#line 388 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new labeled_statement(2, (yyvsp[0].expr)); }
#line 2381 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 135:
#line 392 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new compound_statement(NULL, NULL);}
#line 2387 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 136:
#line 393 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new compound_statement(NULL, (yyvsp[-1].expr));}
#line 2393 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 137:
#line 394 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new compound_statement((yyvsp[-1].expr), NULL);}
#line 2399 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 138:
#line 395 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new compound_statement((yyvsp[-2].expr), (yyvsp[-1].expr));}
#line 2405 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 139:
#line 399 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 2411 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 140:
#line 400 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new declaration_list((yyvsp[-1].expr), (yyvsp[0].expr)); }
#line 2417 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 141:
#line 404 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 2423 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 142:
#line 405 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new statement_list((yyvsp[-1].expr), (yyvsp[0].expr)); }
#line 2429 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 143:
#line 409 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new expression_statement(); }
#line 2435 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 144:
#line 410 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new expression_statement((yyvsp[-1].expr)); }
#line 2441 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 145:
#line 414 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new selection_statement(0, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2447 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 146:
#line 415 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new selection_statement((yyvsp[-4].expr), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2453 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 147:
#line 416 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new selection_statement(2, (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2459 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 148:
#line 420 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new iteration_statement(0, (yyvsp[-2].expr), (yyvsp[0].expr) ); }
#line 2465 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 149:
#line 421 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new iteration_statement(1, (yyvsp[-5].expr), (yyvsp[-2].expr) ); }
#line 2471 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 150:
#line 422 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new iteration_statement((yyvsp[-3].expr), (yyvsp[-2].expr), (yyvsp[0].expr) ); }
#line 2477 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 151:
#line 423 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new iteration_statement((yyvsp[-4].expr), (yyvsp[-3].expr), (yyvsp[-2].expr), (yyvsp[0].expr)); }
#line 2483 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 152:
#line 427 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new jump_statement(0); }
#line 2489 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 153:
#line 428 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new jump_statement(1); }
#line 2495 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 154:
#line 429 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new jump_statement(2); }
#line 2501 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 155:
#line 430 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new jump_statement(3); }
#line 2507 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 156:
#line 431 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new jump_statement(4, (yyvsp[-1].expr)); }
#line 2513 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 157:
#line 435 "src/C90.y" /* yacc.c:1646  */
    { g_root=(yyvsp[0].expr); }
#line 2519 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 158:
#line 438 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 2525 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 159:
#line 439 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new translation_unit((yyvsp[-1].expr), (yyvsp[0].expr)); }
#line 2531 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 160:
#line 443 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new external_declaration(0, (yyvsp[0].expr)); }
#line 2537 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 161:
#line 444 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new external_declaration(1, (yyvsp[0].expr)); }
#line 2543 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 162:
#line 448 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new function_definition((yyvsp[-2].expr),(yyvsp[-1].expr),(yyvsp[0].expr)); }
#line 2549 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 163:
#line 449 "src/C90.y" /* yacc.c:1646  */
    { (yyval.expr) = new function_definition((yyvsp[-1].expr),(yyvsp[0].expr)); }
#line 2555 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
    break;


#line 2559 "src/C90_parser.tab.cpp" /* yacc.c:1646  */
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
