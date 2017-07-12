#ifndef __TMC_MCC_UNIT_H__
#define __TMC_MCC_UNIT_H__
#include "transform.h"

namespace tmc { namespace mcc {

class Unit
{
    public:
        typedef unsigned int Type;
        Transform transform;
        const Type type;
};

}}

#endif
