#include <vector>
#include <sstream>
#include <string>

#include <gtest/gtest.h>

#include "ip_print.h"

TEST(Utilities, string_1)
{
    std::string in{"some string"};
    std::ostringstream str;
    print_utils::print_ip(in, str);
    std::string exp{"some string\n"};
    std::string res = str.str();
    ASSERT_EQ(exp, res);
}

TEST(Utilities, string_2)
{
    std::string in{"192.233.102.1"};
    std::ostringstream str;
    print_utils::print_ip(in, str);
    std::string exp{"192.233.102.1\n"};
    std::string res = str.str();
    ASSERT_EQ(exp, res);
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}