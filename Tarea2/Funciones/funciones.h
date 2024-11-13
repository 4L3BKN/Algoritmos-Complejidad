#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <vector>
#include <string>

using namespace std;

vector<vector<int>> cargarMatriz(const string& nombreArchivo, int tamannio);

vector<int> cargarLista(const string& nombreArchivo, int tamannio);

int indiceLetra(char c);

int costo_sub(char a, char b);

int costo_ins(char a);

int costo_del(char a);

int costo_trans(char a, char b);

#endif