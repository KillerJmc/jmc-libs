#include <gtest/gtest.h>

import "iostream";
import jmclibs.file;

using std::cout, std::endl;

TEST(FileTest, test)
{
	// 文件名
	auto file_name = "a.txt";

	// 获取全路径
	auto absolute_path = jmc::file::absolute_path(".");
	auto file_path = absolute_path + "/" + "a.txt";

	// 判断文件是否存在
	if (jmc::file::exists(file_path))
	{
		// 删除文件
		ASSERT_EQ(jmc::file::delete_path(file_path), true);
	}

	// 创建文件
	jmc::file::create_new_file(file_path);

	ASSERT_EQ(jmc::file::exists(file_name), true);

	// 将字符串填入文件
	jmc::file::out("Hello", file_path);

	// 从文件中读取内容
	ASSERT_EQ(jmc::file::read(file_path), "Hello");

	// 将字符串填入文件，并且标明以追加方式写入
	jmc::file::out("\nWorld", file_path, true);

	// 获取文件里面的所有行
	for (const auto& line : jmc::file::lines(file_path))
	{
		cout << line << endl;
	}
}
