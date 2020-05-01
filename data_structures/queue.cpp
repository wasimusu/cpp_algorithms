// push, pop, front, back

#include <stdexcept>
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

class Queue {
private:
    Node *head;
    size_t length;
public:
    Queue() {
        head = nullptr;
        length = 0;
    }

    void push_back(const int value) {
        auto new_node = new Node(value);
        length++;

        if (head == nullptr) {
            head = new_node;
            return;
        }

        auto *current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = new_node;
    }

    void pop_front() {
        if (head == nullptr) return;
        head = head->next;
    }

    /**
     * @brief Provides random access to the queue. Technically it is not random access.
     * It results in undefined behavior if you're not careful with the index */
    int operator[](const int index) noexcept {
        int id = 0;
        Node *temp = head;
        while (id != index) {
            id++;
            temp = temp->next;
        }
        return head->value;
    }

    /**
     * @brief returns the value at user given index
     * @param[in]index: the index at which value is requested     *
     * @throws out_of_range exception if the index is greater than or equal
     * @see operator[]
     * to the legnth of the queue*/
    int at(const int index) {
        if (index >= length) throw out_of_range("Index out of range. Please mind that the index is zero-based");
        return operator[](index);
    }

    int size() const { return length; }

    friend std::ostream &operator<<(std::ostream &os, const Queue &queue) {
        Node *current_node = queue.head;
        while (current_node) {
            os << current_node->value << " ";
            current_node = current_node->next;
        }
        return os;
    }
};

int main(int argc, char **argv) {
    Queue queue;
    queue.push_back(1);
    queue.push_back(2);
    queue.push_back(3);
//    queue.pop_front();
//    queue.pop_front();
//    queue.pop_front();
    cout << queue << endl;
    cout << queue[0] << endl;

}