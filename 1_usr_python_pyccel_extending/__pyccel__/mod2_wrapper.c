#define PY_ARRAY_UNIQUE_SYMBOL CWRAPPER_ARRAY_API
#include "numpy_version.h"
#include "numpy/arrayobject.h"
#include "cwrapper.h"
#include <stdlib.h>
#include <stdint.h>
#include "ndarrays.h"
#include "cwrapper_ndarrays.h"


int64_t bind_c_matmul(void*, int64_t, int64_t, int64_t, int64_t, void*, int64_t, int64_t, int64_t, int64_t, void*, int64_t, int64_t, int64_t, int64_t);

/*........................................*/

/*........................................*/

/*........................................*/
PyObject* matmul_wrapper(PyObject* self, PyObject* args, PyObject* kwargs)
{
    PyObject* bound_a_obj;
    PyObject* bound_b_obj;
    PyObject* bound_c_obj;
    t_ndarray a = {.shape = NULL};
    void* bound_a;
    int64_t bound_a_shape_1;
    int64_t bound_a_shape_2;
    int64_t bound_a_stride_1;
    int64_t bound_a_stride_2;
    t_ndarray b = {.shape = NULL};
    void* bound_b;
    int64_t bound_b_shape_1;
    int64_t bound_b_shape_2;
    int64_t bound_b_stride_1;
    int64_t bound_b_stride_2;
    t_ndarray c = {.shape = NULL};
    void* bound_c;
    int64_t bound_c_shape_1;
    int64_t bound_c_shape_2;
    int64_t bound_c_stride_1;
    int64_t bound_c_stride_2;
    int64_t Out_0001;
    PyObject* Out_0001_obj;
    static char *kwlist[] = {
        "a",
        "b",
        "c",
        NULL
    };
    if (!PyArg_ParseTupleAndKeywords(args, kwargs, "OOO", kwlist, &bound_a_obj, &bound_b_obj, &bound_c_obj))
    {
        return NULL;
    }
    if (pyarray_check(bound_a_obj, NPY_DOUBLE, INT64_C(2), NPY_ARRAY_C_CONTIGUOUS))
    {
        a = pyarray_to_ndarray(bound_a_obj);
    }
    else
    {
        return NULL;
    }
    bound_a = nd_data(&a);
    bound_a_shape_1 = nd_ndim(&a, INT64_C(0));
    bound_a_shape_2 = nd_ndim(&a, INT64_C(1));
    bound_a_stride_1 = nd_nstep_C(&a, INT64_C(0));
    bound_a_stride_2 = nd_nstep_C(&a, INT64_C(1));
    if (pyarray_check(bound_b_obj, NPY_DOUBLE, INT64_C(2), NPY_ARRAY_F_CONTIGUOUS))
    {
        b = pyarray_to_ndarray(bound_b_obj);
    }
    else
    {
        return NULL;
    }
    bound_b = nd_data(&b);
    bound_b_shape_1 = nd_ndim(&b, INT64_C(0));
    bound_b_shape_2 = nd_ndim(&b, INT64_C(1));
    bound_b_stride_1 = nd_nstep_F(&b, INT64_C(0));
    bound_b_stride_2 = nd_nstep_F(&b, INT64_C(1));
    if (pyarray_check(bound_c_obj, NPY_DOUBLE, INT64_C(2), NPY_ARRAY_C_CONTIGUOUS))
    {
        c = pyarray_to_ndarray(bound_c_obj);
    }
    else
    {
        return NULL;
    }
    bound_c = nd_data(&c);
    bound_c_shape_1 = nd_ndim(&c, INT64_C(0));
    bound_c_shape_2 = nd_ndim(&c, INT64_C(1));
    bound_c_stride_1 = nd_nstep_C(&c, INT64_C(0));
    bound_c_stride_2 = nd_nstep_C(&c, INT64_C(1));
    Out_0001 = bind_c_matmul(bound_a, bound_a_shape_1, bound_a_shape_2, bound_a_stride_1, bound_a_stride_2, bound_b, bound_b_shape_1, bound_b_shape_2, bound_b_stride_1, bound_b_stride_2, bound_c, bound_c_shape_1, bound_c_shape_2, bound_c_stride_1, bound_c_stride_2);
    free_pointer(&a);
    free_pointer(&b);
    free_pointer(&c);
    Out_0001_obj = Int64_to_PyLong(&Out_0001);
    return Out_0001_obj;
}
/*........................................*/

/*........................................*/
int32_t bind_c_mod2_exec_func(PyObject* mod)
{
    return INT64_C(0);
}
/*........................................*/

/*........................................*/

static PyMethodDef mod2_methods[] = {
    {
        "matmul",
        (PyCFunction)matmul_wrapper,
        METH_VARARGS | METH_KEYWORDS,
        ""
    },
    { NULL, NULL, 0, NULL}
};

/*........................................*/

static PyModuleDef_Slot mod2_slots[] = {
    {Py_mod_exec, bind_c_mod2_exec_func},
    {0, NULL},
};

/*........................................*/

static struct PyModuleDef mod2_module = {
    PyModuleDef_HEAD_INIT,
    /* name of module */
    "mod2",
    /* module documentation, may be NULL */
    NULL,
    /* size of per-interpreter state of the module, or -1 if the module keeps state in global variables. */
    0,
    mod2_methods,
    mod2_slots
};

/*........................................*/

PyMODINIT_FUNC PyInit_mod2(void)
{
    import_array();
    return PyModuleDef_Init(&mod2_module);
}
