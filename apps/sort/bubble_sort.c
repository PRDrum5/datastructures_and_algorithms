#include "bubble.h"
#include "lib/bubble.h"
#include <stdbool.h>
#include <stdio.h>

#define LEN 10

void print_arr(int const *const arr, const size_t length) {
    for (size_t i = 0; i < length; ++i) {
        if (i == 0) {
            printf("[%d", arr[i]);
        } else {
            printf(", %d", arr[i]);
        }
    }

    printf("]\n");

    return;
}

int main(void) {
    int arr[LEN] = {1, 4, 3, 6, 5, 8, 9, 67, 2, 4};

    print_arr(arr, LEN);

    bubble_sort(arr, LEN);

    print_arr(arr, LEN);

    return 0;
}

