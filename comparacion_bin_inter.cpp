#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

// Búsqueda Binaria
int binarySearch(int arr[], int n, int x) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == x)
            return mid;
        else if (arr[mid] < x)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

// Búsqueda por Interpolación
int interpolationSearch(int arr[], int n, int x) {
    int low = 0, high = n - 1;
    while (low <= high && x >= arr[low] && x <= arr[high]) {
        int pos = low + ((double)(high - low) / 
                        (arr[high] - arr[low])) * (x - arr[low]);
        if (arr[pos] == x)
            return pos;
        if (arr[pos] < x)
            low = pos + 1;
        else
            high = pos - 1;
    }
    return -1;
}

int main() {
    const int n = 1000000; // 1 millón de elementos
    int* arr = new int[n];

    // Generar arreglo ordenado y uniformemente distribuido
    for (int i = 0; i < n; i++) {
        arr[i] = i * 2; // valores pares
    }

    int x = 987654; // valor a buscar

    // Medir tiempo búsqueda binaria
    clock_t start = clock();
    int indexBinary = binarySearch(arr, n, x);
    clock_t end = clock();
    double timeBinary = double(end - start) / CLOCKS_PER_SEC;

    // Medir tiempo búsqueda por interpolación
    start = clock();
    int indexInterpolation = interpolationSearch(arr, n, x);
    end = clock();
    double timeInterpolation = double(end - start) / CLOCKS_PER_SEC;

    // Resultados
    cout << "Resultado búsqueda binaria: " << indexBinary 
         << " en " << timeBinary << " segundos." << endl;

    cout << "Resultado búsqueda por interpolación: " << indexInterpolation 
         << " en " << timeInterpolation << " segundos." << endl;

    delete[] arr;
    return 0;
}
