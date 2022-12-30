#include <iostream>
#include <jmc-libs/all.h>
#include <gtest/gtest.h>

using std::cin, std::cout, std::endl;

TEST(RandTest, test)
{
	// 生成一个[1, 10]之间的随机整数
	int rand_int = jmc::rand::next_int(1, 10);
	ASSERT_TRUE(rand_int >= 1 && rand_int <= 10);
}