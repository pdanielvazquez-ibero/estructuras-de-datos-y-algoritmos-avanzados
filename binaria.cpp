#include <iostream>
#include <vector>
using namespace std;

int binarySearchIterative(const vector<int>& a, int target) {
    int low = 0;
    int high = (int)a.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2; // punto medio

        if (a[mid] == target) {
            return mid; // encontrado
        } else if (a[mid] < target) {
            // target está a la derecha
            low = mid + 1;
        } else {
            // a[mid] > target, target está a la izquierda
            high = mid - 1;
        }
    }

    // no se encontró
    return -1;
}

int main() {
    vector<int> a = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int target = 72;

    int index = binarySearchIterative(a, target);

    if (index == -1) {
        cout << "Elemento no encontrado\n";
    } else {
        cout << "Elemento encontrado en el índice " << index << "\n";
    }

    return 0;
}