/**
 * C++ style priority queues APIs
 * Allows make_heap, pop_heap, push_heap
 * */

#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <cassert>

using namespace std;

void push_heap_(std::vector<int> &arr) {
    int pos = arr.size() - 1;
    int parentPos;
    while (pos != 0) {
        parentPos = (pos - 1) / 2;
        if (arr[pos] > arr[parentPos]) std::swap(arr[pos], arr[parentPos]);
        else break;
        pos = parentPos;
    }
}

// Consider this as an improvement from the standard API which does not decrease the end pointer.
void pop_heap_(std::vector<int> &arr) {

    int pos = arr.size() - 1;
    swap(arr[0], arr[pos]);
    arr.pop_back();
    cout << "Before : "; for(const auto x: arr) cout << x << " "; cout << endl;
    // repair downward
    int parentPos = 0;
    while(parentPos < pos){
        int c1 = parentPos * 2  + 1;
        int c2 = parentPos * 2 + 2;
        int c = max(c1, c2, [&arr](int a, int b){
            return arr[a] < arr[b];
        });
        if (arr[parentPos] > arr[c]) break;
        else swap(arr[parentPos], arr[c]);
        parentPos = c;
    }

    cout << "After : "; for(const auto x: arr) cout << x << " "; cout << endl;
}


//void make_heap_(std::vector<int> &arr) {
//    std::vector<int> res;
//    for (const auto x: arr) {
//        res.push_back(x);
//        push_heap_(res);
//    }
//    res.swap(arr);
//}


void make_heap(std::vector<int>& arr){
    int n = arr.size() -1;
    int parent = 0;
    while(parent < n){
        int left = 2 * parent  + 1;
        int right = left + 1;

        if (left < n && arr[left] > arr[parent]){
            parent = left;
        }

        if (right < n && arr[right] > arr[parent]){
            parent = right;
        }

        swap(arr[parent], arr[])

    }
}

void sort_heap(std::vector<int> &arr) {
    if (!is_heap(arr.begin(), arr.end())) throw std::invalid_argument("arr must be heapified before using sort_heap");
    vector<int> res(arr.size(), 0);
    int i = 0;
    while (!arr.empty()) {
        res[i++] = arr[0];
        auto res{arr};
        pop_heap_(arr);
//        make_heap(arr.begin(), arr.end());
//        cout << "Heap : "; for(const auto x: arr) cout << x << " "; cout << endl;
        pop_heap(res.begin(), res.end());
        res.pop_back();
        make_heap(res.begin(), res.end());
        cout << "Heap : "; for(const auto x: res) cout << x << " "; cout << endl;
        assert(is_heap(arr.begin(), arr.end()));
    }
    arr = res;
}


int main() {

    int N = 10;
    std::vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    make_heap_(arr);

    const auto heapified = std::is_heap(arr.begin(), arr.end());
    assert(heapified);

    sort_heap(arr);
    for (const auto x: arr) std::cout << x << " ";
    return 0;
}