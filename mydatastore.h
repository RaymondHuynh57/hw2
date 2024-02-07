#ifndef MYDATASTORE_H
#define MYDATASTORE_H
#include "datastore.h"
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <map>
#include "product.h"
#include "user.h"
#include "util.h"
class MyDataStore : public DataStore{
    public:
        ~MyDataStore();

        void CartAdd(std::string, Product* p);

        void PrintCart(std::string username);

        void BuyCart(std::string username);
        /**
        * Adds a product to the data store
        */
        void addProduct(Product* p);  //Have to make function for this

        /**
        * Adds a user to the data store
        */
        void addUser(User* u);  //Have to make function for this

        /**
        * Performs a search of products whose keywords match the given "terms"
        *  type 0 = AND search (intersection of results for each term) while
        *  type 1 = OR search (union of results for each term)
        */
        std::vector<Product*> search(std::vector<std::string>& terms, int type);  //Have to make function for this

        /**
        * Reproduce the database file from the current Products and User values
        */
        void dump(std::ostream& ofile); //Have to make function for this


        std::vector<User*> Users_;
    private:
        std::vector<Product*> Products_;
        
        //Left is username of user and the right are the Products they bought
        //std::map<std::string, std::set<Product*>> Cart;
        std::map<std::string, std::vector<Product*>> Cart;
        //Add a map here
        std::map<std::string, std::set<Product*>> keywordsMap;

        


};

#endif