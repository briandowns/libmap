# libmap

libmap is a simple library to proide a map implementation. They keys and values are of type `void*` so we have some freedom. This implementaiton isn't concerned with item ordering which has the benefit of allowing us to left shift easier not to leave any holes.

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
