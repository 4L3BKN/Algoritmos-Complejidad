#ifndef RANDOMMATRIX_H
#define RANDOMMATRIX_H

#include <vector>
#include <string>

using namespace std;
// Función para generar una matriz cuadrada con valores aleatorios
vector<vector<int>> generateRandomSquareMatrix(int size);

// Función para guardar matrices en un archivo
void saveMatricesToFile(const vector<vector<vector<int>>>& matrices, const string& filename);

// Función para leer matrices desde un archivo
vector<vector<vector<int>>> readMatricesFromFile(const string& filename);

// Función para transponer una matriz
vector<vector<int>> transposeMatrix(const vector<vector<int>>& matrix);
#endif // RANDOMMATRIX_H
