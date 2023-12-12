#include <stdio.h>

// Write a program to read a sentence from keyboard and count the number of words, 
// and the number of vowels are there in the sentence

void countWords(char str[])
{
    int i, count = 0;
    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == ' ')
        {
            count++;
        }
    }
    printf("Number of words in the string = %d\n", count + 1);
}

void countVowels(char str[])
{
    int i, count = 0;
    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == 'a' || str[i] == 'A' ||
            str[i] == 'e' || str[i] == 'E' ||
            str[i] == 'i' || str[i] == 'I' ||
            str[i] == 'o' || str[i] == 'O' ||
            str[i] == 'u' || str[i] == 'U')
        {
            count++;
        }
    }
    printf("Number of vowels in the string = %d\n", count);
}

int main(){
    char str[100];
    printf("Enter the string: ");
    scanf("%[^\n]s", str);
    countWords(str);
    countVowels(str);
    return 0;
}