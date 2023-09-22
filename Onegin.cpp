#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cassert>
#include<sys/stat.h>

#include"My_string.h"
#include"Process_file.h"


int main()
{
    size_t file_size = 0;
    size_t n_strings = 0;

    char *buffer = Get_file_content(&file_size, &n_strings);

    char **strings = Fill_text(buffer, n_strings, file_size);

    My_sort(strings, n_strings, sizeof(char *), My_strcmp);

    Output_poem(strings, n_strings);

    free(buffer);
    free(strings);

    return 0;
}


