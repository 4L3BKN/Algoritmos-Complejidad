#include <bits/stdc++.h>
#include "RandomNumbers.h"
#include <chrono>

using namespace std;
using namespace std::chrono;
int main(){

    string filename;

    cout<<"Ingresar el nombre del archivo a leer:"<<endl;
    cin>> filename;

    // Cargar dataset desde el archivo de texto
    vector<int> numeros = loadDatasetFromFile(filename);
    auto start = high_resolution_clock::now();
    int n = numeros.size();

    for(int i  = 0; i < n; i++){
        for(int j = 0; j < n - 1; j++){
            if(numeros[j] > numeros[j+1]){
                swap(numeros[j], numeros[j+1]);
            }
        }
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout<< duration.count() << endl;
    return  0;
}