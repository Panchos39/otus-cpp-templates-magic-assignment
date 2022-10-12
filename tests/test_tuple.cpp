#include <sstream>
#include <string>
#include <tuple>

#include <gtest/gtest.h>

#include "ip_print.h"

TEST(Utilities, tuple_int)
{
    std::tuple<int, int, int, int> in{127, 0, 0, 1};
    std::ostringstream str;
    print_utils::print_ip(in, str);
    std::string exp{"127.0.0.1\n"};
    std::string res = str.str();
    ASSERT_EQ(exp, res);
}

// check more than 4 values
TEST(Utilities, tuple_int_more_than_4)
{
    auto in = std::make_tuple(255, 255, 255, 255, 1);
    std::ostringstream str;
    print_utils::print_ip(in, str);
    std::string exp{"255.255.255.255.1\n"};
    std::string res = str.str();
    ASSERT_EQ(exp, res);
}

// Check other types than int
TEST(Utilities, tuple_char)
{
    auto in = std::make_tuple("255", "255");
    std::ostringstream str;
    print_utils::print_ip(in, str);
    std::string exp{"255.255\n"};
    std::string res = str.str();
    ASSERT_EQ(exp, res);
}

// Check if print_ip works for tuples with just one element
TEST(Utilities, tuple_1int)
{
    auto in = std::make_tuple(255);
    std::ostringstream str;
    print_utils::print_ip(in, str);
    std::string exp{"255\n"};
    std::string res = str.str();
    ASSERT_EQ(exp, res);
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}