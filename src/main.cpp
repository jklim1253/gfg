#include <iostream>
#include "helper/helper.hpp"
#include "test/test.hpp"

#include <string>
#include <vector>
#include <list>
#include <functional>
#include <map>

using namespace std;

void run_test()
{
  test::out_container();
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

  string input;
  int ret = ec::no_error;
  do {
    cout << "> ";
    getline(cin, input);

    trim(input);

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