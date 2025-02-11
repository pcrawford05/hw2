#include "clothing.h"
#include "util.h"
#include <string>

Clothing::Clothing(const std::string category, const std::string name, double price, int qty, std::string size, std::string brand) : Product(category, name, price, qty), size_(size), brand_(brand)
{

}

std::string Clothing::displayString() const
{
    std::string retStr = "";
    retStr += name_ + "\n";
    retStr += "Size: " + size_ + " Brand: " + brand_ + "\n"; //Bonus items
    retStr += std::to_string(price_) + " " + std::to_string(qty_) + " left." + "\n";
    return retStr;
}

std::set<std::string> Clothing::keywords() const 
{
    return setUnion(parseStringToWords(name_), parseStringToWords(brand_)); 
}

void Clothing::dump(std::ostream& os) const 
{
    Product::dump(os);
    os << size_ << "\n" << brand_ << std::endl;
}