#include<stdio.h>
#include<stdlib.h>
#include <sys/stat.h>
#include<string.h>
#include <assert.h>


int main()
{
    FILE *fp = fopen("Onegin.txt", "r");

    assert(fp != NULL);

    struct stat st;

    int fd = fileno(fp); // получаем дескриптор файла
    fstat(fd, &st);
    off_t file_size = st.st_size;

    char *buffer = (char*)calloc(file_size + 1, sizeof(char)); //заказываю динамическую память размера n+1
    assert(buffer != NULL);

    fread(buffer, sizeof(char), file_size + 1, fp);//записываю в буффер

    char *text[500] = {buffer};
    int line = 1;

    printf("\n");

    for(int i = 1; i < file_size; i++)
    {
        if(buffer[i] == '\n')
        {
            text[line++] = (buffer + i + 1);
        }
    }
    free(buffer);
    return 0;
}


