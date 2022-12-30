#include <iostream>
#include <jmc-libs/str.h>

namespace jmc
{
	auto str::to_upper_case(const std::string& s) -> std::string
	{
		auto res(s);
		for (auto& c : res)
		{
			c = std::toupper(c);
		}
		return res;
	}

	auto str::to_lower_case(const std::string& s) -> std::string
	{
		auto res(s);
		for (auto& c : res)
		{
			c = std::tolower(c);
		}
		return res;
	}

	auto str::capitalize(const std::string& s) -> std::string
	{
		if (s.empty())
		{
			return s;
		}

		return ((char) std::toupper(s[0])) + s.substr(1, s.size() - 1);
	}
}
