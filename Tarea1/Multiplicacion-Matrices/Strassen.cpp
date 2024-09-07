#include <bits/stdc++.h>
#include "RandomMatrix.h"  
#include <chrono>

using namespace std;
using namespace std::chrono;


//La mayor parte del codigo fue hecha con ayuda de chatgpt

// Función para dividir la matriz en submatrices
void splitMatrix(const vector<vector<int>>& matrix, vector<vector<int>>& A, vector<vector<int>>& B, vector<vector<int>>& C, vector<vector<int>>& D) {
    int n = matrix.size() / 2;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            A[i][j] = matrix[i][j];              // Parte superior izquierda
            B[i][j] = matrix[i][j + n];          // Parte superior derecha
            C[i][j] = matrix[i + n][j];          // Parte inferior izquierda
            D[i][j] = matrix[i + n][j + n];      // Parte inferior derecha
        }
    }
}

// Función para combinar submatrices en una matriz
void combineMatrix(const vector<vector<int>>& A, const vector<vector<int>>& B, const vector<vector<int>>& C, const vector<vector<int>>& D, vector<vector<int>>& matrix) {
    int n = A.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = A[i][j];              // Parte superior izquierda
            matrix[i][j + n] = B[i][j];          // Parte superior derecha
            matrix[i + n][j] = C[i][j];          // Parte inferior izquierda
            matrix[i + n][j + n] = D[i][j];      // Parte inferior derecha
        }
    }
}

// Suma de matrices
vector<vector<int>> addMatrix(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> result(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
    return result;
}

// Resta de matrices
vector<vector<int>> subtractMatrix(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();
    vector<vector<int>> result(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = A[i][j] - B[i][j];
        }
    }
    return result;
}

// Algoritmo de Strassen para multiplicación de matrices
vector<vector<int>> strassen(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size();

    // Caso base: multiplicación directa cuando la matriz es 1x1
    if (n == 1) {
        return {{A[0][0] * B[0][0]}};
    }

    int newSize = n / 2;
    vector<int> inner(newSize);
    vector<vector<int>> 
        A11(newSize, inner), A12(newSize, inner), A21(newSize, inner), A22(newSize, inner),
        B11(newSize, inner), B12(newSize, inner), B21(newSize, inner), B22(newSize, inner),
        C11(newSize, inner), C12(newSize, inner), C21(newSize, inner), C22(newSize, inner),
        M1(newSize, inner), M2(newSize, inner), M3(newSize, inner), M4(newSize, inner), 
        M5(newSize, inner), M6(newSize, inner), M7(newSize, inner),
        AResult(newSize, inner), BResult(newSize, inner);

    // Dividir matrices en submatrices
    splitMatrix(A, A11, A12, A21, A22);
    splitMatrix(B, B11, B12, B21, B22);

    // M1 = (A11 + A22) * (B11 + B22)
    AResult = addMatrix(A11, A22);
    BResult = addMatrix(B11, B22);
    M1 = strassen(AResult, BResult);

    // M2 = (A21 + A22) * B11
    AResult = addMatrix(A21, A22);
    M2 = strassen(AResult, B11);

    // M3 = A11 * (B12 - B22)
    BResult = subtractMatrix(B12, B22);
    M3 = strassen(A11, BResult);

    // M4 = A22 * (B21 - B11)
    BResult = subtractMatrix(B21, B11);
    M4 = strassen(A22, BResult);

    // M5 = (A11 + A12) * B22
    AResult = addMatrix(A11, A12);
    M5 = strassen(AResult, B22);

    // M6 = (A21 - A11) * (B11 + B12)
    AResult = subtractMatrix(A21, A11);
    BResult = addMatrix(B11, B12);
    M6 = strassen(AResult, BResult);

    // M7 = (A12 - A22) * (B21 + B22)
    AResult = subtractMatrix(A12, A22);
    BResult = addMatrix(B21, B22);
    M7 = strassen(AResult, BResult);

    // C11 = M1 + M4 - M5 + M7
    C11 = addMatrix(subtractMatrix(addMatrix(M1, M4), M5), M7);

    // C12 = M3 + M5
    C12 = addMatrix(M3, M5);

    // C21 = M2 + M4
    C21 = addMatrix(M2, M4);

    // C22 = M1 - M2 + M3 + M6
    C22 = addMatrix(subtractMatrix(addMatrix(M1, M3), M2), M6);

    // Combinar los resultados en una matriz
    vector<vector<int>> C(n, vector<int>(n));
    combineMatrix(C11, C12, C21, C22, C);

    return C;
}

int main() {

    string filename;  
    cout<<"Ingresar el nombre del archivo a leer:"<<endl;
    cin>> filename;

    // Leer matrices del archivo
    vector<vector<vector<int>>> matrices = readMatricesFromFile(filename);

	int size = matrices[0].size();
	
    // Obtener matrices A y B
    vector<vector<int>> A = matrices[0];
    vector<vector<int>> B = matrices[1];

	auto start = high_resolution_clock::now();
    vector<vector<int>> C = strassen(A, B);	 // Multiplicación de matrices utilizando Strassen
	auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout<< duration.count() << endl;
    
    string archivoResultado = "Resultado-MultiplicacionStrassen.txt";
    ofstream resultado(archivoResultado, ios::app);

    if (!resultado) {
        cerr << "Error al abrir el archivo para escritura.\n";
        return 1;
    }

    resultado <<"Multiplicación con algoritmo Strassen tiempo de multiplicación " << duration.count() << " microsegundos frente a una matriz de tamaño " << size << "x"<<size << endl;

    resultado.close();

    return 0;
}
