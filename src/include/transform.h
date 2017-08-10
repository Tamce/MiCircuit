/**
 * File: Transform.h
 * 
 * The definition of the class `Transform`.
 * In order to describe a position and a direction of a `Unit` or `Component`
 */

#ifndef __TMC_MCC_TRANSFORM_H__
#define __TMC_MCC_TRANSFORM_H__
#include "common.h"
#include <array>
namespace tmc { namespace mcc {

class Transform
{
    public:
        typedef _Position Position;
        typedef _Direction Direction;
        static const unsigned int X = _X_AXIS;
        static const unsigned int Y = _Y_AXIS;
        static const unsigned int Z = _Z_AXIS;
        /* Constructors */
        Transform(const Position &_p, Direction _d):p(_p),d(_d) {}
        Transform():Transform(Position(), Direction::up) {};
        Transform(const Position &_p):Transform(Position(_p), Direction::up) {};
        /**
         * Returns the position of this transform object 
         */
        const Position &position()
        {
            return p;
        }
        
        /**
         * Set the position
         * 
         * Returns the reference of the object itself to implement method chaining
         */
        Transform &position(const Position &_p)
        {
            p = _p;
            return *this;
        }
        
        /**
         * Returns the direction of this transform object
         */
        const Direction &direction()
        {
            return d;
        }
        
        /**
         * Set the direction
         */
        Transform &direction(const Direction &_d)
        {
            d = _d;
            return *this;
        }

        Transform operator+(const Transform &o)
        {
            Transform result(*this);
            for (int i = 0; i < DEMENTION; ++i)
            {
                result.p[i] += o.p[i];
            }
            return result;
        }

        Transform operator-(const Transform &o)
        {
            Transform result(*this);
            for (int i = 0; i < DEMENTION; ++i)
            {
                result.p[i] -= o.p[i];
            }
            return result;
        }
#ifndef DEBUG
    protected:
#endif
        Position p;
        Direction d;

};

}}
#endif
