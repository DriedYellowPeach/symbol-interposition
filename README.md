# symbol-interposition
another way to test functions inside dynamic library

## Build

Build with following command

```bash
mkdir build
cd build
cmake ..
make -j
```

## Test

Test with following command

Inside build dir

```bash
LD_PRELOAD=libB.so ./main
```

## What Happened?

Output:
```
// original version but with injected printf code
From libB.so add_number(left: 1, right: 2)
ADD Result: 3

// modified version from libB
From libB.so mul_number(left: 1, right: 2)
MUL Result: 69

// original version from libA
SUB Result: 2
```

Basically, the dynamic library `libB` is preloaded and overwrite the symbol of `libA` and `libC`, but with `dlsym`, we can still find the original function. With a well-designed data structure called `switch` maybe, we can turn on and off the switch to use either original or modified functions.

