#include <iostream>
#include "RandomMatrix.h"

using namespace std;

int main() {
    srand(static_cast<unsigned int>(time(0)));

    int numMatrices = 2;
    int matrixSize;

    cout << "Ingrese el tamaño de las matrices cuadradas: ";
    cin >> matrixSize;

    vector<vector<vector<int>>> matrices;

    //Generar matrices aleatorias
    for (int i = 0; i < numMatrices; ++i) {
        matrices.push_back(generateRandomSquareMatrix(matrixSize));
    }

    //Guardar matrices en el archivo
    string filename;
    filename = "RandomMatrix-";
    filename += to_string(matrixSize);
    filename += ".txt";

    saveMatricesToFile(matrices, filename);
    
    cout << "Dataset guardado en el archivo " << filename << ".\n";
    return 0;
}
