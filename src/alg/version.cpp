#include "helper/helper.hpp"

#define ALG_VERSION_MAJOR 1
#define ALG_VERSION_MINOR 0
#define ALG_VERSION_PATCH 0

namespace alg
{

int version()
{
  return libversion<ALG_VERSION_MAJOR,
                    ALG_VERSION_MINOR,
                    ALG_VERSION_PATCH>::value;
}

} // namespace alg