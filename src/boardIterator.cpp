#include "include/boardIterator.h"

namespace tmc { namespace mcc {
    
    Unit &BoardIterator::operator*()
    {
        return get();
    }

    Unit &BoardIterator::get()
    {
        return board.at(position);
    }

    

}}
