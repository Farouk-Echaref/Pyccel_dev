#define PY_ARRAY_UNIQUE_SYMBOL CWRAPPER_ARRAY_API
#include "numpy_version.h"
#include "numpy/arrayobject.h"
#include "cwrapper.h"
#include <stdlib.h>
#include <stdint.h>
#include "mod.h"



/*........................................*/

/*........................................*/

/*........................................*/
PyObject* factorial_wrapper(PyObject* self, PyObject* args, PyObject* kwargs)
{
    PyObject* n_obj;
    int64_t n;
    int64_t Out_0001;
    PyObject* Out_0001_obj;
    static char *kwlist[] = {
        "n",
        NULL
    };
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, "O", kwlist, &n_obj))
    {
        return NULL;
    }
    if (PyIs_NativeInt(n_obj))
    {
        n = PyInt64_to_Int64(n_obj);
    }
    else
    {
        PyErr_SetString(PyExc_TypeError, "Expected an argument of type int for argument n");
        return NULL;
    }
    Out_0001 = factorial(n);
    Out_0001_obj = Int64_to_PyLong(&Out_0001);
    return Out_0001_obj;
}
/*........................................*/

/*........................................*/
PyObject* binomial_coefficient_wrapper(PyObject* self, PyObject* args, PyObject* kwargs)
{
    PyObject* n_obj;
    PyObject* k_obj;
    int64_t n;
    int64_t k;
    int64_t Out_0001;
    PyObject* Out_0001_obj;
    static char *kwlist[] = {
        "n",
        "k",
        NULL
    };
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, "OO", kwlist, &n_obj, &k_obj))
    {
        return NULL;
    }
    if (PyIs_NativeInt(n_obj))
    {
        n = PyInt64_to_Int64(n_obj);
    }
    else
    {
        PyErr_SetString(PyExc_TypeError, "Expected an argument of type int for argument n");
        return NULL;
    }
    if (PyIs_NativeInt(k_obj))
    {
        k = PyInt64_to_Int64(k_obj);
    }
    else
    {
        PyErr_SetString(PyExc_TypeError, "Expected an argument of type int for argument k");
        return NULL;
    }
    Out_0001 = binomial_coefficient(n, k);
    Out_0001_obj = Int64_to_PyLong(&Out_0001);
    return Out_0001_obj;
}
/*........................................*/

/*........................................*/
int32_t mod_exec_func(PyObject* mod_0001)
{
    return INT64_C(0);
}
/*........................................*/

/*........................................*/

static PyMethodDef mod_methods[] = {
    {
        "factorial",
        (PyCFunction)factorial_wrapper,
        METH_VARARGS | METH_KEYWORDS,
        ""
    },
    {
        "binomial_coefficient",
        (PyCFunction)binomial_coefficient_wrapper,
        METH_VARARGS | METH_KEYWORDS,
        ""
    },
    { NULL, NULL, 0, NULL}
};

/*........................................*/

static PyModuleDef_Slot mod_slots[] = {
    {Py_mod_exec, mod_exec_func},
    {0, NULL},
};

/*........................................*/

static struct PyModuleDef mod_module = {
    PyModuleDef_HEAD_INIT,
    /* name of module */
    "mod",
    /* module documentation, may be NULL */
    NULL,
    /* size of per-interpreter state of the module, or -1 if the module keeps state in global variables. */
    0,
    mod_methods,
    mod_slots
};

/*........................................*/

PyMODINIT_FUNC PyInit_mod(void)
{
    import_array();
    return PyModuleDef_Init(&mod_module);
}
