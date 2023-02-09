#include "gtest/gtest.h"

import "iostream";
import jmclibs.container;

using std::cout, std::endl;

TEST(ContainerTest, testArray)
{
	int a[] = { 1, 2, 3, 4, 5, 6 };

	// pass array ptr
	auto res = jmc::container::to_string(a, a + 6);
	ASSERT_EQ(res, "[ 1, 2, 3, 4, 5, 6 ]");
}

TEST(ContainerTest, testSimple)
{
	std::vector v = { 1, 2, 3 };

	// pass vec iterator
	auto res = jmc::container::to_string(v.begin(), v.end());
	ASSERT_EQ(res, "[ 1, 2, 3 ]");

	// pass vec itself
	res = jmc::container::to_string(v);
	ASSERT_EQ(res, "[ 1, 2, 3 ]");
}

TEST(ContainerTest, testBasicTypes)
{
	// const char* type
	std::vector v3 = { "aaa", "bbb", "ccc" };
	auto res = jmc::container::to_string(v3);
	ASSERT_EQ(res, "[ aaa, bbb, ccc ]");

	// bool type
	std::vector<bool> v6 = { true, false, true };
	res = jmc::container::to_string(v6);
	ASSERT_EQ(res, "[ true, false, true ]");
}

TEST(ContainerTest, testObjTypes)
{
	// std::string type
	std::vector<std::string> v4 = { "ddd", "eee", "fff" };
	auto res = jmc::container::to_string(v4);
	ASSERT_EQ(res, "[ ddd, eee, fff ]");

	// complicated type
	std::vector<std::pair<int, int>> v7 = { { 1, 2 }, { 3, 4 }, { 5, 6 } };
	// need to pass a to_string function
	res = jmc::container::to_string(v7, [](const auto& p) {
		return std::to_string(p.first) + " -> " + std::to_string(p.second);
	});

	ASSERT_EQ(res, "[ 1 -> 2, 3 -> 4, 5 -> 6 ]");
}







