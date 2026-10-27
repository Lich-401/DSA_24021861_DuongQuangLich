#include <iostream>
#include <utility>
#include <vector>
using namespace std;

int partition(vector<int>& vec, int low, int high) {
    int pivot = vec[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (vec[j] <= pivot) {
            i++;
            swap(vec[i], vec[j]);
        }
    }
    swap(vec[i + 1], vec[high]);
    return i + 1;
}

void quickSort(vector<int>& vec, int low, int high) {
    if (low < high) {
        int pi = partition(vec, low, high);
        quickSort(vec, low, pi - 1);
        quickSort(vec, pi + 1, high);
    }
}

int main() {
    vector<int> vec = {4, 3, 1, 2, 5, 9, 7, 10, 6};
    int n = vec.size();
    quickSort(vec, 0, n - 1);
    for (int i : vec) {
        cout << i << " ";
    }
    return 0;
}