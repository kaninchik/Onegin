#ifndef PROCESS_FILE_H_INCLUDED
#define PROCESS_FILE_H_INCLUDED

#include<cstdio>

size_t Get_file_size(FILE *fp);
char *Get_file_content(size_t *file_size, size_t *n_strings);
size_t Get_n_rows(char *buffer, size_t file_size);
char **Fill_text(char *buffer, size_t n_strings, size_t file_size);

#endif // PROCESS_FILE_H_INCLUDED
