#include "search_algorithms.h"
#include <stdbool.h>
#include <stdio.h>

#define EVEN_LEN 10
#define ODD_LEN 9

void status_printer(const int value, const bool found) {
    if (found) {
        printf("The value %d was found\n", value);
    } else {
        printf("The value %d was not found\n", value);
    }
    return;
}

int main(void) {
    int sorted_arr[EVEN_LEN] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int sorted_arr_odd[ODD_LEN] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    const int search_val = 4;
    const int missing_val = -10;

    printf("Search even length array\n");
    status_printer(search_val, binary_search(sorted_arr, EVEN_LEN, search_val));
    status_printer(
        missing_val, binary_search(sorted_arr, EVEN_LEN, missing_val));

    printf("Search odd length array\n");
    status_printer(
        search_val, binary_search(sorted_arr_odd, ODD_LEN, search_val));
    status_printer(
        missing_val, binary_search(sorted_arr_odd, ODD_LEN, missing_val));

    return 0;
}
