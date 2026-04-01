#include "functions.h"


int main()
{
    vector<symbol> alphabet;
    string filename;
    cin >> filename;
    /* if (Call the read_input_from_file user-defined function here == true false)
    {
        string original_message;
        //original_message.resize(call the original_message_size user-defined function here);
        for (int i=0; i< alphabet.size();i++)
        {
            // Call the decode_positions_and_populate_original_message user-defined function here
        }
        // Call the print_results user-defined function here
    }
    else
    {
        cout << "File not found." << endl;
    } 
    */

    // testing purposes only
    read_input_from_file(filename, alphabet);
    elais_gamma_to_int("0001010");
    elais_gamma_to_int("0001100");
    elais_gamma_to_int("00101");
    elais_gamma_to_int("1"); 
    return 0;
}