#include <gtest/gtest.h>
#include "../lists.hpp"

// Pruebas para la estructura Node
TEST(NodeTests, Constructor)
{
    Node<int> node(42);
    
    EXPECT_EQ(node.value, 42);
    EXPECT_EQ(node.next, nullptr);
}

TEST(NodeTests, Linking)
{
    Node<int> *node1 = new Node<int>(10);
    Node<int> *node2 = new Node<int>(20);
    
    node1->next = node2;
    
    EXPECT_EQ(node1->value, 10);
    EXPECT_EQ(node1->next, node2);
    EXPECT_EQ(node2->value, 20);
    EXPECT_EQ(node2->next, nullptr);
    
    delete node1;
    delete node2;
}
