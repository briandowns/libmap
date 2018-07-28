# libmap

libmap is a very simple library to provide a map implementation in c. They keys and values are of type `void*` so we have some freedom to include any keys and values. This implementaiton isn't concerned with item ordering and has the benefit of allowing us to left shift easier to not leave any holes.

I call this simple because the data structure consists of the size of the map and 2 pointers to arrays of void pointers.  Once a key is stored, the value is stored at the same index in the values array. This gives us the ability to find the key and know where the value is.

## Examples

### Create a new map

```c
struct Map *m = map_new(100);
```

### Add some values

```c
map_set(m, "first", "Brian");
int age = 99;
map_set(m, "age", &age);
```

### Retrieve and print the values

```c
printf("first: %s\n", get(m, "first"));  
int *a = map_get(map, "age");
printf("age: %d\n", *a);
```

### Free the memory used by the map

```c
map_free(m);
```
