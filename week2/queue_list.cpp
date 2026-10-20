#include "../week1/list.cpp"

struct Queue {
    List items;

    Queue() {
        items.initList();
    }

    bool isEmpty() const {
        return items.size == 0;
    }

    bool enqueue(int value) {
        if (items.size >= 100) {
            return false;
        }

        items.insertTail(value);
        return true;
    }

    bool dequeue(int &value) {
        if (isEmpty()) {
            return false;
        }

        value = items.data[0];
        items.deleteHead();
        return true;
    }

    bool getFront(int &value) const {
        if (isEmpty()) {
            return false;
        }

        value = items.data[0];
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