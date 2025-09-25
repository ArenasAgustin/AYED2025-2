#include <gtest/gtest.h>
#include "../lists.hpp"

// Pruebas para la clase Queue
TEST(QueueTests, EnqueueAndGetHead)
{
    Queue<int> queue;

    queue.enqueue(10);
    EXPECT_EQ(queue.getHead(), 10);

    queue.enqueue(20);
    EXPECT_EQ(queue.getHead(), 10); // En queue, el head sigue siendo el primero

    queue.enqueue(30);
    EXPECT_EQ(queue.getHead(), 10); // El primero en entrar sigue siendo el primero
}

TEST(QueueTests, Dequeue)
{
    Queue<int> queue;

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    EXPECT_EQ(queue.getHead(), 10);
    EXPECT_EQ(queue.getLenght(), 3);

    queue.dequeue(0); // Elimina el primer elemento (10)
    EXPECT_EQ(queue.getHead(), 20);
    EXPECT_EQ(queue.getLenght(), 2);

    queue.dequeue(0); // Elimina el primer elemento (20)
    EXPECT_EQ(queue.getHead(), 30);
    EXPECT_EQ(queue.getLenght(), 1);

    queue.dequeue(0); // Elimina el último elemento (30)
    EXPECT_TRUE(queue.isEmpty());
    EXPECT_EQ(queue.getLenght(), 0);
}

TEST(QueueTests, IsEmpty)
{
    Queue<int> queue;
    EXPECT_TRUE(queue.isEmpty());

    queue.enqueue(10);
    EXPECT_FALSE(queue.isEmpty());

    queue.dequeue(0);
    EXPECT_TRUE(queue.isEmpty());
}

TEST(QueueTests, GetLength)
{
    Queue<int> queue;
    EXPECT_EQ(queue.getLenght(), 0);

    queue.enqueue(10);
    EXPECT_EQ(queue.getLenght(), 1);

    queue.enqueue(20);
    EXPECT_EQ(queue.getLenght(), 2);

    queue.enqueue(30);
    EXPECT_EQ(queue.getLenght(), 3);

    queue.dequeue(0);
    EXPECT_EQ(queue.getLenght(), 2);
}