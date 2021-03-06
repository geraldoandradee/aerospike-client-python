/*******************************************************************************
 * Copyright 2013-2014 Aerospike, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 ******************************************************************************/

#pragma once

#include <Python.h>
#include <stdbool.h>

#include <aerospike/aerospike.h>
#include <aerospike/as_key.h>
#include <aerospike/as_query.h>
#include <aerospike/as_scan.h>


typedef struct {
	PyObject_HEAD
	aerospike * as;
} AerospikeClient;

typedef struct {
	PyObject_HEAD
	AerospikeClient * client;
	PyObject * namespace;
	PyObject * set;
	PyObject * key;
} AerospikeKey;

typedef struct {
	PyObject_HEAD
	AerospikeClient * client;
	as_query query;
} AerospikeQuery;

typedef struct {
  PyObject_HEAD
  AerospikeClient * client;
  as_scan scan;
} AerospikeScan;
