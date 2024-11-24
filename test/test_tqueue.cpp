#include "tdatastr.h"

#include <gtest.h>

TEST(TQueue, can_create_default_queue) {
	ASSERT_NO_THROW(TQueue<int> q);
}

TEST(TQueue, default_queue_is_empty) {
	TQueue<int> q;
	EXPECT_TRUE(q.empty());
}

TEST(TQueue, can_get_size) {
	TQueue<int> q;
	q.push(1);
	EXPECT_EQ(1, q.size());
}

TEST(TQueue, can_push_one_element) {
	TQueue<int> q;
	ASSERT_NO_THROW(q.push(1));
	EXPECT_FALSE(q.empty());
}

TEST(TQueue, can_push_several_elements) {
	TQueue<int> q;
	q.push(1);
	ASSERT_NO_THROW(q.push(2));
}

TEST(TQueue, cant_get_front_element_from_an_empty_queue) {
	TQueue<int> q;
	ASSERT_ANY_THROW(q.front());
}

TEST(TQueue, can_get_front_element) {
	TQueue<int> q;
	q.push(1);
	ASSERT_NO_THROW(q.front());
	EXPECT_EQ(1, q.front());
}

TEST(TQueue, cant_pop_element_from_an_empty_queue) {
	TQueue<int> q;
	ASSERT_ANY_THROW(q.pop());
}

TEST(TQueue, can_pop_element) {
	TQueue<int> q;
	q.push(1);
	ASSERT_NO_THROW(q.pop());
	EXPECT_TRUE(q.empty());
}

TEST(TQueue, can_push_element_after_popping_from_queue) {
	TQueue<int> q;
	q.push(1);
	q.pop();
	ASSERT_NO_THROW(q.push(1));
}

TEST(TQueue, can_copy_queue) {
	TQueue<int> q;
	q.push(1);
	ASSERT_NO_THROW(TQueue<int> q1(q));
}

TEST(TQueue, copied_queue_is_equal_to_the_source_one) {
	TQueue<int> q;
	q.push(1);
	TQueue<int> q1(q);
	EXPECT_EQ(1, q1.size());
	EXPECT_EQ(1, q1.front());
}

TEST(TQueue, can_assign_queues) {
	TQueue<int> q, q1;
	q.push(1);
	ASSERT_NO_THROW(q1 = q);
}

TEST(TQueue, assigned_queue_is_equal_to_the_source_one) {
	TQueue<int> q, q1;
	q.push(1);
	q1 = q;
	EXPECT_EQ(1, q1.size());
	EXPECT_EQ(1, q.front());
}