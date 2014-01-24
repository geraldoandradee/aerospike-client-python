#include <Python.h>
#include <stdbool.h>

#include <aerospike/aerospike_scan.h>
#include <aerospike/as_error.h>
#include <aerospike/as_scan.h>

#include "client.h"
#include "conversions.h"
#include "scan.h"

#undef TRACE
#define TRACE()

static bool each_result(const as_val * val, void * udata)
{
	if ( !val ) {
		return false;
	}

	PyObject * py_results = (PyObject *) udata;
	PyObject * py_result = NULL;

	as_error err;

	val_to_pyobject(&err, val, &py_result);

	PyList_Append(py_results, py_result);
	return true;
}

PyObject * AerospikeScan_Results(AerospikeScan * self, PyObject * args, PyObject * kwds)
{
	TRACE();
	
	AerospikeScan * py_scan = self;
	AerospikeClient * py_client = py_scan->client;
	PyObject * py_policy = NULL;

	TRACE();
	
	static char * kwlist[] = {"policy", NULL};

	TRACE();
	
	if ( PyArg_ParseTupleAndKeywords(args, kwds, "|O:foreach", kwlist, &py_policy) == false ) {
		return NULL;
	}

	as_error err;
	as_error_init(&err);

	PyObject * py_results = PyList_New(0);

	aerospike_scan_foreach(py_client->as, &err, NULL, &py_scan->scan, each_result, py_results);

	return py_results;
}