/*-
 * SPDX-License-Identifier: BSD-2-Clause
 *
 * Copyright (c) 2024 Brian J. Downs
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#include <stdio.h>
#include <stdlib.h>

#include "map.h"


map_t*
map_new(const int size)
{
    map_t *m = calloc(1, sizeof(map_t));
    m->keys = calloc(size, sizeof(void*));
    m->values = calloc(size, sizeof(void*));
    m->size = size;

    return m;
}


void
map_free(map_t *m)
{
    free(m->keys);
    free(m->values);
    free(m);
}

/** 
 * key_idx retrieves the index of the given key 
 */
static int
key_idx(map_t *m, const void *key)
{
    int i = (int)key % m->size;
    while (m->keys[i] && m->keys[i] != key) {
        i = (i + 1) % m->size;
    }

    return i;
}


void
map_set(map_t *m, const void *key, const void *value)
{
    int i = key_idx(m, key);

    m->keys[i] = key;
    m->values[i] = value;
}


void*
map_get(map_t *m, const void *key)
{
    int i = key_idx(m, key);

    return m->values[i];
}


void
map_del(map_t *m, const void *key)
{
    int i = key_idx(m, key);
    size_t l = sizeof(m->keys) / sizeof(void*);

    m->keys[i] = m->keys[l - 1];
    m->values[i] = m->values[l - 1];
}
