#include "helper/helper.hpp"
#include <utility>
#include <algorithm>

void trim(std::string& s, std::string const& delimit)
{
  if (s.empty()) return;

  // left trim
  s.erase(0, s.find_first_not_of(delimit, 0));

  // right trim
  auto it = std::find_if(s.rbegin(), s.rend(),
      [=](char c){ return std::string::npos == delimit.find(c); });
  s.erase(it.base(), s.end());
}