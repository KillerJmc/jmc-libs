export module jmclibs.file;

import jmclibs.exception;
import "iostream";
import "vector";
import "filesystem";
import "fstream";
import "cstring";
import "ranges";

export namespace jmc 
{
	/*
		文件操作
		Since:  1.0
		Author: Jmc
	*/
	class file 
	{
	public:
		/*
			判断文件是否存在
			Params:
				path: 文件路径
			Returns: 文件是否存在
		*/
		static bool exists(const std::string& path) 
		{
			return std::filesystem::exists(path);
		}

		/*
			返回文件的绝对路径
			Params:
				path: 文件/文件夹路径
			Returns: 绝对路径
		*/
		static auto absolute_path(const std::string& path) -> std::string 
		{
			if (!exists(path))
			{
				throw exception::runtime_exception("jmc::file::absolute_path: file doesn't exists!");
			}

			return std::filesystem::absolute(path).string();
		}

		/*
			创建新文件
			Params:
				file_path: 文件路径
			Returns: 是否创建成功
		*/
		static bool create_new_file(const std::string& file_path)
		{
			if (!exists(file_path))
			{
				std::filesystem::path path(file_path);

				auto parent_path = path.parent_path();
				if (!exists(parent_path.string()))
				{
					return std::filesystem::create_directories(parent_path);
				}

				std::ofstream out(file_path);

				bool succeed = out.is_open();
				out.clear();
				out.close();
				return succeed;
			}
			return std::filesystem::is_regular_file(file_path);
		}

		/*
			删除路径
			Params:
				path: 文件路径
			Returns: 是否删除成功
			Since: 2.0
		*/
		static bool delete_path(const std::string& path) 
		{
			return std::filesystem::remove_all(path);
		}

		/*
			递归创建文件夹
			Params:
				dir_path: 文件夹路径
			Retruns: 是否创建成功
		*/
		static bool create_directories(const std::string& dir_path)
		{
			return exists(dir_path) ? std::filesystem::is_directory(dir_path) :
				std::filesystem::create_directories(dir_path);
		}

		/*
			读取文件内容到字符串
			Params:
				path: 文件路径
			Returns: 文件内容
		*/
		static auto read(const std::string& path) -> std::string
		{
			auto lines_v = lines(path);

			if (lines_v.empty())
			{
				return "";
			}

			std::string res = lines_v[0];

			for (int i = 1; i < lines_v.size(); i++)
			{
				res += '\n' + std::move(lines_v[i]);
			}

			return res;
		}

		/*
			读取文件所有行到字符串
			Params:
				path: 文件路径
			Returns: 文件内容
		*/
		static auto lines(const std::string& path) -> std::vector<std::string>
		{
			if (!exists(path))
			{
				throw exception::runtime_exception("jmc::file::lines: file doesn't exists!");
			}

			std::ifstream in(path);

			std::string line;

			std::vector<std::string> res;

			while (std::getline(in, line))
			{
				res.emplace_back(line);
			}

			in.clear();
			in.close();

			return res;
		}

		/*
			读取二进制文件的所有字节到列表中
			Params:
				path: 文件路径
			Returns: 字符列表
		*/
		static auto read_binary(const std::string& path) -> std::vector<char>
		{
			if (!exists(path))
			{
				throw exception::runtime_exception("jmc::file::read_binary: file doesn't exists!");
			}

			std::ifstream in(path, std::ios::binary);

			std::vector<char> res;

			// 指定文件长度为vector容量
			res.reserve(std::filesystem::file_size(path));

			char c;
			while (in.read(&c, 1))
			{
				res.emplace_back(c);
			}

			in.clear();
			in.close();

			return res;
		}

		/*
			将字符串写入文件
			Params:
				s:      要写入的字符串
				path:   文件路径
				append: 是否以追加方式写入
		*/
		static void out(const std::string& s, const std::string& path, bool append = false)
		{
			if (!create_new_file(path))
			{
				throw exception::runtime_exception("jmc::file::out: create file failed!");
			}

			std::ofstream out(path, append ? std::ios::app : std::ios::out);
			out << s;
			out.flush();
			out.clear();
			out.close();
		}

		/*
			将字节序列写入文件
			Params:
				bytes:  要写入的字节序列
				path:   文件路径
				append: 是否以追加方式写入
		*/
		static void out_binary(const std::vector<char> bytes, const std::string& path, bool append = false)
		{

			if (!create_new_file(path))
			{
				throw exception::runtime_exception("jmc::file::out: create file failed!");
			}

			std::ofstream out(path, std::ios::binary | (append ? std::ios::app : std::ios::out));
			for (const auto& byte : bytes)
			{
				out.write(&byte, 1);
			}

			out.flush();
			out.clear();
			out.close();
		}

		/*
			将字节数组写入文件
			Params:
				bytes:  要写入的字节
				path:   文件路径
				append: 是否以追加方式写入
		*/
		static void out_binary(const char* bytes, const std::string& path, bool append = false)
		{
			if (!create_new_file(path))
			{
				throw exception::runtime_exception("jmc::file::out: create file failed!");
			}

			std::ofstream out(path, std::ios::binary | (append ? std::ios::app : std::ios::out));
			out.write(bytes, std::strlen(bytes));

			out.flush();
			out.clear();
			out.close();
		}
	};
}
