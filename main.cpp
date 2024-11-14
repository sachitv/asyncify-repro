#include <cstdint>
#include <emscripten.h>
#include <emscripten/bind.h>

int64_t getBigInt() {
    return 1000000000000;
}

EMSCRIPTEN_BINDINGS(my_module) {
    emscripten::function("getBigInt", &getBigInt);
}