# Optimizer
Just a very simple implementations of optimizers
```
Optimizer
|
|-- costfunction
|      |- CMakeLists.txt
|      |- base.hpp (abst base class for the cost function classes)
|      |- quadratic.cpp (quadratic cost function x^T * A * x + b^T * x)
|      |- quadratic.hpp
|
|-- optim
|      |- CMakeLists.txt
|      |- gradient_descent.cpp (GradientDescent optimizer class)
|      |- gradient_descnet.hpp
|
|-- CMakeLists.txt (for example.cpp)
|-- example.cpp (simple example file to run an optimizer)
```

# How to run example.cpp
```
~$ git clone -b main https://github.com/shim98a/Optimizer.git
~$ cd Optimizer
~/Optimizer$ mkdir build
~/Optimizer$ cd build
~/Optimizer/build $ cmake ..
~/Optimizer/build $ cmake --build .
~/Optimizer/build $ ./example
```