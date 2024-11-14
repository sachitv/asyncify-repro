# About
This demonstrates a bug with building emscripten bindings with ASYNCIFY when using WASM_BIGINT

## Reproduction Instructions
### Prerequisite
#### Emscripten
Ensure you have emsdk installed and setup by following [these instructions](https://emscripten.org/docs/getting_started/downloads.html?highlight=installation#installation-instructions-using-the-emsdk-recommended)
#### NodeJS
Install Node 23 following the [instructions](https://nodejs.org/en/download/package-manager)

### Running with ASYNCIFY
In [CMakeLists.txt](./CMakelists.txt) set the value for `-sASYNCIFY` to 1. And then test like so:
```
cd build
emcmake cmake ..
make
node test.js
```

This should give you an  output like:
```
RuntimeError: null function or function signature mismatch
    at wasm://wasm/0001c73a:wasm-function[98]:0x57be
    at ret.<computed> (file:///workspaces/asyncify-repro/build/asyncify_bigint.js:1679:24)
    at file:///workspaces/asyncify-repro/build/asyncify_bigint.js:649:12
    at dynCallLegacy (file:///workspaces/asyncify-repro/build/asyncify_bigint.js:2028:14)
    at dynCall (file:///workspaces/asyncify-repro/build/asyncify_bigint.js:2045:17)
    at file:///workspaces/asyncify-repro/build/asyncify_bigint.js:2049:27
    at Object.getBigInt (eval at newFunc (file:///workspaces/asyncify-repro/build/asyncify_bigint.js:1447:27), <anonymous>:6:10)
    at file:///workspaces/asyncify-repro/test.js:5:19

Node.js v23.2.0
```

### Running without ASYNCIFY
In [CMakeLists.txt](./CMakelists.txt) set the value for `-sASYNCIFY` to 0. And then test like so:
```
cd build
emcmake cmake ..
make
node test.js
```

This should give you the output
```
1000000000000n
```
