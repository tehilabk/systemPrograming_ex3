#include <stdio.h>
#include <string.h>
#include "myEx3.h"
#define WORD 30
#define LINE 256

int getLine(char arr[] , char word[] ){ //check if the word is contained in the line
    int length = strlen(word);
    int j = 0;
    for (int i = 0; i < LINE; i++){
        while (arr[i] == word[j]){
            j++;
            i++;
        }
        if (j == length){
            printf("%s", arr);
            return 1;
        }
        j = 0;
    }
    return 0;
}

void getWord(char arr[], char word[]){
    char *allWords[LINE];                                   //arr of all the words
    int WordLength = strlen(word);                          //length of the word to find
    int next = 0;                                           //index for next word
    char potentialWord[WORD];                               //words with the same length or length plus one of word to find
    allWords[next] = strtok(arr, " \n\t\0");        //works like split
    while (allWords[next] != NULL){
        strcpy(potentialWord, allWords[next]);              //copies the word from all word to the arr
        int potentialWordLength = strlen(potentialWord);    //length of temp word
        if (potentialWordLength - WordLength == 0){         //if same size as the word we are searching we check if its the same word
            if (containWord(potentialWord, word)){          //checks if the same word
                printf("%s\n", potentialWord);
            }
        }
        if (potentialWordLength - WordLength == 1) {        //if the size of the word is longer we check with letter to 'cut'
            char similarWord[WordLength];                   //char for the word after we cut the letter
            int letterToCut = 0;                            //counter of the letter we are cutting in this loop
            while (letterToCut < potentialWordLength){
                int index = 0;
                for (int insert = 0; potentialWord[insert]; insert++){
                    if (insert != letterToCut){
                        similarWord[index] = potentialWord[insert];
                        index++;                            //in this loop we are going through the word with one letter diff
                    }
                }
                similarWord[index] = '\0';                  //adding /0 , cause that's how String works
                if (containWord(similarWord, word)){        //checking if its the word we searcked
                    printf("%s\n", potentialWord);
                    letterToCut = potentialWordLength;      //that's how we stop the while loop
                }
                else{
                    letterToCut++;                          //next letter to cut
                }
            }
        }
        next++;                                             //next word in allwords
        allWords[next] = strtok(NULL, " \n\t\0");//adds the next word
    }
}

int containWord(char arr[], char word[]){   //checks if it is the same word
    int length = strlen(word);
    int i = 0;
    while ((arr[i] == word[i]) && (((arr[i] >= 'a') && (arr[i] <= 'z')) || ((arr[i] >= 'A') && (arr[i] <= 'Z')))){
        i++;
    }
    if (i == length){
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
    while ((arr[j] != '\n') && (arr[j] != '\0') && (arr[j] != ' ') && (arr[j] != '\t'))
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
