%{
#include <stdio.h>
%}

%%

int|float|char|void      { fprintf(yyout, "Keyword: %s\n", yytext); }
"if"|"else"|"while"|"for" { fprintf(yyout, "Control Keyword: %s\n", yytext); }
"=="|"!="|"<="|">="|"<"|">" { fprintf(yyout, "Relational Operator: %s\n", yytext); }
[a-zA-Z_][a-zA-Z0-9_]*   { fprintf(yyout, "Identifier: %s\n", yytext); }
[0-9]+(\.[0-9]+)?        { fprintf(yyout, "Constant: %s\n", yytext); }
[+\-*/%]                 { fprintf(yyout, "Arithmetic Operator: %s\n", yytext); }
"="                      { fprintf(yyout, "Assignment Operator\n"); }
"{"                      { fprintf(yyout, "Open Curly Brace\n"); }
"}"                      { fprintf(yyout, "Close Curly Brace\n"); }
"("                      { fprintf(yyout, "Open Parenthesis\n"); }
")"                      { fprintf(yyout, "Close Parenthesis\n"); }
";"                      { fprintf(yyout, "Semicolon\n"); }
[ \t\n]                  ;  // Ignore whitespace and newline characters
.                        { fprintf(yyout, "Unknown Token: %s\n", yytext); }

%%

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s input_file output_file\n", argv[0]);
        return 1;
    }

    FILE *inputFile = fopen(argv[1], "r");
    FILE *outputFile = fopen(argv[2], "w");

    if (!inputFile || !outputFile) {
        perror("Error opening files");
        return 1;
    }

    yyin = inputFile;
    yyout = outputFile;

    yylex();

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}
