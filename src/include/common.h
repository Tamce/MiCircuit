#ifndef __TMC_MCC_COMMON_H__
#define __TMC_MCC_COMMON_H__
#include <array>

#define MCC_NAMESPACE_START 1
#define MCC_NAMESPACE_END 1
#define DEMENTION 3
#define _X_AXIS 0
#define _Y_AXIS 1
#define _Z_AXIS 2

namespace tmc { namespace mcc {

typedef ::std::array<unsigned int, DEMENTION> _Position;
typedef _Position Size;
typedef enum {up, left, down, right, front, back} _Direction;

}}

#endif
