#ifndef __HELPER_HPP__
#define __HELPER_HPP__

#include "helper/out_container.hpp"

#include <string>

#define FUNC_BEGIN ("=========" __FUNCTION__ " begin=======")
#define FUNC_FINISH ("=========" __FUNCTION__ " finish======")
#define BUILD_VERSION(major,minor,patch) ((major)*1000000+(minor)*1000+(patch))

template<int major, int minor, int patch>
struct libversion
{
  static const int value = (major*1000000+minor*1000+patch);
};

namespace helper
{

int version();

void trim(std::string& s, std::string const& delimit = " ");

} // namespace helper

#endif // __HELPER_HPP__