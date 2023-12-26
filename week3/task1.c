#include <stdio.h>
#include <string.h>
#include <ctype.h>

void recognizeToken(char* token) {
    if (strcmp(token, "+") == 0 || strcmp(token, "-") == 0 || strcmp(token, "*") == 0 || strcmp(token, "/") == 0)
        printf("<optr,%s>\n", token);
    else if (strcmp(token, "=") == 0 || strcmp(token, ";") == 0)
        printf("<sym,%s>\n", token);
    else if (isdigit(token[0]))
        printf("<const,%s>\n", token);
    else
        printf("<var,%s>\n", token);
}

int main() {
    char statement[100];
    printf("Enter a statement: ");
    fgets(statement, 100, stdin); // read the statement

    char* token = strtok(statement, " =+-*/;\n"); // tokenize the statement
    while (token != NULL) {
        recognizeToken(token);
        token = strtok(NULL, " ()\n");
    }

    return 0;
}