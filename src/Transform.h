/**
 * File: Transform.h
 * 
 * The definition of the class `Transform`.
 * In order to describe a position and a direction of a `Unit` or `Component`
 */

#ifndef __TMC_CISIM_TRANSFORM_H__
#define __TMC_CISIM_TRANSFORM_H__
#include <array>

class Transform
{
    private:
        enum Direction;
        array<int, 3> p;
        Direction d;
    public:
        enum Direction {up, left, down, right};
        Transform(const Array<int, 3> &_p, Direction _d):position(_p),direction(_d) {}
        Transform():Transform({0, 0, 0}, Direction::up);
        /**
         * Returns the position of this transform object 
         */
        const array<int, 3> &position()
        {
            return p;
        }
        
        /**
         * Set the position
         * 
         * Returns the reference of the object itself to implement method chaining
         */
        Transform &position(const array<int, 3> &_p)
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
}
#endif