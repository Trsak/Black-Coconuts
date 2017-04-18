/**
 * @file math_lib_tests.cpp
 * @author Tomas Odehnal xodehn08
 * @brief This file contains tests for math_lib.cpp
 */

#include <gtest/gtest.h>
#include <limits>
#include <math.h>
#include "math_lib.h"
#include "exceptions.cpp"

using namespace std;

class Math_lib_test :public ::testing::Test {
protected:
    Math_lib *math_lib;

    virtual void SetUp() {
        math_lib = new Math_lib();
    }

    virtual void TearDown() {
        delete math_lib;
    }
};
// SUM TESTS
TEST_F(Math_lib_test, sum_normal) {
    EXPECT_DOUBLE_EQ(math_lib->sum(5.4,6.25), 11.65);
    EXPECT_DOUBLE_EQ(math_lib->sum(-20.4, -4.21), -24.61);
    EXPECT_DOUBLE_EQ(math_lib->sum(-5, 5), 0);
}

TEST_F(Math_lib_test, sum_overflow) {
    EXPECT_TRUE(isinf(math_lib->sum(numeric_limits<double>::max(),numeric_limits<double>::max())));
    EXPECT_TRUE(isinf(math_lib->sum(-numeric_limits<double>::max(),-numeric_limits<double>::max())));
}

// SUB TESTS
TEST_F(Math_lib_test, sub_normal) {
    EXPECT_DOUBLE_EQ(math_lib->sub(5.4,6.25), -0.85);
    EXPECT_DOUBLE_EQ(math_lib->sub(-20.4, -4.21), -16.19);
    EXPECT_DOUBLE_EQ(math_lib->sub(5, 5), 0);
    EXPECT_DOUBLE_EQ(math_lib->sub(10, 2.4), 7.6);
}

TEST_F(Math_lib_test, sub_overflow) {
    EXPECT_TRUE(isinf(math_lib->sub(numeric_limits<double>::max(),-numeric_limits<double>::max())));
    EXPECT_TRUE(isinf(math_lib->sub(-numeric_limits<double>::max(),numeric_limits<double>::max())));
}

// MUL TESTS
TEST_F(Math_lib_test, mul_normal) {
    EXPECT_DOUBLE_EQ(math_lib->mul(2.1, 5), 10.5);
    EXPECT_DOUBLE_EQ(math_lib->mul(-10.5, 5.5), -57.75);
    EXPECT_DOUBLE_EQ(math_lib->mul(5, 0), 0);
    EXPECT_DOUBLE_EQ(math_lib->mul(10.874, 1), 10.874);
}

TEST_F(Math_lib_test, mul_overflow) {
    EXPECT_TRUE(isinf(math_lib->mul(numeric_limits<double>::max(),numeric_limits<double>::max())));
    EXPECT_TRUE(isinf(math_lib->mul(numeric_limits<double>::max(), 2)));
    EXPECT_EQ(isinf(math_lib->mul(-numeric_limits<double>::min(),numeric_limits<double>::max())), 0);
}

// DIV TESTS
TEST_F(Math_lib_test, div_normal) {
    EXPECT_DOUBLE_EQ(math_lib->div(50.2, 2.0), 25.1);
    EXPECT_DOUBLE_EQ(math_lib->div(4.14, -0.1), -41.4);
    EXPECT_DOUBLE_EQ(math_lib->div(0.25, 0.4), 0.625);
    EXPECT_DOUBLE_EQ(math_lib->div(0, 15.12), 0);
}

TEST_F(Math_lib_test, div_overflow) {
    EXPECT_TRUE(isinf(math_lib->div(numeric_limits<double>::max(),numeric_limits<double>::min())));
    EXPECT_TRUE(isnan(math_lib->div(numeric_limits<double>::infinity(), numeric_limits<double>::infinity())));
    ASSERT_THROW(math_lib->div(10.0, 0), DivideByZeroException);
}


TEST_F(Math_lib_test, natural_power) {
    EXPECT_DOUBLE_EQ(math_lib->natural_power(10.4, 3), 1124.864);
    EXPECT_DOUBLE_EQ(math_lib->natural_power(-2.0, 2), 4.0);
    EXPECT_DOUBLE_EQ(math_lib->natural_power(1204, 0), 1);
    ASSERT_THROW(math_lib->natural_power(4.5, -2), invalid_argument);
    EXPECT_DOUBLE_EQ(math_lib->natural_power(0, 0), 1); // Because pow(0, 0) == 1
}

TEST_F(Math_lib_test, general_sqrt) {
    ASSERT_NEAR(math_lib->general_sqrt(20, 0.01), 1.030410558, 0.0001);
    ASSERT_NEAR(math_lib->general_sqrt(2000000, 0.0001), 1.001451919, 0.0001);
    ASSERT_NEAR(math_lib->general_sqrt(21456, 0.5), 146.478667389, 0.0001);
    EXPECT_TRUE(isnan(math_lib->general_sqrt(-5, 0.5)));
}

TEST_F(Math_lib_test, factorial) {
    EXPECT_EQ(math_lib->factorial(0), 1);
    EXPECT_EQ(math_lib->factorial(5), 120);
    ASSERT_THROW(math_lib->factorial(21), overflow_error);
    ASSERT_THROW(math_lib->factorial(-5), invalid_argument);
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest( &argc, argv );
    return RUN_ALL_TESTS();
}