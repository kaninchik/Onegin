#ifndef PROCESS_FILE_H_INCLUDED
#define PROCESS_FILE_H_INCLUDED

int Get_file_size(FILE *fp);
char *Fill_buffer(FILE *fp, int file_size);
int Get_n_rows(char *buffer, int file_size);
char **Fill_text(char *buffer, int N_strings, int file_size);

#endif // PROCESS_FILE_H_INCLUDED
