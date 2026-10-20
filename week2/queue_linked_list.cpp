#include "../week1/singly_linked_list.cpp"

struct Queue {
    SinglyLinkedList items;

    bool isEmpty() const {
        return items.head == nullptr;
    }

    void enqueue(int value) {
        items.insertTail(value);
    }

    bool dequeue(int &value) {
        if (isEmpty()) {
            return false;
        }

        value = items.head->data;
        items.deleteHead();
        return true;
    }

    bool getFront(int &value) const {
        if (isEmpty()) {
            return false;
        }

        value = items.head->data;
        return true;
    }
};

// int main() {
//     Queue queue;

//     queue.enqueue(10);
//     queue.enqueue(20);
//     queue.enqueue(30);

//     int value;
//     if (queue.getFront(value)) {
//         cout << "Front element: " << value << endl;
//     }

//     while (queue.dequeue(value)) {
//         cout << "Dequeued: " << value << endl;
//     }

//     if (queue.isEmpty()) {
//         cout << "The queue is empty." << endl;
//     }

//     return 0;
// }