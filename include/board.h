#ifndef __TMC_MCC_BOARD_H__
#define __TMC_MCC_BOARD_H__
#include "common.h"
#include "unit.h"
#include <array>
#include <vector>
#include <functional>

namespace tmc { namespace mcc {

class BoardIterator;
class Board
{
    public:
        Board(): Board(Size({0, 0, 0})) {}
        Board(const Size &_size);
        Board(const Board &&) = delete;
        Board(const Board &) = delete;
        ~Board();

        BoardIterator iterator();
        BoardIterator iterator(const Transform::Position &position);

        /**
         * Set the board size to _size.
         *
         * All data will lost after resize.
         * Ignore the case that the memory allocation is failed.
         */
        void resize(const Size &_size);

        /**
         * Returns the size of the board
         */
        const Size &size()
        {
            return msize;
        }
        
        /**
        * Get the Unit object at specific Position
        */
        const Unit &get(const Transform::Position &_position);
        
        /**
        * Set the target position unit to `_unit` if target is `Null`
        *
        * If the target unit is not `Null`, the function does nothing.
        * Returns the reference of `*this` object.
        */
        Board &put(const Transform::Position &_position, const Unit &_unit);
        
        /**
        * Replace the target unit to `_unit` whatever what it is there
        *
        * Returns the reference of `*this` object
        */
        Board &replace(const Transform::Position &_position, const Unit &_unit);
        
        /**
        * Remove the target unit
        *
        * That is to replace that unit with `Null`.
        * Equivalent to `replace(_position, Unit(Unit::Null))`.
        * Returns the reference of `*this` object
        */
        Board &remove(const Transform::Position &_position);
        
        /**
        * -? Experimental
        * Apply Transform to target unit
        */
        // Unit &transform(const Transform::Position &, const Transform &);
    protected:
        friend class MiCircuit;
        /**
         * Returns the reference of the target unit object.
         */
        Unit &at(const Transform::Position &_position);
        Size msize;
        Unit *units;
        std::function<void(Unit, Unit)> updateCallback;
    };
    
}}

#endif
