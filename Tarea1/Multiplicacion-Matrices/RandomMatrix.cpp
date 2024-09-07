#include "RandomMatrix.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>  
#include <ctime>    

using namespace std;

//Función que genera las matrices y sus valores.
vector<vector<int>> generateRandomSquareMatrix(int size) {
    vector<vector<int>> matrix(size, vector<int>(size));
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            matrix[i][j] = rand() % 100;  // Genera un número aleatorio entre 0 y 99
        }
    }
    return matrix;
}

//Función que guarda las matrices en un archivo de texto.
void saveMatricesToFile(const vector<vector<vector<int>>>& matrices, const string& filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        cerr << "No se pudo abrir el archivo para escribir." << endl;
        return;
    }

    //Escribe el número de matrices
    file << matrices.size() << endl;

    for (const auto& matrix : matrices) {
        int size = matrix.size();  //Para matrices cuadradas, filas = columnas

        //Escribe las dimensiones de la matriz
        file << size << " " << size << endl;

        //Escribe los elementos de la matriz
        for (const auto& row : matrix) {
            for (const auto& element : row) {
                file << element << " ";
            }
            file << endl;
        }
    }

    file.close();
    cout << "Matrices guardadas exitosamente en el archivo " << filename << "." << endl;
}


//Funcion que lee las matrices desde un archivo de texto.
vector<vector<vector<int>>> readMatricesFromFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "No se pudo abrir el archivo para leer." << endl;
        return {};
    }

    int numMatrices;
    file >> numMatrices;

    vector<vector<vector<int>>> matrices;

    for (int i = 0; i < numMatrices; ++i) {
        int size;
        file >> size >> size; 

        vector<vector<int>> matrix(size, vector<int>(size));

        for (int r = 0; r < size; ++r) {
            for (int c = 0; c < size; ++c) {
                file >> matrix[r][c];
            }
        }

        matrices.push_back(matrix);
    }

    file.close();
    return matrices;
}

//Función para transponer una matriz cuadrada (Ayuda de chatgpt)
vector<vector<int>> transposeMatrix(const vector<vector<int>>& matrix) {
    int size = matrix.size();
    vector<vector<int>> transposed(size, vector<int>(size, 0));

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            transposed[j][i] = matrix[i][j];
        }
    }

    return transposed;
}
