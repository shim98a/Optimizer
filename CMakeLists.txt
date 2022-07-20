cmake_minimum_required(VERSION 3.14)
project(example_project CXX)

add_subdirectory(./costfunction)
add_subdirectory(./optim)

add_executable(example example.cpp)
target_link_libraries(example PRIVATE costfunction_static optim_static)
target_compile_features(example PRIVATE cxx_std_11)
