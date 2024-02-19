#include <stdio.h>
#include <string.h>
#include <ctype.h>

// List of C keywords
char* keywords[] = {"auto", "break", "case", "char", "const", "continue", "default", "do", "double", "else", "enum", "extern", "float", "for", "goto", "if", "int", "long", "register", "return", "short", "signed", "sizeof", "static", "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while"};

int isKeyword(char* token) {
    int i;
    for (i = 0; i < sizeof(keywords)/sizeof(char*); i++) {
        if (strcmp(token, keywords[i]) == 0)
            return 1;
    }
    return 0;
}

void recognizeToken(char* token) {
    if (isKeyword(token))
        printf("<keyword, %s>\n", token);
    else if (strcmp(token, "+") == 0 || strcmp(token, "-") == 0 || strcmp(token, "*") == 0 || strcmp(token, "/") == 0 || strcmp(token, "%")==0)
        printf("<optr, %s>\n", token);
    else if (strcmp(token, "=") == 0 || strcmp(token, ";") == 0)
        printf("<sym, %s>\n", token);
    else if (isdigit(token[0]))
        printf("<const, %s>\n", token); 
    else
        printf("<var, %s>\n", token);
}

int main() {
    char statement[100];
    printf("Enter a statement: ");
    fgets(statement, 100, stdin); // read the statement

    char* token = strtok(statement, " \n"); // tokenize the statement
    while (token != NULL) {
        recognizeToken(token);
        token = strtok(NULL, " \n");
    }

    return 0;
}
