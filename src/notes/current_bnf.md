
Current structure for the AST parser in BNF format

- Top level

<program> ::= <function>

- Statements

<statement> ::= <jump-statement>
              | <expression-statement>

<jump-statement> ::= "return" {<expression>}? ";"
                   | "continue" ";"
                   | "break" ";"

<expression-statement> = <expression> ";"

---
---
---
- Expressions
```c
// an expression is not directly modelled as a NodeKind
// an initializer may have an expression in it
// also note that <assignment> doesnt follow C99's specification
```

<expression> ::= <assignment> 

<assignment> ::= <equality> | {"=" <assignment>}?

<equality> ::= <relational> {"==" <relational> | "!=" <relational> }*

<relational> ::= <add> { <relational-op>  <add> }*

<add> ::=  <multiplication> { "+" <multiplication> | "-" <multiplication> }*

<multiplication> ::=  <unary> { \"*" <unary> |"/" <unary> }*

<unary> ::= <unary-op> <unary> 
          | <primary>

<primary> ::= "(" <equality> ")"
            | <identifier> 
            | <literal>

---
---
---
- Declarations

-> A declaration is used to introduce identifiers into the program and specify their meaning/properties

<declaration> ::= <variable-declaration> ";"
                | <function-declaration> ";"

<variable-declaration> ::= 
            {<declaration-specifier>}+ <declarator-list> {"=" <initializer>}?

<function-declaration> ::= 
            {<declaration-specifier>}+ <ptr-and-declarator> 
            "(" {<parameter-list>}? ")" {<compound-statement>}?

<declarator> ::= <identifier>
               | <declarator> "(" {<parameter-list>}? ")"
               | <declarator> \[ {<constant-expression>}? \]

<declaration-specifier> ::= <type-qualifier> 
                          | <type-specifier>

<ptr-and-declarator> ::= {<pointer>}? <declarator> 

<declarator-list> ::= <ptr-and-declarator>
                    | <ptr-and-declarator>, <declarator-list>



---
---
---
- Misc definitions
<unary-op> ::= - 
             | ! 
             | ~ 
             | +
<relational-op> ::= < 
                  | > 
                  | <=
                  | >=
<type-specifier> ::= void
                   | char
                   | short
                   | int
                   | long
                   | float
                   | double
                   | signed
                   | unsigned
                   | <struct-or-union-specifier>
                   | <enum-specifier>
                   | <typedef-name>

<pointer> ::= " * " {<type-qualifier>}* {<pointer>}?

---
---
---
- Parameters 
NOTE: haven't added "..." yet

-> a parameter is considered a declaration

<parameter-list> ::= <parameter>
                   | <parameter-list> "," <parameter> 

<parameter> ::= <type-specifier> <identifier> 



---
```c
int a = 1, *p = NULL, f(void), (*pf)(double);
// the type specifier is "int"

// declarator "a" defines an object of type int
//   initializer "=1" provides its initial value

// declarator "*p" defines an object of type pointer to int
//   initializer "=NULL" provides its initial value

// declarator "f(void)" declares a function
//   taking void and returning int

// declarator "(*pf)(double)" defines an object of type pointer to function 
//   taking double and returning int

struct C
{
    int member; // "int" is the type specifier
                // "member" is the declarator
} obj, *pObj = &obj;
// "struct C { int member; }" is the type specifier

// declarator "obj" defines an object of type struct C

// declarator "*pObj" declares a pointer to C,

// initializer "= &obj" provides the initial value for that pointer
```
---
---
---

