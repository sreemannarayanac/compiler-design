#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char type; // Variable ('V'), Array ('A'), Function ('F'), Structure ('S')
    char name[50]; // Identifier name
} Identifier;

int isValidIdentifier(char identifier[]) {
    return strlen(identifier) > 0 && isalpha(identifier[0]) || identifier[0] == '_';
}

int isVariable(char identifier[]) {
    int length = strlen(identifier);
    return length > 0 && isalpha(identifier[length - 1]) && identifier[length - 1] != '_';
}

int isArray(char identifier[]) {
    int length = strlen(identifier);
    return length > 0 && identifier[length - 1] == ']';
}

int isFunction(char identifier[]) {
    int length = strlen(identifier);
    return length > 0 && identifier[length - 1] == ')';
}

int isStructure(char identifier[]) {
    int length = strlen(identifier);
    return length > 0 && identifier[length - 1] == '}';
}

void parseIdentifier(char identifier[], Identifier *id) {
    id->name[0] = '\0';
    id->type = ' ';

    if (isValidIdentifier(identifier)) {
        if (isVariable(identifier)) {
            id->type = 'V';
        } else if (isArray(identifier)) {
            id->type = 'A';
        } else if (isFunction(identifier)) {
            id->type = 'F';
        } else if (isStructure(identifier)) {
            id->type = 'S';
        }
        strcpy(id->name, identifier);
    }
}

int main() {
    char identifier[50];
    Identifier id;

    printf("Enter the identifier: ");
    scanf("%s", identifier);

    parseIdentifier(identifier, &id);

    if (id.type != ' ')
    {
        printf("It is a valid identifier: %s\n", id.name);
        switch (id.type)
        {
            case 'V': printf("It is a variable.\n"); break;
            case 'A': printf("It is an array.\n"); break;
            case 'F': printf("It is a function.\n"); break;
            case 'S': printf("It is a structure.\n"); break;
        }
    }
    else
    {
        printf("It is not a valid identifier.\n");
    }

    return 0;
}