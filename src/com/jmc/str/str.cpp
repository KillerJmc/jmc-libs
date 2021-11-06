#include <iostream>
#include <str.h>

namespace jmc {
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
}
