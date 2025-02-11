#include "product.h"

class Book : public Product{
    public:
        Book(const std::string category, const std::string name, double price, int qty, std::string author, std::string ISBN);
        std::string displayString() const;
        std::set<std::string> keywords() const;
        void dump(std::ostream& os) const;
    private:
        std::string author_;
        std::string ISBN_;
};

