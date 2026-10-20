#include <iostream>
using namespace std;
struct List {
    int data[100];
    int size;
};
void khoi_tao(List &L) {
    L.size = 0;
}

void them_dau(List &L, int x) {
    if (L.size >= 100) return;
    for (int i = L.size; i > 0; i--) {
        L.data[i] = L.data[i - 1];
    }
    L.data[0] = x;
    L.size++;
}

void them_cuoi(List &L, int x) {
    if (L.size >= 100) return;
    L.data[L.size] = x;
    L.size++;
}

void them_tai(List &L, int x, int pos) {
    if (L.size >= 100) return;
    if (pos <= 0) {
        them_dau(L, x);
        return;
    }
    if (pos >= L.size) {
        them_cuoi(L, x);
        return;
    }
    for (int i = L.size; i > pos; i--) {
        L.data[i] = L.data[i - 1];
    }
    L.data[pos] = x;
    L.size++;
}

void xoa_dau(List &L) {
    if (L.size == 0) return;
    for (int i = 0; i < L.size - 1; i++) {
        L.data[i] = L.data[i + 1];
    }
    L.size--;
}

void xoa_cuoi(List &L) {
    if (L.size == 0) return;
    L.size--;
}

void xoa_tai(List &L, int pos) {
    if (L.size == 0 || pos < 0 || pos >= L.size) return;
    for (int i = pos; i < L.size - 1; i++) {
        L.data[i] = L.data[i + 1];
    }
    L.size--;
}

void duyet_xuoi(const List &L) {
    for (int i = 0; i < L.size; i++) {
        cout << L.data[i] << " ";
    }
    cout << endl;
}

void duyet_nguoc(const List &L) {
    for (int i = L.size - 1; i >= 0; i--) {
        cout << L.data[i] << " ";
    }
    cout << endl;
}

int main() {
    List L;
    khoi_tao(L);

    them_cuoi(L, 10);
    them_cuoi(L, 20);
    them_cuoi(L, 30);
    them_dau(L, 5);

    duyet_xuoi(L);
    duyet_nguoc(L);

    them_tai(L, 15, 2);
    duyet_xuoi(L);

    xoa_tai(L, 2);
    duyet_xuoi(L);

    xoa_dau(L);
    duyet_xuoi(L);

    xoa_cuoi(L);
    duyet_xuoi(L);

    return 0;
}