#include "mergesort.h"
#include <stdlib.h>
#include <stddef.h>

void copy(char* first, char* second, size_t copy_size) {
    for (size_t i = 0; i < copy_size; i++) {
        first[i] = second[i];
    }
}

void mergesort_buf(void *array, void* buf, size_t elements, size_t element_size, int (*comparator)(const void*, const void*)) {
    if (elements <= 1) 
        return;
    mergesort_buf(array, buf, elements / 2, element_size, comparator);
    mergesort_buf(array + elements / 2 * element_size, buf, (elements + 1) / 2, element_size, comparator);
    char *left_end = (char*)array + elements / 2 * element_size;
    char *array_end = (char*)array + elements * element_size;
    char *buf_end = (char*)buf + elements * element_size;
    for (char *i = array, *j = array + elements / 2 * element_size, *now = buf; now != buf_end; now += element_size) {
        if (j == array_end || (i != left_end && comparator((void*)i, (void*)j) <= 0)) {
            copy(now, i, element_size);
            i += element_size;
        } else {
            copy(now, j, element_size);
            j += element_size;
        }
    }
    copy(array, buf, elements * element_size);
}

int mergesort(void *array, size_t elements, size_t element_size, int (*comparator)(const void*, const void*)) {
    void *buf = malloc(elements * element_size);
    if (buf == NULL) {
        return 1;
    }
    mergesort_buf(array, buf, elements, element_size, comparator);
    free(buf);
    return 0;
}
