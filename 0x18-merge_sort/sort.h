#ifndef SORT_H
#define SORT_H
#include <stddef.h>

void print_array(const int *array, size_t size);
void merge_sort(int *array, size_t size);
void recur_merge_sort(int *array, size_t left, size_t right);
void merge(int *array, size_t left, size_t mid, size_t right);
void print_sub_array(int *array, size_t start, size_t end);

#endif /* SORT_H */
