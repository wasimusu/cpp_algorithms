#include <bits/stdc++.h>

using namespace std;

void generate_random_arrs(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }
}


/**
 * Split an array into half recursively until the parts consist of only single elements.
 * Merge those sorted parts
 *
 * 7 5 8 4 4 3 1 2
 *
 * Splitting input array
 * 7 5 8 4 | 4 3 1 2
 *
 * Recursively split the two parts further into two parts each and so on
 * 7 5 | 8 4 | 4 3 | 1 2
 * 7 | 5 | 8 | 4 | 4 | 3 | 1 | 2
 *
 * Since a list consist of only one item, it is considered to be sorted.
 * Now merge the sorted lists
 *
 * 7 | 5 | 8 | 4 | 4 | 3 | 1 | 2
 * 5 7 | 4 8 | 3 4 | 1 2
 * 4 5 7  8 | 1 2 3 4
 * 1 2 3 4 4 5 7  8
 *
 * */
template<class T>
void merge(T *arr, int start, int mid, int end) {
    int n = end - start + 1;
    T temp[n];

    int i = start;
    int j = mid + 1;
    int k = 0;
    while (i <= mid && j <= end) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i];
            i++;
        } else {
            temp[k++] = arr[j];
            j++;
        }
    }

    for (int m = i; m <= mid; m++) { temp[k++] = arr[m]; }
    for (int m = j; m <= end; m++) { temp[k++] = arr[m]; }

    std::copy(temp, temp + n, arr + start);
}

template<class T>
void merge_sort(T *arr, int start, int end) {
    if (end - start <= 1) {
        if (arr[start] > arr[end]) std::swap(arr[start], arr[end]);
        return;
    }
    int mid = (start + end) / 2;
    merge_sort(arr, start, mid);
    merge_sort(arr, mid + 1, end);
    merge(arr, start, mid, end);
}

template<class T>
void mergesort(T *arr, int n) {
    merge_sort(arr, 0, n - 1);
}


int main() {
    int n = 500;
    int arr[n];
    for (int _ = 0; _ < 100; _++) {
        generate_random_arrs(arr, n);
        mergesort(arr, n);
        assert(std::is_sorted(arr, arr + n));
    }

    // Check if it works with chars
    n = 5;
    char str[] = {'w', 'a', 's', 'i', 'm'};
    mergesort(str, n);
    assert(std::is_sorted(str, str + n));

    std::cout << "Successfully sorted using merge sort! \n";
    return 0;
}