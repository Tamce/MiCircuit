#include "include/boardIterator.h"
#include "include/transform.h"

namespace tmc { namespace mcc {
    
    Unit &BoardIterator::operator*()
    {
        return get();
    }

    Unit &BoardIterator::get()
    {
        return board.at(position);
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

    BoardIterator &BoardItertor::up()
    {
        position[Transform::Y] += 1;
        return *this;
    }

    BoardIterator &BoardIterator::down()
    {
        position[Transform::Y] -= 1;
        return *this;
    }

    BoardIterator &BoardIterator::move(const Position &p)
    {
        for (int i = 0; i < DEMENTION; ++i)
        {
            position[i] += p[i];
        }
        return *this;
    }

    BoardIterator &move(const Direction &d, int n)
    {
        auto foo = &top;
        switch (d)
        {
            case Direction::up:
                foo = up;
            case Direction::down:
                foo = down;
            case Direction::left:
                foo = left;
            case Direction::right:
                foo = right;
            case Direction::top:
                foo = top;
            case Direction::bottom:
                foo = bottom;
            default:
                throw "Unexpected Direction enum value!";
        }
        while (n-- > 0)
        {
            foo();
        }
        return *this;
    }

    

}}
