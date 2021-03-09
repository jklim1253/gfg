#include "alg/search/search.hpp"

namespace alg
{

////////////////////////////////////////////////////////////////////////////////
// search
// linear search
//
// v : randomized array
// value : target to search 
//
// return : if found, index of target value is located, or -1
////////////////////////////////////////////////////////////////////////////////
int search_linear(std::vector<int> const& v, int value)
{
  int pos = -1;
  int left = 0;
  int right = static_cast<int>(v.size()) - 1;
  while (left < right)
  {
    if (v[left] == value)
    {
      pos = left;
      break;
    }
    if (v[right] == value)
    {
      pos = right;
      break;
    }
    ++left;
    --right;
  }

  return pos;
}

} // namespace alg
