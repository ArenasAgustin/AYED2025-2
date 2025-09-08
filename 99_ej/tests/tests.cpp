#include <gtest/gtest.h>
#include "../lists.hpp"

TEST(ListTests, PushAndGetHead)
{
    List<int> list;

    list.push(10);
    EXPECT_EQ(list.getHead(), 10);

    list.push(20);
    EXPECT_EQ(list.getHead(), 20);
}

TEST(ListTests, IsEmpty)
{
    List<int> list;
    EXPECT_TRUE(list.isEmpty());

    list.push(10);
    EXPECT_FALSE(list.isEmpty());
}

TEST(ListTests, GetLength)
{
    List<int> list;
    EXPECT_EQ(list.getLenght(), 0);

    list.push(10);
    EXPECT_EQ(list.getLenght(), 1);

    list.push(20);
    EXPECT_EQ(list.getLenght(), 2);
}

TEST(ListTests, GetTail)
{
    List<int> list;

    list.push(10);
    list.push(20);

    List<int> *tail = list.getTail();

    EXPECT_EQ(tail->getHead(), 10);
    EXPECT_EQ(tail->getLenght(), 1);
}

TEST(ListTests, Get)
{
    List<int> list;

    list.push(10);
    list.push(20);
    list.push(30);

    EXPECT_EQ(list.get(0), 30);
    EXPECT_EQ(list.get(1), 20);
    EXPECT_EQ(list.get(2), 10);
}

TEST(ListTests, Slice)
{
    List<int> list;

    list.push(10); // Lista: [10]
    list.push(20); // Lista: [20, 10]
    list.push(30); // Lista: [30, 20, 10]

    // slice(0, 2) debería devolver índices 0 y 1: [30, 20]
    List<int> *sublist = list.slice(0, 2);

    EXPECT_EQ(sublist->getLenght(), 2);
    EXPECT_EQ(sublist->get(0), 30); // Primer elemento del slice
    EXPECT_EQ(sublist->get(1), 20); // Segundo elemento del slice

    delete sublist;

    // Probar otro slice: índices 1 y 2: [20, 10]
    List<int> *sublist2 = list.slice(1, 3);

    EXPECT_EQ(sublist2->getLenght(), 2);
    EXPECT_EQ(sublist2->get(0), 20); // Primer elemento del slice
    EXPECT_EQ(sublist2->get(1), 10); // Segundo elemento del slice

    delete sublist2;
}