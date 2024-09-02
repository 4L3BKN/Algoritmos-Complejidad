#include <bits/stdc++.h>
#include "RandomNumbers.h"

using namespace std;

int main(){

    string filename;
    cout<<"Ingresar el nombre del archivo a leer:"<<endl;
    cin>> filename;

    vector<int> numeros = loadDatasetFromFile(filename);
    sort(numeros.begin(), numeros.end());

    for (int i : numeros){
        cout<<i << " ";
    }
    cout<<endl;
    return 0;
}