%{
#include <stdio.h>
%}

%%

[a-zA-Z][a-zA-Z0-9]*    printf("IDENTIFIER: %s\n", yytext);
[0-9]+                  printf("NUMBER: %s\n", yytext);
"+"                     printf("PLUS OPERATOR\n");
"-"                     printf("MINUS OPERATOR\n");
"*"                     printf("MULTIPLICATION OPERATOR\n");
"/"                     printf("DIVISION OPERATOR\n");
"="                     printf("EQUALS OPERATOR\n");
"("                     printf("LEFT PARENTHESIS\n");
")"                     printf("RIGHT PARENTHESIS\n");
[ \t\n]                 /* ignore whitespace */
.                       printf("UNKNOWN CHARACTER: %s\n", yytext);

%%

int main(void) {
    yylex();
    return 0;
}
