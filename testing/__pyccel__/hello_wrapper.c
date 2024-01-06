#define PY_ARRAY_UNIQUE_SYMBOL CWRAPPER_ARRAY_API
#include "numpy_version.h"
#include "numpy/arrayobject.h"
#include "cwrapper.h"
#include <stdlib.h>
#include <stdint.h>
#include "hello.h"



/*........................................*/

/*........................................*/


/*........................................*/
int32_t hello_exec_func(PyObject* mod)
{
    return INT64_C(0);
}
/*........................................*/

/*........................................*/

static PyMethodDef hello_methods[] = {
    { NULL, NULL, 0, NULL}
};

/*........................................*/

static PyModuleDef_Slot hello_slots[] = {
    {Py_mod_exec, hello_exec_func},
    {0, NULL},
};

/*........................................*/

static struct PyModuleDef hello_module = {
    PyModuleDef_HEAD_INIT,
    /* name of module */
    "hello",
    /* module documentation, may be NULL */
    NULL,
    /* size of per-interpreter state of the module, or -1 if the module keeps state in global variables. */
    0,
    hello_methods,
    hello_slots
};

/*........................................*/

PyMODINIT_FUNC PyInit_hello(void)
{
    import_array();
    return PyModuleDef_Init(&hello_module);
}
