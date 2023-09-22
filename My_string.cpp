#include<cstdio>
#include<cstring>
#include<cassert>
#include<cstdlib>

#include"My_string.h"
#include"Process_file.h"


void My_sort(void *arr, int n_strings, int ellement_size, int (*Compare)(void *str1, void *str2))
{
    assert(arr != NULL);

    char *strings = (char *)arr;

    for(int n = 0; n < n_strings - 1; n++)
    {
        bool is_swap = false;

        for(int i = 0; i < n_strings - n - 1; i++)
        {
            if(Compare(strings + i * ellement_size, strings + (i + 1)*ellement_size) > 0)
            {
                is_swap = true;

                My_swap(strings + i*ellement_size, strings + (i + 1)*ellement_size, ellement_size);
            }
        }

        if(is_swap == false)
            break;
    }
}

void My_swap(void *str1, void *str2, size_t size_one)
{
    assert(str1 != NULL);
    assert(str2 != NULL);

    void *tmp = calloc(1, size_one);

    if(tmp == NULL)
    {
        printf("I can't find that much memory for you((");

        exit(EXIT_FAILURE);
    }

    memcpy(tmp, str1, size_one);
    memcpy(str1, str2, size_one);
    memcpy(str2, tmp, size_one);

    free(tmp);
}

int My_strcmp_rev(void *ptr1, void *ptr2)
{
    assert(ptr1 != NULL);
    assert(ptr2 != NULL);

    char *str1 = (char *)ptr1;
    char *str2 = (char *)ptr2;

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

int My_strcmp(void *ptr1, void *ptr2)
{
    assert(ptr1 != NULL);
    assert(ptr2 != NULL);

    char *str1 = (char *)ptr1;
    char *str2 = (char *)ptr2;

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

void Output_poem(char **strings, int n_strings)
{
    assert(strings != NULL);

    for(int i = 0; i < n_strings; i++)
        puts(strings[i]);
}
