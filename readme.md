# Pyccel debunking
## background
* Pyccel is a static compiler for Python3, using Fortran or C as a backend language.
* Python Object vs Python Variable
* Python garbage cololector
* reference count:
https://towardsdatascience.com/understanding-reference-counting-in-python-3894b71b5611

## how pyccel works:
* type inference
* Assumptions and Restrictions(cannot decide on type based on conditions and it cannot be changed)
* type annotations in functions
* Fortran/C/Open-MPI(for distributed-memory parallel programming)

## code generation:
* in case of a python program => generate equivalent c file and a compiled executable.
* 

