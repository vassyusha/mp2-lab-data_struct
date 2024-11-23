#include "tdatastr.h"

#include <gtest.h>

TEST(TStack, can_create_default_stack) {
	ASSERT_NO_THROW(TStack<int> st);
}

TEST(TStack, default_stack_is_empty) {
	TStack<int> st;
	EXPECT_TRUE(st.empty());
}

TEST(TStack, can_create_stack_on_deque) {
	std::deque<int> deq = { 1 };
	ASSERT_NO_THROW(TStack<int> st(deq));
}

TEST(TStack, created_on_deque_stack_is_equal_to_the_deque) {
	std::deque<int> deq = { 1 };
	TStack<int> st(deq);
	EXPECT_EQ(1, st.size());
	EXPECT_EQ(1, st.top());
}

TEST(TStack, can_copy_stack) {
	std::deque<int> deq = { 1 };
	TStack<int> st(deq);
	ASSERT_NO_THROW(TStack<int> st1(st));
}

TEST(TStack,copied_stack_is_equal_to_the_source_one) {
	std::deque<int> deq = { 1 };
	TStack<int> st(deq);
	TStack<int> st1(st);
	EXPECT_EQ(1, st1.size());
	EXPECT_EQ(1, st1.top());
}

TEST(TStack, can_assign_stacks) {
	std::deque<int> deq = { 1 };
	TStack<int> st(deq), st1;
	ASSERT_NO_THROW(st1 = st);
}

TEST(TStack, assigned_stack_is_equal_to_the_source_one) {
	std::deque<int> deq = { 1 };
	TStack<int> st(deq), st1;
	st1 = st;
	EXPECT_EQ(1, st1.size());
	EXPECT_EQ(1, st1.top());
}

TEST(TStack, can_push_element) {
	TStack<int> st;
	ASSERT_NO_THROW(st.push(1));
	EXPECT_FALSE(st.empty());
}

TEST(TStack, can_get_size) {
	TStack<int> st;
	st.push(1);
	EXPECT_EQ(1, st.size());
}

TEST(TStack, cant_get_top_element_from_empty_stack) {
	TStack<int> st;
	ASSERT_ANY_THROW(st.top());
}

TEST(TStack, can_get_top_element) {
	TStack<int> st;
	st.push(1);
	EXPECT_EQ(1, st.top());
}

TEST(TStack, cant_pop_element_from_empty_stack) {
	TStack<int> st;
	ASSERT_ANY_THROW(st.pop());
}

TEST(TStack, can_pop_element) {
	TStack<int> st;
	st.push(1);
	ASSERT_NO_THROW(st.pop());
	EXPECT_TRUE(st.empty());
}