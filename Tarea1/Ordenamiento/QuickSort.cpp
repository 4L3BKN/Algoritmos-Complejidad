#include <bits/stdc++.h>
#include "RandomNumbers.h"
#include <chrono>

using namespace std;
using namespace std::chrono;

//El codigo fue sacado desde  https://www.geeksforgeeks.org/cpp-program-for-quicksort

int partition(vector<int> &numeros, int low, int high) {

    // Elige el ultimo elemento como pivote
    int pivot = numeros[high];

    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {

        // Si el numero en la posición j es menor al pivote
        if (numeros[j] <= pivot) {
            i++;
            swap(numeros[i], numeros[j]);
        }
    }

    // Pone al pivote en la otra posición
    swap(numeros[i + 1], numeros[high]);

    // Return the point of partition
    return (i + 1);
}

void quickSort(vector<int> &numeros, int low, int high) {

    //Se hace si el pivote tiene algo a su izquierda
    if (low < high) {

        int p = partition(numeros, low, high);
        quickSort(numeros, low, p - 1);
        quickSort(numeros, p + 1, high);
    }
}

int main() {

    string filename;
    cout<<"Ingresar el nombre del archivo a leer:"<<endl;
    cin>> filename;
    
    //Carga el vector desde el archivo de texto
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

    resultado <<"QuickSort tiempo de ordenamiento " << duration.count() << " microsegundos frente a un arreglo de largo " << n << endl;//Guarda el resultado de la ejecución

    resultado.close();
    return 0;
}
