#include "helper/helper.hpp"

int version()
{
  return (
    VERSION_MAJOR * 1000000 +
    VERSION_MINOR * 1000 +
    VERSION_PATCH
  );
}