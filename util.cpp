#include <iostream>
#include <sstream>
#include <cctype>
#include <algorithm>
#include "util.h"

using namespace std;
std::string convToLower(std::string src)
{
    std::transform(src.begin(), src.end(), src.begin(), ::tolower);
    return src;
}

/** Complete the code to convert a string containing a rawWord
    to a set of words based on the criteria given in the assignment **/
std::set<std::string> parseStringToWords(string rawWords)
{
    std::set<std::string> retSet{};
    stringstream ss(rawWords);
    string temp = "";
    while(!ss.fail()){
        ss >> temp;
        if(temp.size() < 2)
            continue;
        bool hasPunct = false;
        for(size_t i = 0; i < temp.size(); i++){
            if(ispunct(temp[i])){ //Checks if any character is punctuation, assumes there's only one punctuation
                hasPunct = true;
                if(i > 1)
                    retSet.insert(temp.substr(0,i));
                if(i + 1 < temp.size())
                    retSet.insert(temp.substr(i+1, temp.size()));
                break;
            }
        }
        if(!hasPunct)
            retSet.insert(temp);
    }
    return retSet;








}

/**************************************************
 * COMPLETED - You may use the following functions
 **************************************************/

// Used from http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
// trim from start
/*std::string &ltrim(std::string &s) {
    s.erase(s.begin(), 
	    std::find_if(s.begin(), 
			 s.end(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))));
    return s;
}

// trim from end
std::string &rtrim(std::string &s) {
    s.erase(
	    std::find_if(s.rbegin(), 
			 s.rend(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))).base(), 
	    s.end());
    return s;
}

// trim from both ends
std::string &trim(std::string &s) {
    return ltrim(rtrim(s));
}
*/