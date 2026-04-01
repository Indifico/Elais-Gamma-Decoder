#include "functions.h"


int main()
{
    vector<symbol> alphabet;
    string filename;
    cin >> filename;
    if (read_input_from_file(filename, alphabet) == true)
    {
        string original_message;
        original_message.resize(original_message_size(alphabet));
        for (int i=0; i< alphabet.size();i++)
        {
            decode_positions_and_populate_original_message(alphabet.at(i), original_message);
        }
        print_results(alphabet, original_message);
    }
    else
    {
        cout << "File not found." << endl;
    } 

    // testing purposes only
    /*
    read_input_from_file(filename, alphabet);
    elais_gamma_to_int("0001010");
    elais_gamma_to_int("0001100");
    elais_gamma_to_int("00101");
    elais_gamma_to_int("1");
    */

    return 0;
}