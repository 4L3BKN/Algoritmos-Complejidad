// C++ Program to demonstrate how to implement the quick
// sort algorithm
#include <bits/stdc++.h>
#include "RandomNumbers.h"
using namespace std;

int partition(vector<int> &vec, int low, int high) {

    // Selecting last element as the pivot
    int pivot = vec[high];

    // Index of elemment just before the last element
    // It is used for swapping
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {

        // If current element is smaller than or
        // equal to pivot
        if (vec[j] <= pivot) {
            i++;
            swap(vec[i], vec[j]);
        }
    }

    // Put pivot to its position
    swap(vec[i + 1], vec[high]);

    // Return the point of partition
    return (i + 1);
}

void quickSort(vector<int> &vec, int low, int high) {

    // Base case: This part will be executed till the starting
    // index low is lesser than the ending index high
    if (low < high) {

        // p is partitioning index, arr[p] is now at
        // right place
        int p = partition(vec, low, high);

        // Separately sort elements before and after the
        // partition index p
        quickSort(vec, low, p - 1);
        quickSort(vec, p + 1, high);
    }
}

int main() {
    //vector<int> vec = {10, 7, 8, 9, 1, 5};

    string filename;
    cout<<"Ingresar el nombre del archivo a leer:"<<endl;
    cin>> filename;
    
    vector<int> vec = loadDatasetFromFile(filename);

    int N = vec.size();
    cout << "Unsorted Array: \n";
    for (auto i : vec) {
        cout << i << " ";
    }
    cout << endl;

    quickSort(vec, 0, N - 1);

    cout << "Sorted Array: \n";
    for (auto i : vec) {
        cout << i << " ";
    }
    cout<<endl;
    return 0;
}