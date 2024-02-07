#include "book.h"
#include "util.h"
#include <iostream>
#include <string>
#include <cctype>
#include <sstream>
#include <iomanip>
#include <set>
using namespace std;

Book::Book(const string category, const string name, double price, int qty, string author, string isbn): Product(category, name, price, qty), author_(author), isbn_(isbn)
{

};
Book::~Book(){

}
/**
* Returns the appropriate keywords that this product should be associated with
*/

/*
  keywords() which returns the appropriate keywords to index the product,
*/
set<string> Book::keywords() const{
    //cout << "keywords" << endl;
    //Name, author name, isbn number
    set<string> result;
    set<string>::iterator it;
    set<string> result_one = parseStringToWords(name_);
    set<string> result_two = parseStringToWords(author_);
    
    for(it = result_one.begin(); it != result_one.end(); ++it){
        result.insert(*it);
    }
    for(it = result_two.begin(); it != result_two.end(); ++it){
        result.insert(*it);
    }
    result.insert(isbn_);
    return result;

}

/**
* Allows for a more detailed search beyond simple keywords
*/
bool Book::isMatch(vector<string>& searchTerms) const{
    //cout << "isMatch" << endl;
}

/**
* Returns a string to display the product info for hits of the search
*/
string Book::displayString() const{ //Can't modify private and protected variables. Even if protected variables are from the base class, you can't modify the protected variables no matter what
    stringstream ss;
    ss << fixed << setprecision(2) << price_;
    string string_price;
    ss >> string_price;
    string result = name_ + "\nAuthor: " + author_ + " ISBN: " + isbn_ + "\n" + string_price + " " + to_string(qty_) + " left.";
    return result;
    
}

/**
* Outputs the product info in the database format
*/
void Book::dump(ostream& os) const{
    os << category_ << "\n" << name_ << "\n" << price_ << "\n" << qty_ << "\n" << isbn_ << "\n" << author_ << endl;
}