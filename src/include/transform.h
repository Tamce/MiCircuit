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

typedef ::std::array<unsigned int, DEMENTION> _Position;
typedef _Position Size;
// To get the opposite direction of one just do the calculation: `(d ^ 0x10)`
// Rotate(Not considering up and down): up --- +1 ---> right --- ^0x11 ---> down --- +1 ----> left --- ^0x11 ---> up
// Rotate: if (d & 1) d ^= 0x11; else d += 1;
typedef enum {
    up    = 0x00, down   = 0x10,
    right = 0x01, left   = 0x11,
    top   = 0x02, bottom = 0x12,
} _Direction;

// Get the opposite direction of given direction `d`
_Direction operator!(const _Direction &d)
{
    return _Direction(d ^ 0x10);
}

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

        Transform &rotate(int times = 1)
        {
            // if d is {top, bottom}, do nothing
            if (d & 0x02)
                return *this;

            // rotate `times` times in clockwise direction
            while (times-- > 0)
            {
                if (d & 1)
                {
                    // d is one of {right, left}
                    d = Direction(d ^ 0x11);
                } else {
                    // d is one of {up, down}
                    d = Direction(d + 1);
                }
            }
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

    protected:
        Position p;
        Direction d;

};

}}
#endif
