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

int disMinimaPD(const string& palabraInicial, const string& palabraMeta, int i, int j){
    
    if(i == 0){
        int costo = 0;
        for(int k = 0; k < j; k++){
            costo += costo_ins(palabraMeta[k]);
        }
         return costo;
    }
    if(j == 0){
        int costo = 0;
        for(int k = 0; k < i; k++){
            costo += costo_del(palabraInicial[k]);
        }
        return costo;
    }

    if(tabla[i][j] != -1){
        return tabla[i][j];
    }

    if(palabraInicial[i -1 ] == palabraMeta[j - 1]){
        return disMinimaPD(palabraInicial, palabraMeta, i - 1, j - 1);
    }
    int costoInsercion = costo_ins(palabraMeta[j]) + disMinimaPD(palabraInicial, palabraMeta, i, j - 1);
    int costoEliminacion = costo_del(palabraInicial[i]) + disMinimaPD(palabraInicial, palabraMeta, i - 1, j);
    int costoSustitucion = costo_sub(palabraInicial[i], palabraMeta[j]) + disMinimaPD(palabraInicial, palabraMeta, i - 1, j - 1);

    int res = min( costoInsercion, min(costoEliminacion, costoSustitucion));
    tabla[i][j] = res;
    return res;
}
int main(){
    string meta, inicial; 

    cout<<"Ingresar palabra va a ser cambiada (0 para la palabra vacia):";
    cin>> inicial;
    
    cout<<"Ingresar palabra final (0 para la palabra vacia):";
    cin>>meta;
    
    if(inicial == "0"){
        inicial = "";
    }
    if(meta == "0"){
        meta = "";
    }

    tamPalabraInicial = inicial.length();
    tamPalabraMeta = meta.length();

    for(int i = 0; i < tamPalabraInicial + 1; i++){
        for(int j = 0; j < tamPalabraMeta + 1; j++){
            tabla[i][j] = -1;
        }
    }

    matrizSustitucion = cargarMatriz("../ArchivosEntrada/cost_replace.txt", tam);
    matrizTransposicion = cargarMatriz("../ArchivosEntrada/cost_transpose.txt", tam);
    listaInsercion = cargarLista("../ArchivosEntrada/cost_insert.txt", tam);
    listaEliminacion = cargarLista("../ArchivosEntrada/cost_delete.txt", tam);
    int respuesta = 0;
    respuesta = disMinimaPD(inicial, meta, inicial.length(), meta.length());
    cout<<"El costo minimo es:" << respuesta << endl;
}