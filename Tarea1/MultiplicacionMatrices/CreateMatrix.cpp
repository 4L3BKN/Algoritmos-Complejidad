#include <iostream>
#include "RandomMatrix.h"

using namespace std;

int main() {
    srand(static_cast<unsigned int>(time(0)));  // Semilla para números aleatorios

    int numMatrices;
    int matrixSize;

    // Pedir al usuario el número de matrices y el tamaño de cada matriz
    cout << "Ingrese el número de matrices a generar: ";
    cin >> numMatrices;
    cout << "Ingrese el tamaño de las matrices cuadradas: ";
    cin >> matrixSize;

    vector<vector<vector<int>>> matrices;

    // Generar matrices aleatorias
    for (int i = 0; i < numMatrices; ++i) {
        matrices.push_back(generateRandomSquareMatrix(matrixSize));
    }

    // Guardar matrices en el archivo
    string filename;
    cout<<"Ingrese el nombre del archivo donde seran guardados los datos"<<endl;
    cin>> filename;
    saveMatricesToFile(matrices, filename);

    return 0;
}
