#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
#include "../utils.cpp"


void generate_random_arrs(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }
}

/*
 * Places everything smaller than the pivot value to the left and greater to the right.
 * Returns the index of the pivot in the partitioned array
 * */
template<class T>
int partition(T *arr, int left, int right, T pivot) {
    int leftPointer = left - 1;
    int rightPointer = right;

    while (true) {
        while (arr[++leftPointer] < pivot) {}
        while (rightPointer > 0 && arr[--rightPointer] > pivot) {}
        if (leftPointer >= rightPointer) break;
        else {
            std::swap(arr[leftPointer], arr[rightPointer]);
        }
    }
    std::swap(arr[leftPointer], arr[right]);
    return leftPointer;
}

/*
 * Recursive sorting calls.
 * Partitions elements based on pivot so that elements on left of pivot are smaller and elements on right are greater than pivot.
 * */
template<class T>
void quick_sort(T *arr, int left, int right) {
    if (right - left <= 0) return;
    T pivotIndex = arr[right]; // The pivotIndex can be of your choice
    int newPivotIndex = partition(arr, left, right, pivotIndex);
    quick_sort(arr, left, newPivotIndex - 1);
    quick_sort(arr, newPivotIndex + 1, right);
}

template<class T>
void quicksort(T *arr, int n) {
    quick_sort(arr, 0, n - 1);
}

int main() {
    int n = 1000;
    int arr[n];
    for (int _ = 0; _ < 100; _++) {
        generate_random_arrs(arr, n);
        quicksort(arr, n);
    }
    std::cout << "Successfully sorted using bubble sort! \n";
    return 0;
}