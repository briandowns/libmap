#include <stdio.h>
#include <stdlib.h>

#include "map.h"

/** 
 * map_new creates a new map  with the given size 
 */
map_t* map_new(int size) {
    map_t* m = calloc(1, sizeof(map_t));
    m->keys = calloc(size, sizeof(void*));
    m->values = calloc(size, sizeof(void*));
    m->size = size;
    return m;
}

/** 
 * map_free takes the given map and frees the memory it uses 
 */
void map_free(map_t* m) {
    free(m->keys);
    free(m->values);
    free(m);
}

/** 
 * key_idx retrieves the index of the given key 
 */
int key_idx(map_t* m, void* key) {
    int i = (int)key % m->size;
    while (m->keys[i] && m->keys[i] != key) {
        i = (i + 1) % m->size;
    }
    return i;
}

/** 
 * map_set adds the key and it's value to the given map 
 */
void map_set(map_t* m, void* key, void* value) {
    int i = key_idx(m, key);
    m->keys[i] = key;
    m->values[i] = value;
}

/** 
 * map_get retrieves the given key from the map 
 */
void* map_get(map_t* m, void* key) {
    int i = key_idx(m, key);
    return m->values[i];
}

/** 
 * map_del removes the given key and associated value 
 * from the given map 
 */
void map_del(map_t* m, void* key) {
    int i = key_idx(m, key);
    size_t l = sizeof(m->keys) / sizeof(void*);
    m->keys[i] = m->keys[l - 1];
    m->values[i] = m->values[l - 1];
}
