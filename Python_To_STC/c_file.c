# include "c_header_file.h"

bool initialised;
vec_int a;
vec_float b;
/*........................................*/

void declare_init(void) 
{
    if (!initialised)
    {
        a = vec_int_init();
        b = vec_float_init();
        // vec_int a = {0};  // Using vec_int defined in c_header_file.h
        // vec_float b = {0};  // Using vec_float defined in c_header_file.h

        vec_int_push(&a, 1);
        vec_float_push(&b, 2);

        initialised = 1;
    }
}

/*........................................*/

// void declare__free(vec_int *a, vec_int *b)
// void declare_free()
// {
//     if (initialised)
//     {
//         vec_int_drop(a);
//         vec_float_drop(b);
//         initialised = 0;
//     }
// }
