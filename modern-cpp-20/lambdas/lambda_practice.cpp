// Lambdas are anonymous functions(nameless). We can give them names and call them or we can call them 
// directly.

#include <iostream>
  int main()
  {
	// Declaring and using lambdas
	// Lambda syntax
	// [capture list] (params) -> return type{
	// function body
	// };
	// Example 1:
	auto func = [](){
		std::cout << "Hello World" << std::endl;
	};

	// function call
	func();
	// Using lambda without a name
	[](){
		std::cout << "Hello World" << std::endl;
	}();
	// Example 2:
	// Using params in lambda function
	[](int x, int y){
		return (x + y);
	}(20,30);
	// Example 3:
	// Use lambda with cout
	std::cout << "Result: " << [](int x, int y){
		return (x+y);
	// func call with args
	}(10,20) << std::endl;

	// Capture List Practice
	// Lambdas do not have access to things outside of its scope. To gain access to variables out 
	// of its scope, pass them into the capture list.
	// Example 4:
	double a{25};
	double b{45};
	auto func2 = [a,b](){
		std::cout << "a + b : " << a + b << std::endl;
	};
	func2();

	std::cout << "Capturing by value" << std::endl;
	// Capturing by value
	// Example 5:
	int c{50};
	auto func3 = [c](){
		std::cout << "Inner Val: " << c << std::endl;
	};

	for(int i{}; i < 5; ++i){
		std::cout << "Outer Val: " << c <<  std::endl;
		func3();
		++c;
	}
	std::cout << "Capturing by referrence" << std::endl;
	// Capturing by value
	// Example 6;
	auto func4 = [&c](){
		std::cout << "Inner Val: " << c << std::endl;
	};

	for(int i{}; i < 5; ++i){
		std::cout << "Outer Val: " << c <<  std::endl;
		func4();
		++c;
	}
	std::cout << "Capture all in context" << std::endl;

	std::cout << "Capturing by val" << std::endl;
	// Capture all in context
	// Example 7:
	
	auto func5 = [=](){
		std::cout << "Inner Val: " << c << std::endl;
	};

	for(int i{}; i < 5; ++i){
		std::cout << "Outer Val: " << c <<  std::endl;
		func5();
		++c;
	}
	std::cout << "Capturing by reference" << std::endl;
	// Capture everything by reference
	auto func6 = [&](){
		std::cout << "Inner Val: " << c << std::endl;
	};

	for(int i{}; i < 5; ++i){
		std::cout << "Outer Val: " << c <<  std::endl;
		func6();
		++c;
	}
	return 0;

  }
