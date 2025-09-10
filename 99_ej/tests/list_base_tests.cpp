#include <gtest/gtest.h>
#include "../list_base.hpp"

// Pruebas para la clase base ListBase
TEST(ListBaseTests, PushAndGetHead)
{
    ListBase<int> listBase;

    listBase.push(10);
    EXPECT_EQ(listBase.getHead(), 10);

    listBase.push(20);
    EXPECT_EQ(listBase.getHead(), 20);
}

TEST(ListBaseTests, IsEmpty)
{
    ListBase<int> listBase;
    EXPECT_TRUE(listBase.isEmpty());

    listBase.push(10);
    EXPECT_FALSE(listBase.isEmpty());
}

TEST(ListBaseTests, GetLength)
{
    ListBase<int> listBase;
    EXPECT_EQ(listBase.getLenght(), 0);

    listBase.push(10);
    EXPECT_EQ(listBase.getLenght(), 1);

    listBase.push(20);
    EXPECT_EQ(listBase.getLenght(), 2);
}
