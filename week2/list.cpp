#include <iostream>
using namespace std;
struct ArrayList {
    int* data;
    int capacity;
    int size;
    ArrayList(int cap = 100) {
        capacity = cap;
        size = 0;
        data = new int[capacity];
    }
    ~ArrayList() {
        delete[] data;
    }
    void traverseForward() {
        if (size == 0) {
            cout << "Danh sach rong!\n";
            return;
        }
        cout << "Duyet xuoi: ";
        for (int i = 0; i < size; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
    void traverseBackward() {
        if (size == 0) {
            cout << "Danh sach rong!\n";
            return;
        }
        cout << "Duyet nguoc: ";
        for (int i = size - 1; i >= 0; i--) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
    void insertHead(int val) {
        insertAt(val, 0);
    }
    void insertTail(int val) {
        insertAt(val, size);
    }
    void insertAt(int val, int k) {
        if (size >= capacity) {
            cout << "Mang da day!\n";
            return;
        }
        if (k < 0 || k > size) {
            cout << "Vi tri k khong hop le!\n";
            return;
        }
        for (int i = size; i > k; i--) {
            data[i] = data[i - 1];
        }
        data[k] = val;
        size++;
    }
    void deleteHead() {
        deleteAt(0);
    }
    void deleteTail() {
        deleteAt(size - 1);
    }
    void deleteAt(int k) {
        if (size == 0) {
            cout << "Danh sach rong, khong the xoa!\n";
            return;
        }
        if (k < 0 || k >= size) {
            cout << "Vi tri k khong hop le!\n";
            return;
        }
        for (int i = k; i < size - 1; i++) {
            data[i] = data[i + 1];
        }
        size--;
    }
};
int main() {
    ArrayList list;
    list.insertHead(10);
    list.insertHead(20);
    list.insertTail(30);
    list.insertAt(15, 1); 
    list.traverseForward();  
    list.traverseBackward(); 
    list.deleteHead();    
    list.deleteTail();      
    list.deleteAt(1);      
    list.traverseForward(); 
    return 0;
}