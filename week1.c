// Write a program to count the number of words in a given string.

#include <stdio.h>
#include <string.h>

int task1()
{
    printf("Program to count the number of words in a given string.\n");
    char str[100];
    int i, count = 0;

    printf("Enter the string: ");
    scanf("%[^\n]s", str);

    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == ' ')
        {
            count++;
        }
    }

    printf("Number of words in the string = %d\n", count + 1);

    return 0;
}

// Enter the string: Hello World
// Number of words in the string = 2

// Write a program to count the length of the string without using string handling functions.
int task2()
{
    printf("\nProgram to count the length of the string without using string handling functions.\n");
    char str[100];
    int i, count = 0;

    printf("Enter the string: ");
    scanf("%[^\n]s", str);

    for (i = 0; str[i] != '\0'; i++)
    {
        count++;
    }

    printf("Length of the string = %d\n", count);

    return 0;
}

// Enter the string: Hello World
// Length of the string = 11

int main()
{
    task1();
    task2();
    return 0;
}