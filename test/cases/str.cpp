#include <iostream>
#include <jmc-libs/all.h>
#include <gtest/gtest.h>

using std::cout, std::endl;

TEST(StrTest, test)
{
	std::string s = "jmcA";
	
	// 首字母大写
	ASSERT_EQ(jmc::str::capitalize(s), "JmcA");

	// 字符串全部大写
	ASSERT_EQ(jmc::str::to_upper_case(s), "JMCA");

	// 字符串全部小写
	ASSERT_EQ(jmc::str::to_lower_case(s), "jmca");
}