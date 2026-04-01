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
        for (int i = 0; i < alphabet.size(); i++)
        {
            decode_positions_and_populate_original_message(alphabet.at(i), original_message);
        }
        print_results(alphabet, original_message);
    }
    else
    {
        cout << "File not found." << endl;
    } 

    return 0;
}