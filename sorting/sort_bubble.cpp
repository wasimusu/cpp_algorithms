#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
#include "../utils.cpp"


void generate_random_arrs(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }
}


/**
 *
 * 1. In a single pass through the array
 *  Swap the pair of elements at position (i, i + 1) if it is not sorted.
 * Repeat 1 if you had to swap elements.
 *
 *
 * For arr,
 * 5 4 3 2 1
 *
 * This is what a single pass looks like
 * 4 5 3 2 1
 * 4 3 5 2 1
 * 4 3 2 5 1
 * 4 3 2 1 5
 *
 * Since we swapped elements in the last pass. We will take one more pass through the array.
 *
 * The next pass looks like the following
 * 3 4 2 1 5
 * 3 2 4 1 5
 * 3 2 1 4 5
 * 3 2 1 4 5
 *
 * We will stop when no items are swapped in a single pass.
 * For instance, when the array becomes 1, 2, 3, 4, 5 no swapping will be necessary.
 * So we will terminate the program.
 *
 * Complexity: O(n*n)
 * Space: O(1)
 * */
template<class T>
void bubble_sort(T *arr, int n) {
    bool is_sorted = false;
    while (!is_sorted) {
        is_sorted = true;
        for (int j = 0; j < n - 1; ++j) {
            if ((arr[j] > arr[j + 1])) {
                std::swap(arr[j], arr[j + 1]);
                is_sorted = false;
            }
        }
    }
}


int main() {
    int n = 1000;
    int arr[n];
    for (int _ = 0; _ < 100; _++) {
        generate_random_arrs(arr, n);
        bubble_sort(arr, n);
        assert(std::is_sorted(arr, arr + n));
    }
    std::cout << "Successfully sorted using bubble sort! \n";
    return 0;
}