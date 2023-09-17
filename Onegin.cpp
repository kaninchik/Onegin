#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include<sys/stat.h>
#include"My_string.h"
#include"Process_file.h"


int main()
{
    FILE *fp = fopen("Onegin.txt", "r");

    int file_size = Get_file_size(fp);

    char *buffer = Fill_buffer(fp, file_size);

    assert(buffer != NULL);

    fclose(fp);

    int N_strings = Get_n_rows(buffer, file_size);

    char **text = Fill_text(buffer, N_strings, file_size);

    My_sort(text, N_strings, My_strcmp_rev);

    output_poem(text, N_strings);

    free(buffer);
    free(text);

    getchar();

    return 0;
}


