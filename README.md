# libmap

libmap is a simple library to proide a map implementation. They keys and values are of type `void*` so we have some freedom. This implementaiton isn't concerned with item ordering which has the benefit of allowing us to left shift easier not to leave any holes.

## Examples

### Create a new map

```
map_t* m = new_map(100);
```

### Add some values

```
set(m, "first", "Brian");
int age = 99;
set(m, "age", &age);
```

### Retrieve and print the values

```
printf("first: %s\n", get(m, "first"));  
void* a = get(m, "age");
printf("age: %d\n", *((int*)a));
```

### Free the memory used by the map

```
free_map(m);
```

## TODO

- [ ] make thread safe
- [ ] add support for buckets
