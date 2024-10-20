#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "funciones.h"


using namespace std;

#define tam 26

int main(){
    
    string meta, inicial; 

    cout<<"Ingresar palabra va a ser cambiada:";
    cin>> inicial;
    
    cout<<"Ingresar palabra final:";
    cin>>meta;
    cout<<endl;

    /*vector<vector<int>> matrizSustitucion = cargarMatriz("costos-sustitucion.txt", tam);
    vector<vector<int>> matrizTransposicion = cargarMatriz("costos-transposicion.txt", tam);
    vector<int> listaInsercion = cargarLista("costos-insercion.txt", tam);
    vector<int> listaEliminacion = cargarLista("costos-eliminacion.txt", txt);
    */

    int indice = 0;

    while(meta != inicial){
        if(indice > meta.size())break;
        if(meta[indice] != inicial[indice]){
            cout<<"Es diferentes la letra: "<< meta[indice]<<endl;
            
        }
        indice++;
        
    }
}