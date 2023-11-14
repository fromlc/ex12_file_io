//------------------------------------------------------------------------------
// ex12_file_io.cpp
//
// -Read from text file into vector, 1 string element per line
// -Write vector elements 
// -Display each vector element, from highest to lowest index
// -Uses global namespace infile, so functions share ifstream
// 
// -#TODO This code deletes all vector elements with pop_back() - fix this.
// -#TODO Add a function to output each vector element to a file. 
//      Start your research here: https://cplusplus.com/doc/tutorial/files/
//------------------------------------------------------------------------------
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

//------------------------------------------------------------------------------
// toggle DEBUG mode
//------------------------------------------------------------------------------
#define _LCDEBUG

//------------------------------------------------------------------------------
// file metadata
//------------------------------------------------------------------------------
namespace infile {
    const string INPUT_FILENAME = "ex12_data.csv";
    ifstream input_file;
}

namespace outfile {
    const string OUTPUT_FILENAME = "ex12_output.txt";
    ofstream output_file;
}

//------------------------------------------------------------------------------
// error return codes
//------------------------------------------------------------------------------
namespace error {
    constexpr int INPUT_FILE_ERROR = 1;
    constexpr int OUTPUT_FILE_ERROR = 2;
}

//------------------------------------------------------------------------------
// local functions
//------------------------------------------------------------------------------
void open_input_file();
void read_input_file(vector<string>&);
void display_file_data(vector<string>&); // #TODO fix data loss

//------------------------------------------------------------------------------
// entry point
//------------------------------------------------------------------------------
int main() {

    open_input_file();

    // read file data into vector one line at a time
    vector<string> vs;
    read_input_file(vs);

    // be sure to close the file!
    infile::input_file.close();

    display_file_data(vs);

    return 0;
}

//------------------------------------------------------------------------------
// -opens passed file name for reading
// -uses global ifstream infile::input_file
// -exits application on file open error
//------------------------------------------------------------------------------
void open_input_file() {

    infile::input_file.open(infile::INPUT_FILENAME);

    if (!infile::input_file.is_open()) {

        cerr << "Could not open input file: " << infile::INPUT_FILENAME << ".\n";
        exit(error::INPUT_FILE_ERROR);
    }
}

//------------------------------------------------------------------------------
// -reads each line of open input file
// -stores string data in passed vector
//------------------------------------------------------------------------------
void read_input_file(vector<string>& v) {

    while (infile::input_file.good()) {

        string input_line;
        getline(infile::input_file, input_line);

#ifdef _LCDEBUG
        cout << "read from file: " << input_line << '\n';
#endif

        v.push_back(input_line);
    }
}

//------------------------------------------------------------------------------
// -display each element of passed vector, last index first
// #TODO this function removes elements from passed vector!
// #TODO prevent losing data
//      BAD: use call by value (forces vector copy), or
//      BETTER: use v.at(i), start with i set to highest index of v 
//------------------------------------------------------------------------------
void display_file_data(vector<string>& v) {

    while (!v.empty()) {

        cout << v.back() << '\n';
        v.pop_back();
    }

    cout << '\n';
}
