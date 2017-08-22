#include "../include/boardIterator.h"
#include "../include/transform.h"

namespace tmc { namespace mcc {
    
    Unit &BoardIterator::operator*()
    {
        return get();
    }

    Unit &BoardIterator::get()
    {
        return board.at(position);
    }

    const Transform::Position &BoardIterator::pos() const
    {
        return position;
    }

    BoardIterator &BoardIterator::top()
    {
        position[Transform::Z] += 1;
        return *this;
    }

    BoardIterator &BoardIterator::bottom()
    {
        position[Transform::Z] -= 1;
        return *this;
    }

    BoardIterator &BoardIterator::left()
    {
        position[Transform::X] -= 1;
        return *this;
    }

    BoardIterator &BoardIterator::right()
    {
        position[Transform::X] += 1;
        return *this;
    }

    BoardIterator &BoardIterator::up()
    {
        position[Transform::Y] += 1;
        return *this;
    }

    BoardIterator &BoardIterator::down()
    {
        position[Transform::Y] -= 1;
        return *this;
    }

    BoardIterator &BoardIterator::move(const Transform::Position &p)
    {
        for (int i = 0; i < DEMENTION; ++i)
        {
            position[i] += p[i];
        }
        return *this;
    }

    BoardIterator &BoardIterator::move(const Transform::Direction &d, int n)
    {
        // Make a pointer point to the function to call.
        BoardIterator &(BoardIterator::*foo)();
        switch (d)
        {
            case Transform::Direction::up:
                foo = &BoardIterator::up;
                break;
            case Transform::Direction::down:
                foo = &BoardIterator::down;
                break;
            case Transform::Direction::left:
                foo = &BoardIterator::left;
                break;
            case Transform::Direction::right:
                foo = &BoardIterator::right;
                break;
            case Transform::Direction::top:
                foo = &BoardIterator::top;
                break;
            case Transform::Direction::bottom:
                foo = &BoardIterator::bottom;
                break;
            default:
                throw "Unexpected Direction enum value!";
        }
        while (n-- > 0)
        {
            // Call that member function on `this`
            (this->*foo)();
        }
        return *this;
    }

    

}}
