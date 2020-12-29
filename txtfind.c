#include <stdio.h>
#include <string.h>
#include "myEx3.h"
#define WORD 30
#define LINE 256

int getLine(char arr[], char word[])
{
    int length = strlen(word);
    int j = 0;
    for (int i = 0; i < LINE; i++)
    {
        while (arr[i] == word[j])
        {
            j++;
            i++;
        }
        if (j == length)
        {
            printf("%s", arr);
            return 1;
        }
        j = 0;
    }
    return 0;
}


void getword(char arr[], char word[])
{
    
    char printWord[WORD];
    int length = strlen(word);
    int j = 0;

    for (int i = 0; i < LINE; i++)
    {
        while (arr[i] != '\n' && arr[i] != ' ' && arr[i] != '\t')
        {
            printWord[j] = arr[i];
            j++;
            i++;
        }
        if (j - length == 0)
        {
            if (containWord(printWord, word))
                {
                    printf("%s", printWord);
                }
        }
        if (j - length == 1)
        {
            char checkWord[j];
            int index = 0;
            int k = j;
            while (k)
            {
                for (int w = 0; w < j; w++)
                {
                    if (w != k)
                    {
                        checkWord[index] = printWord[w];
                        index++;
                    }
                }
                index = 0;
                if (containWord(checkWord, word))
                {
                    printf("%s", printWord);
                    k = 0;
                }
                else
                {
                    k--;
                }
            }
        }
    }
}

int containWord(char arr[], char word[])
{
    int length = strlen(word);
    int j = 0;
    for (int i = 0; i < LINE; i++)
    {
        while (arr[i] == word[j])
        {
            j++;
            i++;
        }
        if (j == length)
        {
            return 1;
        }
        j = 0;
    }
    return 0;
}

int main()
{
    char arr[LINE];
    char option;
    char word[WORD];

    fgets(arr, LINE, stdin);

    int j = 0;

    while (arr[j] != '\n' && arr[j] != ' ' && arr[j] != '\t')
    {
        word[j] = arr[j];
        j++;
    }
    j++;
    option = arr[j];

    if (option == 'a' || option == 'A')
    {
        while (fgets(arr, LINE, stdin))
        {
            getLine(arr, word);
        }
    }

    if (option == 'b' || option == 'B')
    {
        while (fgets(arr, LINE, stdin))
        {
            getword(arr, word);
        }
    }

    return 0;
}