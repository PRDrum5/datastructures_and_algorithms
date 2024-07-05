#ifndef SEARCH_ALGORITHMS_H
#define SEARCH_ALGORITHMS_H

#include <stdbool.h>
#include <stddef.h>

bool linear(int const *const arr, const size_t length, const int val);
bool binary_search(int const *const arr, const size_t length, const int val);

#endif // SEARCH_ALGORITHMS_H
