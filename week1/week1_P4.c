#include <stdio.h>
#include <string.h>

// Write a program to read a sentence from keyboard and break them into words,
// write in an array and sort the words into dictionary order.

void readSentence(char str[])
{
    printf("Enter the sentence: ");
    scanf("%[^\n]s", str);
}

void breakWords(char str[], char words[][100], int *n)
{
    int i, j, k = 0;
    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == ' ')
        {
            words[*n][k] = '\0';
            (*n)++;
            k = 0;
        }
        else
        {
            words[*n][k++] = str[i];
        }
    }
    words[*n][k] = '\0';
    (*n)++;
}

void sortWords(char words[][100], int n)
{
    int i, j;
    char temp[100];
    for (i = 0; i < n - 1; i++)
    {
        for (j = i; j < n; j++)
        {
            if (strcmp(words[i], words[j]) > 0)
            {
                strcpy(temp, words[i]);
                strcpy(words[i], words[j]);
                strcpy(words[j], temp);
            }
        }
    }
}

void printWords(char words[][100], int n)
{
    int i;
    printf("The words in the sentence are:\n");
    for (i = 0; i < n; i++)
    {
        printf("%s\n", words[i]);
    }
}

int main()
{
    char str[100], words[100][100];
    int n = 0;
    readSentence(str);
    breakWords(str, words, &n);
    sortWords(words, n);
    printWords(words, n);
    return 0;
}