#include "clothing.h"
#include "util.h"
#include <string>

std::string Clothing::displayString() const
{
    std::string retStr = "";
    retStr += name_ + "\n";
    retStr += "Size: " + size_ + " Brand: " + brand_ + "\n";
    retStr += std::to_string(price_) + " " + std::to_string(qty_) + " left." + "\n";
    return retStr;
}

std::set<std::string> Clothing::keywords() const 
{
    std::set retSet = parseStringToWords(); //ATTENTION: Needs name and brand
    return retSet;
}

void Clothing::dump(std::ostream& os) const 
{
    Product::dump(os);
    os << size_ << "\n" << brand_ << std::endl;
}