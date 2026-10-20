#include <iostream>
using namespace std;
struct List {
    int data[100];
    int size;
};

void initList(List &L) {
    L.size = 0;
}

void insertHead(List &L, int x) {
    if (L.size >= 100) return;
    for (int i = L.size; i > 0; i--) {
        L.data[i] = L.data[i - 1];
    }
    L.data[0] = x;
    L.size++;
}

void insertTail(List &L, int x) {
    if (L.size >= 100) return;
    L.data[L.size] = x;
    L.size++;
}

void insertAt(List &L, int x, int pos) {
    if (L.size >= 100) return;
    if (pos <= 0) {
        insertHead(L, x);
        return;
    }
    if (pos >= L.size) {
        insertTail(L, x);
        return;
    }
    for (int i = L.size; i > pos; i--) {
        L.data[i] = L.data[i - 1];
    }
    L.data[pos] = x;
    L.size++;
}

void deleteHead(List &L) {
    if (L.size == 0) return;
    for (int i = 0; i < L.size - 1; i++) {
        L.data[i] = L.data[i + 1];
    }
    L.size--;
}

void deleteTail(List &L) {
    if (L.size == 0) return;
    L.size--;
}

void deleteAt(List &L, int pos) {
    if (L.size == 0 || pos < 0 || pos >= L.size) return;
    for (int i = pos; i < L.size - 1; i++) {
        L.data[i] = L.data[i + 1];
    }
    L.size--;
}

void printForward(const List &L) {
    for (int i = 0; i < L.size; i++) {
        cout << L.data[i] << " ";
    }
    cout << endl;
}

void printBackward(const List &L) {
    for (int i = L.size - 1; i >= 0; i--) {
        cout << L.data[i] << " ";
    }
    cout << endl;
}

int main() {
    List L;
    initList(L);

    insertTail(L, 10);
    insertTail(L, 20);
    insertTail(L, 30);
    insertHead(L, 5);

    printForward(L);
    printBackward(L);

    insertAt(L, 15, 2);
    printForward(L);

    deleteAt(L, 2);
    printForward(L);

    deleteHead(L);
    printForward(L);

    deleteTail(L);
    printForward(L);

    return 0;
}