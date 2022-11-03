#ifndef LIB_HELLO_WORLD_LIBRARY_HPP
#define LIB_HELLO_WORLD_LIBRARY_HPP

#include <string>

namespace hello_world {
class HelloWorld {
public:
    HelloWorld() = default;
    HelloWorld(HelloWorld&&) = default;
    HelloWorld& operator=(const HelloWorld&) = default;
    HelloWorld& operator=(HelloWorld&&) = default;
    virtual ~HelloWorld() = default;

    void print_hello() const;

    virtual  std::string say_hello() const noexcept;
};

}
#endif // LIB_HELLO_WORLD_LIBRARY_HPP
