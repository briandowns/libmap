#ifndef _MAP_H
#define _MAP_H

/** 
 * Map is the data structure to store keys and values 
 */
struct Map {
    int size;
    void **keys;
    void **values;
};

struct Map *map_new(int size);
void map_free(struct Map *h);
void *map_get(struct Map *h, void *key);
void map_set(struct Map *h, void *key, void *value);
void map_del(struct Map *m, void *key);

#endif
