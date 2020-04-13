#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
#include "utils.cpp"


void generate_random_arrs(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }
}


/**
 * Insert each item in the correct position
 */
void insertion_sort(int *arr, int n) {

    for (int i = 1; i < n; i++) {
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