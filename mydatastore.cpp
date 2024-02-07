#include "mydatastore.h"
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <map>
#include <algorithm>
#include "product.h"
#include "user.h"
#include "util.h"






#include "movie.h"
#include "book.h"
#include "clothing.h"
using namespace std;


MyDataStore::~MyDataStore(){
    for(unsigned int i = 0; i < Products_.size(); ++i){
        delete Products_[i];
    }
    for(unsigned int i = 0 ; i < Users_.size(); ++i){
        delete Users_[i];
    }
}


void MyDataStore::CartAdd(string username, Product* p){
    Cart[username].push_back(p);
}


void MyDataStore::PrintCart(string username){
    vector<Product*> temp = Cart[username];
    for(size_t i = 0; i < temp.size(); ++i){
        cout << "Item " << i + 1 << endl; 
        cout << temp[i]->displayString() << endl;
        cout << endl;
    }
   
}


void MyDataStore::BuyCart(string username){
    vector<Product*> temp = Cart[username];
    User* temp_User;
    for(size_t i = 0; i < Users_.size(); ++i){
        if(username == Users_[i]->getName()){
            temp_User = Users_[i];
        }
    }


 
    for(size_t i = 0; i < temp.size(); ++i){
        if((temp_User->getBalance() >= temp[i]->getPrice()) && (temp[i]->getQty() != 0)){
            temp_User->deductAmount(temp[i]->getPrice());
            temp[i]->subtractQty(1);
            Cart[username].pop_back();
        }else{

        }
       
    }
}
/**
* Adds a product to the data store
*/
void MyDataStore::addProduct(Product* p){
    Products_.push_back(p);
    set<string> s1 = p->keywords();
    set<string>::iterator it;
   
    for(it = s1.begin(); it != s1.end(); ++it){
        keywordsMap[*it].insert(p);
    }
}






/**
* Adds a user to the data store
*/
void MyDataStore::addUser(User* u){
    Users_.push_back(u);
}


/**
* Performs a search of products whose keywords match the given "terms"
*  type 0 = AND search (intersection of results for each term) while
*  type 1 = OR search (union of results for each term)
*/
vector<Product*> MyDataStore::search(vector<string>& terms, int type){
    /*
      Books: the words in the author’s name should be searchable keywords as well as the book’s ISBN number
      Clothing: the words in the brand should be searchable keywords
      Movie: the movie’s genre should be a searchable keyword




    */
      //Key are search terms
      //Values are the set of products that are found based off of the search terms




/*
AND/OR Search - Your system should allow users to search for products based on entering one or more keywords at the program menu prompt. An AND search should return all the products that contain ALL the search terms entered. An OR search is defined as all the products that contain ANY of the search terms entered. At the prompt the user will need to write AND or OR as their first word/command followed by any number of search terms separated by spaced. Your search should treat those terms as case-insensitive when it comes to matching. Examples might be:
AND Men would be the same as OR Men since there is only 1 term and would return all products that have the word men. (i.e. the book Great Men and Women of Troy and Men's Fitted Shirt).
AND hidden Data would return nothing since no products have both those terms
OR hidden Data would return both the Hidden Figures DVD and Data Abstraction & Problem Solving with C++ products
You may choose any reasonable behavior if the search consists only of AND or OR (no keywords)
Your search must be implemented "efficiently". You should not have to iterate over ALL products to find the appropriate matches. Some kind of mapping between keywords and products that match that keyword should be implemented.
*/


/*
So currently it's easy to go from Product* to a keyword, but our goal is to go from keyword to Product*.
When we read in a new Product, we can easily retrieve its list of keywords by calling keywords().
And we know that for each of those keywords, it is linked to that said Product. Is there a
good location where we can store this information, and what data structure would make
the most sense for this design?
*/
    vector<Product*> result;
    set<Product*> Intersect;
    set<Product*> Union;


    if(type == 0){  //AND SEARCH
        for(size_t i = 0; i < Products_.size(); ++i){
            Intersect.insert(Products_[i]);
        }
       
        for(unsigned int i = 0; i < terms.size(); ++i){
          string lowercase = convToLower(terms[i]);
          if(keywordsMap.find(lowercase) != keywordsMap.end()){
             
              set<Product*> example_one = keywordsMap.find(lowercase)->second;
              Intersect = setIntersection(Intersect, example_one);
              //set<Product*>::iterator it;
             
          }
        }


        set<Product*>::iterator it_result;
        for(it_result = Intersect.begin(); it_result != Intersect.end(); ++it_result){
            result.push_back(*it_result);
        }




    }else{  //OR SEARCH
         for(unsigned int i = 0; i < terms.size(); ++i){
          string lowercase = convToLower(terms[i]);
          if(keywordsMap.find(lowercase) != keywordsMap.end()){
              set<Product*> example_one = keywordsMap.find(lowercase)->second;
              Union = setUnion(Union, example_one);
              //set<Product*>::iterator it;
             
          }
        }


        set<Product*>::iterator it_result;
        for(it_result = Union.begin(); it_result != Union.end(); ++it_result){
            result.push_back(*it_result);
        }
    }
  return result;
}


/**
* Reproduce the database file from the current Products and User values
*/
void MyDataStore::dump(ostream& ofile){
   
    ofile << "<products>" << endl;
    for(size_t i = 0; i < Products_.size(); ++i){
        Products_[i]->dump(ofile);
    }
    ofile << "</products>" << endl;
    ofile << "<users>" << endl;
    for(size_t i = 0; i < Users_.size(); ++i){
        Users_[i]->dump(ofile);
    }
    ofile << "</users>" << endl;
}


//Iterators can’t be modified (meaning that you can’t erase them, that’s it)
