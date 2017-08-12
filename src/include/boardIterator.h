#ifndef __TMC_MCC_BOARDITERATOR_H__
#define __TMC_MCC_BOARDITERATOR_H__
#include "board.h"

namespace tmc { namespace mcc {

class BoradIterator
{
    public:
        /* Create a iterator of a board */
        BoardIterator(Board &_board):board(_board) {}
        BoardIterator(Board &_board, Transform::Position p):board(_board), position(p) {}
        BoardIterator(Board &_board, const Unit &unit):board(_board), position(unit.transform().position()) {}
        /* Get the element that the iterator is pointing to */
        Unit &operator*();
        Unit &get();
        /* Move the iterator by 1 unit */
        BoardIterator &top();
        BoardIterator &bottom();
        BoardIterator &left();
        BoardIterator &right();
        BoardIterator &up();
        BoardIterator &down();
        /* Move the iterator by a vector*/
        BoardIterator &move(const Position &);
        /* Move the iterator by n unit */
        BoardIterator &move(const Direction &, int n = 1);
    protected:
        Board &board;
        Transform::Position position;
};

}}

#endif
