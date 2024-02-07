#ifndef BOOK_H
#define BOOK_H
#include "product.h"
#include <iostream>
#include <string>


//#include <set>

class Book : public Product{
    public:

    //Product(const std::string category, const std::string name, double price, int qty)


        //Book(const std::string category, const std::string name, double price, int qty, std::string author, size_t isbn): Product(category, name, price, qty), author_(author), isbn_(isbn){};
        Book(const std::string category, const std::string name, double price, int qty, std::string author, std::string isbn);

        ~Book();
         /**
        * Returns the appropriate keywords that this product should be associated with
        */

        /*
        keywords() which returns the appropriate keywords to index the product,
        */
        std::set<std::string> keywords() const;

        /**
        * Allows for a more detailed search beyond simple keywords
        */
        bool isMatch(std::vector<std::string>& searchTerms) const;

        /**
        * Returns a string to display the product info for hits of the search
        */
        std::string displayString() const;

        /**
        * Outputs the product info in the database format
        */
        void dump(std::ostream& os) const;



    private:
        std::string author_;
        std::string isbn_;

};
#endif