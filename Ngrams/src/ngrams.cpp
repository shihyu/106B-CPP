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
#include "hashmap.h"
#include "hashset.h"
#include "map.h"
#include "queue.h"
#include "random.h"
#include "set.h"
#include "simpio.h"
#include "vector.h"
#include "tokenscanner.h"

using namespace std;
typedef Vector<string> keyvector;
typedef Map<keyvector,keyvector> NGRAM;

NGRAM readFile(string fn,int n);
void writeArticle(NGRAM map,int num);

// this code is from http://stackoverflow.com/questions/19344087/mapvectorstring-string-giving-me-an-error
bool operator<( const Vector<string>& lhs, const Vector<string>& rhs )
{
    int pos = 0;
    while( true ) {
        if( pos == lhs.size() && pos == rhs.size() ) return false;
        if( pos == lhs.size() ) return true;
        if( pos == rhs.size() ) return false;
        if( lhs[ pos ] < rhs[ pos ] ) return true;
        if( rhs[ pos ] < lhs[ pos ] ) return false;
        ++pos;
    }
}

int main() {
    setConsoleSize(750, 450);
    setConsoleFont("Courier New-18");
    setConsoleEcho(true);

    int n,gnum;
    cout << "Please enter N:";
    cin >> n;
    string filename;
    cout << "Input file?";
    cin >> filename;
    cout << "\n";
    cout <<"# of random words to generate (0 to quit)?";
    cin >> gnum;

    // TODO: Finish the program!
    NGRAM ngrammap;
    ngrammap = readFile(filename,n);

    writeArticle(ngrammap,gnum);

    cout << "Exiting." << endl;
    return 0;
}

void writeArticle(NGRAM map,int num){
    keyvector window;
    string next;
    int rannum;

    rannum = randomInteger(0,map.size()-1); // for start point
    window = map.keys().get(rannum);

    for(int i=0;i<window.size();i++){  // print out first n-1 words
        cout << "..."<<window[i] << " ";
    }

    for(int j=0;j<(num-window.size());j++){
        if(map.get(window).size()>1){ //if the values are more than one
            rannum = randomInteger(0,map.get(window).size()-1);
            next = map.get(window).get(rannum);
            cout << next << " ";
            window.remove(0);
            window.add(next);
        }else{ // only 1 value
            next = map.get(window).get(0);
            cout << next << " ";
            window.remove(0);
            window.add(next);
        }
    }
    cout << "...";
}

NGRAM readFile(string fn, int n){
    NGRAM map;
    keyvector value;
    keyvector window;
    string token,last;
    Queue<string> wrap;

    ifstream ifs;
    openFile(ifs,fn);
    TokenScanner scanner(ifs);
    scanner.ignoreWhitespace();
    while(scanner.hasMoreTokens() || !wrap.isEmpty()){

        token = scanner.nextToken();
        //cout << token << endl; // for test

        if(map.size()==0 && window.size()<n-1){ // first key set up
            window.add(token);
            wrap.enqueue(token);
        }else if(token==""  && !wrap.isEmpty()){ //wrap around handle

            value.clear();
            last=wrap.dequeue();
            //cout<<last<<endl; //for test
            //cout<<window<<endl; //for test
            value.add(last);
            map.put(window,value);
            window.remove(0);
            window.add(last);
        }else{
            if(map.containsKey(window)){ // if key happened before
                value=map.get(window);
                value.add(token);
                map[window]=value;
                window.remove(0);
                window.add(token);
            }else{ // else
                value.clear();
                value.add(token);
                map.put(window,value);
                window.remove(0);
                window.add(token);
            }

        }


    }

    //cout << map.toString()<<endl; //for test
    //window.clear(); //
    //cout<<map.keys().get(3); //test for start key



    return map;
}

