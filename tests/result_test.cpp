#include "result.hpp"
#include "unittest.hpp"

using namespace con;

SIMPLE_TEST(result_test_1)
{
    result<int> r = 42;
    ASSERT_TRUE(r.has_value());
    ASSERT_EQ(r.value(), 42);
}

SIMPLE_TEST(result_test_2)
{
    result<int> r;

    try {
        throw std::runtime_error("error");
    } catch (...) {
        r = std::current_exception();
    }

    ASSERT_TRUE(r.has_exception());
}

SIMPLE_TEST(result_test_3)
{
    result<int> r;

    ASSERT_TRUE(r.has_value());
    ASSERT_TRUE(!r.has_exception());
}

SIMPLE_TEST(result_test_4)
{
    result<int> r;

    try {
        throw std::runtime_error("error");
    } catch (...) {
        r = std::current_exception();
    }

    bool caught = false;

    try {
        r.value();
    } catch (...) {
        caught = true;
    }

    ASSERT_TRUE(caught);
}

TEST_MAIN()
