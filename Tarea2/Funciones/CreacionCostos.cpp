#include <fstream>
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

#define tam 26

void crearInsercionTxt(){
    fstream archivo;
    archivo.open("../ArchivosEntrada/cost_insert.txt", ios::out);

    if (!archivo) {
        cerr << "Error al abrir el archivo cost_insert.txt\n";
        return;
    }

    srand(static_cast<unsigned>(time(0)));

    for(int i  = 0; i < tam; i++){
        archivo <<1<< " ";
    }

    /*for(int i = 0; i < tam; i++){
        archivo << rand() % 5 + 1 << " ";
    }*/

    archivo.close();
}

void crearEliminacionTxt(){
    fstream archivo;
    archivo.open("../ArchivosEntrada/cost_delete.txt", ios::out);

    if (!archivo) {
        cerr << "Error al abrir el archivo cost_insert.txt\n";
        return;
    }

    srand(static_cast<unsigned>(time(0)));

    for(int i  = 0; i < tam; i++){
        archivo <<1<< " ";
    }
    /*for(int i  = 0; i < tam; i++){
        archivo << rand() % 5 + 1 << " ";
    }*/
    cout<<tam<<endl;
    archivo.close();
}

void crearSustitucionTxt(){
    fstream archivo;
    archivo.open("../ArchivosEntrada/cost_replace.txt", ios::out);

    if (!archivo) {
        cerr << "Error al abrir el archivo cost_insert.txt\n";
        return;
    }

    srand(static_cast<unsigned>(time(0)));
    for(int i = 0; i < tam; i++){
        for(int j = 0; j < tam; j++){
            if(i == j){
                archivo<<0<<" ";
            }else{
                archivo<<2<<" ";
            }
        }
        archivo<<endl;
    }
    /*for(int i = 0; i < tam; i++){
        for(int j = 0; j < tam; j++){
            archivo << rand() % 5 + 1 << " ";
        }
        archivo<<endl;
    }*/

    archivo.close();
}

void crearTransposicionTxt(){
    fstream archivo;
    archivo.open("../ArchivosEntrada/cost_transpose.txt", ios::out);

    if (!archivo) {
        cerr << "Error al abrir el archivo cost_insert.txt\n";
        return;
    }

    srand(static_cast<unsigned>(time(0)));

    for(int i = 0; i < tam; i++){
        for(int j = 0; j < tam; j++){
            archivo << 1 <<" ";
        }
        archivo<<endl;
    }
    /*for(int i = 0; i < tam; i++){
        for(int j = 0; j < tam; j++){
            archivo << rand() % 5 + 1 << " ";
        }
        archivo<<endl;
    }*/

    archivo.close();
}

int main(){
    crearEliminacionTxt();
    crearInsercionTxt();
    crearSustitucionTxt();
    crearTransposicionTxt();
}