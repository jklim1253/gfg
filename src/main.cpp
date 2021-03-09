#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <functional>
#include <map>
#include <cstdlib>
#include <cmath>
#include <algorithm>

#include "helper/helper.hpp"
#include "test/test.hpp"
#include "alg/alg.hpp"

using namespace std;

////////////////////////////////////////////////////////////////////////////////
// run_test
////////////////////////////////////////////////////////////////////////////////
void run_test()
{
  test::out_container();
}

////////////////////////////////////////////////////////////////////////////////
// run_search
////////////////////////////////////////////////////////////////////////////////
void run_search()
{
  const int limit_value = 50;
  vector<int> v(10, 0);

  // linear search
  cout << "====================" << endl;
  for (int i = 0; i < 10; ++i)
  {
    for (int j = 0; j < 10; ++j)
    {
      v[j] = rand() % limit_value;
    }
    auto temp = alg::to_shuffle(v);

    int value = rand() % limit_value;
    cout << temp << endl;
    int pos = alg::search_linear(temp, value);
    if (pos == -1)
      cout << "  => " << value << " is not exist in array." << endl;
    else
      cout << "  => " << value << " is located at " << pos << endl;
  }

  // binary search
  cout << "====================" << endl;
  for (int i = 0; i < 10; ++i)
  {
    // prepare random value array whose size is 10.
    for (int j = 0; j < 10; ++j)
    {
      v[j] = rand() % limit_value;
    }

    // sort
    sort(v.begin(), v.end());

    int value = rand() % limit_value;
    cout << v << endl;
    int pos = alg::search_binary(v, value);
    if (pos == -1)
      cout << "  => " << value << " is not exist in array." << endl;
    else
      cout << "  => " << value << " is located at " << pos << endl;
  }
}

namespace ec
{
enum error_code : int
{
  no_error = 0,
  request_quit,
};
} // namespace ec

int main()
{
  srand((unsigned int)time(nullptr));

  // TODO: implement command hierarchy
  //
  // base commands
  //  + sub commands
  //  + sub commands
  using command_type = pair<string, function<int()>>;
  map<string, function<int()>> commands;

  // prepare default commands
  commands.insert(make_pair(
    "quit", [](){
      return ec::request_quit;
    }));
  commands.insert(make_pair(
    "exit", [](){
      return ec::request_quit;
    }));
  commands.insert(make_pair(
    "help", [&](){
      cout << "available command list :\n";
      for (auto const& command : commands)
      {
        cout << "  " << command.first << "\n";
      }
      return ec::no_error;
    }));
  commands.insert(make_pair(
    "test", [](){
      run_test();
      return ec::no_error;
    }));
  commands.insert(make_pair(
    "search", [](){
      run_search();
      return ec::no_error;
    }));

  string input;
  int ret = ec::no_error;
  do {
    cout << "> ";
    getline(cin, input);

    helper::trim(input);

    if (input.empty()) continue;

    auto command = commands.find(input);
    if (command == commands.end())
    {
      cout << "not supported command: " << input << endl;
      cout << "enter 'help' for help." << endl;
      continue;
    }

    ret = command->second();

  } while (ret == ec::no_error);

  cout << "press enter to exit...";
  cin.get();
  return 0;
}