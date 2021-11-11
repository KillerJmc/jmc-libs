#include <filesystem>
#include <fstream>
#include <file.h>
#include <exception.h>

namespace jmc 
{
	bool file::exists(const std::string& path)
	{
		return std::filesystem::exists(path);
	}

	auto file::absolute_path(const std::string& path) -> std::string
	{
		if (!exists(path))
		{
			throw exception::runtime_exception("jmc::file::absolute_path: file doesn't exists!");
		}

		return std::filesystem::absolute(path).string();
	}

	bool file::create_new_file(const std::string& file_path)
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

	bool file::create_directories(const std::string& dir_path)
	{
		return exists(dir_path) ? std::filesystem::is_directory(dir_path) :
			std::filesystem::create_directories(dir_path);
	}

	auto file::read(const std::string& path) -> std::string
	{
		std::string res;
		for (const auto& line : lines(path))
		{
			res += line + '\n';
		}
		return res;
	}

	auto file::lines(const std::string& path) -> std::vector<std::string>
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

	auto file::read_binary(const std::string& path) -> std::vector<char>
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

	void file::out(const std::string& s, const std::string& path, bool append)
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

	void file::out_binary(const std::vector<char> bytes, const std::string& path, bool append)
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

	void file::out_binary(const char* bytes, const std::string& path, bool append)
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
}

