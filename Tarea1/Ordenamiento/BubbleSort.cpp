#include <bits/stdc++.h>
#include "RandomNumbers.h"
#include <chrono>

using namespace std;
using namespace std::chrono;

int main(){

    string filename;

    cout<<"Ingresar el nombre del archivo a leer: (tiene que incluir el .txt)"<<endl;
    cin>> filename;

    //Carga el vector desde el archivo de texto
    vector<int> numeros = loadDatasetFromFile(filename);
    
    int n = numeros.size();
    auto start = high_resolution_clock::now();
    for(int i  = 0; i < n; i++){//Recorre el arreglo, elemento por elemento
        for(int j = 0; j < n - 1; j++){
            if(numeros[j] > numeros[j+1]){
                swap(numeros[j], numeros[j+1]);
            }
        }
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout<< duration.count() << endl;

    string archivoResultado = "Resultado-BubbleSort.txt";
    ofstream resultado(archivoResultado, ios::app);

    if (!resultado) {
        cerr << "Error al abrir el archivo para escritura.\n";
        return 1;
    }

    resultado <<"BubbleSort tiempo de ordenamiento " << duration.count() << " microsegundos frente a un arreglo de largo " << n << endl;//Guarda el resultado de la ejecución.

    resultado.close();
    return  0;
}