#pragma once
// clang-format off

#include <expected>
#include <string>
#include "macro-utils/map-macro.hpp"
#include "macro-utils/zip-macro.hpp"
using str = std::string;
template<typename Ok, typename Err>
using Result = std::expected<Ok, Err>;
template<typename T>
using Err = std::unexpected<T>;
#define map_macro(macro, ...) MAP(macro, __VA_ARGS__)


#define punctuators                     \
    less,                               \
    greater,                            \
    exclamation,                        \
    plus,                               \
    minus,                              \
    asterisk,                           \
    ampersand,                          \
    negate,                             \
    percent,                            \
    hashtag,                            \
    hat,                                \
    bar,                                \
    division,                           \
    equals,                             \
    question_mark,                      \
    colon,                              \
    dot,                                \
    open_bracket,                       \
    close_bracket,                      \
    open_paren,                         \
    close_paren,                        \
    open_brace,                         \
    close_brace,                        \
    semicolon,                          \
    comma,                              \
    equals_equals,                      \
    greater_equals,                     \
    less_equals,                        \
    exclamation_equals,                 \
    plus_equals,                        \
    minus_equals,                       \
    asterisk_equals,                    \
    division_equals,                    \
    percent_equals,                     \
    ampersand_equals,                   \
    hat_equals,                         \
    bar_equals,                         \
    bar_bar,                            \
    minus_minus,                        \
    plus_plus,                          \
    hashtag_hashtag,                    \
    ampersand_ampersand,                \
    greater_greater,                    \
    less_less,                          \
    less_less_equals,                   \
    greater_greater_equals,             \
    dot_dot_dot,                        \
    minus_greater
#define keywords                        \
    auto             ,                  \
    break            ,                  \
    case             ,                  \
    char             ,                  \
    const            ,                  \
    continue         ,                  \
    default          ,                  \
    do               ,                  \
    double           ,                  \
    else             ,                  \
    enum             ,                  \
    extern           ,                  \
    float            ,                  \
    for              ,                  \
    goto             ,                  \
    if               ,                  \
    inline           ,                  \
    int              ,                  \
    long             ,                  \
    register         ,                  \
    restrict         ,                  \
    return           ,                  \
    short            ,                  \
    signed           ,                  \
    sizeof           ,                  \
    static           ,                  \
    struct           ,                  \
    switch           ,                  \
    typedef          ,                  \
    union            ,                  \
    unsigned         ,                  \
    void             ,                  \
    volatile         ,                  \
    while            ,                  \
    _Bool
#define literals                        \
    identifier,                         \
    keyword,                            \
    integer,                            \
    floating_point,                     \
    string

#define all_tokens punctuators, literals, is_EOF
//----------------------------------------------------------------
// for printing
#define symbol_reprs__  \
"<"  ,                  \
">"  ,                  \
"!"  ,                  \
"+"  ,                  \
"-"  ,                  \
"*"  ,                  \
"&"  ,                  \
"~"  ,                  \
"%"  ,                  \
"#"  ,                  \
"^"  ,                  \
"|"  ,                  \
"/"  ,                  \
"="  ,                  \
"?"  ,                  \
":"  ,                  \
"."  ,                  \
"["  ,                  \
"]"  ,                  \
"("  ,                  \
")"  ,                  \
"{"  ,                  \
"}"  ,                  \
";"  ,                  \
","  ,                  \
"==" ,                  \
">=" ,                  \
"<=" ,                  \
"!=" ,                  \
"+=" ,                  \
"-=" ,                  \
"*=" ,                  \
"/=" ,                  \
"%=" ,                  \
"&=" ,                  \
"^=" ,                  \
"|=" ,                  \
"||" ,                  \
"--" ,                  \
"++" ,                  \
"&&" ,                  \
">>" ,                  \
"<<" ,                  \
"##" ,                  \
"<<=",                  \
">>=",                  \
"...",                  \
"->" 

#define add_parens(S) (S)
#define symbol_reprs_ map_macro(add_parens, symbol_reprs__)
#define punctuators_ map_macro(add_parens, punctuators)

//-----------------------------------------------------------------------------
// for switch case usage in lexer
enum struct Symbol {
// has singular
    question_mark   =     '?',
    colon           =     ':',
    open_bracket    =     '[',
    close_bracket   =     ']',
    open_paren      =     '(',
    close_paren     =     ')',
    open_brace      =     '{',
    close_brace     =     '}',
    semicolon       =     ';',
    comma           =     ',',
    negate          =     '~',
// has equals
    exclamation     =     '!',
    asterisk        =     '*',
    percent         =     '%',
    hat             =     '^',
// has double and equals
    bar             =     '|',
    ampersand       =     '&',
    plus            =     '+',
    minus           =     '-',
    equals          =     '=',
// has triple
    dot             =     '.',
    greater         =     '>',
    less            =     '<',
    division        =     '/',
    hashtag         =     '#',
// ignore
    space           =     ' ',
    tab             =     '\t',
    r_thing         =     '\r',
    alert           =     '\a',
    newline         =     '\n',
};

#define singular                    \
    question_mark   ,               \
    colon           ,               \
    open_bracket    ,               \
    close_bracket   ,               \
    open_paren      ,               \
    close_paren     ,               \
    open_brace      ,               \
    close_brace     ,               \
    semicolon       ,               \
    negate          ,               \
    comma
#define has_equals                  \
    exclamation     ,               \
    asterisk        ,               \
    percent         ,               \
    hat
#define has_double_and_equals       \
    ampersand       ,               \
    bar,                            \
    plus            ,               \
    equals
#define has_triple                  \
    minus           ,               \
    dot             ,               \
    greater         ,               \
    division        ,               \
    less            ,               \
    hashtag         ,               \
    newline
#define ignore                      \
    space           ,               \
    tab             ,               \
    r_thing         ,               \
    alert          

#define all_symbols singular, has_equals, has_double_and_equals, has_triple, ignore
