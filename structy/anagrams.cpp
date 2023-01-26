#include <string>
#include <algorithm>
#include <iostream>
// Time Complexity: O(l + n log(n) + m log(m))
// Space Complexity: O(1):
// solution
bool anagrams(std::string s1, std::string s2) {
	std::sort(s1.begin(),s1.end()); // n log(n)
	std::sort(s2.begin(),s2.end()); // m log(m)
	if(s1.length() == s2.length()){ // O(1)
		int i = 0;
		while(i < s1.length()){ // O(n)
			if(s1[i] == s2[i]) {
				i++;
			} else {
				return false;
			}
		}
		return true;
	}
	return false;
}
// main function
int main(){
	// Test Cases
	// anagrams("restful", "fluster"); // -> true
	// anagrams("cats", "tocs"); // -> false
	// anagrams("monkeyswrite", "newyorktimes"); // -> true
	// anagrams("po", "popp"); // -> false
	std::cout << anagrams("restful", "fluster") << std::endl;
	std::cout << anagrams("cats", "tocs") << std::endl;
	std::cout << anagrams("monkeyswrite", "newyorktimes") << std::endl;
	std::cout << anagrams("po", "popp") << std::endl;

	return 0;
}
