#include <Python.h>

#include "dinero.h"

static PyObject *dinero_getpowhash(PyObject *self, PyObject *args)
{
    char *output;
    PyObject *value;
#if PY_MAJOR_VERSION >= 3
    PyBytesObject *input;
#else
    PyStringObject *input;
#endif
    if (!PyArg_ParseTuple(args, "S", &input))
        return NULL;
    Py_INCREF(input);
    output = PyMem_Malloc(32);

#if PY_MAJOR_VERSION >= 3
    dinero_hash((char *)PyBytes_AsString((PyObject*) input), (int)PyBytes_Size((PyObject*) input), output);
#else
    dinero_hash((char *)PyString_AsString((PyObject*) input), (int)PyString_Size((PyObject*) input), output);
#endif
    Py_DECREF(input);
#if PY_MAJOR_VERSION >= 3
    value = Py_BuildValue("y#", output, 32);
#else
    value = Py_BuildValue("s#", output, 32);
#endif
    PyMem_Free(output);
    return value;
}

static PyMethodDef DineroMethods[] = {
    { "getPoWHash", dinero_getpowhash, METH_VARARGS, "Returns the proof of work hash using dinero hash" },
    { NULL, NULL, 0, NULL }
};

#if PY_MAJOR_VERSION >= 3
static struct PyModuleDef DineroModule = {
    PyModuleDef_HEAD_INIT,
    "dinero_hash",
    "...",
    -1,
    DineroMethods
};

PyMODINIT_FUNC PyInit_dinero_hash(void) {
    return PyModule_Create(&DineroModule);
}

#else

PyMODINIT_FUNC initdinero_hash(void) {
    (void) Py_InitModule("dinero_hash", DineroMethods);
}
#endif
