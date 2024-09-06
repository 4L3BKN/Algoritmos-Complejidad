#include "RandomNumbers.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Implementación de la función para generar un dataset aleatorio
vector<int> generateRandomDataset(size_t size, int minVal, int maxVal) {
    vector<int> data(size);
    srand(static_cast<unsigned>(time(0))); // Semilla para números aleatorios

    for (size_t i = 0; i < size; ++i) {
        data[i] = minVal + rand() % (maxVal - minVal + 1);
    }

    return data;
}

// Implementación de la función para guardar un dataset en un archivo de texto
void saveDatasetToFile(const vector<int>& data, const string& filename) {
    ofstream outFile(filename);
    if (!outFile) {
        cerr << "Error al abrir el archivo para escritura.\n";
        return;
    }

    for (int num : data) {
        outFile << num << " ";
    }

    outFile.close();
}

// Implementación de la función para cargar un dataset desde un archivo de texto
vector<int> loadDatasetFromFile(const string& filename) {
    vector<int> data;
    ifstream inFile(filename);

    if (!inFile) {
        cerr << "Error al abrir el archivo para lectura.\n";
        return data;
    }

    int num;
    while (inFile >> num) {
        data.push_back(num);
    }

    inFile.close();
    return data;
}
