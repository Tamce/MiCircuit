#ifndef __TMC_MCC_BOARD_H__
#define __TMC_MCC_BOARD_H__
#include "common.h"
#include "unit.h"
#include <array>
#include <vector>

namespace tmc { namespace mcc {

class Borad
{
    public:
        void resize(const array<int, DEMENTION> &);
        Unit &get(const array<int, DEMENTION> &);
        Unit &put(const array<int, DEMENTION> &, const Unit &);
        Unit &replace(const array<int, DEMENTION> &, const Unit &);
        void remove(const array<int, DEMENTION> &);
        Unit &transform(const array<int, DEMENTION> &, const Transform &);
    protected:
        array<int, 3> size;
        vector<Unit> units;
};

}}

#endif
