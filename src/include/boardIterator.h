#ifndef __TMC_MCC_BOARDITERATOR_H__
#define __TMC_MCC_BOARDITERATOR_H__
#include "board.h"

namespace tmc { namespace mcc {

class BoradIterator
{
    public:
        BoardIterator(Board &_board):board(_board);
        Unit &operator*();
        Unit &get();
        BoardIterator &up();
        BoardIterator &down();
        BoardIterator &left();
        BoardIterator &right();
        BoardIterator &move(const array<int, DEMENTION> &);
        BoardIterator &move(Direction, int);
    protected:
        Board &board;
        Transform::Position position;
};

}}

#endif
