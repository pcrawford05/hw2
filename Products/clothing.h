#include "product.h"

class Clothing : public Product{
    public:
        std::string displayString() const;
        std::set<std::string> keywords() const;
        void dump(std::ostream& os) const;
    private:
        std::string size_;
        std::string brand_;
};

