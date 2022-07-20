cmake_minimum_required(VERSION 3.14)

file(
    GLOB COSTFUNCTION_SRC
    "*.cpp"
    "*.hpp"
)

add_library(costfunction_static STATIC ${COSTFUNCTION_SRC})
target_include_directories(costfunction_static INTERFACE .)
target_compile_features(costfunction_static PRIVATE cxx_std_11)

add_library(costfunction_shared SHARED ${COSTFUNCTION_SRC})
target_include_directories(costfunction_shared INTERFACE .)
target_compile_features(costfunction_shared PRIVATE cxx_std_11)
