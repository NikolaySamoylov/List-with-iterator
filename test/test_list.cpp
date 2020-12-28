#include "list.h"
#include <gtest.h>

TEST(Iterator, can_create_iterator)
{
  ASSERT_NO_THROW(List<int>::Iterator i);
}

TEST(Iterator, can_copy_iterator)
{
	List<int>::Iterator i1, i2(i1);

	EXPECT_TRUE(i1 == i2);
}

TEST(Iterator, increment_can_be_used)
{
	List<int> l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	List<int>::Iterator i1(l.get_first());
	++i1;
	List<int>::Iterator i2(i1++);

	EXPECT_EQ(i1->data, 3);
	EXPECT_EQ(i2->data, 2);
}

TEST(Iterator, operator_equal_is_correct)
{
	List<int> l;
	l.push_back(1);
	List<int>::Iterator i1(l.get_first());
	List<int>::Iterator i2(i1);

	EXPECT_EQ(i2 == i1, true);
}
TEST(Iterator, operator_not_equal_is_correct)
{
	List<int> l;
	l.push_back(1);
	l.push_back(2);
	List<int>::Iterator i1(l.get_first());
	List<int>::Iterator i2(i1++);

	EXPECT_EQ(i2 != i1, true);
}

TEST(List, can_create_list)
{
	ASSERT_NO_THROW(List<int> l);
}

TEST(List, can_copy_list)
{
	List<int> l1;

	ASSERT_NO_THROW(List<int> l2(l1));
}

TEST(List, can_push_front)
{
	List<int> l;

	ASSERT_NO_THROW(l.push_front(1));
}

TEST(List, can_pop_front)
{
	List<int> l;
	l.push_front(1);
	l.push_front(2);

	ASSERT_NO_THROW(l.pop_front());
}

TEST(List, can_push_back)
{
	List<int> l;

	ASSERT_NO_THROW(l.push_back(1));
}

TEST(List, can_pop_back)
{
	List<int> l;

	l.push_back(1);
	l.push_back(2);

	ASSERT_NO_THROW(l.pop_back());
}

TEST(List, list_is_empty)
{
	List<int> l;

	EXPECT_TRUE(l.empty());
}

TEST(List, list_is_not_empty)
{
	List<int> l;
	l.push_front(1);

	EXPECT_FALSE(l.empty());
}

TEST(List, can_return_size)
{
	List<int> l;
	l.push_front(3);
	l.push_front(2);
	l.push_front(1);

	EXPECT_EQ(3, l.get_size());
}

TEST(List, can_insert)
{
	List<int> l;
	l.push_front(4);
	l.push_front(3);
	l.push_front(2);

	ASSERT_NO_THROW(l.insert(l.get_first(), 1));
}

TEST(List, can_erase)
{
	List<int> l;
	l.push_front(3);
	l.push_front(2);
	l.push_front(1);

	ASSERT_NO_THROW(l.erase(l.get_first()));
}