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
            symbol line_symbol; // temp var for the latest line's symbol
            line_symbol.frequency = 0;
            line_symbol.n_bits_elias_gamma = 0;

            istringstream line_stream(file_line);
            line_stream >> line_symbol.data; // assigns leading character to the symbol's data char
            line_stream.ignore();

            cout << "Character: " << line_symbol.data << " ";
            //cout << "Encodings: ";
            string encoding;
            while(getline(line_stream, encoding, ' '))
            {
                line_symbol.frequency++;
                line_symbol.elias_gamma_positions.push_back(encoding); // adds each encoding listed to position vector
                
                line_symbol.n_bits_elias_gamma += encoding.length();
                
                //cout << encoding << " ";
            }
            cout << "Frequency: " << line_symbol.frequency << " ";
            cout << "Total Bits: " << line_symbol.n_bits_elias_gamma << endl;
        }
        return true;
    }
    return false;
}

unsigned int elais_gamma_to_int(string encoding)
{
    istringstream encoding_stream(encoding);
    string zeros;
    getline(encoding_stream, zeros, '1');

    cout << zeros.length() << endl;
    

    return 0;
}

#endif