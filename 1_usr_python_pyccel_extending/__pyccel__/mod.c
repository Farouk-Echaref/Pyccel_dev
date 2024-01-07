#include "mod.h"
#include <stdlib.h>
#include <stdint.h>
#include <math.h>


/*........................................*/
int64_t factorial(int64_t n)
{
    int64_t Out_0001;
    if (n <= INT64_C(0))
    {
        return INT64_C(1);
    }
    else
    {
        return n * factorial(n - INT64_C(1));
    }
}
/*........................................*/
/*........................................*/
int64_t binomial_coefficient(int64_t n, int64_t k)
{
    int64_t num;
    int64_t den;
    num = factorial(n);
    den = factorial(k) * factorial(n - k);
    return (int64_t)floor((double)(num) / (double)(den));
}
/*........................................*/

