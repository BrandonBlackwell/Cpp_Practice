#include<iostream>
#include<cctype>
#include<string>
/*
 Time Complexity:O()
 Space Complexity:
 */
std::string compress(std::string s){
	s += "*";
	std::string res = "";
	int ptr1 = 0;
	int ptr2 = 1;
	int count = 1;
	// Keep looping as long as ptr2 is less than the length of s
	while(ptr2 < s.length()){
		if(s[ptr1] == s[ptr2]){
			count++;
		} else {
			if(s[ptr1] != s[ptr2] && count == 1){
				res += s[ptr1];
				ptr1++;
			} else {
				std::string c = std::to_string(count);
				res += c;
				res += s[ptr1];
				count = 1;
				ptr1 = ptr2;
			}
		}
		ptr2++;
	}
	return res;
}

int main(){
	// Test Cases:
	std::cout<< compress("ccaaatsss") << std::endl;
	std::cout<< compress("ssssbbz") << std::endl;
	std::cout<< compress("ppoppppp") << std::endl;
	std::cout<< compress("nnneeeeeeeeeeeezz") << std::endl;
	// compress("ssssbbz");
	//compress("ppoppppp"); 
	//compress("nnneeeeeeeeeeeezz");
		return 0;
}
