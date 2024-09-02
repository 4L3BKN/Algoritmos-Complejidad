#include <iostream>
#include <vector>
#include <chrono>
#include "RandomMatrix.h"  // Incluir el archivo de cabecera que contiene nuestras funciones

using namespace std;
using namespace std::chrono;

int main() {
    string filename;  // Nombre del archivo que contiene las matrices
    cout<<"Ingresar el nombre del archivo a leer:"<<endl;
    cin>> filename;
    
    // Leer matrices del archivo
    vector<vector<vector<int>>> matrices = readMatricesFromFile(filename);

    // Verificar si hay al menos dos matrices en el archivo
    if (matrices.size() < 2) {
        cerr << "El archivo debe contener al menos dos matrices para multiplicar." << endl;
        return 1;
    }

    // Asumimos que las matrices leídas son cuadradas y de igual tamaño
    int size = matrices[0].size();

    // Obtener las dos matrices para multiplicar
    vector<vector<int>> a = matrices[0];
    vector<vector<int>> b = matrices[1];

    // Matriz para almacenar el resultado de la multiplicación
    vector<vector<int>> mul(size, vector<int>(size, 0));

    auto start = high_resolution_clock::now();
    // Realizar la multiplicación de matrices
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            for (int k = 0; k < size; k++) {
                mul[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout<< duration.count() << endl;

    return 0;
}
