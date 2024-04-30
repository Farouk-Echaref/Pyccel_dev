# include "c_header_file.h"

bool initialised;

/*........................................*/

void declare_init(void) 
{
    if (!initialised)
    {
        vec_int a = {0};  // Using vec_int defined in c_header_file.h
        vec_float b = {0};  // Using vec_float defined in c_header_file.h

        vec_int_push(&a, 1);
        vec_float_push(&b, 2);

        initialised = 1;
    }
}

/*........................................*/

void declare__free(vec_int *a, vec_int *b)
{
    if (initialised)
    {
        vec_int_drop(a);
        vec_float_drop(b);
        initialised = 0;
    }
}
