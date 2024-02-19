%{
#include <stdio.h>
%}

/* Regular expression for C identifiers */
identifier [a-zA-Z_][a-zA-Z0-9_]*

/* List of C keywords */
keyword "auto"|"break"|"case"|"char"|"const"|"continue"|"default"|"do"|"double"|"else"|"enum"|"extern"|"float"|"for"|"goto"|"if"|"int"|"long"|"register"|"return"|"short"|"signed"|"sizeof"|"static"|"struct"|"switch"|"typedef"|"union"|"unsigned"|"void"|"volatile"|"while"

%%

{keyword}    { printf("Keyword: %s\n", yytext); }
{identifier} { printf("Identifier: %s\n", yytext); }
[\n\t ]+     /* Ignore whitespace */
.            { /* Ignore other characters */ }

%%

int main(int argc, char **argv)
{
    ++argv, --argc;  /* skip over program name */
    if (argc > 0)
        yyin = fopen(argv[0], "r");
    else
        yyin = stdin;

    yylex();
}
