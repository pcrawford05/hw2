#include "movie.h"
#include "util.h"
#include <string>

std::string Movie::displayString() const
{
    std::string retStr = "";
    retStr += name_ + "\n";
    retStr += "Genre: " + genre_ + " Rating: " + rating_ + "\n";
    retStr += std::to_string(price_) + " " + std::to_string(qty_) + " left." + "\n";
    return retStr;
}

std::set<std::string> Movie::keywords() const 
{
    std::set retSet = parseStringToWords(); //ATTENTION: Needs name and genre
    return retSet;
}

void Movie::dump(std::ostream& os) const 
{
    Product::dump(os);
    os << genre_ << "\n" << rating_ << std::endl;
}