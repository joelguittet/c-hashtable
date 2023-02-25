# c-hashtable

[![CI Badge](https://github.com/joelguittet/c-hashtable/workflows/ci/badge.svg)](https://github.com/joelguittet/c-hashtable/actions)
[![Issues Badge](https://img.shields.io/github/issues/joelguittet/c-hashtable)](https://github.com/joelguittet/c-hashtable/issues)
[![License Badge](https://img.shields.io/github/license/joelguittet/c-hashtable)](https://github.com/joelguittet/c-hashtable/blob/master/LICENSE)

[![Bugs](https://sonarcloud.io/api/project_badges/measure?project=joelguittet_c-hashtable&metric=bugs)](https://sonarcloud.io/dashboard?id=joelguittet_c-hashtable)
[![Code Smells](https://sonarcloud.io/api/project_badges/measure?project=joelguittet_c-hashtable&metric=code_smells)](https://sonarcloud.io/dashboard?id=joelguittet_c-hashtable)
[![Duplicated Lines (%)](https://sonarcloud.io/api/project_badges/measure?project=joelguittet_c-hashtable&metric=duplicated_lines_density)](https://sonarcloud.io/dashboard?id=joelguittet_c-hashtable)
[![Lines of Code](https://sonarcloud.io/api/project_badges/measure?project=joelguittet_c-hashtable&metric=ncloc)](https://sonarcloud.io/dashboard?id=joelguittet_c-hashtable)
[![Vulnerabilities](https://sonarcloud.io/api/project_badges/measure?project=joelguittet_c-hashtable&metric=vulnerabilities)](https://sonarcloud.io/dashboard?id=joelguittet_c-hashtable)

[![Maintainability Rating](https://sonarcloud.io/api/project_badges/measure?project=joelguittet_c-hashtable&metric=sqale_rating)](https://sonarcloud.io/dashboard?id=joelguittet_c-hashtable)
[![Reliability Rating](https://sonarcloud.io/api/project_badges/measure?project=joelguittet_c-hashtable&metric=reliability_rating)](https://sonarcloud.io/dashboard?id=joelguittet_c-hashtable)
[![Security Rating](https://sonarcloud.io/api/project_badges/measure?project=joelguittet_c-hashtable&metric=security_rating)](https://sonarcloud.io/dashboard?id=joelguittet_c-hashtable)

Provide hashtables support in C.

## Features

*   add and remove elements of any type in the hashtable
*   elements of the hashtable as a copy or reference

## Building

Build `libhashtable.so` with the following commands:

``` bash
mkdir build
cd build
cmake ..
make
```

## Installing

Install `libhashtable.so` with the following commands:

``` bash
make install
```

## Examples

Build examples with the following commands:
``` bash
mkdir build
cd build
cmake -DENABLE_HASHTABLE_EXAMPLES=ON .
make
```

### hashtable_sort

Add string elements to a hashtable and sort them alphabetically.

## Performances

Performances have not been evaluated yet.

## What's it good for?

This goal of this library is to provide a C implementation to provide hashtable support.

## API

### hashtable_t *hashtable_create(size_t size, bool alloc)

Create a new hashtable with initial `size`. Hashtable lookup performances are greater with largest `size` but leads to a larger memory footprint. Set `alloc` to create copies of the values when `hashtable_add` is called.

### int hashtable_add(hashtable_t *hashtable, char *key, void *e, size_t size)

Add element `e` of size `size` with key `key` to the `hashtable`. The key is a string.

### size_t hashtable_get_count(hashtable_t *hashtable)

Return the number of elements in the `hashtable`.

### bool hashtable_has_key(hashtable_t *hashtable, char *key)

Check if `key` elment is available in the `hashtable`.

### size_t hashtable_get_keys(hashtable_t *hashtable, char ***keys)

Return all `keys` of the `hashtable`.

### void *hashtable_lookup(hashtable_t *hashtable, char *key)

Get element of key `key` from the `hashtable`.

### void *hashtable_remove(hashtable_t *hashtable, char *key)

Remove element of key `key` from the `hashtable`.

### void hashtable_release(hashtable_t *hashtable)

Release the hashtable. Must be called to free ressources.

## License

MIT
