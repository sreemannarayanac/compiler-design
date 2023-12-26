#include <stdio.h>
#include <stdbool.h>

bool isDigit(char c) {
    return (c >= '0' && c <= '9');
}

bool isInteger(char* str) {
    int i = 0;
    if (str[i] == '-' || str[i] == '+') {
        i++;
    }
    while (str[i] != '\0') {
        if (!isDigit(str[i])) {
            return false;
        }
        i++;
    }
    return true;
}

bool isReal(char* str) {
    int i = 0;
    if (str[i] == '-' || str[i] == '+') {
        i++;
    }
    bool hasDot = false;
    while (str[i] != '\0') {
        if (str[i] == '.') {
            if (hasDot) {
                return false;
            }
            hasDot = true;
        } else if (!isDigit(str[i])) {
            return false;
        }
        i++;
    }
    return hasDot;
}

int main() {
    char str[100];
    printf("Enter a constant: ");
    scanf("%s", str);

    if (isInteger(str)) {
        printf("The constant is an integer.\n");
    } else if (isReal(str)) {
        printf("The constant is a real number.\n");
    } else {
        printf("The constant is neither an integer nor a real number.\n");
    }

    return 0;
}
