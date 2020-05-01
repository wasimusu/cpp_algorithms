#include <limits>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cassert>

using namespace std;

void generate_random_arrs(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = random() % 100;
    }
}

/**
 * Pick the smallest number each time and put it in sorted order from the front
 * of the array
 * */
template<class T>
void selection_sort(T *arr, const int n) {
    for (int i = 0; i < n; i++) {
        int min_pos = i;
        int min_value = arr[i];
        // Pick the smallest number from ith to nth
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < min_value) {
                min_value = arr[j];
                min_pos = j;
            }
        }
        swap(arr[i], arr[min_pos]);
    }
}


int main() {
    int n = 500;
    int arr[n];
    for (int _ = 0; _ < 100; _++) {
        generate_random_arrs(arr, n);
        selection_sort(arr, n);
        assert(std::is_sorted(arr, arr + n));
    }
    std::cout << "Successfully sorted using selection sort! \n";
    return 0;
}