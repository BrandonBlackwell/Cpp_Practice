#include <string>
#include<cctype>
#include<iostream>
// Structy's "uncompress" problem. 
// The function should return an uncompressed version of the string where each 'char' of a group is repeated 'number' times consecutively.
// Time Complexity: O(l+n x m) n = # of groups, l = length of substring, m = max # found in any group
// Space Complexity: O(n x m) 
// Test Cases:
//uncompress("2c3a1t");
// uncompress("127y");
// uncompress("4s2b");
// uncompress("2p1o5p");
std::string uncompress(std::string s) {
  // todo
  s += '*'; //O(1)
  std::string result = ""; //O(1)
  std::string str_num = ""; //O(1)
  int len = 0; //O(1)
  int i = 0; //O(1)
  int j = 0; //O(1)
  while(j < s.length()){ //O(n)
    // if current char is not in the alphabet go to next char.
    if(!std::isalpha(s[j])){ //O(1)
      j++; //O(1)
    } else {
      // create len for substr
      for(int c = i; c <= j; c++){ //O(n)
        len += 1;
      }
      //slice portion of str 
      str_num = s.substr(i,len); //O(n)
      // convert str to int
      int int_num = std::stoi(str_num); //O(1)
      // Loop 
      for(int i = 0; i < int_num; i++){ //O(n)
        result += s[j];
      }
      str_num = ""; //O(1)
      i = j+1; //O(1)
      j += 1; //O(1)
      len = 0; //O(1)
    }
  }
  
  return result; //O(1)
}


int  main() {
	// function call
std::string result = uncompress("2c3a1t");
std::cout<<result<<std::endl;
return 0;

}
