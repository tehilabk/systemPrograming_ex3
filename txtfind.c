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

void getWord(char arr[], char word[])
{
    // printf("line: %s\n", arr);

    char *allWords[LINE];
    int WordLength = strlen(word);
    int next = 0;
    char potentialWord[WORD];
    allWords[next] = strtok(arr, " \n\t\0\r");
    while (allWords[next] != NULL)
    {
        strcpy(potentialWord, allWords[next]);
        // printf("after copy: %s\n", potentialWord);

        int potentialWordLength = strlen(potentialWord);
       
        
        if (potentialWordLength - WordLength == 0)
        {
            if (containWord(potentialWord, word))
            {
                printf("%s\n", potentialWord);
            }
        }


        if (potentialWordLength - WordLength == 1)
        {
            char similarWord[WordLength];

            int letterToCut = 0;
            while (letterToCut < potentialWordLength)
            {
                // printf("letter: %d \n", letterToCut);
                int index = 0;
                for (int insert = 0; potentialWord[insert]; insert++)
                {
                    if (insert != letterToCut)
                    {
                        similarWord[index] = potentialWord[insert];
                        index++;
                    }
                }
                similarWord[index] = '\0';
                //  printf("!!word im sent %s\n", similarWord);

                if (containWord(similarWord, word))
                {
                    printf("%s\n", potentialWord);
                    letterToCut = potentialWordLength;
                }
                else
                {
                    letterToCut++;
                }
            }
        }
        next++;
        allWords[next] = strtok(NULL, " \n\t\0\r");
    }
}

int containWord(char arr[], char word[])
{
    int length = strlen(word);
    int i = 0;

    while ((arr[i] == word[i]) && (arr[i] >= 'a') && (arr[i] <= 'z'))
    {
        i++;
    }
    if (i == length)
    {
        return 1;
    }
    return 0;
}

int main()
{
    char arr[LINE] = {0};
    char option;
    char word[WORD] = {0};

    fgets(arr, LINE, stdin);

    int j = 0;

    while ((arr[j] != '\n') && (arr[j] != '\0') && (arr[j] != ' ') && (arr[j] != '\t') && (arr[j] != '\r'))
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
            getWord(arr, word);
        }
    }   

    return 0;
}
