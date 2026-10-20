#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node* prev;

    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};
struct DoublyLinkedList {
    Node* head;
    Node* tail;
    int size;
    DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}
    void duyet_xuoi() {
        if (head == nullptr) {
            cout << "Danh sach rong!\n";
            return;
        }
        cout << "Duyet xuoi: ";
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    void duyet_nguoc() {
        if (tail == nullptr) {
            cout << "Danh sach rong!\n";
            return;
        }
        cout << "Duyet nguoc: ";
        Node* temp = tail;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << endl;
    }
    void them_dau(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        size++;
    }
    void them_cuoi(int val) {
        Node* newNode = new Node(val);
        if (tail == nullptr) {
            head = tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }
    void them_tai(int val, int k) {
        if (k < 0 || k > size) {
            cout << "Vi tri k khong hop le!\n";
            return;
        }
        if (k == 0) {
            them_dau(val);
            return;
        }
        if (k == size) {
            them_cuoi(val);
            return;
        }
        Node* newNode = new Node(val);
        Node* temp = head;
        for (int i = 0; i < k - 1; i++) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next->prev = newNode;
        temp->next = newNode;
        size++;
    }
    void xoa_dau() {
        if (head == nullptr) {
            cout << "Danh sach rong!\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }
        delete temp;
        size--;
    }
    void xoa_cuoi() {
        if (tail == nullptr) {
            cout << "Danh sach rong!\n";
            return;
        }
        Node* temp = tail;
        tail = tail->prev;
        if (tail != nullptr) {
            tail->next = nullptr;
        } else {
            head = nullptr;
        }
        delete temp;
        size--;
    }
    void xoa_tai(int k) {
        if (k < 0 || k >= size) {
            cout << "Vi tri k khong hop le!\n";
            return;
        }
        if (k == 0) {
            xoa_dau();
            return;
        }
        if (k == size - 1) {
            xoa_cuoi();
            return;
        }
        Node* temp = head;
        for (int i = 0; i < k; i++) {
            temp = temp->next;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
        size--;
    }
};
int main() {
    DoublyLinkedList dll;
    dll.them_dau(10);
    dll.them_dau(20);
    dll.them_cuoi(30);
    dll.them_tai(15, 1);
    dll.duyet_xuoi(); 
    dll.duyet_nguoc();
    dll.xoa_dau(); 
    dll.xoa_cuoi(); 
    dll.xoa_tai(1);   
    dll.duyet_xuoi(); 
    return 0;
}