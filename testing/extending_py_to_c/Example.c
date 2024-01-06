#include <Python.h>

int CaddNums(int num1, int num2){
    int res = 0;

    res = num1 + num2;

    return (res);
}

// boilerplate code for addNums function
static PyObject* addNums(PyObject* self, PyObject *args){

    // args that are passed to the c function and the return result
    int num1, num2, res;

    //args are passed as a python tuple
    // check if args are passed to the c function
    if (!PyArg_ParseTuple(args, "ii", &num1, &num2))
        return (NULL);
    res = CaddNums(num1, num2);

    //int in python are long
    return (PyLong_FromLong(res));
}

// another function, for the version of the module, doesn't take arguments
static PyObject* version(PyObject* self){
    return (Py_BuildValue("s", "Version 6.9"));
}
exit
//methods
static PyMethodDef Examples[] = {
    {"addNums", addNums, METH_VARARGS, "add two nums"},
    {"version", (PyCFunction)version, METH_NOARGS, "return version of module"},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef Example = {
    PyModuleDef_HEAD_INIT, 
    "Example",
    "addNums Module",
    -1, //global stat
    Examples
};

//INITIALIZER FUNCTION
PyMODINIT_FUNC PyInit_Example(void){
    return (PyModule_Create(&Example));
}