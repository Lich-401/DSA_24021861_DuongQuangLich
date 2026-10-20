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
    void duyet_xuoi() {
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
    void in_nguoc(Node* current) {
        if (current == nullptr) return;
        in_nguoc(current->next);
        cout << current->data << " ";
    }
    void duyet_nguoc() {
        if (head == nullptr) {
            return;
        }
        in_nguoc(head);
        cout << endl;
    }
    void them_dau(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }
    void them_cuoi(int val) {
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
    void them_tai(int val, int k) {
        if (k == 0) {
            them_dau(val);
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
    void xoa_dau() {
        if (head == nullptr) return;
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    void xoa_cuoi() {
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
    void xoa_tai(int k) {
        if (head == nullptr) return;
        if (k == 0) {
            xoa_dau();
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
int main() {
    SinglyLinkedList list;
    list.them_dau(10);
    list.them_dau(20);
    list.them_cuoi(30);
    list.them_tai(15, 1);
    list.duyet_xuoi(); 
    list.duyet_nguoc();
    list.xoa_dau(); 
    list.xoa_cuoi(); 
    list.xoa_tai(1);   
    list.duyet_xuoi(); 
    return 0;
}