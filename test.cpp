#include <iostream>
#include <algorithm>
#include "util.h"
using namespace std;

int main() {
    set<string> words = parseStringToWords("A senten'ce for my parser to try.");
    for(string x : words){
        cout << x << endl;
    } 
}