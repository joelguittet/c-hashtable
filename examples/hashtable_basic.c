/**
 * @file      hashtable_basic.c
 * @brief     Hashtable basic example in C
 *
 * MIT License
 *
 * Copyright (c) 2021-2023 joelguittet and c-hashtable contributors
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

/******************************************************************************/
/* Includes                                                                   */
/******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "hashtable.h"

/******************************************************************************/
/* Functions                                                                  */
/******************************************************************************/

/**
 * @brief Main function
 * @param argc Number of arguments
 * @param argv Arguments
 * @return Always returns 0
 */
int
main(int argc, char **argv) {

    hashtable_t *hashtable;

    /* Create hashtable instance */
    if (NULL == (hashtable = hashtable_create(64, false))) {
        printf("unable to create hashtable instance\n");
        exit(EXIT_FAILURE);
    }

    /* Add elements to the hashtable */
    hashtable_add(hashtable, "key1", "element1", sizeof(char *));
    hashtable_add(hashtable, "key2", "element2", sizeof(char *));
    hashtable_add(hashtable, "key3", "element3", sizeof(char *));

    /* Print elements of the hashtable */
    char **keys  = NULL;
    size_t count = hashtable_get_keys(hashtable, &keys);
    if (NULL != keys) {
        for (size_t index = 0; index < count; index++) {
            char *element = hashtable_lookup(hashtable, keys[index]);
            if (NULL != element) {
                printf("%s: %s\n", keys[index], element);
            }
        }
        free(keys);
    }

    /* Release memory */
    hashtable_release(hashtable);

    return 0;
}
