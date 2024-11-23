cmake_minimum_required(VERSION 3.0)
project(AsyncifyBigIntExample)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 11)

# Define Emscripten-specific compiler and linker flags
set(EM_FLAGS "-sMODULARIZE -sWASM_BIGINT=1 -lembind -sEXPORT_ES6=1 -sASYNCIFY=1 -sUSE_PTHREADS=1 -sPROXY_TO_PTHREAD=1")

# Apply compiler flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${EM_FLAGS}")

# Include directories
include_directories(${CMAKE_SOURCE_DIR})

# Add the executable and link flags
add_executable(asyncify_bigint main.cpp)
target_link_options(asyncify_bigint PRIVATE ${EM_FLAGS})
