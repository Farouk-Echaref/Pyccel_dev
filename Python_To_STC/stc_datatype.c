#include <stdio.h>
#include <stdlib.h>
#define i_key int64_t
// #define i_keyraw int64_t
#define i_use_cmp // enable sorting/searhing using default <, == operators
#include "STC/include/stc/vec.h"

int main()
{
    vec_int64_t a;
    
    a = vec_int64_t_with_capacity(3);
    // vec_int64_t_push_back(&a, 1);
  
    int64_t raw[] = {INT64_C(1), INT64_C(2), INT64_C(3)};
    vec_int64_t_emplace_n(&a, 0, raw, 3);
    c_foreach (k, vec_int64_t, a) {
        printf(" %d", *k.ref);
    }
    // i_keyraw elements_to_insert[] = {INT64_C(1), INT64_C(2), INT64_C(3)};
    // vec_int64_t_emplace_n(&a, 0, elements_to_insert, 3);
}