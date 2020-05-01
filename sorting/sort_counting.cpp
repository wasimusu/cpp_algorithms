#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
#include "../utils.cpp"


void generate_random_arrs(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10;
    }
}


/**
 * Count freq of each item
 * Useful if the range of numbers is small compared to the length of the array
 */
template<class T>
void counting_sort(T *arr, int n) {
    std::map<int, int> counter;
    for(int i = 0; i < n; i++)
        counter[arr[i]] += 1;

    int j = 0;
    for(auto kv: counter){
        for(int i = 0; i < kv.second; i++) arr[j++] = kv.first;
    }
}


int main() {
    int n = 200;
    int arr[n];
    for (int _ = 0; _ < 100; _++) {
        generate_random_arrs(arr, n);
        counting_sort(arr, n);
        assert(std::is_sorted(arr, arr + n));
    }
    std::cout << "Successfully sorted using counting sort! \n";
    return 0;
}