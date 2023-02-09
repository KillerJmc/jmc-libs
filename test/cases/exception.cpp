#include <gtest/gtest.h>

import "iostream";
import jmclibs.exception;

using std::cout, std::endl;

TEST(ExceptionTest, test)
{
	try
	{
		// 在初始化的时候就会直接打印出异常的信息
		throw jmc::exception::runtime_exception("e!");
	}
	catch (std::exception& e)
	{
		ASSERT_EQ(std::string(e.what()), "e!");
	}
}
