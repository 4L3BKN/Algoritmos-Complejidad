#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "funciones.h"
#include <chrono>

using namespace std;

#define tam 26

vector<vector<int>> matrizSustitucion;
vector<vector<int>> matrizTransposicion;
vector<int> listaInsercion;
vector<int> listaEliminacion;
vector<vector<int>> tabla;

int disMinimaPD(const string& palabraInicial, const string& palabraMeta, int i, int j){
    
    if(i == 0 && j == 0)return 0;
    if(i == 0){
        return tabla[0][j];
    }
    if(j == 0){
        return tabla[i][0];
    }

    if(tabla[i][j] != -1){
        return tabla[i][j];
    }

    if(palabraInicial[i - 1] == palabraMeta[j - 1]){
        tabla[i][j] = disMinimaPD(palabraInicial, palabraMeta, i - 1, j - 1);
        return tabla[i][j];
    }
    int costoInsercion = costo_ins(palabraMeta[j - 1]) + disMinimaPD(palabraInicial, palabraMeta, i, j - 1);
    int costoEliminacion = costo_del(palabraInicial[i - 1]) + disMinimaPD(palabraInicial, palabraMeta, i - 1, j);
    int costoSustitucion = costo_sub(palabraInicial[i - 1], palabraMeta[j - 1]) + disMinimaPD(palabraInicial, palabraMeta, i - 1, j - 1);

    int res = min( costoInsercion, min(costoEliminacion, costoSustitucion));

    if (i > 1 && j > 1 && palabraInicial[i - 1] == palabraMeta[j - 2] && palabraInicial[i - 2] == palabraMeta[j - 1]) {
        int costoTrans1 = costo_trans(palabraInicial[i - 1], palabraInicial[i - 2]) + disMinimaPD(palabraInicial, palabraMeta, i - 2, j - 2);
        int costoTrans2 = costo_trans(palabraInicial[i - 2], palabraInicial[i - 1]) + disMinimaPD(palabraInicial, palabraMeta, i - 2, j - 2);
        int comparar = min(costoTrans1, costoTrans2);

        res = min(res, comparar);
    }
    tabla[i][j] = res;
    return tabla[i][j];
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

    int n = inicial.length();
    int m = meta.length();
    tabla.assign(n + 1, vector<int>(m + 1, -1));
        
    matrizSustitucion = cargarMatriz("../ArchivosEntrada/cost_replace.txt", tam);
    matrizTransposicion = cargarMatriz("../ArchivosEntrada/cost_transpose.txt", tam);
    listaInsercion = cargarLista("../ArchivosEntrada/cost_insert.txt", tam);
    listaEliminacion = cargarLista("../ArchivosEntrada/cost_delete.txt", tam);
    
    for (int i = 0; i <= n; i++) { 
        if (i > 0) {
            tabla[i][0] = tabla[i - 1][0] + costo_del(inicial[i - 1]);
        } else {
            tabla[i][0] = 0; 
        }
    }

    for (int j = 0; j <= m; j++) {
        if(j > 0){
            tabla[0][j] = tabla[0][j - 1] + costo_ins(meta[j - 1]); 
        }else{
            tabla[0][j] = 0;
        }
    }
    
    int respuesta = 0;
    auto inicio = chrono::high_resolution_clock::now();
    respuesta = disMinimaPD(inicial, meta, inicial.length(), meta.length());
    auto fin = chrono::high_resolution_clock::now();

    auto duracion = chrono::duration_cast<chrono::nanoseconds>(fin - inicio);
    cout<<"El costo minimo es:" << respuesta << endl;
    cout<<"Se demoro:"<<duracion.count()<<" nanosegundos"<<endl;

    /*Descomentar en caso de querer ver la matriz de memoizacion resultante
    for(int i = 0; i<=n; i++){
        for(int j = 0; j<=m; j++){
            cout<<tabla[i][j]<<" ";
        }
        cout<<endl;
    }*/
}