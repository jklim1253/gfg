#ifndef __OUT_CONTAINER_HPP__
#define __OUT_CONTAINER_HPP__

#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <utility>

template<class T, class Alloc>
std::ostream& operator << (std::ostream& os, std::vector<T,Alloc> const& o)
{
  os << '[';
  for (auto it = o.begin(); it != o.end(); ++it)
  {
    os << *it;
    if (1 != std::distance(it, o.end()))
      os << ' ';
  }
  os << ']';
  return os;
}

template<class T, class Alloc>
std::ostream& operator << (std::ostream& os, std::list<T,Alloc> const& o)
{
  os << '(';
  for (auto it = o.begin(); it != o.end(); ++it)
  {
    os << *it;
    if (1 != std::distance(it, o.end()))
      os << ' ';
  }
  os << ')';
  return os;
}

#endif // __OUT_CONTAINER_HPP__