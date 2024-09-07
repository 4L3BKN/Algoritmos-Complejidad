#include <bits/stdc++.h>
#include <chrono>
#include "RandomMatrix.h" 

using namespace std;
using namespace std::chrono;

int main() {
    string filename;  
    cout<<"Ingresar el nombre del archivo a leer:"<<endl;
    cin>> filename;
    
    //Obtiene las matrices desde un archivo 
    vector<vector<vector<int>>> matrices = readMatricesFromFile(filename);

    int size = matrices[0].size();

    //Divide las matrices en variables distintas para poder multiplicarlas
    vector<vector<int>> matrizA = matrices[0];
    vector<vector<int>> matrizB = matrices[1];

    //Transponer la segunda matriz
    vector<vector<int>> transpuestaB = transposeMatrix(matrizB);

    //Matriz que guarda el resultado de la multiplicación
    vector<vector<int>> mul(size, vector<int>(size, 0));

    auto start = high_resolution_clock::now();
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            for (int k = 0; k < size; k++) {
                mul[i][j] += matrizA[i][k] * transpuestaB[j][k];
            }
        }
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout<< duration.count() << endl;
    
    string archivoResultado = "Resultado-MultiplicacionTradicionalTranspuesta.txt";
    ofstream resultado(archivoResultado, ios::app);

    if (!resultado) {
        cerr << "Error al abrir el archivo para escritura.\n";
        return 1;
    }

    //Guarda el resultado de la ejecución
    resultado <<"Multiplicación tradicional con matriz transpuesta tiempo de multiplicación " << duration.count() << " microsegundos frente a una matriz de tamaño " << size << "x"<<size << endl;

    resultado.close();
    return 0;
}
