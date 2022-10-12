#include <vector>
#include <list>
#include <sstream>
#include <string>

#include <gtest/gtest.h>

#include "ip_print.h"



TEST(Utilities, vector_int)
{
    std::vector<int> in{255, 255, 255, 1,};
    std::ostringstream str;

    print_utils::print_ip(in, str);

    std::string exp{"255.255.255.1\n"};
    std::string res = str.str();
    ASSERT_EQ(exp, res);
}

TEST(Utilities, list_int)
{
    std::list<int> in{255, 255, 255, 1};
    std::ostringstream str;

    print_utils::print_ip(in, str);
    std::string exp{"255.255.255.1\n"};
    std::string res = str.str();
    ASSERT_EQ(exp, res);
}

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}