#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include<sys/stat.h>
#include"My_string.h"
#include"Process_file.h"

int Get_file_size(FILE *fp)
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

    fclose(fp);

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
