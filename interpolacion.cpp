#include <iostream>
using namespace std;

int interpolationSearch(int arr[], int n, int x) {
    int low = 0, high = n - 1;

    while (low <= high && x >= arr[low] && x <= arr[high]) {
        // Fórmula de interpolación
        int pos = low + ((double)(high - low) / 
                        (arr[high] - arr[low])) * (x - arr[low]);

        // Verificar si encontramos el elemento
        if (arr[pos] == x)
            return pos;

        // Ajustar los límites
        if (arr[pos] < x)
            low = pos + 1;
        else
            high = pos - 1;
    }
    return -1; // No encontrado
}

int main() {
    int arr[] = {10, 20, 30, 40, 50, 60, 70};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 80;

    int index = interpolationSearch(arr, n, x);

    if (index != -1)
        cout << "Elemento encontrado en la posición: " << index << endl;
    else
        cout << "Elemento no encontrado." << endl;

    return 0;
}
