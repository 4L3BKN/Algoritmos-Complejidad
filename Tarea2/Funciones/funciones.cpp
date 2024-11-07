#include "funciones.h"
#include <fstream>
#include <iostream>
#include <vector>

vector<vector<int>> cargarMatriz(const string& nombreArchivo, int tamannio){
    ifstream archivo(nombreArchivo);
    vector<vector<int>> matriz(tamannio, vector<int>(tamannio,0));

    for(int i = 0; i < tamannio; i++){
        for(int j = 0; j < tamannio; j++){
            archivo >> matriz[i][j];
        }
    }

    return matriz;
}

vector<int> cargarLista(const string& nombreArchivo, int tamannio){
    ifstream archivo(nombreArchivo);
    vector<int> lista(26,0);

    for(int i = 0; i < tamannio; i++){
        archivo>> lista[i];
    }

    return lista;
}

int indiceLetra(char c){
    return c - 'a';
}

int costo_sub(char a, char b, vector<vector<int>>& matriz){
    int costo;

    int indiceA = indiceLetra(a);
    int indiceB = indiceLetra(b);

    costo = matriz[indiceA][indiceB];
    return costo;
}

int costo_ins(char a, vector<int>& lista){
    int costo;

    int indiceA = indiceLetra(a);

    costo = lista[indiceA];
    return costo;
}

int costo_del(char a, vector<int>& lista){
    int costo;

    int indiceA = indiceLetra(a);

    costo = lista[indiceA];
    return costo;
}

int costo_trans(char a, char b, vector<vector<int>>& matriz){
    int costo;

    int indiceA = indiceLetra(a);
    int indiceB = indiceLetra(b);

    costo = matriz[indiceA][indiceB];
    return costo;
}