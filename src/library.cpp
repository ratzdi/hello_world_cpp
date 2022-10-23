#include "library.hpp"

#include <iostream>

namespace hello_world {
void HelloWorld::print_hello() const
{
    std::cout << "Hello World from Hello World Library!" << std::endl;
}
}