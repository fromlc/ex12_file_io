//------------------------------------------------------------------------------
// ut_file_io.cpp
//
// -Utility functions read and write from text file into vector
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
static void open_input_file();

//------------------------------------------------------------------------------
// -opens passed file name for reading
// -uses global ifstream infile::input_file
// -exits application on file open error
//------------------------------------------------------------------------------
static void open_input_file() {

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

    open_input_file();

    while (f::input_file.good()) {

        string input_line;
        getline(f::input_file, input_line);

#ifdef _LCDEBUG
        cout << "read from file: " << input_line << '\n';
#endif

        v.push_back(input_line);
    }

    // remove empty string element added after eof
    v.pop_back();

    // be sure to close the file!
    f::input_file.close();
}

