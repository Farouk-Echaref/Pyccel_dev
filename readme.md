# Pyccel debunking
## background
* Pyccel is a static compiler for Python3, using Fortran or C as a backend language.
* Python Object vs Python Variable
* Python garbage cololector
* reference count:
https://towardsdatascience.com/understanding-reference-counting-in-python-3894b71b5611

## how pyccel works:
* type inference (type inference: chose largest type)
* Assumptions and Restrictions(cannot decide on type based on conditions and it cannot be changed)
* type annotations in functions
* Fortran/C/Open-MPI(for distributed-memory parallel programming)

## code generation:
* in case of a python program => generate equivalent c file and a compiled executable.
* in case of a python without main (python functions and classes) => pyccel treats them as a **python module** => won't generate a program, but will generate **Python C extension module** which can be imported from Python(mod.<\TAG>.so), and in addition it also generates equivalent c files. 
    * Extending Python with C:
        * converting C to Python to increase performance.
        * https://www.youtube.com/watch?v=l8dRF_AnFE0
        * steps:
            - CFunction
            - Pyobject Function to parse the C into Python
            - Method Definition
            - Module definition
* complicated calculations using Open_MP


# Dev Docs:
* Syntatic Stage.
* Semantic Stage.
* Code Generation Stage.
* Wrapping Stage.
* Compilation Stage.

## Syntatic Stage:
* Read input in Python AST and convert to Pyccel AST.
### AST (AST Python):
* https://www.youtube.com/watch?v=OjPT15y2EpE
* https://www.youtube.com/watch?v=Yq3wTWkoaYY
* https://medium.com/@wshanshan/intro-to-python-ast-module-bbd22cd505f7


