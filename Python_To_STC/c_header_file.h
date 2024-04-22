#ifndef MY_FILE_H
#define MY_FILE_H


#ifndef _VEC_INT
#define _VEC_INT

#define i_key int
#define i_use_cmp // enable sorting/searhing using default <, == operators
#include "stc/vec.h"

#endif // _VEC_INT

#ifndef _VEC_FLOAT
#define _VEC_FLOAT

#define i_key float
#define i_use_cmp // enable sorting/searhing using default <, == operators
#include "stc/vec.h"

#endif // _VEC_FLOAT

#endif // MY_FILE_H
