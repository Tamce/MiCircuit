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

    BoardIterator &BoardIterator::front()
    {
        position[Transform::Y] += 1;
        return *this;
    }

    BoardIterator &BoardIterator::back()
    {
        position[Transform::Y] -= 1;
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
        position[Transform::Z] += 1;
        return *this;
    }

    BoardIterator &BoardIterator::down()
    {
        position[Transform::Z] -= 1;
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

    // !耦合
    BoardIterator &move(const Direction &d, int n)
    {
        switch (d)
        {
            case Direction::up:
                return up();
            case Direction::down:
                return down();
            case Direction::left:
                return left();
            case Direction::right:
                return right();
            case Direction::front:
                return front;
            case Direction::back:
                return back();
            default:
                throw "Something bad happened(";
        }
    }

    

}}
