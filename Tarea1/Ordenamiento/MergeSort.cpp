#include <iostream>
#include <vector>
#include "RandomNumbers.h"

using namespace std;

void printl(vector<int> avector) {
    for (unsigned int i=0; i<avector.size(); i++) {
        cout << avector[i] << " ";
    }
    cout << endl;
}

vector<int> mergeSort(vector<int> avector) {
    printl(avector);
    if (avector.size()>1) {
        int mid = avector.size()/2;
        vector<int> lefthalf(avector.begin(),avector.begin()+mid);
        vector<int> righthalf(avector.begin()+mid,avector.begin()+avector.size());

        lefthalf = mergeSort(lefthalf);
        righthalf = mergeSort(righthalf);

        unsigned i = 0;
        unsigned j = 0;
        unsigned k = 0;
        while (i < lefthalf.size() && j < righthalf.size()) {
            if (lefthalf[i] < righthalf[j]) {
                avector[k]=lefthalf[i];
                i++;
            } else {
                avector[k] = righthalf[j];
                j++;
            }
            k++;
        }

        while (i<lefthalf.size()) {
            avector[k] = lefthalf[i];
            i++;
            k++;
        }

        while (j<righthalf.size()) {
            avector[k]=righthalf[j];
            j++;
            k++;
        }

    }
    printl(avector);

    return avector;
}

int main() {
    
    string filename;
    cout<<"Ingresar el nombre del archivo a leer:"<<endl;
    cin>> filename;

    vector<int> avector = loadDatasetFromFile(filename);

    printl(mergeSort(avector));

    return 0;
}