#include "include/board.h"

namespace tmc { namespace mcc {

    /**
     * Todo: Contructor
     */
    Board::Board(const Size &_size)
    {
        resize(_size);
    }

    ~Board::Board()
    {
        delete[] units;
    }

    void Board::resize(const Transform::Position &_size)
    {
        delete[] units;
        unsigned int s = 1;
        for (auto &i : _size)
        {
            s *= i;
        }
        units = new Unit[s];
    }

    Unit &Board::at(const Transform::Position &_position)
    {
        // Return the value in the target position
        // As if the `units` data is orderred as `Unit[x][y][z]...`
        auto unit = units;
        for (int i = 0; i < DEMENTION; ++i)
        {
            unit += p[i] * size[i];
        }
        return *unit;
    }

    const Unit &Board::get(const Transform::Position &p) const
    {
        return at(p);
    }

    Board &Board::put(const Transform::Position &p, const Unit &u)
    {
        auto target = at(p);
        if (target == Unit(Null))
            target = u;
        return *this;
    }

    Board &Board::replace(const Transform::Position &p, const Unit &u)
    {
        at(p) = u;
        return *this;
    }

    Board &Board::remove(const Transform::Position &p)
    {
        return replace(p, Unit(Unit::Null));
    }

// the close brackets of namespace tmc::mcc
}}
