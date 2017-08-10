#ifndef __TMC_MCC_BOARDITERATOR_H__
#define __TMC_MCC_BOARDITERATOR_H__
#include "board.h"

namespace tmc { namespace mcc {

class BoradIterator
{
    public:
        /* Create a iterator of a board */
        BoardIterator(Board &_board):board(_board);
        /* Get the element that the iterator is pointing to */
        Unit &operator*();
        Unit &get();
        /* Move the iterator by 1 unit */
        BoardIterator &front();
        BoardIterator &back();
        BoardIterator &left();
        BoardIterator &right();
        BoardIterator &up();
        BoardIterator &down();
        /* Move the iterator by a vector*/
        BoardIterator &move(const Position &);
        /* Move the iterator by n unit */
        BoardIterator &move(const Direction &, int n);
    protected:
        Board &board;
        Transform::Position position;
};

}}

#endif
