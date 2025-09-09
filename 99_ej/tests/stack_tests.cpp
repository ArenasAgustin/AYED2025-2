#include <gtest/gtest.h>
#include "../lists.hpp"

// Pruebas para la clase Stack
TEST(StackTests, PushAndTop)
{
    Stack<int> stack;

    stack.push(10);
    EXPECT_EQ(stack.top(), 10);

    stack.push(20);
    EXPECT_EQ(stack.top(), 20);
}

TEST(StackTests, Pop)
{
    Stack<int> stack;

    stack.push(10);
    stack.push(20);
    EXPECT_EQ(stack.top(), 20);
    EXPECT_EQ(stack.getLenght(), 2);

    stack.pop(0); // Elimina el tope (20)
    EXPECT_EQ(stack.top(), 10);
    EXPECT_EQ(stack.getLenght(), 1);

    stack.pop(0); // Elimina el tope (10)
    EXPECT_TRUE(stack.isEmpty());
    EXPECT_EQ(stack.getLenght(), 0);
}

TEST(StackTests, IsEmpty)
{
    Stack<int> stack;
    EXPECT_TRUE(stack.isEmpty());

    stack.push(10);
    EXPECT_FALSE(stack.isEmpty());
}

TEST(StackTests, GetLength)
{
    Stack<int> stack;
    EXPECT_EQ(stack.getLenght(), 0);

    stack.push(10);
    EXPECT_EQ(stack.getLenght(), 1);

    stack.push(20);
    EXPECT_EQ(stack.getLenght(), 2);
}
