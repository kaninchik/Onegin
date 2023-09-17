#ifndef MY_STRING_H_INCLUDED
#define MY_STRING_H_INCLUDED

void My_sort(char **text, int N_strings, int (*Compare)(char*, char*));
void My_swap(char **str1, char **str2);
int My_strcmp(char *str1, char *str2);
int My_strcmp_rev(char *str1, char *str2);
void output_poem(char **text, int N_strings);

#endif
