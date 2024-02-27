%{
#include <stdio.h>
%}

%%
int|float|char        { fprintf(yyout, "Keyword: %s\n", yytext); }
[a-zA-Z_][a-zA-Z0-9_]* { fprintf(yyout, "Identifier: %s\n", yytext); }
[ \t\n]               ;  // Ignore whitespace and newline characters
.                     ;  // Ignore other characters

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