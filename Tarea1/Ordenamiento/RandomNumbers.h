#ifndef RANDOMNUMBERS_H 
#define RANDOMNUMBERS_H

#include <vector>
#include <string>
using namespace std;

// Declaraciones de funciones
vector<int> generateRandomDataset(size_t size, int minVal, int maxVal);
void saveDatasetToFile(const vector<int>& data, const string& filename);
vector<int> loadDatasetFromFile(const string& filename);

#endif // RANDOMNUMBERS_H
