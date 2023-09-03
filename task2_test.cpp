
#include "task2.h"
#include "gtest/gtest.h"

namespace {

// TODO: переименовать тесты, написать реализации
TEST(TaskTest, say_hello) {
    using task::say_hello;

    EXPECT_EQ(say_hello("world"), "Hello, world!");
}

}