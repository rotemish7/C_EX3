//
// Created by rotem levy on 19/12/2019.
//

#include "isort.h"
#include <stdio.h>
#define size 50
void print_array(int *data, int n)
{
    int i;
    for(i = 0; i<n; i++)
    {
        if(i == n-1)
        {
            printf("%d",*data);
        }else{
            printf("%d,", *data);
            data++;
        }
    }
    printf("\n");
}

void shift_element(int *arr, int *i)
{
    int ival;
    for(ival = *i; i > arr && *(i-1) > ival; i--)
    {
        *i = *(i-1);
    }
    *i = ival;
}

void insertion_sort(int *arr, int len)
{
    int *i, *last = arr + len;
    for(i = arr + 1; i < last; i++)
        if(*i < *(i-1))
            shift_element(arr, i);
}

int main()
{
    int arr[size];
    for (int i = 0; i < size; ++i)
    {
        scanf("%d", &arr[i]);
    }
    insertion_sort(&arr[0], size);
    print_array(&arr[0], size);
    return 0;
}
