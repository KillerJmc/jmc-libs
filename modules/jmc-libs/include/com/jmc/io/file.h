#include <iostream>
#include <vector>

namespace jmc {
	/*
		文件操作
		Since:  1.0
		Author: Jmc
	*/
	class file {
	public:
		/*
			判断文件是否存在
			Params:
				path: 文件路径
			Returns: 文件是否存在
		*/
		static bool exists(const std::string& path);

		/*
			创建新文件
			Params:
				file_path: 文件路径
			Returns: 是否创建成功
		*/
		static bool create_new_file(const std::string& file_path);

		/*
			递归创建文件夹
			Params:
				dir_path: 文件夹路径
			Retruns: 是否创建成功
		*/
		static bool create_directories(const std::string& dir_path);

		/*
			读取文件内容到字符串
			Params:
				path: 文件路径
			Returns: 文件内容
		*/
		static auto read(const std::string& path)->std::string;

		/*
			读取文件所有行到字符串
			Params:
				path: 文件路径
			Returns: 文件内容
		*/
		static auto lines(const std::string& path)->std::vector<std::string>;

		/*
			读取二进制文件的所有字节到列表中
			Params:
				path: 文件路径
			Returns: 字符列表
		*/
		static auto read_binary(const std::string& path)->std::vector<char>;

		/*
			将字符串写入文件
			Params:
				s:      要写入的字符串
				path:   文件路径
				append: 是否以追加方式写入
		*/
		static void out(const std::string& s, const std::string& path, bool append = false);

		/*
			将字节序列写入文件
			Params:
				bytes:  要写入的字节序列
				path:   文件路径
				append: 是否以追加方式写入
		*/
		static void out_binary(const std::vector<char> bytes, const std::string& path, bool append = false);

		/*
			将字节数组写入文件
			Params:
				bytes:  要写入的字节
				path:   文件路径
				append: 是否以追加方式写入
		*/
		static void out_binary(const char* bytes, const std::string& path, bool append = false);
	};
}
