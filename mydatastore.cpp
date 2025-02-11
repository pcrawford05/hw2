#include "mydatastore.h"
#include "util.h"

MyDataStore::~MyDataStore(){
    //Deletes all products
    for(std::vector<Product*>::iterator it = products_.begin(); it != products_.end(); ++it){
        delete (*it);
    }

    //Deletes all users
    for(std::vector<User*>::iterator it = users_.begin(); it != users_.end(); ++it){
        delete (*it);
    }

    /*
    //Deletes all items in carts, is this not needed because we are using Product pointers so the above deletes them all?
    for(std::vector<std::queue<Product*>>::iterator it = carts_.begin(); it != carts_.end(); ++it){
        while (!(it->empty())){
            delete it->front();
            it->pop();
        }
    }
    */
}

void MyDataStore::addProduct(Product* p)
{
    products_.push_back(p);
}

void MyDataStore::addUser(User* u)
{
    users_.push_back(u);
    carts_.push_back(std::queue<Product*>()); //Puts an empty cart in the same index, I would just add it to the user class but I don't think I'm supposed to modify that
}
  
void MyDataStore::addToCart(Product* p, size_t user_idx) {
    carts_[user_idx].push(p);
}

std::string MyDataStore::cartToString(size_t user_idx){
    std::string retStr = "";
    std::queue<Product*> q = carts_[user_idx]; //Make a copy so we don't change the actual cart but more so that we can iterate through
    int num = 1;
    while(!q.empty()){
        retStr += "Item " + std::to_string(num++) + ": \n" + q.front()->displayString();
        q.pop();
    }
    return retStr;
}

void MyDataStore::buyCart(size_t user_idx){
    std::queue<Product*>& q = carts_[user_idx]; //Renaming for ease of use
    User*& u = users_[user_idx]; //Renaming for ease of use
    size_t size = q.size(); //Needed because the size changes
    for(size_t i = 0; i < size; i++){
        if(q.front()->getQty() > 0 && q.front()->getPrice() <= u->getBalance()){
            q.front()->subtractQty(1);
            u->deductAmount(q.front()->getPrice());
        }
        else
          q.push(q.front());//If we can't buy we just move it to the back
        q.pop();
    }
}

std::vector<Product*> MyDataStore::search(std::vector<std::string>& terms, int type)
{
    std::vector<Product*> retProds; //Vector of "hits" to return

    
    if(type) { // OR Search
        for(std::vector<Product*>::iterator prodIt = products_.begin(); prodIt != products_.end(); ++prodIt){
            for(std::vector<std::string>::iterator termIt = terms.begin(); termIt != terms.end(); ++termIt){    
                std::set<std::string> keywords = (*prodIt)->keywords(); //Create a variable so we don't have to do calculation twice
                if(setUnion({(*termIt)}, keywords) == keywords) //Checks if the term changes the union, if not then it is in it and we add that product
                    retProds.push_back(*prodIt);
            }
        }
    } else { // AND Search
        std::set<std::string> termSet = {}; // Set of all the terms
        for(std::vector<std::string>::iterator it = terms.begin(); it != terms.end(); ++it){
            termSet.insert(*it);
        }
        for(std::vector<Product*>::iterator it = products_.begin(); it != products_.end(); ++it){
            if(setIntersection(termSet, (*it)->keywords()) == termSet) //Checks if the keywords have at least all the terms in it
                retProds.push_back(*it);
        }
    }

    return retProds;
}
        
void MyDataStore::dump(std::ostream& ofile)
{
    //Outputs all the details for each product
    ofile << "<products>" << std::endl;
    for(std::vector<Product*>::iterator it = products_.begin(); it != products_.end(); ++it){
        (*it)->dump(ofile);
    }
    ofile << "</products>" << std::endl;
    
    //Outputs all the details for each user
    ofile << "<users>" << std::endl;
    for(std::vector<User*>::iterator it = users_.begin(); it != users_.end(); ++it){
        (*it)->dump(ofile);
    }
    ofile << "</users>" << std::endl;
}

int MyDataStore::isValidUsername(std::string& u) {
    for(size_t i = 0; i < users_.size(); i++){
        std::string uname = (users_[i])->getName(); //Needed to declare it separately because of reference shananigans. Couldn't keep it anonymous.
        if(convToLower(uname) == convToLower(u))
            return i;
    }
    return -1;
}