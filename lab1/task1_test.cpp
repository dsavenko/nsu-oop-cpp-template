
#include "task1.h"
#include "gtest/gtest.h"

namespace {

// TODO: переименовать тесты, написать реализации
TEST(TaskTest, plus) {
    using task::plus;

    EXPECT_EQ(plus(2, 3), 5);
}

}