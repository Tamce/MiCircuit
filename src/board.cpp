#include "include/board.h"

namespace tmc { namespace mcc {

    Board::Board(const Size &_size):units(nullptr)
    {
        resize(_size);
    }

    Board::~Board()
    {
        delete[] units;
    }

    // !耦合维度
    void Board::resize(const Transform::Position &_size)
    {
        delete[] units;
        unsigned int s = 1;
        for (auto &i : _size)
        {
            s *= i;
        }
        units = new Unit[s];
        
        unsigned int blockX = _size[1] * _size[2];
        unsigned int blockY = _size[2];
        for (unsigned int x = 0; x < _size[0]; ++x)
            for (unsigned int y = 0; y < _size[1]; ++y)
                for (unsigned int z = 0; z < _size[2]; ++z)
                    units[x * blockX + y * blockY + z].setTransform(Transform({x, y, z}));
        msize = _size;
    }

    Unit &Board::at(const Transform::Position &p)
    {
        // Return the value in the target position
        // As if the `units` data is orderred as `Unit[x][y][z]...`
        // unit + x * size(dy * dz) + y * size(dz) + z
        auto unit = units;
        unsigned int blockSize = 1;
        for (int i = DEMENTION - 1; i >= 0; --i)
        {
            unit += p[i] * blockSize;
            blockSize *= msize[i];
        }
        return *unit;
    }

    const Unit &Board::get(const Transform::Position &p)
    {
        return at(p);
    }

    Board &Board::put(const Transform::Position &p, const Unit &u)
    {
        auto target = at(p);
        if (target.is(UnitType::Null))
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
        return replace(p, Unit(UnitType::Null));
    }

// the close brackets of namespace tmc::mcc
}}
