#include "bubble.h"
#include <stddef.h>

void bubble_sort(int *const arr, const size_t len) {
    int tmp = 0;
    for (size_t i = 0; i < len; ++i) {
        for (size_t j = 0; j < len - 1 - i; ++j) {
            if (arr[j] > arr[j + 1]) {
                tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
    return;
}
