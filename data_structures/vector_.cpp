#include <bits/stdc++.h>
#include <ostream>

using namespace std;


template<class T>
class vector_ {
private:
    size_t capacity = 2;
    unique_ptr<T[]> arr;
    size_t _size = 0;
public:
    vector_() {
        arr = make_unique<T[]>(capacity);
    }

    // Copy constructor
    explicit vector_(const T &other) {
        arr = other.arr;
        _size = other.length;
        capacity = other.capacity;
    }

    // copy assignment operator
    vector_ &operator=(const T &other) {
        arr = other.arr;
        _size = other.length;
        capacity = other.capacity;
        return *this;
    }

    T &operator[](int index) {
        return arr[index];
    }

    T &at(int index) {
        if (index >= _size) throw invalid_argument("Index out of range error");
        return arr[index];
    }

    void insert(const int index, const T &value) {
        if (_size + 1 > capacity) {
            resize();
        }
        if (index < 0 || index > _size) {
            throw invalid_argument("Index out of range error");
        }
        for (int i = _size; i > index; i--) {
            arr[i] = arr[i - 1];
        }
        arr[index] = value;
        ++_size;
    }

    // move constructor
    explicit vector_(const T &&other) noexcept {
        if (other == *this) return;

        arr = other.arr;
        _size = other.length;
        capacity = other.capacity;
        delete other;
    }


    // move assignment operator
    vector_ &operator=(const T &&other) noexcept {
        if (other == *this) return this;

        arr = other.arr;
        _size = other.length;
        capacity = other.capacity;
        delete other;
        return this;
    }

    void push_back(const T &val) {
        if (_size + 1 > capacity) {
            resize();
        }

        arr[_size] = val;
        ++_size;
    }

    void pop_back() {
        if (_size > 0) {
            _size -= 1;
        }
    }

    size_t size() const {
        return _size;
    }

    bool empty() const {
        return _size == 0;
    }

    T front() const {
        if (_size < 1) throw ("Empty vector");
        return arr[0];
    }

    T back() const {
        if (_size == 0) throw ("Empty vector");
        return arr[_size - 1];
    }

    void resize() {
        capacity *= 2;
        auto temp = make_unique<T[]>(capacity);
        for (int i = 0; i < _size; i++) {
            temp[i] = arr[i];
        }
        arr = std::move(temp);
    }

    T *begin() {
        return &arr[0];
    }

    T *end() {
        return &arr[_size];
    }

    ~vector_() {
    }

    void clear() {
        capacity = 4;
        vector_();
    }

    friend ostream &operator<<(ostream &os, const vector_ &vector) {
        for (int i = 0; i < vector._size; i++) {
            os << vector.arr[i] << " ";
        }
        return os;
    }


};

int main() {
    vector_<char> arr;
    arr.push_back('w');
    arr.push_back('s');
    arr.push_back('i');
    arr.push_back('m');
    arr.insert(1, 'a');
    arr.push_back('a');
    arr.push_back('k');
    arr.push_back('r');
    arr.push_back('a');
    arr.push_back('m');
    arr.push_back('k');
    arr.push_back('h');
    arr.push_back('a');
    arr.push_back('n');
    cout << arr << endl;
    cout << sizeof(arr) << endl;
    arr.clear();
}