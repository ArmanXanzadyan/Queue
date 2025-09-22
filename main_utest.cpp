#include "gtest/gtest.h"
#include "headers/Queue.hpp"

TEST(QueueTest, DefaultConstructor)
{
    Queue<int> q;
    EXPECT_TRUE(q.empty());
    EXPECT_EQ(q.size(), 0u);
}

TEST(QueueTest, PushAndTop)
{
    Queue<int> q;
    q.push(10);
    EXPECT_FALSE(q.empty());
    EXPECT_EQ(q.top(), 10);
    EXPECT_EQ(q.size(), 1u);

    q.push(20);
    EXPECT_EQ(q.top(), 10);
    EXPECT_EQ(q.size(), 2u);
}

TEST(QueueTest, Pop)
{
    Queue<int> q;
    q.push(5);
    q.push(15);
    q.pop();
    EXPECT_EQ(q.top(), 15);
    EXPECT_EQ(q.size(), 1u);
}

TEST(QueueTest, CopyConstructor)
{
    Queue<int> q1;
    q1.push(42);
    Queue<int> q2(q1);
    EXPECT_EQ(q2.top(), 42);
    EXPECT_EQ(q2.size(), 1u);
    EXPECT_FALSE(q2.empty());
}

TEST(QueueTest, AssignmentOperator)
{
    Queue<int> q1;
    q1.push(7);
    Queue<int> q2;
    q2 = q1;
    EXPECT_EQ(q2.top(), 7);
    EXPECT_EQ(q2.size(), 1u);
}

TEST(QueueTest, EqualityOperators)
{
    Queue<int> q1;
    Queue<int> q2;
    EXPECT_TRUE(q1 == q2);

    q1.push(1);
    EXPECT_TRUE(q1 != q2);

    q2.push(1);
    EXPECT_TRUE(q1 == q2);
}

TEST(QueueTest, RelationalOperators)
{
    Queue<int> q1;
    Queue<int> q2;

    q1.push(1);
    q1.push(2);

    q2.push(1);
    q2.push(3);

    EXPECT_TRUE(q1 < q2);
    EXPECT_TRUE(q2 > q1);
    EXPECT_TRUE(q1 <= q2);
    EXPECT_TRUE(q2 >= q1);
}

TEST(QueueTest, ConstTop)
{
    Queue<int> q;
    q.push(99);
    const Queue<int>& cq = q;
    EXPECT_EQ(cq.top(), 99);
}

int
main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

