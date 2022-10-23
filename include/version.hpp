#ifndef HELLO_WORLD_CPP_VERSION_HPP
#define HELLO_WORLD_CPP_VERSION_HPP

#include <string>

namespace hello_world {
class Version {
public:
    Version() = default;
    Version(Version&&) = default;
    Version& operator=(const Version&) = default;
    Version& operator=(Version&&) = default;
    virtual ~Version() = default;

    static std::string get_git_hash();
};
}

#endif // HELLO_WORLD_CPP_VERSION_HPP
