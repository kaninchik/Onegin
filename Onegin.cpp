#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include<sys/stat.h>
#include<ctype.h>

int Get_size(FILE *fp);
char *Fill_buffer(FILE *fp, int file_size);
int Get_n_rows(char *buffer, int file_size);
char **Fill_text(char *buffer, int N_strings, int file_size);
void My_sort(char **text, int N_strings);
void My_swap(char **str1, char **str2);
int My_strcmp(char *str1, char *str2);
void My_sort2(char **text, int N_strings);

int main()
{
    FILE *fp = fopen("Onegin.txt", "r");

    assert(fp != NULL);

    int file_size = Get_size(fp);

    char *buffer = Fill_buffer(fp, file_size);

    assert(buffer != NULL);

    fclose(fp);

    puts(buffer);

    printf("\n");

    int N_strings = Get_n_rows(buffer, file_size);

    char **text = Fill_text(buffer, N_strings, file_size);

    My_sort2(text, N_strings);

    for(int i = 0; i < N_strings; i++)
        puts(*(text + i));

    free(buffer);
    free(text);

    return 0;
}

int Get_size(FILE *fp)
{
    assert(fp != NULL);

    struct stat st;
    int fd = fileno(fp);

    fstat(fd, &st);

    return st.st_size;
}

char *Fill_buffer(FILE *fp, int file_size)
{
    assert(fp != NULL);

    char *buffer = (char*)calloc(file_size + 1, sizeof(char));

    if(buffer == NULL)
        printf("Couldn't allocated that much memory");

    fread(buffer, sizeof(char), file_size + 1, fp);

    return buffer;
}

int Get_n_rows(char *buffer, int file_size)
{
    assert(buffer != NULL);

    int N_strings = 0;

    for(int i = 0; i < file_size; i++)
    {
        if(buffer[i] == '\n')
            N_strings++;
    }

    return N_strings;
}

char **Fill_text(char *buffer, int N_strings, int file_size)
{
    assert(buffer != NULL);

    char **text = (char**)calloc(N_strings, sizeof(char*));

    if(text == NULL)
        printf("Couldn't allocated that much memory");

    int line = 1;

    text[0] = buffer;

    for(int i = 1; i < file_size; i++)
    {
        if(buffer[i] == '\n')
        {
            buffer[i] = '\0';
            text[line++] = (buffer + i + 1);
        }
    }

    return text;
}

void My_sort(char **text, int N_strings)
{
    assert(text != NULL);

    for(int n = 0; n < N_strings - 1; n++)
    {
        bool nSwap = 0;

        for(int i = 0; i < N_strings - n - 1; i++)
        {
            if(strcmp(text[i], text[i+1]) > 0)
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

void My_sort2(char **text, int N_strings)
{
    assert(text != NULL);

    for(int n = 0; n < N_strings - 1; n++)
    {
        bool nSwap = 0;

        for(int i = 0; i < N_strings - n - 1; i++)
        {
            if(My_strcmp(text[i], text[i+1]) > 0)
                My_swap(&text[i], &text[i+1]);

            nSwap = 1;
        }
        if(nSwap == 0)
            break;
    }
}

int My_strcmp(char *str1, char *str2)
{
    assert(str1 != NULL);
    assert(str2 != NULL);

    for(int i = strlen(str1) - 1, j = strlen(str2) - 1; i >= 0, j >= 0;)
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

