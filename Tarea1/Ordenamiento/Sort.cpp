#include <bits/stdc++.h>
#include "RandomNumbers.h"
#include <chrono>

using namespace std;
using namespace std::chrono;

int main(){

    string filename;
    cout<<"Ingresar el nombre del archivo a leer:"<<endl;
    cin>> filename;

    vector<int> numeros = loadDatasetFromFile(filename);

    int n = numeros.size();
    auto start = high_resolution_clock::now();
    sort(numeros.begin(), numeros.end());
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout<< duration.count() << endl;

    string archivoResultado = "Resultado-Sort.txt";
    ofstream resultado(archivoResultado, ios::app);

    if (!resultado) {
        cerr << "Error al abrir el archivo para escritura.\n";
        return 1;
    }

    resultado <<"Sort tiempo de ordenamiento " << duration.count() << " microsegundos frente a un arreglo de largo " << n << endl;

    resultado.close();

    return 0;
}