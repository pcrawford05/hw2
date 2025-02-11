#include "movie.h"
#include "util.h"
#include <string>

Movie::Movie(const std::string category, const std::string name, double price, int qty, std::string genre, std::string rating) : Product(category, name, price, qty), genre_(genre), rating_(rating)
{

}

std::string Movie::displayString() const
{
    std::string retStr = "";
    retStr += name_ + "\n";
    retStr += "Genre: " + genre_ + " Rating: " + rating_ + "\n"; //Bonus items
    retStr += std::to_string(price_) + " " + std::to_string(qty_) + " left." + "\n";
    return retStr;
}

std::set<std::string> Movie::keywords() const 
{
    return setUnion(parseStringToWords(name_), parseStringToWords(genre_)); // parseStringToWords likely not needed for genre as it is likely one word but wanted to include it to catch even edge cases
}

void Movie::dump(std::ostream& os) const 
{
    Product::dump(os);
    os << genre_ << "\n" << rating_ << std::endl;
}