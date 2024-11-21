#include "tdatastr.h"

#include <gtest.h>

TEST(TStack, can_create_default_stack) {
	ASSERT_NO_THROW(TStack<int> st);
}

TEST(TStack, default_stack_is_empty) {
	TStack<int> st;
	EXPECT_TRUE(st.empty());
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