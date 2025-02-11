#include "product.h"

class Movie : public Product{
    public:
        Movie(const std::string category, const std::string name, double price, int qty, std::string genre, std::string rating);
        std::string displayString() const;
        std::set<std::string> keywords() const;
        void dump(std::ostream& os) const;
    private:
        std::string genre_;
        std::string rating_;
};

