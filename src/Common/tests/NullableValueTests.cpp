#include <gtest/gtest.h>

#include "Common/NullableValue.h"

using com::common::NullableValue;

class NullableValueTests : public ::testing::Test {
};

TEST_F(NullableValueTests, GetEmpty)
{
    NullableValue<int> val;
    int value;
    auto res = val.getValue(value);
    ASSERT_FALSE(res);
}

TEST_F(NullableValueTests, GetSetRValue)
{
    NullableValue<int> val;
    int value;
    val.setValue(56);
    auto res = val.getValue(value);
    ASSERT_TRUE(res);
    ASSERT_EQ(value, 56);
}

TEST_F(NullableValueTests, GetSetLValue)
{
    NullableValue<int> val;
    int value;
    int putVal = 34;
    val.setValue(putVal);
    auto res = val.getValue(value);
    ASSERT_TRUE(res);
    ASSERT_EQ(value, putVal);
}

TEST_F(NullableValueTests, DoubleSetValue)
{
    NullableValue<int> val;
    int value;
    int putVal = 34;
    val.setValue(12);
    val.setValue(putVal);
    auto res = val.getValue(value);
    ASSERT_TRUE(res);
    ASSERT_EQ(value, putVal);
}
