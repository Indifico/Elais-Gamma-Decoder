// Add the include guard.

// Include all the libraries needed by your solution
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

// DO NOT MODIFY THIS STRUCTURE

struct symbol
{
    char data;
    int frequency;
    vector<string> elias_gamma_positions;
    vector<int> positions;
    unsigned int n_bits_elias_gamma;
};


// Write your functions here