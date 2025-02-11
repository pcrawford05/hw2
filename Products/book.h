#include "product.h"

class Book : public Product{
    public:
        std::string displayString() const;
        std::set<std::string> keywords() const;
        void dump(std::ostream& os) const;
    private:
        std::string ISBN_;
        std::string author_;
};

