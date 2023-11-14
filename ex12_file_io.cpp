//------------------------------------------------------------------------------
// ex12_file_io.cpp
//
// -Read from text file into vector, 1 string element per line
// -Write vector elements 
// -Display each vector element, from highest to lowest index
// 
// -#TODO This code deletes all vector elements with pop_back() - fix this.
// -#TODO Add a function to output each vector element to a file. 
//      Start your research here: https://cplusplus.com/doc/tutorial/files/
//------------------------------------------------------------------------------
#include <fstream>
#include <iostream>
#include <vector>

#include "ut_file_io.h"

using namespace std;

//------------------------------------------------------------------------------
// local functions
//------------------------------------------------------------------------------
void display_file_data(vector<string>&); // #TODO fix data loss

//------------------------------------------------------------------------------
// entry point
//------------------------------------------------------------------------------
int main() {

    // read file data into vector one line at a time
    vector<string> vs;
    read_input_file(vs);

    display_file_data(vs);

    return 0;
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
