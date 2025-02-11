#include <iostream>
#include <sstream>
#include <cctype>
#include <algorithm>
#include "util.h"

using namespace std;
std::string& convToLower(std::string& src)
{
    std::transform(src.begin(), src.end(), src.begin(), ::tolower);
    return src;
}

/** Complete the code to convert a string containing a rawWord
    to a set of words based on the criteria given in the assignment **/
std::set<std::string> parseStringToWords(string rawWords)
{
    std::set<std::string> retSet{};
    repPunctWithSpaces(convToLower(rawWords)); //Makes sure we change case so there's no issues with that
    stringstream ss(rawWords);
    string keyWord = "";
    while(!ss.fail()){
        ss >> keyWord;
        if(keyWord.size() >= 2) //Makes sure the string size is at least 2 to match criteria
            retSet.insert(keyWord);
    }
    return retSet;

}

//Replaces the punctuation in a string with spaces
void repPunctWithSpaces(string& str){
    for(size_t i = 0; i < str.size(); i++){
        if(ispunct(str[i])) //Returns true if this char is punctuation
            str[i] = ' ';
    }
}

/**************************************************
 * COMPLETED - You may use the following functions
 **************************************************/

// Used from http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
// trim from start
// trim from start (in place)
std::string &ltrim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
        return !std::isspace(ch);
    }));
    return s;
}

// trim from end (in place)
std::string &rtrim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
        return !std::isspace(ch);
    }).base(), s.end());
    return s;
}

// trim from both ends
std::string &trim(std::string &s) {
    return ltrim(rtrim(s));
}