#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};
struct SinglyLinkedList {
    Node* head;
    SinglyLinkedList() {
        head = nullptr;
    }

    void traverseForward() {
        if (head == nullptr) {
            return;
        }
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }
    
    void printReverse(Node* current) {
        if (current == nullptr) return;
        printReverse(current->next);
        cout << current->data << " ";
    }
    
    void traverseBackward() {
        if (head == nullptr) {
            return;
        }
        printReverse(head);
        cout << endl;
    }
    
    void insertHead(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }
    
    void insertTail(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    
    void insertAt(int val, int k) {
        if (k == 0) {
            insertHead(val);
            return;
        }
        Node* temp = head;
        for (int i = 0; i < k - 1; i++) {
            if (temp == nullptr) {
                cout << "Vi tri k khong hop le!\n";
                return;
            }
            temp = temp->next;
        }
        if (temp == nullptr) {
            cout << "Vi tri k khong hop le!\n";
            return;
        }
        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
    }
    
    void deleteHead() {
        if (head == nullptr) return;
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    
    void deleteTail() {
        if (head == nullptr) return;
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
    }
    
    void deleteAt(int k) {
        if (head == nullptr) return;
        if (k == 0) {
            deleteHead();
            return;
        }
        Node* temp = head;
        for (int i = 0; i < k - 1; i++) {
            if (temp->next == nullptr) {
                cout << "Vi tri k khong hop le!\n";
                return;
            }
            temp = temp->next;
        }
        if (temp->next == nullptr) return;
        Node* p = temp->next;
        temp->next = p->next;
        delete p;
    }
};
// int main() {
//     SinglyLinkedList list;
//     list.insertHead(10);
//     list.insertHead(20);
//     list.insertTail(30);
//     list.insertAt(15, 1);
//     list.traverseForward();
//     list.traverseBackward();
//     list.deleteHead();
//     list.deleteTail();
//     list.deleteAt(1);
//     list.traverseForward();
//     return 0;
// }