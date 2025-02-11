#include "book.h"
#include "util.h"
#include <string>

Book::Book(const std::string category, const std::string name, double price, int qty, std::string author, std::string ISBN) : Product(category, name, price, qty), author_(author), ISBN_(ISBN)
{

}

std::string Book::displayString() const
{
    std::string retStr = "";
    retStr += name_ + "\n";
    retStr += "Author: " + author_ + " ISBN: " + ISBN_ + "\n"; //Bonus Items
    retStr += std::to_string(price_) + " " + std::to_string(qty_) + " left." + "\n";
    return retStr;
}

std::set<std::string> Book::keywords() const 
{
    return setUnion(setUnion(parseStringToWords(name_), parseStringToWords(author_)), {ISBN_}); //Note: Multiple authors will include and in the name which I hope is fine

}

void Book::dump(std::ostream& os) const 
{
    Product::dump(os);
    os << ISBN_ << "\n" << author_ << std::endl;
}