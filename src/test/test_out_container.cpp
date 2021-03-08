#include "test/test.hpp"
#include "helper/helper.hpp"

#include <iostream>
#include <vector>
#include <list>
using namespace std;

namespace test
{

void out_container()
{
  cout << FUNC_BEGIN << endl;

  vector<int> v = {1,2,5,3,2};
  list<int> l = {2,0,12,7,999};
  vector<vector<int>> dv = {
    {1,2,3},
    {4,12,38},
    {0,999,13},
  };

  cout << v << endl;
  cout << l << endl;
  cout << dv << endl;

  cout << FUNC_FINISH << endl;
}

} // namespace test