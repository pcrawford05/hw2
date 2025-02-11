#ifndef MYDATASTORE_H
#define MYDATASTORE_H
#include "datastore.h"
#include <queue>

class MyDataStore : public DataStore {
    public:
        ~MyDataStore();
        void addProduct(Product* p);
        void addUser(User* u);
        //Adds product p to cart at index user_idx, to line up with the given user index
        void addToCart(Product* p, size_t user_idx);
        //Prints out the items in the cart
        std::string cartToString(size_t user_idx);
        //Attempts to buy all items in cart of the user in index use_idx
        void buyCart(size_t user_idx);
        std::vector<Product*> search(std::vector<std::string>& terms, int type);
        void dump(std::ostream& ofile);
        //Checks to see if the inputted username matches one of the usernames
        int isValidUsername(std::string& u);
    private:
    std::vector<Product*> products_;
    std::vector<User*> users_;
    std::vector<std::queue<Product*>> carts_;
};

#endif