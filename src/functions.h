// Added the include guard.
#ifndef FUNCTIONS_H
#define FUNCTIONS_H
// Included all the libraries needed by solution
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

// DID NOT MODIFY THIS STRUCTURE :)

struct symbol
{
    char data;
    int frequency;
    vector<string> elias_gamma_positions;
    vector<int> positions;
    unsigned int n_bits_elias_gamma;
};


// Wrote functions here

bool read_input_from_file(string filename, vector<symbol> symbol_vector)
{
    //cout << "Filename: " << filename << endl;
    ifstream input_file(filename);
    if(input_file.is_open())
    {
        // Implementation
        string file_line;
        while(getline(input_file, file_line))
        {
            //cout << file_line << endl;
            istringstream line_stream(file_line);
            char letter;
            line_stream >> letter;
            break;
        }
        return true;
    }
    return false;
}

#endif