#include <gtest/gtest.h>
#include "dummy.hpp"

TEST(DummyTest, ReturnsHelloString) {
    EXPECT_EQ(getHello(), "Hello");
}