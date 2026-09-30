#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};
class SinglyLinkedList {
private:
    Node* head;
    int size;
    void traverseBackwardHelper(Node* current) {
        if (current == nullptr) return;
        traverseBackwardHelper(current->next);
        cout << current->data << " ";
    }
public:
    SinglyLinkedList() : head(nullptr), size(0) {}
    ~SinglyLinkedList() {
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
        if (head == nullptr) {
            cout << "Danh sach rong!\n";
            return;
        }
        cout << "Duyet nguoc: ";
        traverseBackwardHelper(head);
        cout << endl;
    }
    void insertHead(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
        size++;
    }
    void insertTail(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
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
        Node* newNode = new Node(val);
        Node* temp = head;
        for (int i = 0; i < k - 1; i++) {
            temp = temp->next;
        }
        newNode->next = temp->next;
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
        delete temp;
        size--;
    }
    void deleteTail() {
        if (head == nullptr) {
            cout << "Danh sach rong!\n";
            return;
        }
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
        } else {
            Node* temp = head;
            while (temp->next->next != nullptr) {
                temp = temp->next;
            }
            delete temp->next;
            temp->next = nullptr;
        }
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
        Node* temp = head;
        for (int i = 0; i < k - 1; i++) {
            temp = temp->next;
        }
        Node* nodeToDelete = temp->next;
        temp->next = nodeToDelete->next;
        delete nodeToDelete;
        size--;
    }
};
int main() {
    SinglyLinkedList sll;
    sll.insertHead(10);
    sll.insertHead(20);
    sll.insertTail(30);
    sll.insertAt(15, 1);
    sll.traverseForward(); 
    sll.traverseBackward();
    sll.deleteHead();    
    sll.deleteTail();    
    sll.deleteAt(1);     
    sll.traverseForward(); 
    return 0;
}