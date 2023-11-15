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
namespace f {
    const string INPUT_FILENAME = "ex12_data.csv";
    ifstream input_file;

    const string OUTPUT_FILENAME = "ex12_output.txt";
    ofstream output_file;

    constexpr int INPUT_FILE_ERROR = 1;
    constexpr int OUTPUT_FILE_ERROR = 2;
}

//------------------------------------------------------------------------------
// local functions
//------------------------------------------------------------------------------
void open_input_file();
void read_input_file(vector<string>&);
void display_file_data(vector<string>&); // #TODO fix data loss
void write_output_file(vector<string>&);

//------------------------------------------------------------------------------
// entry point
//------------------------------------------------------------------------------
int main() {

    open_input_file();

    // read file data into vector one line at a time
    vector<string> vs;
    read_input_file(vs);

    // be sure to close the file!
    f::input_file.close();

    // display vector elements read from input file
    display_file_data(vs);

    // write vector elements to output file
    write_output_file(vs);

    return 0;
}

//------------------------------------------------------------------------------
// -opens passed file name for reading
// -uses global ifstream f::input_file
// -exits application on file open error
//------------------------------------------------------------------------------
void open_input_file() {

    f::input_file.open(f::INPUT_FILENAME);

    if (!f::input_file.is_open()) {

        cerr << "Could not open input file: " << f::INPUT_FILENAME << ".\n";
        exit(f::INPUT_FILE_ERROR);
    }
}

//------------------------------------------------------------------------------
// -reads each line of open input file
// -stores string data in passed vector
//------------------------------------------------------------------------------
void read_input_file(vector<string>& v) {

    while (f::input_file.good()) {

        string input_line;
        getline(f::input_file, input_line);

#ifdef _LCDEBUG
        cout << "read from file: " << input_line << '\n';
#endif

        // remove empty string element added by last getline()
        if (v.size() > 0)
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

    for (int index = v.size() - 1; index >= 0; index--) {

        cout << v.at(index) << '\n';
    }

    cout << '\n';
}

//void display_file_data(vector<string>& v) {
//
//    while (!v.empty()) {
//
//        cout << v.back() << '\n';
//        v.pop_back();
//    }
//
//    cout << '\n';
//}

//------------------------------------------------------------------------------
// write vector elements to text file
//------------------------------------------------------------------------------
void write_output_file(vector<string>& v) {

    f::output_file.open(f::OUTPUT_FILENAME);

    if (!f::output_file.is_open()) {

        cerr << "Could not open output file: " << f::OUTPUT_FILENAME << ".\n";
        exit(f::OUTPUT_FILE_ERROR);
    }

    for (string str : v) {
        f::output_file << str + "\n";
    }

    f::output_file.close();
}
