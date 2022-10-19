#include <iostream>
#include <vector>

// Passing vector to a function
           void print_vector(std::vector<int> &v){
                  for(int i = 0; i < v.size();i++){
                          std::cout << v[i] << "\n" << std::endl;
   }
  }


int main(){

	std::vector<int> my_vector1 = {1,2,3,4};
	my_vector1.push_back(5);
	my_vector1.pop_back();
	// function call
	print_vector(my_vector1);

 return 0;
}
