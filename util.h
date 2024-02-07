#ifndef UTIL_H
#define UTIL_H

#include <string>
#include <iostream>
#include <set>
#include <vector>



/** Complete the setIntersection and setUnion functions below
 *  in this header file (since they are templates).
 *  Both functions should run in time O(n*log(n)) and not O(n^2)
 */

 //SETS
template <typename T>
std::set<T> setIntersection(std::set<T>& s1, std::set<T>& s2)
{

  
  std::set<T> result;
  typename std::set<T>::iterator it;  //When using T template, must put typename before everything
  //typename std::set<T>::iterator it_two;

  for(it = s1.begin(); it != s1.end(); ++it){ //O(n)
      //std::cout << "INSIDE INTERSECTION: " << *it << std::endl;
      if(s2.find(*it) != s2.end()){ //If I find the substring in the second set. O(logn)
          
          result.insert(*it);
      }
  }
  return result;
}
template <typename T>
std::set<T> setUnion(std::set<T>& s1, std::set<T>& s2)
{
  std::set<T> result;
  typename std::set<T>::iterator it;

  for(it = s1.begin(); it != s1.end(); ++it){ //O(n)
      //std::cout << "SOMETHING" << std::endl;
      
      if(s2.find(*it) != s2.end()){
        //std::cout << "IN IF: " << *it << std::endl;
        result.insert(*it);
      }else{
        //std::cout << "ELSE: " << *it << std::endl;
        result.insert(*it);
      }
  }

  //std::cout << "------------>" << std::endl;
  for(it = s2.begin(); it != s2.end(); ++it){
      //std::cout << "s2: " << *it << std::endl;
      if(result.find(*it) != result.end()){
          //std::cout << "s2: " << *it << std::endl;
      }else{
          //std::cout << "INSERT" << std::endl;
          result.insert(*it);
      }
  }
  /*
  std::cout << "RESULT--------------->" << std::endl;
  for(it = result.begin(); it != result.end(); ++it){
      std::cout << *it << std::endl;
  }
  */
  return result;


}

//-------------------------->

/***********************************************/
/* Prototypes of functions defined in util.cpp */
/***********************************************/

std::string convToLower(std::string src);

std::set<std::string> parseStringToWords(std::string line);

// Used from http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
// Removes any leading whitespace
std::string &ltrim(std::string &s) ;

// Removes any trailing whitespace
std::string &rtrim(std::string &s) ;

// Removes leading and trailing whitespace
std::string &trim(std::string &s) ;
#endif
