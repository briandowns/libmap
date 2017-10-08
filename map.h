/** map_t is the data structure to store keys and values */
typedef struct {
    int size;
    void **keys;
    void **values;
} map_t;

map_t *new_map(int size);
void free_map(map_t* h);
void* get(map_t* h, void* key);
void set(map_t* h, void* key, void* value);
void del(map_t* m, void* key);
