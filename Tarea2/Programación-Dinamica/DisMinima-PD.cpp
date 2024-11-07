#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "funciones.h"


using namespace std;

#define tam 26

vector<vector<int>> matrizSustitucion;
vector<vector<int>> matrizTransposicion;
vector<int> listaInsercion;
vector<int> listaEliminacion;
vector<int> tabla;

int disMinima(int i, int j){
    
}
int main(){
    
    string meta, inicial; 

    cout<<"Ingresar palabra va a ser cambiada:";
    cin>> inicial;
    
    cout<<"Ingresar palabra final:";
    cin>>meta;
    cout<<endl;

    matrizSustitucion = cargarMatriz("cost_replace.txt", tam);
    matrizTransposicion = cargarMatriz("cost_transpose.txt", tam);
    listaInsercion = cargarLista("cost_insert.txt", tam);
    listaEliminacion = cargarLista("cost_delete.txt", txt);
    

}