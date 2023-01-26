/*This section covers "Unique Pointers"
 *
 * There can only be one pointer managing memory.
 * Memory is automatically released when pointer goes out of scope.
 * To use smart pointers you have to include the memory header.
 * Smart pointers use heap memory.
 * When using "Raw Pointers" memory is allocated on the heap by using the keyword "new" and deallocated using "delete".
 * Once allocated you can then use the access operator "->" to access the member variables/methods and use the dereference operator to dereference the pointer and gain access to what the pointer is pointing to.
 * Unique pointers can't be copied. Which means we can't use a unique pointer to initialize another unique pointer.
 * Instead of copying unique pointers we can "move ownership"
 * Moving ownership of a unique pointer gives up it's memory management rights to another unique pointer
 std::move(smart pointer namel)
 * Smart Pointers eliminates the headache of releasing the memory  when then pointer is no longer needed which saves you from memory leaks.
 *
 *
 * There are different ways to use unique pointers
 * 1. Use unique pointers to manage raw pointers
 * 2. We can initialize a unique pointer with nullptr and give it memory to manage later
 * 3. We can use it just like a raw pointer
 * 4. Another way you can initialize a unique pointer without having to specify the "new" keyword is by
 * using "std::make_unique<type>(data to be initialized)". Doing it this way makes the code cleaner, it allows the system to call the "new operator" instead of us doing it manually
 * 5. Move ownership of a unique pointer
 * 6. 
 */


#include<iostream>
#include<string>
#include<memory>

//main function
int main(){
	//Classic ptr
	std::string *ptr1 = new std::string ("Hello World");
	//std::cout << ptr1 << std::endl;
	//std::cout << *ptr1 << std::endl;
	//
	//1.
	// unique pointer declaration/init
	// Using a smart pointer to manage a raw pointer
	std::unique_ptr<std::string> smart_ptr1{ptr1};
	std::cout<< smart_ptr1 <<std::endl;
	std::cout << *smart_ptr1 << std::endl;
	//2.
	//intialized ptr to nullptr
	std::unique_ptr<int> smart_ptr2{nullptr};
	//std::cout << *smart_ptr2 << std::endl;
	//3.
	//using unique pointer just like a raw pointer
	std::unique_ptr<std::string> smart_ptr3(new std::string("You created a unique ptr successfully"));
	std::cout << *smart_ptr3 << std::endl;

	//4.
	//not using "new" keyword by using make_unique
	std::unique_ptr<std::string> smart_ptr4 = std::make_unique<std::string>("new is gone");
	//std::make_unique<Vec3>();
	std::cout << *smart_ptr4 << std::endl;
	//5.
	// Reassigned smart_ptr2
	// Moved ownership of that memory location
	std::unique_ptr<int> ptr2 {std::make_unique<int>(20)};
	smart_ptr2 = std::move(ptr2);
	std::cout << *smart_ptr2 << std::endl;
	return 0;
}
