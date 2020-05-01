#include <bits/stdc++.h>

using namespace std;

void generate_random_arrs(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }
}

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