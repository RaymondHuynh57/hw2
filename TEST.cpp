#include <iostream>
#include <set>
#include "util.h"
//#include "product.h";
#include "book.h"
#include "clothing.h"
#include "movie.h"
#include "product_parser.h"
#include "product.h"
#include "mydatastore.h"
using namespace std;

int main(){
 
  

/*
  set <string> s1;
  s1.insert("s1 Number 1");
  s1.insert("s1 Number 2");
  s1.insert("s1 Number 3");

  set <string> s2;
  s2.insert("s1 Number 1");
  s2.insert("s1 Number 2");
  s2.insert("s2 Number 2");
  //set <string> Intersect = setIntersection(s1, s2);
  set <string> Intersect = setUnion(s1, s2);
*/

//Test book
/*



  Book b1("book", "Data Abstraction & Problem Solving with C++", 79.99, 20, "Carrano and Henry", "978-013292372-9");
  set<string> res = b1.keywords();
  string result = b1.displayString();
  b1.dump(cout);
*/

  //Test Clothing
/*
  Clothing c1("clothing", "Men's Fitted Shirt", 39.99, 25, "J. Crew", "Medium");
  string result = c1.displayString();
  cout << "YO-------------->" << endl;
  c1.dump(cout);
*/

  //Test Movies

/*
  Movie m1("movie", "Hidden Figures DVD", 17.99, 1, "Drama", "PG");
  string result = m1.displayString();
  cout << "LINE--------------------->" << endl;
  m1.dump(cout);
*/

 //Product Parser Test
  //ProductBookParser PB1;
  //PB1.makeProduct();

  //parseStringToWords Test
  /*
  set<string> parse = parseStringToWords("TEST.TEST2");
  set<string>::iterator it;
  cout << "----------------->" << endl;
  for(it = parse.begin(); it != parse.end(); ++it){
      cout << *it << endl;
  }
  cout << "------------------->" << endl;
  vector<string> parse_result(parse.begin(), parse.end());
  for(unsigned int i = 0; i < parse_result.size(); ++i){
      cout << "VECTOR: " << parse_result[i] << endl;
  }

  */
  //cout << "MYDATASTORE----------------->" << endl;
  MyDataStore m1;

  //Movie(const std::string category, const std::string name, double price, int qty, std::string genre, std::string rating);
  //Product* temp = new Movie("movie", "Black Panther", 21.21, 4, "action", "PG");
  //Book(const std::string category, const std::string name, double price, int qty, std::string author, std::string isbn);
  //Product* temp_two = new Book("book", "Mrs. Frisby and the Rats of Nimh", 44.21, 3, "Kelly", "382479243297");

  //vector<Product*> parse_result;
  //parse_result.push_back(temp);
  //parse_result.push_back(temp_two);
  vector<string> parse_result;
  parse_result.push_back("hidden");
  parse_result.push_back("Data");
  //parse_result.push_back("something_two");
  vector<Product*> p1 = m1.search(parse_result, 1);

  //cout << p1.size() << endl;
  for(size_t i = 0; i < p1.size(); ++i){
      //cout << "SOMETHING" << endl;
      p1[i]->dump(cout);
  }

  cout << "------------>" << endl;
  m1.dump(cout);
}