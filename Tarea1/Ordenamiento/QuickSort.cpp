#include <bits/stdc++.h>
#include "RandomNumbers.h"
#include <chrono>

using namespace std;
using namespace std::chrono;

//La idea del codigo fue sacada desde  https://www.geeksforgeeks.org/cpp-program-for-quicksort

int partition(vector<int> &numeros, int low, int high) {

    // Selecting last element as the pivot
    int pivot = numeros[high];

    // Index of elemment just before the last element
    // It is used for swapping
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {

        // If current element is smaller than or
        // equal to pivot
        if (numeros[j] <= pivot) {
            i++;
            swap(numeros[i], numeros[j]);
        }
    }

    // Put pivot to its position
    swap(numeros[i + 1], numeros[high]);

    // Return the point of partition
    return (i + 1);
}

void quickSort(vector<int> &numeros, int low, int high) {

    // Base case: This part will be executed till the starting
    // index low is lesser than the ending index high
    if (low < high) {

        // p is partitioning index, arr[p] is now at
        // right place
        int p = partition(numeros, low, high);

        // Separately sort elements before and after the
        // partition index p
        quickSort(numeros, low, p - 1);
        quickSort(numeros, p + 1, high);
    }
}

int main() {

    string filename;
    cout<<"Ingresar el nombre del archivo a leer:"<<endl;
    cin>> filename;
    
    vector<int> numeros = loadDatasetFromFile(filename);

    int n = numeros.size();
    
    auto start = high_resolution_clock::now();
    quickSort(numeros, 0, n - 1);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout<< duration.count() << endl;

    string archivoResultado = "Resultado-QuickSort.txt";
    ofstream resultado(archivoResultado, ios::app);

    if (!resultado) {
        cerr << "Error al abrir el archivo para escritura.\n";
        return 1;
    }

    resultado <<"QuickSort tiempo de ordenamiento " << duration.count() << " microsegundos frente a un arreglo de largo " << n << endl;

    resultado.close();
    return 0;
}
