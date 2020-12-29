#include <stdio.h>
#include "myEx3.h"
#define LENGTH 50

void shift_element(int *arr, int i)
{
    for (int j = 0; j < i; j++)
    {
        *(arr + i - j) = *(arr + i - j - 1);
    }
}

int check(int *arr, int i)
{
    int counter = 0;
    while (i)
    {
        if (*(arr + i) < *(arr + i - 1))
        {
            counter++;
            i--;
        }
        else
        {
            return counter;
        }
    }
    return counter;
}

void insertion_sort(int *arr, int len)
{

    int temp, shift;

    for (int k = 0; k < len; k++)
    {
        for (int i = 1; i < len; i++)
        {
            if (*(arr + i) < *(arr + i - 1))
            {
                temp = *(arr + i);
                shift = check(arr, i);
                shift_element((arr + i - 1), shift);
                *(arr + i - shift) = temp;
            }
        }
    }
}

void printArr(int *arr, int size)
{
    for (int i = 0; i < size - 1; ++i)
    {
        printf("%d,", *(arr + i));
    }
    printf("%d\n", *(arr + size - 1));
}

int main()
{
    int arr[LENGTH] = {0};
    int insert;
    // printf("pleas enter %d integers:\n", LENGTH);
    for (int i = 0; i < LENGTH; i++)
    {
        scanf("%d", &insert);
        *(arr + i) = insert;
    }
    insertion_sort(arr, LENGTH);
    printArr(arr, LENGTH);
    return 0;
}
