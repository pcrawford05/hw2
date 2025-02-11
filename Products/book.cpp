#include "book.h"
#include "util.h"
#include <string>

std::string Book::displayString() const
{
    std::string retStr = "";
    retStr += name_ + "\n";
    retStr += "Author: " + author_ + " ISBN: " + ISBN_ + "\n";
    retStr += std::to_string(price_) + " " + std::to_string(qty_) + " left." + "\n";
    return retStr;
}

std::set<std::string> Book::keywords() const 
{
    std::set retSet = parseStringToWords(author_); //ATTENTION: Needs name as well and some authors have "and" in them
    retSet.insert(ISBN_);
    return retSet;
}

void Book::dump(std::ostream& os) const 
{
    Product::dump(os);
    os << ISBN_ << "\n" << author_ << std::endl;
}