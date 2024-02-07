#include "movie.h"
#include "util.h"
#include <iostream>
#include <string>
#include <cctype>
#include <sstream>
#include <iomanip>
#include <set>

using namespace std;

Movie::Movie(const string category, const string name, double price, int qty, string genre, string rating): Product(category, name, price, qty), genre_(genre), rating_(rating)
{

}
Movie::~Movie(){

}
/**
* Returns the appropriate keywords that this product should be associated with
*/

/*
  keywords() which returns the appropriate keywords to index the product,
*/
set<string> Movie::keywords() const{
    
    set <string> result;
    set<string> result_one = parseStringToWords(name_);
    //Genre
    set<string> result_two = parseStringToWords(genre_);
    set<string>::iterator it;
    for(it = result_one.begin(); it != result_one.end(); ++it){
        result.insert(*it);
    }
    for(it = result_two.begin(); it != result_two.end(); ++it){
        result.insert(*it);
    }
    
    return result;

}

/**
* Allows for a more detailed search beyond simple keywords
*/
bool Movie::isMatch(vector<string>& searchTerms) const{
    //cout << "isMatch" << endl;
}

/**
* Returns a string to display the product info for hits of the search
*/
string Movie::displayString() const{ //Can't modify private and protected variables. Even if protected variables are from the base class, you can't modify the protected variables no matter what

    stringstream ss;
    ss << fixed << setprecision(2) << price_;
    string string_price;
    ss >> string_price;
    string result = name_ + "\nGenre: " + genre_ + " Rating: " + rating_ + "\n" + string_price + " " + to_string(qty_) + " left.";
    return result;
    
}


/**
* Outputs the product info in the database format
*/
void Movie::dump(ostream& os) const{
    os << category_ << "\n" << name_ << "\n" << price_ << "\n" << qty_ << "\n" << genre_ << "\n" << rating_ << endl;
}