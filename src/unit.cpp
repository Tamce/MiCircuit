#include "include/unit.h"
namespace tmc { namespace mcc {
    Unit &Unit::setTransform(const Transform &tr)
    {
        mtransform = tr;
        return *this;
    }
}}