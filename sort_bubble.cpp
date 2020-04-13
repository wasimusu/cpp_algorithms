#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
#include "utils.cpp"


void generate_random_arrs(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }
}


void bubble_sort(int *arr, int n) {
    bool is_sorted = false;
    while (!is_sorted) {
        is_sorted = true;
        for (int j = 0; j < n - 1; j++) {
            if ((j < n - 1 && arr[j] > arr[j + 1])) {
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