#ifndef MY_STRING_H_INCLUDED
#define MY_STRING_H_INCLUDED

void My_sort(void *arr, int n_strings, int ellement_size, int (*Compare)(void *str1, void *str2));
void My_swap(void *str1, void *str2, size_t size_one);
int My_strcmp(void *ptr1, void *ptr2);
int My_strcmp_rev(void *ptr1, void *ptr2);
void Output_poem(char **strings, int n_strings);

#endif
