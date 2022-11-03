#include <hello_world_cpp/library.hpp>

#include <gtest/gtest.h>

namespace test {

using namespace testing;

class HelloWorldTest : public Test {
protected:
    hello_world::HelloWorld m_testee {};
};

TEST_F(HelloWorldTest, print_hello__returns_expected)
{
    const std::string expected_result { "Hello World!" };
    EXPECT_EQ(m_testee.say_hello(), expected_result);
}
}
