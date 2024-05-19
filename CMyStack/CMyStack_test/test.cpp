#include "pch.h"
#include <gtest/gtest.h>
#include "../../CMyStack/CMyStack/CMyStack.hpp"
#include <string>

TEST(CMyStackTest, IntStackOperations)
{
    CMyStack<int> stack;
    EXPECT_TRUE(stack.is_empty());

    stack.push(10);
    EXPECT_FALSE(stack.is_empty());
    EXPECT_EQ(stack.top(), 10);

    stack.push(20);
    EXPECT_EQ(stack.top(), 20);

    stack.pop();
    EXPECT_EQ(stack.top(), 10);

    stack.pop();
    EXPECT_TRUE(stack.is_empty());

    EXPECT_THROW(stack.pop(), std::underflow_error);
    EXPECT_THROW(stack.top(), std::underflow_error);
}

TEST(CMyStackTest, StringStackOperations) 
{
    CMyStack<std::string> stack;
    EXPECT_TRUE(stack.is_empty());

    stack.push("Hello");
    EXPECT_FALSE(stack.is_empty());
    EXPECT_EQ(stack.top(), "Hello");

    stack.push("World");
    EXPECT_EQ(stack.top(), "World");

    stack.pop();
    EXPECT_EQ(stack.top(), "Hello");

    stack.pop();
    EXPECT_TRUE(stack.is_empty());

    EXPECT_THROW(stack.pop(), std::underflow_error);
    EXPECT_THROW(stack.top(), std::underflow_error);
}

TEST(CMyStackTest, DoubleStackOperations) 
{
    CMyStack<double> stack;
    EXPECT_TRUE(stack.is_empty());

    stack.push(1.1);
    EXPECT_FALSE(stack.is_empty());
    EXPECT_EQ(stack.top(), 1.1);

    stack.push(2.2);
    EXPECT_EQ(stack.top(), 2.2);

    stack.pop();
    EXPECT_EQ(stack.top(), 1.1);

    stack.pop();
    EXPECT_TRUE(stack.is_empty());

    EXPECT_THROW(stack.pop(), std::underflow_error);
    EXPECT_THROW(stack.top(), std::underflow_error);
}

TEST(CMyStackTest, PushRValue)
{
    CMyStack<std::string> stack;
    std::string str = "Hello";
    stack.push(str);
    EXPECT_EQ(stack.top(), "Hello");

    stack.push(std::string("World"));
    EXPECT_EQ(stack.top(), "World");

    stack.pop();
    EXPECT_EQ(stack.top(), "Hello");

    stack.pop();
    EXPECT_TRUE(stack.is_empty());
}

TEST(CMyStackTest, CopyConstructorAndAssignment) 
{
    CMyStack<int> stack1;
    stack1.push(10);
    stack1.push(20);

    CMyStack<int> stack2(stack1);
    EXPECT_EQ(stack2.top(), 20);
    stack2.pop();
    EXPECT_EQ(stack2.top(), 10);

    CMyStack<int> stack3;
    stack3 = stack1;
    EXPECT_EQ(stack3.top(), 20);
    stack3.pop();
    EXPECT_EQ(stack3.top(), 10);
}

TEST(CMyStackTest, MoveConstructorAndAssignment)
{
    CMyStack<int> stack1;
    stack1.push(10);
    stack1.push(20);

    CMyStack<int> stack2(std::move(stack1)); 
    EXPECT_EQ(stack2.top(), 20);
    stack2.pop();
    EXPECT_EQ(stack2.top(), 10);

    CMyStack<int> stack3;
    stack3 = CMyStack<int>();
    stack3 = std::move(stack2);
    EXPECT_EQ(stack3.top(), 10);
    stack3.pop();
    EXPECT_TRUE(stack3.is_empty());
}
