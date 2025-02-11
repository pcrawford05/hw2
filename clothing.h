#include "product.h"

class Clothing : public Product{
    public:
        Clothing(const std::string category, const std::string name, double price, int qty, std::string size, std::string brand);
        std::string displayString() const;
        std::set<std::string> keywords() const;
        void dump(std::ostream& os) const;
    private:
        std::string size_;
        std::string brand_;
};

