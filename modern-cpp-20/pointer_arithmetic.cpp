#include<iostream>
#include<array>
// SECTION 17 POINTERS:
/* A pointer a memory address
 *
 */

// Pointer and Arrays
// The name of an array acts as a pointer to the first value in the array.
// You can derefence an array name just like a pointer in order to get a value.
int main(){
	std::array<int>scores[5]{5,10,15,20,25};
	int *ptr {scores};
	std::cout<< *(scores) <<std::endl;
	std::cout<< *(ptr) <<std::endl;
}
