#include "helper/helper.hpp"

#define VERSION_MAJOR 1
#define VERSION_MINOR 0
#define VERSION_PATCH 0

namespace helper
{

int version()
{
  // return BUILD_VERSION(VERSION_MAJOR,VERSION_MINOR,VERSION_PATCH);
  return libversion<VERSION_MAJOR,VERSION_MINOR,VERSION_PATCH>::value;
}

} // namespace helper