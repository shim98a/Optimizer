cmake_minimum_required(VERSION 3.14)

file(
    GLOB OPTIM_SRC
    "*.cpp"
    "*.hpp"
)

add_library(optim_static STATIC ${OPTIM_SRC})
# target_link_libraries(optim_static costfunction_static)
target_include_directories(optim_static INTERFACE .)
target_compile_features(optim_static PRIVATE cxx_std_11)
