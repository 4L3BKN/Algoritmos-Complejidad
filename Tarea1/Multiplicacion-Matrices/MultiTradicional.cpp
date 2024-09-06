
#include <bits/stdc++.h>
#include <chrono>
#include "RandomMatrix.h"

using namespace std;
using namespace std::chrono;

int main() {
    string filename;  // Nombre del archivo que contiene las matrices
    cout<<"Ingresar el nombre del archivo a leer:"<<endl;
    cin>> filename;
    
    // Leer matrices del archivo
    vector<vector<vector<int>>> matrices = readMatricesFromFile(filename);

    // Asumimos que las matrices leídas son cuadradas y de igual tamaño
    int size = matrices[0].size();

    // Obtener las dos matrices para multiplicar
    vector<vector<int>> matrizA = matrices[0];
    vector<vector<int>> matrizB = matrices[1];

    // Matriz para almacenar el resultado de la multiplicación
    vector<vector<int>> mul(size, vector<int>(size, 0));

    auto start = high_resolution_clock::now();
    // Realizar la multiplicación de matrices
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            for (int k = 0; k < size; k++) {
                mul[i][j] += matrizA[i][k] * matrizB[k][j];
            }
        }
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout<< duration.count() << endl;

    string archivoResultado = "Resultado-MultiplicacionTradicional.txt";
    ofstream resultado(archivoResultado, ios::app);

    if (!resultado) {
        cerr << "Error al abrir el archivo para escritura.\n";
        return 1;
    }

    resultado <<"Multiplicación tradicional tiempo de multiplicación " << duration.count() << " microsegundos frente a una matriz de tamaño " << size << "x"<<size << endl;

    resultado.close();
    return 0;
}
