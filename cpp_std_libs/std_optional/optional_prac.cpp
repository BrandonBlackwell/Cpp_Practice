#include <algorithm>
#include <iostream>
#include <optional>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>

using namespace std;

// A common use case for optional is the return value of a function that may fail.
// Can also be used to create function with optional parameters.
// Optional handles expensive-to-construct objects well and is more readable, as the intent is expressed explicitly.

optional<vector<int>> api_data( bool api_call ) 
{
  if ( !api_call ){
    return nullopt;
  }

  srand ( time(NULL) );

  vector<int> data( 10 );

  generate(data.begin(),data.end(), [&](){ return rand()%100'000; });

  return make_optional<vector<int>>( data );
  
}

int main ()
{
  vector<optional<vector<int>>> storage;
  vector<bool> api_calls = {true, true, false};

  for (auto i : api_calls)
  {
    optional<vector<int>> results = api_data(i); 
    storage.push_back( results );
  }

  // Checks if the object conatins value
  cout << "Has Value" << endl;
  for (auto obj : storage)
  {
    cout << obj.has_value() << endl;
  }

  // Accesses the contained value
  cout << "Accessing the contained value" << endl;
  int count = 1;
  for (auto obj : storage)
  {
    cout << "optional obj" << " " << count << endl;

    // Using *obj accesses the contained obj as well BUT the behavior is undefined if obj does not contain a value. 
    for (auto i : obj.value()){
      cout << i << endl;
    }
    ++count;
  }


  // Resets contained value
  cout << "Resting contained value" << endl;
  for (auto obj : storage)
  {
    obj.reset();
    // Accessing a destroyed optional
    obj.value();
  }

  // compare optional objects


  return 0;
}
