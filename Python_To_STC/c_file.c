# include "c_header_file.h"

void declare_list(void) 
{
    vec_int a = {0};  // Using vec_int defined in c_header_file.h
    vec_float b = {0};  // Using vec_float defined in c_header_file.h

    vec_int_push(&a, 1);
    vec_float_push(&b, 2);

    c_foreach (k, vec_int, a) {
        printf(" %d\n", *k.ref);
    }

    // free function, could be inside pyccel free functions
    vec_int_drop(&a);
    vec_float_drop(&b);

    return 0;
}
