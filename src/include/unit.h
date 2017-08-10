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

#ifdef DEBUG
#include <cstdio>
#endif
#ifndef __TMC_MCC_UNIT_H__
#define __TMC_MCC_UNIT_H__
#include "transform.h"

namespace tmc { namespace mcc {

class UnitType
{
    UnitType(){}
    public:
        typedef unsigned int Type;
        static const Type Null;
        static const Type Error;
};

/**
 * Definition of Unit types
 */
const UnitType::Type UnitType::Null = 0;
const UnitType::Type UnitType::Error = -1;


class Unit
{
    public:
        typedef UnitType::Type Type;

        Unit(const Type &t, const Transform &tr):mtype(t),mtransform(tr){}
        Unit(const Type &t):Unit(t, Transform()){}
        Unit():Unit(UnitType::Null, Transform()){}
        const Type &type()
        {
            return mtype;
        }
        bool is(const Type &t)
        {
            return mtype == t;
        }
        Unit &setTransform(const Transform &);
#ifdef DEBUG
        virtual void print()
        {
            std::printf("Unit(%d;%d,%d,%d)", mtype, mtransform.position()[0], mtransform.position()[1], mtransform.position()[2]);
        }
#endif
    protected:
        Transform mtransform;
        Type mtype;
};

}}

#endif
