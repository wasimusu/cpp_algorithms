#include <iostream>

using namespace std;

template<typename T>
struct ListNode {
    explicit ListNode(const T &value) : value(value), prev(0), next(0) {}

    T value;
    ListNode<T> *next;
    ListNode<T> *prev;
};

template<typename T>
class list {
private:
    ListNode<T> *head;
    ListNode<T> *tail;
    size_t _size;
public:
    list() : head(nullptr), tail(nullptr), _size(0) {}

    list(const list &other) = default;

    list(list &&other) noexcept = default;

    list &operator=(const list &other) = default;

    list &operator=(list &&other) noexcept = default;

    int size() const { return _size; }

    void pop_front() {
        _remove_internal(head);
    }

    void pop_back() {
        _remove_internal(tail);
    }

    void _remove_internal(ListNode<T> *pos) {
        if (pos) {
            if (pos->prev)
                pos->prev->next = pos->next;

            if (pos->next)
                pos->next->prev = pos->prev;

            if (pos == head)
                head = pos->next;

            if (pos == tail)
                tail = tail->prev;

            delete pos;
            _size--;
        }
    }

    void push_front(const T &value) {
        auto *node = new ListNode<T>(value);
        if (!head && !tail) {
            head = node;
            tail = node;
        } else if (head) {
            auto temp = head;
            head = node;
            temp->prev = head;
            head->next = temp;
            // Do I need to delete temp here.
        }
        _size++;
    }

    void push_back(const T &value) {
        auto *node = new ListNode<T>(value);
        if (!head && !tail) {
            head = node;
            tail = node;
        } else if (tail) {
            auto t_temp = tail;
            tail->next = node;
            tail = tail->next;
            tail->prev = t_temp;
        }
        _size++;
    }

    T *begin() const {
        return head;
    }

    T *end() const {
        return tail;
    }

    void clear() {
        list();
    }

    ~list() = default;

    friend ostream &operator<<(ostream &os, list &other) {
        auto t_head = other.head;
        while (t_head != other.tail) {
            os << t_head->value << " ";
            t_head = t_head->next;
        }
        if(t_head) os << t_head->value;
        return os;
    }

};

int main() {

    list<int> ll;
    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(3);
    ll.push_front(4);
    ll.push_front(-1);
    ll.push_front(-2);
    ll.push_front(-3);
    ll.push_front(-4);
    cout << ll << endl;
    return 0;
}