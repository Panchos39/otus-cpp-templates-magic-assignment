#include <vector>
#include <sstream>
#include <string>

#include <gtest/gtest.h>

#include "ip_print.h"


TEST(Utilities, integral_int)
{
    int in{1234};
    std::ostringstream str;
    print_utils::print_ip(in, str);
    std::string exp{"0.0.4.210\n"};
    std::string res = str.str();
    ASSERT_EQ(exp, res);
}

TEST(Utilities, integral_int2)
{
    int in{2130706433};
    std::ostringstream str;
    print_utils::print_ip(in, str);
    std::string exp{"127.0.0.1\n"};
    std::string res = str.str();
    ASSERT_EQ(exp, res);
}

TEST(Utilities, integral_char)
{
    char in{-1};
    std::ostringstream str;
    print_utils::print_ip(in, str);
    std::string exp{"255\n"};
    std::string res = str.str();
    ASSERT_EQ(exp, res);
}

TEST(Utilities, integral_short)
{
    short in{0};
    std::ostringstream str;
    print_utils::print_ip(in, str);
    std::string exp{"0.0\n"};
    std::string res = str.str();
    ASSERT_EQ(exp, res);
}

TEST(Utilities, integral_long)
{
    long in{8875824491850138409};
    std::ostringstream str;
    print_utils::print_ip(in, str);
    std::string exp{"123.45.67.89.101.112.131.41\n"};
    std::string res = str.str();
    ASSERT_EQ(exp, res);
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

