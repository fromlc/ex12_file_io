//------------------------------------------------------------------------------
// ex12_file_io.cpp
//
// Read from text file into vector, 1 field per line
// Write vector elements backwards into an output file
//------------------------------------------------------------------------------
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

//------------------------------------------------------------------------------
// file metadata
//------------------------------------------------------------------------------
namespace infile {
    const string INPUT_FILENAME = "ex12_data.csv";
    constexpr int INPUT_FILE_ERROR = 1;
    ifstream input_file;
}

//------------------------------------------------------------------------------
// local functions
//------------------------------------------------------------------------------
void open_input_file(const string&);
void read_input_file(vector<string>&);
void display_file_data(vector<string>&);

//------------------------------------------------------------------------------
// entry point
//------------------------------------------------------------------------------
int main() {

    open_input_file(infile::INPUT_FILENAME);

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
void open_input_file(const string& filename) {
    // open file for reading
    infile::input_file.open(filename);

    if (!infile::input_file.is_open()) {

        cerr << "Could not open input file: " << filename << ".\n";
        exit(infile::INPUT_FILE_ERROR);
    }
}

//------------------------------------------------------------------------------
// -reads each line of open input file
// -stores string data in passed vector
//------------------------------------------------------------------------------
void read_input_file(vector<string>& v) {

    string input_line;

    while (infile::input_file.good()) {

        getline(infile::input_file, input_line);
        v.push_back(input_line);
    }
}

//------------------------------------------------------------------------------
// -display each element of passed vector, last index first
// -removes elements from passed vector!
// #TODO use call by value to prevent losing data
//------------------------------------------------------------------------------
void display_file_data(vector<string>& v) {

    while (!v.empty()) {

        cout << v.back() << '\n';
        v.pop_back();
    }

    cout << '\n';
}
