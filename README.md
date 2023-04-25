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

Basically, the dynamic library `libB` is preloaded and overwrite the symbol of `libA` and `libC`, but with `dlsym`, we can still find the original function. With a well-designed data structure called `switch` maybe, we can turn on and off the switch to use either original or modified functions.

