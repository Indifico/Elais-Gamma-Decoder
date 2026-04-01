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

bool read_input_from_file(const string &filename, vector<symbol> &symbol_vector)
{
    ifstream input_file(filename);
    if(input_file.is_open())
    {
        string file_line;
        while(getline(input_file, file_line)) // get each line of file as string
        {
            symbol line_symbol; // temp var for the latest line's symbol
            line_symbol.frequency = 0;
            line_symbol.n_bits_elias_gamma = 0;

            istringstream line_stream(file_line); // use line string as stream for parsing

            line_symbol.data = line_stream.get(); // assigns leading character to the symbol's data char
            line_stream.ignore();

            string encoding;
            while(line_stream >> encoding) // reads each encoded position; (' ' (or /t ig) == delimiter)
            {
                line_symbol.frequency++;
                line_symbol.elias_gamma_positions.push_back(encoding); // adds each encoding listed to position vector
                
                line_symbol.n_bits_elias_gamma += encoding.length(); // adds bits from each encoding to bit counter
            }
            symbol_vector.push_back(line_symbol); // add read symbol data to vector
        }
        return true;
    }
    return false; // file not found
}

unsigned int original_message_size(const vector<symbol> &symbol_vector)
{
    unsigned int count = 0;
    for(int i = 0; i < symbol_vector.size(); i++)
    {
        count += symbol_vector.at(i).frequency; // use sum of frequencies to get length
    }

    return count;
}

unsigned int elais_gamma_to_int(string encoding)
{
    istringstream encoding_stream(encoding); // parse string from parameter

    string zeros;
    string binary;
    int encoding_n = 2;
    int binary_int = 0;
    int decimal_int = 0;

    getline(encoding_stream, zeros, '1'); // get zeros from string up to 1
    getline(encoding_stream, binary); // get the rest as binary

    if(binary != "") // avoiding stoi exception
    {
        binary_int = stoi(binary);
    }

    if(zeros.length() == 0) // N = 2^0
    {
        encoding_n = 1;
    }
    else // N = 2^n_zeros
    {
        for(int i = 0; i < zeros.length() - 1; i++)
        {
            encoding_n *= 2;
        }
    }

    int index = 0;
    while(binary_int > 0) // binary to decimal
    {
        if(binary_int % 10 == 1)
        {
            if(index > 0)
            {
                int add_int = 2;
                for(int i = 0; i < index - 1; i++)
                {
                    add_int *= 2;
                }
                decimal_int += add_int;
            }
            else
            {
                decimal_int += 1;
            }
        }
        binary_int /= 10;
        index++;
    }
    
    return encoding_n + decimal_int;
}

void decode_positions_and_populate_original_message(symbol &input_symbol, string &original_message)
{
    for(int i = 0; i < input_symbol.frequency; i++)
    {
        unsigned int position = elais_gamma_to_int(input_symbol.elias_gamma_positions.at(i)) - 1; // decode elais gamma
        input_symbol.positions.push_back(position); // append decoded int
        original_message.at(position) = input_symbol.data; // populate position in original message
    }
}

void print_results(const vector<symbol> &symbol_vector, const string &original_message)
{
    // print in requested format
    cout << "Alphabet: " << endl;

    for(int i = 0; i < symbol_vector.size(); i++)
    {
        symbol current_symbol = symbol_vector.at(i);

        cout << "Symbol: " << current_symbol.data << ", Frequency: " << current_symbol.frequency << endl
            << "Positions: ";

        for(int j = 0; j < current_symbol.positions.size(); j++)
        {
            cout << current_symbol.positions.at(j) << " ";
        }
        cout << endl;

        cout << "Number of bits to represent the positions: " << current_symbol.n_bits_elias_gamma << endl;
    }

    cout << "Decoded message: " << original_message << endl;
}

#endif