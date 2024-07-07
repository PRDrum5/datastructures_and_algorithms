#include "quick.h"

#include <stdio.h>

static int partition(int *arr, size_t low, size_t high) {
    int pivot = arr[high];
    int tmp;
    int j = low - 1;

    for (int i = low; i < high; ++i) {
        if (arr[i] <= pivot) {
            j++;
            if (i != j) {
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }

    j++;
    arr[high] = arr[j];
    arr[j] = pivot;

    return j;
}

static void sort(int *arr, size_t low, size_t high) {
    if (low >= high) {
        return;
    } else {
        int pivot = partition(arr, low, high);

        sort(arr, low, pivot - 1);
        sort(arr, pivot, high);
    }
    return;
}

int quick_sort(int *arr, const size_t len) {
    int status = 1;

    if (arr != NULL) {
        status = 0;
        size_t low = 0;
        size_t high = len - 1;

        sort(arr, low, high);
    }

    return status;
}
