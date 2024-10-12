#ifndef MY_FILE_H
#define MY_FILE_H

#include <stdio.h>
#include <stdlib.h>
#ifndef _VEC_INT_64_T
#define _VEC_INT_64_T

#define i_key int64_t
#define i_keyraw int64_t
#define i_use_cmp // enable sorting/searhing using default <, == operators
#include "STC/include/stc/vec.h"
#endif

#endif // MY_FILE_H
