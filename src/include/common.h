#ifndef __TMC_MCC_COMMON_H__
#define __TMC_MCC_COMMON_H__
#include <array>

#define MCC_NAMESPACE_START 1
#define MCC_NAMESPACE_END 1
#define DEMENTION 3

namespace tmc { namespace mcc {

typedef ::std::array<int, DEMENTION> _Position;
typedef enum {up, left, down, right} _Direction;

}}

#endif
