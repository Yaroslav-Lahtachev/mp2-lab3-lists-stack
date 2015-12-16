#include "gtest.h"
#include "stack.h"

TEST(Stack, can_create_stack)
{
	Stack<int> *stack;
	ASSERT_NO_THROW(stack=new Stack<int>());
}
TEST(Stack, can_create_copied_stack)
{
	Stack<int> s1;
	s1.push(3);
	s1.push(2);
	ASSERT_NO_THROW(Stack<int> s2(s1));
}
TEST(Stack, copied_stack_is_equal_to_sourse_one)
{
	Stack<int> s1;
	s1.push(3);
	Stack<int> s2(s1);
	EXPECT_EQ(s1.printS(), s2.printS());
}
TEST(Stack, copied_stack_has_its_own_memory)
{
	Stack<int> stack;
	stack.push(1);
	Stack<int> stack1(stack);
	stack1.pop();
	stack1.push(2);
	EXPECT_NE(stack.printS(), stack1.printS());
}
TEST(Stack, can_pop)
{
	Stack<int> s;
	s.push(1);
	ASSERT_NO_THROW(s.pop());
}
TEST(Stack, pop_element)
{
	Stack<int> stack;
	stack.push(1);
	EXPECT_EQ(1, stack.pop());
}
TEST(Stack, IsEmpty_return_1_when_empty)
{
	Stack<int> stack;
	EXPECT_EQ(1, stack.isEmpty());
}
TEST(Stack, IsEmpty_return_0_when_not_empty)
{
	Stack<int> stack;
	stack.push(1);
	EXPECT_EQ(0, stack.isEmpty());
}
TEST(Stack, IsFull_returns_0_when_not_full)
{
	Stack<int> stack;
	stack.push(1);
	EXPECT_EQ(0, stack.isFull());
}
TEST(Stack, can_push_elem)
{
	Stack<int> stack;
	ASSERT_NO_THROW(stack.push(1));
}
TEST(Stack, can_not_print_elem_form_empty_stack)
{
	Stack<int> stack;
	ASSERT_ANY_THROW(stack.printS());
}
TEST(Stack, can_print_elem)
{
	Stack<int> stack;
	stack.push(1);
	ASSERT_NO_THROW(stack.printS());
}
