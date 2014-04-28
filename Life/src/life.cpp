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
    int rows;
    int columns;

    ifstream inf;
    openFile(inf,fn);
    string line;
    getline(inf,line);
    rows = stringToInteger(line);
    getline(inf,line);
    columns = stringToInteger(line);
    //mgrid.resize(rows,columns); //will fail , so change another way to construct
    Grid<char> mgrid(rows,columns);
    //while(true){
       // cout << line<<endl;
    //}
    int i,j;
    if(i=0,i<rows,i++){
        if(j=0,j<columns,j++){
            mgrid[i][j]=inf.get();
        }
    }

    mgrid.toString();

}
