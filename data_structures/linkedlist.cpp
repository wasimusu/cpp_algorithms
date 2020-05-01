#include <iostream>

using namespace std;

struct Node {
    int value;
    Node *next;

    Node(const int value) {
        this->value = value;
        next = nullptr;
    }
};

class linkedlist {
private:
    Node *head;
    size_t length;

public:
    linkedlist();

    explicit linkedlist(int value);

    void push_back(int value);

    void pop_back();

    void push_front(int value);

    void pop_front();

    int size() const { return length; }


    friend ostream &operator<<(ostream &os, const linkedlist &linkedlist);

    void print() const {
        auto *curr = head;
        while (curr != nullptr) {
            cout << curr->value << " ";
            curr = curr->next;
        }
        cout << endl;
    }

};

linkedlist::linkedlist() {
    head = nullptr;
    length = 0;
}

linkedlist::linkedlist(const int value) {
    head = new Node(value);
    length = 1;
}

void linkedlist::push_back(const int value) {
    auto *new_node = new Node(value);
    length++;

    if (head == nullptr) {
        head = new_node;
        return;
    }

    auto *current_node = head;
    while (current_node->next != nullptr) {
        current_node = current_node->next;
    }

    current_node->next = new_node;
}

void linkedlist::pop_back() {
    auto *curr = head;

    if (curr == nullptr) return;
    length--;

    if (curr->next == nullptr) {
        head = nullptr;
        return;
    }

    while (curr->next->next != nullptr) {
        curr = head->next;
    }
    curr->next = nullptr;
}

void linkedlist::push_front(const int value) {
    auto *current_node = new Node(value);
    length++;

    if (head == nullptr) {
        head = current_node;
        return;
    }

    current_node->next = head;
    head = current_node;
}

void linkedlist::pop_front() {
    if (head != nullptr) head = head->next;
}

ostream &operator<<(ostream &os, const linkedlist &linkedlist) {
    auto *curr = linkedlist.head;
    while (curr) {
        os << curr->value << " ";
        curr = curr->next;
    }
    return os;
}

int main() {

    linkedlist l1;
    l1.push_back(2);
    l1.push_back(3);
    l1.push_front(1);
//    l1.pop_back();
//    l1.pop_back();
//    l1.pop_back();
    l1.pop_front();
    l1.pop_front();
//    l1.pop_front();
    cout << l1 << endl;
    return 0;
}