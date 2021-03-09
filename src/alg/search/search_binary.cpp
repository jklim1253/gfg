#include "alg/search/search.hpp"

namespace alg
{

////////////////////////////////////////////////////////////////////////////////
// search
// binary search
//
// v : sorted array
// value : target to search 
//
// return : if found, index of target value is located, or -1
////////////////////////////////////////////////////////////////////////////////
int search_binary(std::vector<int> const& v, int value)
{
  int start = 0;
  int end = static_cast<int>(v.size()) - 1;

  while (start <= end)
  {
    int pos = (start + end) / 2;

    if (v[pos] == value)
      return pos;

    if (v[pos] < value)
      start = pos + 1;
    else
      end = pos - 1;
  }

  return -1;
}

} // namespace alg
