#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cassert>
#include<sys/stat.h>

#include"My_string.h"
#include"Process_file.h"


size_t Get_file_size(FILE *fp)
{
    assert(fp != NULL);

    struct stat st = {};
    int fd = fileno(fp);

    fstat(fd, &st);

    return st.st_size;
}

char *Get_file_content(size_t *file_size, size_t *n_strings)
{
    FILE *fp = fopen("Onegin.txt", "rb");

    if(fp == NULL)
    {
        printf("I can't find your file((");

        exit(EXIT_FAILURE);
    }

    *file_size = Get_file_size(fp);

    char *buffer = (char*)calloc(*file_size + 1, sizeof(char));

    if(buffer == NULL)
    {
        printf("I can't find that much memory for you((");

        exit(EXIT_FAILURE);
    }

    size_t sym = fread(buffer, sizeof(char), *file_size + 1, fp);

    if(sym != *file_size)
    {
        printf("I can't transfer the contents of the file to the line((");

        exit(EXIT_FAILURE);
    }

    puts(buffer);

    fclose(fp);

    *n_strings = Get_n_rows(buffer, *file_size);

    return buffer;
}

size_t Get_n_rows(char *buffer, size_t file_size)
{
    assert(buffer != NULL);

    size_t n_strings = 0;

    for(size_t i = 0; i < file_size; i++)
    {
        if(buffer[i] == '\n')
            n_strings++;
    }

    return n_strings;
}

char **Fill_text(char *buffer, size_t n_strings, size_t file_size)
{
    assert(buffer != NULL);

    char **strings = (char**)calloc(n_strings, sizeof(char*));

    if(strings == NULL)
    {
        printf("I can't find that much memory for you((");

        exit(EXIT_FAILURE);
    }

    int line = 1;

    strings[0] = buffer;

    for(size_t i = 1; i < file_size; i++)
    {
        if(buffer[i] == '\n')
        {
            buffer[i] = '\0';
            strings[line++] = (buffer + i + 1);
        }
    }

    return strings;
}
