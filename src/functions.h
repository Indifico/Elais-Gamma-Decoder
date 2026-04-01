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

            cout << "Character: " << line_symbol.data << endl;
            cout << "Encodings: ";
            string encoding;
            while(getline(line_stream, encoding, ' '))
            {
                line_symbol.frequency++;
                line_symbol.elias_gamma_positions.push_back(encoding); // adds each encoding listed to position vector
                
                line_symbol.n_bits_elias_gamma += encoding.length(); // adds bits from each encoding to bit counter
                cout << encoding << " ";
            }
            symbol_vector.push_back(line_symbol); // add read symbol data to vector

            cout << endl << "Frequency: " << line_symbol.frequency << " ";
            cout << "Total Bits: " << line_symbol.n_bits_elias_gamma << endl;
            cout << endl;
        }
        return true;
    }
    return false;
}

unsigned int original_message_size(vector<symbol> symbol_vector)
{
    unsigned int count = 0;
    for(int i = 0; i < symbol_vector.size(); i++)
    {
        count += symbol_vector.at(i).data;
    }
    return count;
}

unsigned int elais_gamma_to_int(string encoding)
{
    istringstream encoding_stream(encoding);

    string zeros;
    string binary;
    int encoding_n = 2;
    int binary_int = 0;
    int decimal_int = 0;

    getline(encoding_stream, zeros, '1');
    getline(encoding_stream, binary);

    if(binary != "") // avoiding stoi exception
    {
        binary_int = stoi(binary);
    }

    cout << "Encoding Test: " << encoding << endl;
    cout << "Number of zeros: " << zeros.length() << endl;
    cout << "Binary: " << binary << endl;

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

    cout << "Encoding N: " << encoding_n << endl;

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
    cout << "Binary Int: " << decimal_int << endl;
    cout << endl;
    
    return encoding_n + decimal_int;
}

void decode_positions_and_populate_original_message(symbol input_symbol, string original_message)
{
    for(int i = 0; i < input_symbol.frequency; i++)
    {
        unsigned int position = elais_gamma_to_int(input_symbol.elias_gamma_positions.at(i));
        input_symbol.positions.push_back(position);
        original_message.at(position) = input_symbol.data;
    }
}

#endif