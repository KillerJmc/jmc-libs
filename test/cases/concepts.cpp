#include <gtest/gtest.h>

import "iostream";
import jmclibs.concepts;

using std::cout, std::endl;

// 限制参数类型必须为指针
template <jmc::concepts::is_pointer Ptr>
auto get_value(Ptr p)
{
	return *p;
}

// 限制参数类型必须为迭代器
template <jmc::concepts::is_iterator Iter>
auto get_first(Iter iter)
{
	return *iter;
}

// 限制参数类型必须为int或者long
template <jmc::concepts::is_any_of<int, long> T>
T check_int_or_long(T t)
{
	return t;
}

// 限制参数类型必须为数字或者小数
template <jmc::concepts::is_num T>
T check_num(T t)
{
	return t;
}


TEST(ConceptTest, test)
{
	int a = 666;
	ASSERT_EQ(get_value(&a), 666);

	std::vector v = { 1, 2, 3 };
	ASSERT_EQ(get_first(v.begin()), 1);

	ASSERT_EQ(check_int_or_long(123), 123);
	ASSERT_EQ(check_int_or_long(123L), 123L);

	ASSERT_EQ(check_num(1), 1);
}
