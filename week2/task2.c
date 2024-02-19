#include <stdio.h>
#include <ctype.h>

int main() {
    char str[100];
    printf("Enter a constant: ");
    scanf("%s", str);

    int flag=0; // 0 for integer, 1 for real

    for (int i=0; str[i]!='\0'; i++) {
        if (str[i] == '.') {
            flag = 1;
            printf("Real constant\n");
            return 0;
        } 
        else if (i!=0 && (str[i] == '-' || str[i] == '+')) {
            printf("Invalid constant\n");
            return 0;
        }
        else if (i==0 && str[i+1]=='\0' && (str[i] == '-' || str[i] == '+')) {
            printf("Invalid constant\n");
            return 0;
        
        }
        else if (!isdigit(str[i])) {
            printf("Invalid constant\n");
            return 0;
        }
    }
    printf("Integer constant\n");
}