// This is the CPP file you will edit and turn in.
// Also remove these comments here and add your own.
// TODO: remove this comment header

#include <cctype>
#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include "console.h"
#include "filelib.h"
#include "grid.h"
#include "gwindow.h"
#include "simpio.h"
using namespace std;

void ReadFile(string);

int main(void) {
    string filename;
    cout << "enter name:";
    cin >> filename;

    ReadFile(filename);



    return 0;
}

void ReadFile(string fn){
    ifstream inf;
    openFile(inf,fn);
    string line;
    while(getline(inf,line)){
        cout << line<<endl;
    }


}
