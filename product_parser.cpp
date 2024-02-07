#include <iostream>
#include <sstream>
#include "product_parser.h"
#include "book.h"
#include "clothing.h"
#include "movie.h"
#include "util.h"
using namespace std;


ProductParser::ProductParser()
{
  //cout << "PRODUCT PARSER" << endl;
}


ProductParser::~ProductParser()
{

}


Product* ProductParser::parse(string category,
                              istream& is,
                              bool& error,
                              string& errorMsg,
                              int& lineno)
{

    parseCommonProduct(is, error, errorMsg, lineno);
    if(error) return NULL;
    return parseSpecificProduct(category, is, error, errorMsg, lineno);
}

void ProductParser::parseCommonProduct(std::istream& is,
                                       bool& error,
                                       string& errorMsg,
                                       int& lineno)

{
    string myline;
    getline(is, myline);
    myline = trim(myline);
    if(myline.size() == 0) {
        error = true;
        errorMsg = "Unable to find a product name";
        return;
    }
    prodName_ = myline;

    lineno++;
    getline(is, myline);
    if(is.fail()) {
        error = true;
        errorMsg = "Expected another line with the price";
        return;
    }
    stringstream ss1(myline);
    ss1 >> price_;
    if( ss1.fail() ) {
        error = true;
        errorMsg = "Unable to read price";
        return;
    }

    lineno++;
    getline(is, myline);
    if(is.fail()) {
        error = true;
        errorMsg = "Expected another line with the quantity";
        return;
    }
    stringstream ss2(myline);
    ss2 >> qty_;
    if( ss2.fail() ) {
        error = true;
        errorMsg = "Unable to read quantity";
        return;
    }
    lineno++;
}

ProductBookParser::ProductBookParser() : ProductParser()
{
  //cout << "BOOK PARSER" << endl;
}

Product* ProductBookParser::parseSpecificProduct(std::string category,
        std::istream& is,
        bool& error,
        std::string& errorMsg,
        int& lineno)
{
    string myline;
    getline(is, myline);
    stringstream ss3(myline);
    ss3 >> isbn_;
    if(ss3.fail()) {
        error = true;
        errorMsg = "Unable to read ISBN";
        return NULL;
    }

    lineno++;
    getline(is, author_);
    if(is.fail()) {
        error = true;
        errorMsg = "Unable to read author";
        return NULL;
    }
#ifdef DEBUG
    cout << "Making product " << prodName_ << endl;
#endif
    lineno++;
    if(error) {
        return NULL;
    }
    return makeProduct();

}

std::string ProductBookParser::categoryID()
{
    return "book";
}

/**
     * Dynamically allocates a specific product type from the data
     *  parsed and stored in the specific product parser
*/
/**
 * Your job to fill in the code to create a new book product
 * using the data members in this class and the parent ProductParser class
 */

 //Book(const std::string category, const std::string name, double price, int qty, std::string author, std::string isbn);
Product* ProductBookParser::makeProduct()
{
    Product * temp = new Book("book", prodName_, price_, qty_, author_, isbn_);
    return temp;
}


ProductClothingParser::ProductClothingParser()
{
}

Product* ProductClothingParser::parseSpecificProduct(std::string category,
        std::istream& is,
        bool& error,
        std::string& errorMsg,
        int& lineno)
{
    string myline;
    getline(is, myline);
    stringstream ss3(myline);
    ss3 >> size_;
    if(ss3.fail()) {
        error = true;
        errorMsg = "Unable to read size";
        return NULL;
    }

    lineno++;
    getline(is, brand_);
    if(is.fail() || (brand_.size() == 0)) {
        error = true;
        errorMsg = "Unable to read brand";
        return NULL;
    }
#ifdef DEBUG
    cout << "Making product " << prodName_ << endl;
#endif
    lineno++;
    if(error) {
        return NULL;
    }
    return makeProduct();

}

std::string ProductClothingParser::categoryID()
{
    return "clothing";
}

// Clothing(const std::string category, const std::string name, double price, int qty, std::string brand, std::string size);
/**
     * Dynamically allocates a specific product type from the data
     *  parsed and stored in the specific product parser
*/
/**
 * Your job to fill in the code to create a new clothing product
 * using the data members in this class and the parent ProductParser class
 */
Product* ProductClothingParser::makeProduct()
{
    Product * temp = new Clothing("clothing", prodName_, price_, qty_, brand_, size_);
    return temp;
}



ProductMovieParser::ProductMovieParser()
{
}


Product* ProductMovieParser::parseSpecificProduct(std::string category,
        std::istream& is,
        bool& error,
        std::string& errorMsg,
        int& lineno)
{
    string myline;
    getline(is, myline);
    stringstream ss3(myline);
    ss3 >> genre_;
    if(ss3.fail()) {
        error = true;
        errorMsg = "Unable to read genre";
        return NULL;
    }

    lineno++;
    getline(is, myline);
    stringstream ss4(myline);
    ss4 >> rating_;
    if(ss4.fail()) {
        error = true;
        errorMsg = "Unable to read rating";
        return NULL;
    }
#ifdef DEBUG
    cout << "Making product " << prodName_ << endl;
#endif
    lineno++;
    if(error) {
        return NULL;
    }
    return makeProduct();

}

std::string ProductMovieParser::categoryID()
{
    return "movie";
}

//Movie(const std::string category, const std::string name, double price, int qty, std::string genre, std::string rating);
/**
 * Your job to fill in the code to create a new movie product
 * using the data members in this class and the parent ProductParser class
 */
Product* ProductMovieParser::makeProduct()
{
    Product * temp = new Movie("movie", prodName_, price_, qty_, genre_, rating_);
    return temp;

}
