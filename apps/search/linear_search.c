#include "search_algorithms.h"
#include <stdbool.h>
#include <stdio.h>

#define LEN 10

void status_printer(const int value, const bool found) {
    if (found) {
        printf("The value %d was found\n", value);
    } else {
        printf("The value %d was not found\n", value);
    }
    return;
}

int main(void) {
    int arr[LEN] = {1, 2, 5, 4, 6, 7, 3, 9, 8, 0};

    const int search_val = 4;
    const int missing_val = -10;

    status_printer(search_val, linear(arr, LEN, search_val));
    status_printer(missing_val, linear(arr, LEN, missing_val));

    return 0;
}
