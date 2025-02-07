#include <iostream>
#include <algorithm>
#include "util.h"
using namespace std;

int main() {
    
    set<string> words = parseStringToWords("..A senten'ce f.!or my parser to try'ings.");
    for(string x : words){
        cout << x << endl;
    }
/*
   set<int> s1 = {1,2,3,4,5,6};
   set<int> s2 = {2, 9, 6, 7};
   set<int> intersection = setIntersection(s1, s2);
   set<int> u = setUnion(s1,s2);
   cout << "Intersection" << endl;
   for(int x : intersection)
    cout << x << endl;
   cout << "Union" << endl;
   for(int x : u)
    cout << x << endl;
    */
}