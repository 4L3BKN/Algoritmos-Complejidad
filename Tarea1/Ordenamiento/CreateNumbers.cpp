#include <iostream>
#include "RandomNumbers.h"  // Incluir el archivo de encabezado

using namespace std;

int main() {
    size_t size; // Tamaño del dataset
    int minVal, maxVal; // Rango de valores aleatorios
    string filename;

    cout<<"Ingresa el tamaño del dataset:"<<endl;
    cin>> size;
    cout<<"Ingresa el valor minimo que puede tomar los datos:"<<endl;
    cin>> minVal;
    cout<<"Ingresa el valor maximo que puede tomar los datos:"<<endl;
    cin>> maxVal;

    cout<<"Ingrese el nombre del archivo donde seran guardados los datos"<<endl;
    cin>> filename;
    // Generar dataset aleatorio
    vector<int> randomData = generateRandomDataset(size, minVal, maxVal);

    // Guardar dataset en un archivo de texto
    
    saveDatasetToFile(randomData, filename);

    cout << "Dataset guardado en el archivo " << filename << ".\n";

    return 0;
}
