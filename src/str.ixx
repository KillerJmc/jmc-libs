export module jmclibs.str;

import "iostream";

export namespace jmc 
{
	/*
		字符串操作
		Since:  1.0
		Author: Jmc
	*/
	class str 
	{
	public:
		/*
			把字符串转为大写
			Params:
				s: 传入字符串
			Returns: 结果字符串
		*/
		static auto to_upper_case(const std::string& s) -> std::string
		{
			auto res(s);
			for (auto& c : res)
			{
				c = std::toupper(c);
			}
			return res;
		}

		/*
			把字符串转为小写
			Params:
				s: 传入字符串
			Returns: 结果字符串
		*/
		static auto to_lower_case(const std::string& s) -> std::string
		{
			auto res(s);
			for (auto& c : res)
			{
				c = std::tolower(c);
			}
			return res;
		}

		/*
			把字符串首字母大写
			Params:
				s: 传入字符串
			Returns: 结果字符串
			Since: 2.0
		*/
		static auto capitalize(const std::string& s) -> std::string
		{
			if (s.empty())
			{
				return s;
			}

			return ((char)std::toupper(s[0])) + s.substr(1, s.size() - 1);
		}
	};
}