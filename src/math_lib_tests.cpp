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
    Math_lib *math_lib; /**< Instance of Math_lib for calling methods **/

    virtual void SetUp() {
        math_lib = new Math_lib();
    }

    virtual void TearDown() {
        delete math_lib;
    }
};

/**
 * @brief Test method sum() with normal values.
 */
TEST_F(Math_lib_test, sum_normal) {
    /** Sums up 5.4 and 6.25 and result should by equal to 11.65 */
    EXPECT_DOUBLE_EQ(math_lib->sum(5.4,6.25), 11.65);
    /** Sums up -20.4 and -4.21 and result should by equal to -24.61 */
    EXPECT_DOUBLE_EQ(math_lib->sum(-20.4, -4.21), -24.61);
    /** Sums up -5 and 5 and result should by equal to 0 */
    EXPECT_DOUBLE_EQ(math_lib->sum(-5, 5), 0);
}

/**
 * @brief Test method sum() with limit values.
 */
TEST_F(Math_lib_test, sum_overflow) {
    /** Sums up max value of double and max value of double and result should by equal to Inf */
    EXPECT_TRUE(isinf(math_lib->sum(numeric_limits<double>::max(),numeric_limits<double>::max())));
    /** Sums up max negative value of double and max negative value of double and result should by equal to Inf */
    EXPECT_TRUE(isinf(math_lib->sum(-numeric_limits<double>::max(),-numeric_limits<double>::max())));
}

/**
 * @brief Test method sub() with normal values.
 */
TEST_F(Math_lib_test, sub_normal) {
    /** Subtract 5.4 and 6.25 and result should by equal to -0.85 */
    EXPECT_DOUBLE_EQ(math_lib->sub(5.4,6.25), -0.85);
    /** Subtract -20.4 and -4.21 and result should by equal to -16.19 */
    EXPECT_DOUBLE_EQ(math_lib->sub(-20.4, -4.21), -16.19);
    /** Subtract 5 and 5 and result should by equal to 0 */
    EXPECT_DOUBLE_EQ(math_lib->sub(5, 5), 0);
    /** Subtract 10 and 2.4 and result should by equal to 7.6 */
    EXPECT_DOUBLE_EQ(math_lib->sub(10, 2.4), 7.6);
}

/**
 * @brief Test method sub() with limit values.
 */
TEST_F(Math_lib_test, sub_overflow) {
    /** Subtract max value of double and max negative value of double and result should by equal to Inf */
    EXPECT_TRUE(isinf(math_lib->sub(numeric_limits<double>::max(),-numeric_limits<double>::max())));
    /** Subtract max negative value of double and  max value of double and result should by equal to Inf */
    EXPECT_TRUE(isinf(math_lib->sub(-numeric_limits<double>::max(),numeric_limits<double>::max())));
}

/**
 * @brief Test method mul() with normal values.
 */
TEST_F(Math_lib_test, mul_normal) {
    /** Multiply 2.1 and 5 and result should by equal to 10.5 */
    EXPECT_DOUBLE_EQ(math_lib->mul(2.1, 5), 10.5);
    /** Multiply -10.5 and 5.5 and result should by equal to -57.75 */
    EXPECT_DOUBLE_EQ(math_lib->mul(-10.5, 5.5), -57.75);
    /** Multiply 5 and 0 and result should by equal to 0 */
    EXPECT_DOUBLE_EQ(math_lib->mul(5, 0), 0);
    /** Multiply 10.874 and 1 and result should by equal to 10.874 */
    EXPECT_DOUBLE_EQ(math_lib->mul(10.874, 1), 10.874);
}

/**
 * @brief Test method mul() with limit values.
 */
TEST_F(Math_lib_test, mul_overflow) {
    /** Multiply max value of double and max value of double and result should by equal to Inf */
    EXPECT_TRUE(isinf(math_lib->mul(numeric_limits<double>::max(),numeric_limits<double>::max())));
    /** Multiply max value of double and 2 and result should by equal to Inf */
    EXPECT_TRUE(isinf(math_lib->mul(numeric_limits<double>::max(), 2)));
    /** Multiply max value of double and 0 and result should by equal to 0 */
    EXPECT_EQ(math_lib->mul(numeric_limits<double>::min(), 0), 0);
}

/**
 * @brief Test method div() with normal values.
 */
TEST_F(Math_lib_test, div_normal) {
    /** Divide 50.2 and 2.0 and result should by equal to 25.1 */
    EXPECT_DOUBLE_EQ(math_lib->div(50.2, 2.0), 25.1);
    /** Divide 4.14 and -0.1 and result should by equal to -41.4 */
    EXPECT_DOUBLE_EQ(math_lib->div(4.14, -0.1), -41.4);
    /** Divide 0.25 and 0.4 and result should by equal to 0.625 */
    EXPECT_DOUBLE_EQ(math_lib->div(0.25, 0.4), 0.625);
    /** Divide 0 and 15.12 and result should by equal to 0 */
    EXPECT_DOUBLE_EQ(math_lib->div(0, 15.12), 0);
}

/**
 * @brief Test method div() with limit values.
 */
TEST_F(Math_lib_test, div_overflow) {
    /** Divide max value of double and min value of double and result should by equal to Inf */
    EXPECT_TRUE(isinf(math_lib->div(numeric_limits<double>::max(),numeric_limits<double>::min())));
    /** Divide Inf and Inf result should by equal to NaN */
    EXPECT_TRUE(isnan(math_lib->div(numeric_limits<double>::infinity(), numeric_limits<double>::infinity())));
    /** Divide 10.0 and 0 and the method should throw DivideByZeroException */
    ASSERT_THROW(math_lib->div(10.0, 0), DivideByZeroException);
}

/**
 * @brief Test method natural_power
 */
TEST_F(Math_lib_test, natural_power) {
    /** Call method natural_power with 10.4 and 3 and result should by equal to 1124.864 */
    EXPECT_DOUBLE_EQ(math_lib->natural_power(10.4, 3), 1124.864);
    /** Call method natural_power with -2.0 and 2 and result should by equal to 4.0 */
    EXPECT_DOUBLE_EQ(math_lib->natural_power(-2.0, 2), 4.0);
    /** Call method natural_power with 1204 and 0 and result should by equal to 1 */
    EXPECT_DOUBLE_EQ(math_lib->natural_power(1204, 0), 1);
    /** Call method natural_power with 4.5 and -2 and the method should throw invalid_argument */
    ASSERT_THROW(math_lib->natural_power(4.5, -2), invalid_argument);
    /** Call method natural_power with 0 and 0 and result should by equal to 1 */
    EXPECT_DOUBLE_EQ(math_lib->natural_power(0, 0), 1); // Because pow(0, 0) == 1
}

TEST_F(Math_lib_test, general_sqrt) {
    /** Call method general_sqrt with 20 and 0.01 and result should by equal to 1.03041 */
    ASSERT_NEAR(math_lib->general_sqrt(20, 0.01), 1.030410558, 0.0001);
    /** Call method general_sqrt with 2000000 and 0.0001 and result should by equal to 1.00145 */
    ASSERT_NEAR(math_lib->general_sqrt(2000000, 0.0001), 1.001451919, 0.0001);
    /** Call method general_sqrt with 21456 and 0.5 and result should by equal to 146.47866 */
    ASSERT_NEAR(math_lib->general_sqrt(21456, 0.5), 146.478667389, 0.0001);
    /** Call method general_sqrt with -5 and 0.5 and result should by equal to NaN */
    EXPECT_TRUE(isnan(math_lib->general_sqrt(-5, 0.5)));
}

TEST_F(Math_lib_test, factorial) {
    /** Call method factorial with 0 and result should by equal to 1 */
    EXPECT_EQ(math_lib->factorial(0), 1);
    /** Call method factorial with 5 and result should by equal to 120 */
    EXPECT_EQ(math_lib->factorial(5), 120);
    /** Call method factorial with 21 and result should throw everflow_error */
    ASSERT_THROW(math_lib->factorial(21), overflow_error);
    /** Call method factorial with -5 and result should throw invalid_argument */
    ASSERT_THROW(math_lib->factorial(-5), invalid_argument);
}

TEST_F(Math_lib_test, bin_or) {
    /** Call method bin_or with 0101 and 0011 and result should by equal to 0111 */
    EXPECT_EQ(math_lib->bin_or("0101", "0011"), "0111");
    /** Call method bin_or with 10101010 and 01010101 and result should by equal to 11111111 */
    EXPECT_EQ(math_lib->bin_or("10101010", "01010101"), "11111111");
    /** Call method bin_or with 11111111 and 0000000000 and result should by equal to 0011111111 */
    EXPECT_EQ(math_lib->bin_or("11111111", "0000000000"), "0011111111");
    /** Call method bin_or with 11111111111111111111111111111111 and 00000000000000000000000000000000 and result should by equal to 11111111111111111111111111111111 */
    EXPECT_EQ(math_lib->bin_or("11111111111111111111111111111111", "00000000000000000000000000000000"), "11111111111111111111111111111111");
    /** Call method bin_or with 111111111111111111111111111111110 and 000000000000000000000000000000001 and result should throw invalid_argument */
    ASSERT_THROW(math_lib->bin_or("111111111111111111111111111111110","000000000000000000000000000000001"), invalid_argument);
}

TEST_F(Math_lib_test, bin_nor) {
    /** Call method bin_or with 0101 and 0011 and result should by equal to 1000 */
    EXPECT_EQ(math_lib->bin_nor("0101", "0011"), "1000");
    /** Call method bin_or with 10101010 and 01010101 and result should by equal to 00000000 */
    EXPECT_EQ(math_lib->bin_nor("10101010", "01010101"), "00000000");
    /** Call method bin_or with 11111111 and 0000000000 and result should by equal to 1100000000 */
    EXPECT_EQ(math_lib->bin_nor("11111111", "0000000000"), "1100000000");
    /** Call method bin_or with 11111111111111111111111111111111 and 00000000000000000000000000000000 and result should by equal to 00000000000000000000000000000000 */
    EXPECT_EQ(math_lib->bin_nor("11111111111111111111111111111111", "00000000000000000000000000000000"), "00000000000000000000000000000000");
    /** Call method bin_or with 111111111111111111111111111111110 and 000000000000000000000000000000001 and result should throw invalid_argument */
    ASSERT_THROW(math_lib->bin_nor("111111111111111111111111111111110","000000000000000000000000000000001"), invalid_argument);
}

TEST_F(Math_lib_test, bin_and) {
    /** Call method bin_or with 0101 and 0011 and result should by equal to 0001 */
    EXPECT_EQ(math_lib->bin_and("0101", "0011"), "0001");
    /** Call method bin_or with 10101010 and 01010101 and result should by equal to 00000000 */
    EXPECT_EQ(math_lib->bin_and("10101010", "01010101"), "00000000");
    /** Call method bin_or with 11111111 and 0000000000 and result should by equal to 1100000000 */
    EXPECT_EQ(math_lib->bin_and("11111111", "0000000000"), "0000000000");
    /** Call method bin_or with 11111111111111111111111111111111 and 00000000000000000000000000000000 and result should by equal to 00000000000000000000000000000000 */
    EXPECT_EQ(math_lib->bin_and("11111111111111111111111111111111", "00000000000000000000000000000000"), "00000000000000000000000000000000");
    /** Call method bin_or with 111111111111111111111111111111110 and 000000000000000000000000000000001 and result should throw invalid_argument */
    ASSERT_THROW(math_lib->bin_and("111111111111111111111111111111110","000000000000000000000000000000001"), invalid_argument);
}

TEST_F(Math_lib_test, bin_nand) {
    /** Call method bin_or with 0101 and 0011 and result should by equal to 1110 */
    EXPECT_EQ(math_lib->bin_nand("0101", "0011"), "1110");
    /** Call method bin_or with 10101010 and 01010101 and result should by equal to 11111111 */
    EXPECT_EQ(math_lib->bin_nand("10101010", "01010101"), "11111111");
    /** Call method bin_or with 11111111 and 0000000000 and result should by equal to 1111111111 */
    EXPECT_EQ(math_lib->bin_nand("11111111", "0000000000"), "1111111111");
    /** Call method bin_or with 11111111111111111111111111111111 and 00000000000000000000000000000000 and result should by equal to 11111111111111111111111111111111 */
    EXPECT_EQ(math_lib->bin_nand("11111111111111111111111111111111", "00000000000000000000000000000000"), "11111111111111111111111111111111");
    /** Call method bin_or with 111111111111111111111111111111110 and 000000000000000000000000000000001 and result should throw invalid_argument */
    ASSERT_THROW(math_lib->bin_nand("111111111111111111111111111111110","000000000000000000000000000000001"), invalid_argument);
}

TEST_F(Math_lib_test, bin_xor) {
    /** Call method bin_or with 0101 and 0011 and result should by equal to 0110 */
    EXPECT_EQ(math_lib->bin_xor("0101", "0011"), "0110");
    /** Call method bin_or with 10101010 and 01010101 and result should by equal to 11111111 */
    EXPECT_EQ(math_lib->bin_xor("10101010", "01010101"), "11111111");
    /** Call method bin_or with 11111111 and 0000000000 and result should by equal to 0011111111 */
    EXPECT_EQ(math_lib->bin_xor("11111111", "0000000000"), "0011111111");
    /** Call method bin_or with 11111111111111111111111111111111 and 00000000000000000000000000000000 and result should by equal to 11111111111111111111111111111111 */
    EXPECT_EQ(math_lib->bin_xor("11111111111111111111111111111111", "00000000000000000000000000000000"), "11111111111111111111111111111111");
    /** Call method bin_or with 111111111111111111111111111111110 and 000000000000000000000000000000001 and result should throw invalid_argument */
    ASSERT_THROW(math_lib->bin_xor("111111111111111111111111111111110","000000000000000000000000000000001"), invalid_argument);
}

TEST_F(Math_lib_test, bin_xnor) {
    /** Call method bin_or with 0101 and 0011 and result should by equal to 1001 */
    EXPECT_EQ(math_lib->bin_xnor("0101", "0011"), "1001");
    /** Call method bin_or with 10101010 and 01010101 and result should by equal to 00000000 */
    EXPECT_EQ(math_lib->bin_xnor("10101010", "01010101"), "00000000");
    /** Call method bin_or with 11111111 and 0000000000 and result should by equal to 1100000000 */
    EXPECT_EQ(math_lib->bin_xnor("11111111", "0000000000"), "1100000000");
    /** Call method bin_or with 11111111111111111111111111111111 and 00000000000000000000000000000000 and result should by equal to 00000000000000000000000000000000 */
    EXPECT_EQ(math_lib->bin_xnor("11111111111111111111111111111111", "00000000000000000000000000000000"), "00000000000000000000000000000000");
    /** Call method bin_or with 111111111111111111111111111111110 and 000000000000000000000000000000001 and result should throw invalid_argument */
    ASSERT_THROW(math_lib->bin_xnor("111111111111111111111111111111110","000000000000000000000000000000001"), invalid_argument);
}

TEST_F(Math_lib_test, bin_not) {
    /** Call method bin_or with 01 and result should by equal to 10 */
    EXPECT_EQ(math_lib->bin_not("01"), "10");
    /** Call method bin_or with 10101010 and result should by equal to 01010101 */
    EXPECT_EQ(math_lib->bin_not("10101010"), "01010101");
    /** Call method bin_or with 11111111 and result should by equal to 00000000 */
    EXPECT_EQ(math_lib->bin_not("11111111"), "00000000");
    /** Call method bin_or with 00000000000000000000000000000000 and result should by equal to 11111111111111111111111111111111 */
    EXPECT_EQ(math_lib->bin_not("00000000000000000000000000000000"), "11111111111111111111111111111111");
    /** Call method bin_or with 111111111111111111111111111111110 and result should throw invalid_argument */
    ASSERT_THROW(math_lib->bin_not("111111111111111111111111111111110"), invalid_argument);
}

/**
 * Run all tests.
 * @return Return results of all tests.
 */
int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest( &argc, argv );
    return RUN_ALL_TESTS();
}

/*** End of file math_lib_tests.cpp ***/