#include <fstream>
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

#define tam 26

int seed; 

void crearInsercionTxt(){
    fstream archivo;
    archivo.open("../ArchivosEntrada/cost_insert.txt", ios::out);

    if (!archivo) {
        cerr << "Error al abrir el archivo cost_insert.txt\n";
        return;
    }

    srand(seed);

    /*Quitar comentarios para hacer una matriz con numeros constantes, hay que comentar el for de más abajo.
    for(int i  = 0; i < tam; i++){
        archivo <<1<< " ";
    }
    */

    for(int i = 0; i < tam; i++){
        archivo << rand() % 5 + 1 << " ";
    }

    archivo.close();
}

void crearEliminacionTxt(){
    fstream archivo;
    archivo.open("../ArchivosEntrada/cost_delete.txt", ios::out);

    if (!archivo) {
        cerr << "Error al abrir el archivo cost_insert.txt\n";
        return;
    }

    srand(seed + 1);

    /*Quitar comentarios para hacer una matriz con numeros constantes, hay que comentar el for de más abajo.
    for(int i  = 0; i < tam; i++){
        archivo <<1<< " ";
    }
    */

    for(int i  = 0; i < tam; i++){
        archivo << rand() % 5 + 1 << " ";
    }

    archivo.close();
}

void crearSustitucionTxt(){
    fstream archivo;
    archivo.open("../ArchivosEntrada/cost_replace.txt", ios::out);

    if (!archivo) {
        cerr << "Error al abrir el archivo cost_insert.txt\n";
        return;
    }

    srand(seed + 2);
    /*Quitar comentarios para hacer una matriz con numeros constantes, hay que comentar el for de más abajo.
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
    */
    for(int i = 0; i < tam; i++){
        for(int j = 0; j < tam; j++){
            archivo << rand() % 5 + 1 << " ";
        }
        archivo<<endl;
    }

    archivo.close();
}

void crearTransposicionTxt(){
    fstream archivo;
    archivo.open("../ArchivosEntrada/cost_transpose.txt", ios::out);

    if (!archivo) {
        cerr << "Error al abrir el archivo cost_insert.txt\n";
        return;
    }

    srand(seed + 3);
    /*Quitar comentarios para hacer una matriz con numeros constantes, hay que comentar el for de más abajo.
    for(int i = 0; i < tam; i++){
        for(int j = 0; j < tam; j++){
            archivo << 1 <<" ";
        }
        archivo<<endl;
    }
    */
    for(int i = 0; i < tam; i++){
        for(int j = 0; j < tam; j++){
            archivo << rand() % 5 + 1 << " ";
        }
        archivo<<endl;
    }

    archivo.close();
}

int main(){

    cout<<"Ingresar semilla para generar los archivos"<<endl;
    cin>>seed;

    int eleccion;
    cout<<"Elegir que archivos crear"<<endl;
    cout<<"1)Insercion 2)Eliminacion 3)Sustitución 4)Transposición 5)Todos"<<endl;
    cin>>eleccion;

    if(eleccion == 1){
        crearInsercionTxt();
    }else if(eleccion == 2){
        crearEliminacionTxt();
    }else if(eleccion == 3){
        crearSustitucionTxt();
    }else if(eleccion == 4){
        crearTransposicionTxt();
    }else if(eleccion == 5){
        crearEliminacionTxt();
        crearInsercionTxt();
        crearSustitucionTxt();
        crearTransposicionTxt();
    }else{
        cout<<"Esa no era una opción posible"<<endl;
    }
    
}