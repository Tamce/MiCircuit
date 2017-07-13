/**
 * File: unit.h
 *
 * Definition of class Unit.
 *
 * Todo:
 *  - Constructor from type
 *  - Copy construtor
 *
 */

#ifndef __TMC_MCC_UNIT_H__
#define __TMC_MCC_UNIT_H__
#include "transform.h"

namespace tmc { namespace mcc {

class Unit
{
    public:
        Unit();
        typedef unsigned int Type;
        Transform transform;
        const Type type;
};

}}

#endif
