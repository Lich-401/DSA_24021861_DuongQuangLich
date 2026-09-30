#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node* prev;

    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};
class DoublyLinkedList {
private:
    Node* head;
    Node* tail;
    int size;
public:
    DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}
    ~DoublyLinkedList() {
        while (head != nullptr) {
            deleteHead();
        }
    }
    void traverseForward() {
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
    void traverseBackward() {
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
    void insertHead(int val) {
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
    void insertTail(int val) {
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
    void insertAt(int val, int k) {
        if (k < 0 || k > size) {
            cout << "Vi tri k khong hop le!\n";
            return;
        }
        if (k == 0) {
            insertHead(val);
            return;
        }
        if (k == size) {
            insertTail(val);
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
    void deleteHead() {
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
    void deleteTail() {
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
    void deleteAt(int k) {
        if (k < 0 || k >= size) {
            cout << "Vi tri k khong hop le!\n";
            return;
        }
        if (k == 0) {
            deleteHead();
            return;
        }
        if (k == size - 1) {
            deleteTail();
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
    dll.insertHead(10);
    dll.insertHead(20);
    dll.insertTail(30);
    dll.insertAt(15, 1); 
    dll.traverseForward();  
    dll.traverseBackward(); 
    dll.deleteHead();    
    dll.deleteTail();    
    dll.deleteAt(1);     
    dll.traverseForward();  
    return 0;
}