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

* syntactic stage also handles parsing header comments. This is managed using textx.

### Navigation and AST Creation:
* Python visit ast nodes:
https://www.youtube.com/watch?v=OjPT15y2EpE&t=380s
In summary, when you uncomment the generic visit() method, it becomes the default method called for nodes that don't have a more specific visit_x() method. If you have both a generic visit() and a specific visit_x() method, both methods may get called for nodes of type "x." This is why you observe that it prints all nodes when you call visitor.visit_Assign(node) - it's using both methods.


## Order:
* How an array is laid out in memory; Row-Major(C-style) or COlumn-Major(F-style).
- For both C and F orders, the arrays are stored contiguously in memory, but they differ in how their entries are aranged.
- Pyccel Doc: 
https://github.com/pyccel/pyccel/blob/devel/developer_docs/order_docs.md
- Wikipedia:
https://en.wikipedia.org/wiki/Row-_and_column-major_order 

