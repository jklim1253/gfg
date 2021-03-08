#ifndef __HELPER_HPP__
#define __HELPER_HPP__

#include "helper/out_container.hpp"

#define FUNC_BEGIN ("=========" __FUNCTION__ " begin=======")
#define FUNC_FINISH ("=========" __FUNCTION__ " finish======")

#define VERSION_MAJOR 1
#define VERSION_MINOR 0
#define VERSION_PATCH 0

int version();

#include <string>

void trim(std::string& s, std::string const& delimit = " ");

#endif // __HELPER_HPP__