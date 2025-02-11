#include "product.h"

class Movie : public Product{
    public:
        std::string displayString() const;
        std::set<std::string> keywords() const;
        void dump(std::ostream& os) const;
    private:
        std::string genre_;
        std::string rating_;
};

