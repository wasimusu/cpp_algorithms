/**
 * C++ style priority queues APIs
 * Allows make_heap, pop_heap, push_heap
 * */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <random>

using namespace std;

template<class T, class Comparator>
void _sift_down(T &arr, int parent_pos, size_t size, Comparator comparator) {
  int n = size - 1;
  int child_pos = 1;

  while (child_pos < n) {
    child_pos = parent_pos * 2 + 1;

    if (child_pos + 1 <= n && comparator(arr[child_pos + 1], arr[child_pos])) {
      child_pos = child_pos + 1;
    }

    if (!comparator(arr[parent_pos], arr[child_pos])) {
      swap(arr[parent_pos], arr[child_pos]);
    } else {
      return;
    }

    parent_pos = child_pos;
  }
}

template<class T, class Comparator>
void make_heap_(T &arr, Comparator comparator) {
  int n = arr.size();
  int start = (n - 1) / 2;
  while (start >= 0) {
    _sift_down(arr, start, arr.size(), comparator);
    start -= 1;
  }
}

template<class T>
void make_heap_(T &arr) {
  auto comparator = greater<>{};
  make_heap_(arr, comparator);
}

template<class T>
void push_heap_(T &arr) {
  int child_pos = arr.size() - 1;
  int parent_pos;
  while (child_pos > 0) {
    parent_pos = (child_pos - 1) / 2;

    if (arr[parent_pos] < arr[child_pos]) {
      swap(arr[parent_pos], arr[child_pos]);
    } else {
      break;
    }
    child_pos = parent_pos;
  }

}

template<class T, class Comparator>
void pop_heap_(T &arr, Comparator comparator) {
  int n = arr.size() - 1;
  swap(arr[0], arr[n]); // Swap the first & last item
  _sift_down(arr, 0, n, comparator);
}

int main() {
  vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  shuffle(arr.begin(), arr.end(), default_random_engine());
  make_heap_(arr);
//    pop_heap_(arr);
//    arr.pop_back();
  assert(is_heap(arr.begin(), arr.end()));
  return 0;
}