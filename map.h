#ifndef _MAP_H
#define _MAP_H

/** 
 * map_t is the data structure to store keys and values 
 */
typedef struct {
    int size;
    void **keys;
    void **values;
} map_t;

map_t *map_new(int size);
void map_free(map_t* h);
void *map_get(map_t* h, void* key);
void map_set(map_t* h, void* key, void* value);
void map_del(map_t* m, void* key);

#endif
