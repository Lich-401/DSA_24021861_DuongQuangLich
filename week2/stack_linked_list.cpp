#include "../week1/singly_linked_list.cpp"

struct Stack {
    SinglyLinkedList items;

    bool isEmpty() const {
        return items.head == nullptr;
    }

    void push(int value) {
        items.insertHead(value);
    }

    bool pop(int &value) {
        if (isEmpty()) {
            return false;
        }

        value = items.head->data;
        items.deleteHead();
        return true;
    }

    bool peek(int &value) const {
        if (isEmpty()) {
            return false;
        }

        value = items.head->data;
        return true;
    }
};

// int main() {
//     Stack stack;

//     stack.push(10);
//     stack.push(20);
//     stack.push(30);

//     int value;
//     if (stack.peek(value)) {
//         cout << "Top element: " << value << endl;
//     }

//     while (stack.pop(value)) {
//         cout << "Popped: " << value << endl;
//     }

//     if (stack.isEmpty()) {
//         cout << "The stack is empty." << endl;
//     }

//     return 0;
// }
