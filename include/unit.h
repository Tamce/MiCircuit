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
#include <unordered_map>

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
        typedef int ElectricPotential;
        typedef ::std::unordered_map<
            Transform::Direction, ElectricPotential,
            ::std::hash<int>, ::std::equal_to<int>, ::std::allocator<std::pair<const int, ElectricPotential>>> Status;

        Unit(const Type &t, const Transform &tr):mtype(t),mtransform(tr), mstatus({{Transform::Direction::up, 0},{Transform::Direction::down, 0},{Transform::Direction::left, 0},{Transform::Direction::right, 0},{Transform::Direction::top, 0},{Transform::Direction::bottom, 0}}) {}
        Unit(const Type &t):Unit(t, Transform()){}
        Unit():Unit(UnitType::Null, Transform()){}
        /**
         * Determine whether a Unit is a instance of Type t.
         */
        bool is(const Type &t) const;
        const Type &type() const;
        const Transform &transform() const;
        Unit &setTransform(const Transform &t);
        const Status &status() const;
        Unit &setStatus(const Transform::Direction &d, const ElectricPotential &ep);

        /**
         * Update the Status information of this Unit.
         */
        virtual Unit &update(const Transform::Direction &srcDir, const ElectricPotential &ep);
        /**
         * Toggle the State (if possible) of this Unit.
         */
        virtual Unit &toggle();
#ifdef DEBUG
        virtual void print() const
        {
            std::printf("Unit(%d;%d,%d,%d):Status(%d,%d,%d,%d,%d,%d)\n",
                mtype,
                mtransform.position()[0], mtransform.position()[1], mtransform.position()[2],
                mstatus.at(Transform::Direction::up), mstatus.at(Transform::Direction::down),
                mstatus.at(Transform::Direction::left), mstatus.at(Transform::Direction::right),
                mstatus.at(Transform::Direction::top), mstatus.at(Transform::Direction::bottom));
        }
#endif
    protected:
        Transform mtransform;
        Type mtype;
        Status mstatus;
};

}}

#endif
