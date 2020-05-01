#include <bits/stdc++.h>
#include <ostream>

using namespace std;


template<class T>
class vector_ {
private:
    T arr[2];
    size_t length = 0;
    size_t capacity = 2;
public:
    vector_() = default;

    // Copy constructor
    explicit vector_(const T &other) {
        arr = other.arr;
        length = other.length;
        capacity = other.capacity;
    }

    // copy assignment operator
    vector_& operator=(const T &other) {
        arr = other.arr;
        length = other.length;
        capacity = other.capacity;
        return *this;
    }

    // move constructor
    explicit vector_(const T &&other) noexcept {
        if (other == *this) return;

        arr = other.arr;
        length = other.length;
        capacity = other.capacity;
        delete other;
    }


    // move assignment operator
    vector_ operator=(const T &&other) noexcept {
        if (other == *this) return this;

        arr = other.arr;
        length = other.length;
        capacity = other.capacity;
        delete other;
        return this;
    }

    void push_back(const T &val) {
        if (length + 1 > capacity) {
            resize();
        }

        arr[length] = val;
        ++length;
    }

    void pop_back() {
        if (length > 0) {
            length -= 1;
        }
    }

    size_t size() const {
        return length;
    }

    T front() const {
        if (length < 1) throw ("Empty vector");
        return arr[0];
    }

    T back() const {
        if (length == 0) throw ("Empty vector");
        return arr[length - 1];
    }

    void resize() {
        capacity *= 2;
        auto temp = new T[capacity];
        std::move(arr, arr + length, temp);
//        temp.swap(arr);
    }

    friend ostream &operator<<(ostream &os, const vector_ &vector) {
        for (int i = 0; i < vector.length; i++) {
            os << vector.arr[i] << " ";
        }
        return os;
    }


};

int main() {
    vector_<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    auto temp = arr;
//    arr.push_back(3);
    cout << arr << endl;
    arr.pop_back();
    cout << arr << endl;
    cout << temp << endl;
}