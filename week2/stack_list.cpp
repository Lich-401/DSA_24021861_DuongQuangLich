// #define LIST_NO_MAIN
#include "../week1/list.cpp"

struct Stack {
    List items;

    void init() {
        items.initList();
    }

    bool isEmpty() const {
        return items.size == 0;
    }

    bool push(int value) {
        if (items.size >= 100) {
            return false;
        }

        items.insertTail(value);
        return true;
    }

    bool pop(int &value) {
        if (isEmpty()) {
            return false;
        }

        value = items.data[items.size - 1];
        items.deleteTail();
        return true;
    }

    bool peek(int &value) const {
        if (isEmpty()) {
            return false;
        }

        value = items.data[items.size - 1];
        return true;
    }
};

// int main() {
//     Stack stack;
//     stack.init();
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