#include <iostream>
#include "RandomNumbers.h" 

using namespace std;

int main() {
    size_t size; // Tamaño del dataset
    int minVal = 0;
    int maxVal = 10000; // Rango de valores aleatorios

    cout<<"Ingresa el tamaño del dataset:"<<endl;
    cin>> size;
    //Crea dataset aleatorio
    vector<int> randomData = generateRandomDataset(size, minVal, maxVal);
    string filename;
    filename = "RandomNumbers-";
    filename += to_string(size);
    filename += ".txt";

    //Guardar dataset en un archivo de texto
    saveDatasetToFile(randomData, filename);

    cout << "Dataset guardado en el archivo " << filename << ".\n";

    return 0;
}
