#include <bits/stdc++.h>
#include "RandomNumbers.h"
#include <chrono>

using namespace std;
using namespace std::chrono;

int main(){

    string filename;
    cout<<"Ingresar el nombre del archivo a leer:"<<endl;
    cin>> filename;

    //Carga el vector desde un archivo de texto
    vector<int> numeros = loadDatasetFromFile(filename);

    int n = numeros.size();
    auto start = high_resolution_clock::now();
    sort(numeros.begin(), numeros.end());//ordena los elementos del vector
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout<< duration.count() << endl;

    string archivoResultado = "Resultado-Sort.txt";
    ofstream resultado(archivoResultado, ios::app);

    if (!resultado) {
        cerr << "Error al abrir el archivo para escritura.\n";
        return 1;
    }

    resultado <<"Sort tiempo de ordenamiento " << duration.count() << " microsegundos frente a un arreglo de largo " << n << endl;//Guarda el resultado de la ejecución

    resultado.close();

    return 0;
}