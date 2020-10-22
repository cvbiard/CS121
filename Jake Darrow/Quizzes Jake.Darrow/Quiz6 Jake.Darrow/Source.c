#include "header.h"

int remove_punct(char array[])
{
    int numspace = 0;
    for (int i = 0; array[i] != '\0'; i++)
    {
        if (array[i] == ' ')
        {
            numspace++;
            for (int j = i; array[j] != '\0'; j++)
            {
                array[j] = array[j + 1];
            }
        }
    }
    return numspace;
}

void print(char array[])
{
    for (int i = 0; array[i] != '\0'; i++)
    {
        printf("%c", array[i]);
    }
    printf("\n");
}

int largest_sum_sequence(int array[], int num)
{
    if (num == 1)
    {
        return array[0];
    }

    else
    {
        int total = array[0];
        int maxs = array[0];
        for (int i = 1; i < num; i++)

        {
            total = max(array[i], total + array[i]);

            maxs = max(maxs, total);
        }
        return maxs;
    }
    
}