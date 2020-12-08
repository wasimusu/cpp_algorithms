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
 * Insert each item in the correct position
 *
 * Assume at arr[0] is sorted.
 * So A[0] is the sorted array, A[1 to n-1] is the unsorted array.
 * Starting from arr[1] insert it in the sorted array in the correct position.
 *
 * 5 4 1 6 3
 *
 * Assume 5 is sorted.
 * 5 | 4 1 6 3
 *
 * Gotta insert 4 at appropriate place.
 * 4 5 | 1 6 3
 *
 * Similarly
 * 1 4 5 | 6 3
 * 1 4 5 6 | 3
 * 1 4 5 6 3
 *
 * Complexity: O(n*n)
 * Space: O(1)
 */
template<class T>
void insertion_sort(T *arr, int n) {

    for (int i = 1; i < n; ++i) {
        int j = i;
        while (j > 0 && arr[j] < arr[j - 1]) {
            std::swap(arr[j], arr[j - 1]);
            j--;
        }
    }
}


int main() {
    int n = 500;
    int arr[n];
    for (int _ = 0; _ < 100; _++) {
        generate_random_arrs(arr, n);
        insertion_sort(arr, n);
        assert(std::is_sorted(arr, arr + n));
    }
    std::cout << "Successfully sorted using insertion sort! \n";
    return 0;
}