#include "search_algorithms.h"
#include <stdbool.h>
#include <stddef.h>

bool linear(int const *const arr, const size_t length, const int val) {
    bool found = false;

    for (size_t i = 0; i < length; ++i) {
        if (*arr == val) {
            found = true;
            break;
        }
    }

    return found;
}

static bool binary_search_split(
    int const *const arr, const int v, int l, int r) {
    bool found = false;

    if (l != r) {
        int m = ((r - l) / 2) + l;

        if (v == arr[m]) {
            found = true;
        } else if (v > arr[m]) {
            l = m + 1;
            found = binary_search_split(arr, v, l, r);
        } else {
            r = m;
            found = binary_search_split(arr, v, l, r);
        }
    }

    return found;
}

bool binary_search(int const *const arr, const size_t length, const int val) {
    bool found = false;
    int l = 0;
    int r = length;

    found = binary_search_split(arr, val, l, r);

    return found;
}
