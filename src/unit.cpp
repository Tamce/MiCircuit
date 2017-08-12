#include "include/unit.h"
namespace tmc { namespace mcc {
    const Transform &Unit::transform()
    {
        return mtransform;
    }

    Unit &Unit::setTransform(const Transform &tr)
    {
        mtransform = tr;
        return *this;
    }

    const Unit::Status &Unit::status()
    {
        return mstatus;
    }

    Unit &Unit::setStatus(const Transform::Direction &d, ElectricPotential ep)
    {
        mstatus[d] = ep;
        return *this;
    }

    bool Unit::is(const Type &t)
    {
        return mtype == t;
    }

    const Unit::Type &Unit::type()
    {
        return mtype;
    }

    Unit &Unit::update(const Transform::Direction &srcDir)
    {
        return *this;
    }

    Unit &Unit::toggle()
    {
        return *this;
    }
}}