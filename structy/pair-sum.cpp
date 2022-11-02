#include <array>
#include <vector>
#include <unordered_map>
#include <iostream>

std::array<int, 2> pairSum(std::vector<int> numbers, int target) {
	// Brute force way
	// Time Complexity: O(n^2), Nested loops
	// Space Complexity: O(1), I create an array of size 2. No matter the size of the input, the result array will always be 2.
	// std::array <int, 2> indexes{};
	//   for(int i = 0; i < numbers.size()-1; i++){
	//     for(int j = i+1; j < numbers.size(); j++){
	//       int tot = numbers[i]+numbers[j];
	//       if(tot == target){
	//         indexes[0] = i;
	//         indexes[1] = j;
	//       }
	//     }
	//   }
	// return indexes;

	// A more optimal way
	// Time Complexity:O(n) <=> O(n+n) because I iterate through numbers array on 2 seperate occasions.
	// Space Complexity:O(n) because ever item from the input is stored in umap and result 2 items is stored in a result array.
	std::array<int,2> res {};
	std::unordered_map<int,int>dict{};
	for(int i = 0; i < numbers.size(); i++){
		dict[numbers[i]] = i;
	}

	for(int i = 0; i < numbers.size(); i++){
		int pair = target - numbers[i];
		if(dict[pair] && pair > 0){
			res[0] = i;
			res[1] = dict[pair];
			return res;
		} 

	}
  
}

// main function
int main() {
	std::vector<int> numbers { 1, 6, 7, 2 };
	std::array<int,2>res{};
     	res = pairSum(numbers,13);
	for(auto num: res){
		std::cout<<num<<std::endl;
	}
	
}
