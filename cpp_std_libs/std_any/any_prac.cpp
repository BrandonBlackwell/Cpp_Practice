#include <any>
#include <iostream>
#include <string>
#include <typeinfo>
#include <type_traits>
#include <vector>

using namespace std;

int main()
{
  // any can be used on any copy constructible type
  // Used when you need to store an object of an arbitrary type. 
  any a1 = 5867.9697;

  cout << typeid(a1).name() << endl;

  cout << a1.type().name() << ": " << any_cast<double>(a1) << " " 
  << "is copy contructible: " << is_copy_constructible<double>::value 
  << endl;

  cout << typeid(a1).name() << endl;

  cout << endl;

  // Copy constructing 
  any a2 = a1;

  cout << a2.type().name() << ": " << any_cast<double>(a2) << " " 
  << "is copy contructible: " << is_copy_constructible<double>::value 
  << endl;

  cout << endl;

  // Any vector holding multiple copy constructible types
  vector<any> any_vector{ 321.124, 250789, "123", 'A' };
  for (auto i : any_vector)
  {
    if (i.type() == typeid(double)) {
      cout << "Type is: " << i.type().name() << endl;
    } 
    else if (i.type() == typeid(int)) {
      cout << "Type is: " << i.type().name() << endl;
    }
    else if (i.type() == typeid(string)) {
      cout << "Type is: " << i.type().name() << endl;
    }
    else if (i.type() == typeid(char)) {
      cout << "Type is: " << i.type().name() << endl;
    }
    else {
      cout << "Unknown" << endl;
    }
  }

  return 0;
}
