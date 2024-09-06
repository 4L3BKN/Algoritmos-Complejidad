#include <bits/stdc++.h>
#include "RandomNumbers.h"
#include <chrono>

using namespace std;
using namespace std::chrono;

//La idea del codigo fue sacada desde https://runestone.academy/ns/books/published/cppds/Sort/TheMergeSort.html

vector<int> mergeSort(vector<int> numeros) {
    if (numeros.size()>1) {
        int mid = numeros.size()/2;
        vector<int> lefthalf(numeros.begin(),numeros.begin()+mid);
        vector<int> righthalf(numeros.begin()+mid,numeros.begin()+numeros.size());

        lefthalf = mergeSort(lefthalf);
        righthalf = mergeSort(righthalf);

        unsigned i = 0;
        unsigned j = 0;
        unsigned k = 0;
        while (i < lefthalf.size() && j < righthalf.size()) {
            if (lefthalf[i] < righthalf[j]) {
                numeros[k]=lefthalf[i];
                i++;
            } else {
                numeros[k] = righthalf[j];
                j++;
            }
            k++;
        }

        while (i<lefthalf.size()) {
            numeros[k] = lefthalf[i];
            i++;
            k++;
        }

        while (j<righthalf.size()) {
            numeros[k]=righthalf[j];
            j++;
            k++;
        }

    }
    return numeros;
}

int main() {
    
    string filename;
    cout<<"Ingresar el nombre del archivo a leer:"<<endl;
    cin>> filename;

    vector<int> numeros = loadDatasetFromFile(filename);

    int n = numeros.size();
    auto start = high_resolution_clock::now();
    mergeSort(numeros);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout<< duration.count() << endl;

    string archivoResultado = "Resultado-MergeSort.txt";
    ofstream resultado(archivoResultado, ios::app);

    if (!resultado) {
        cerr << "Error al abrir el archivo para escritura.\n";
        return 1;
    }

    resultado <<"MergeSort tiempo de ordenamiento " << duration.count() << " microsegundos frente a un arreglo de largo " << n << endl;

    resultado.close();

    return 0;
}