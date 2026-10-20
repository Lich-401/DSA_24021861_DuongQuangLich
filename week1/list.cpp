#include <iostream>
using namespace std;

struct List {
    int data[100];
    int size;

    void initList() {
        size = 0;
    }

    void insertHead(int value) {
        if (size >= 100) return;

        for (int i = size; i > 0; i--) {
            data[i] = data[i - 1];
        }

        data[0] = value;
        size++;
    }

    void insertTail(int value) {
        if (size >= 100) return;

        data[size] = value;
        size++;
    }

    void insertAt(int value, int position) {
        if (size >= 100) return;

        if (position <= 0) {
            insertHead(value);
            return;
        }
        if (position >= size) {
            insertTail(value);
            return;
        }

        for (int i = size; i > position; i--) {
            data[i] = data[i - 1];
        }

        data[position] = value;
        size++;
    }

    void deleteHead() {
        if (size == 0) return;

        for (int i = 0; i < size - 1; i++) {
            data[i] = data[i + 1];
        }

        size--;
    }

    void deleteTail() {
        if (size == 0) return;
        size--;
    }

    void deleteAt(int position) {
        if (size == 0 || position < 0 || position >= size) return;

        for (int i = position; i < size - 1; i++) {
            data[i] = data[i + 1];
        }

        size--;
    }

    void traverseForward() const {
        for (int i = 0; i < size; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }

    void traverseBackward() const {
        for (int i = size - 1; i >= 0; i--) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

// #ifndef LIST_NO_MAIN
// int main() {
//     List list;
//     list.initList();

//     list.insertTail(10);
//     list.insertTail(20);
//     list.insertTail(30);
//     list.insertHead(5);

//     list.traverseForward();
//     list.traverseBackward();

//     list.insertAt(15, 2);
//     list.traverseForward();

//     list.deleteAt(2);
//     list.traverseForward();

//     list.deleteHead();
//     list.traverseForward();

//     list.deleteTail();
//     list.traverseForward();

//     return 0;
// }
// #endif
