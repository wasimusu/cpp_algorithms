#include <bits/stdc++.h>

void generate_random_arrs(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }
}


void merge(int *arr, int start, int mid, int end) {
    int n = end - start + 1;
    int temp[n];

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


void merge_sort(int *arr, int start, int end) {
    if (end - start <= 1) {
        if (arr[start] > arr[end]) std::swap(arr[start], arr[end]);
        return;
    }
    int mid = (start + end) / 2;
    merge_sort(arr, start, mid);
    merge_sort(arr, mid + 1, end);
    merge(arr, start, mid, end);
}

void mergesort(int *arr, int n) {
    merge_sort(arr, 0, n - 1);
}


int main() {
    int n = 615;
    int arr[n];
    for (int _ = 0; _ < 100; _++) {
        generate_random_arrs(arr, n);
        mergesort(arr, n);
        assert(std::is_sorted(arr, arr + n));
    }
    std::cout << "Successfully sorted using merge sort! \n";
    return 0;
}