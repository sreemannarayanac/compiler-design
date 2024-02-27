%{
#include <stdio.h>
%}

%%

int|float|char       { printf("Keyword: %s\n", yytext); }
[a-zA-Z_][a-zA-Z0-9_]* { printf("Identifier: %s\n", yytext); }
[0-9]+(\.[0-9]+)?     { printf("Constant: %s\n", yytext); }
[ \t\n]               ;  // Ignore whitespace and newline characters
"("                   { printf("Open Parenthesis\n"); }
")"                   { printf("Close Parenthesis\n"); }
"{"                   { printf("Open Curly Brace\n"); }
"}"                   { printf("Close Curly Brace\n"); }
"["                   { printf("Open Square Bracket\n"); }
"]"                   { printf("Close Square Bracket\n"); }
.                     { printf("Invalid token: %s\n", yytext); }

%%

int main() {
    yylex();
    return 0;
}
