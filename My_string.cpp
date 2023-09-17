#include<stdio.h>
#include<string.h>
#include<assert.h>
#include"My_string.h"
#include"Process_file.h"


void My_sort(char **text, int N_strings, int (*Compare)(char*, char*))
{
    assert(text != NULL);

    for(int n = 0; n < N_strings - 1; n++)
    {
        bool nSwap = 0;

        for(int i = 0; i < N_strings - n - 1; i++)
        {
            if(Compare(text[i], text[i+1]) > 0)
            {
                nSwap = 1;
                My_swap(&text[i], &text[i+1]);
            }
        }

        if(nSwap == 0)
            break;
    }
}

void My_swap(char **str1, char **str2)
{
    assert(str1 != NULL);
    assert(str2 != NULL);

    char *Swap = *str1;

    assert(Swap != NULL);

    *str1 = *str2;
    *str2 = Swap;
}

int My_strcmp_rev(char *str1, char *str2)
{
    assert(str1 != NULL);
    assert(str2 != NULL);

    for(int i = strlen(str1) - 1, j = strlen(str2) - 1; i >= 0 && j >= 0;)
    {
        if(str1[i] == str2[j])
        {
            i--;
            j--;
        }
        else if(str1[i] > str2[j])
        {
            return 1;
        }
        else
        {
            return -1;
        }
    }
    return 0;
}

int My_strcmp(char *str1, char *str2)
{
    assert(str1 != NULL);
    assert(str2 != NULL);

    for(int i = 0, j = 0; str1[i] != '\0' && str2[j] != '\0'; )
    {
        if(str1[i] == str2[j])
        {
            i++;
            j++;
        }
        else if(str1[i] > str2[j])
        {
            return 1;
        }
        else
        {
            return -1;
        }
    }
    return 0;
}

void output_poem(char **text, int N_strings)
{
    for(int i = 0; i < N_strings; i++)
        puts(*(text + i));
}
