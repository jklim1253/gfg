#include "alg/shuffle/shuffle.hpp"

#include <algorithm>

namespace alg
{

////////////////////////////////////////////////////////////////////////////////
// shuffle
////////////////////////////////////////////////////////////////////////////////
void shuffle(std::vector<int>& v)
{
  int size = static_cast<int>(v.size());
  for (int i = 0; i < size - 1; ++i)
  {
    int lhs = i; // lhs index
    int rhs = i + 1 + (rand() % (size - (i + 1))); // rhs index
    std::swap(v[lhs], v[rhs]);
  }
}

std::vector<int> to_shuffle(std::vector<int> const& v)
{
  std::vector<int> buffer(v.begin(), v.end());
  shuffle(buffer);
  return buffer;
}

} // namespace alg
