#include <functional>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
  int num1 = 10;
  int num2 = 20;
  int num3 = 30;
  int &ref1 = num1;
  int &ref2 = num2;
  int &ref3 = num3;
  // Vector cannot hold refs. Error!
  // vector<int &> vec = {ref1, ref2, ref3};
  vector<reference_wrapper<int>> vec = { ref1, ref2, ref3 };
  for (auto &i : vec) {
    cout << i << endl;
  }
  int num4 = 40;
  int num5 = 50;
  int num6 = 60;
  // using std::ref
  vector<reference_wrapper<int>> vec2 = { ref(num4), ref(num5), ref(num6) };
  for (auto &i : vec2) {
    cout << i << endl;
  }
  return 0;
}
