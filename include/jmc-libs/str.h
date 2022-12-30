#pragma once

#include <iostream>

namespace jmc 
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
		static auto to_upper_case(const std::string& s) -> std::string;

		/*
			把字符串转为小写
			Params:
				s: 传入字符串
			Returns: 结果字符串
		*/
		static auto to_lower_case(const std::string& s) -> std::string;

		/*
			把字符串首字母大写
			Params:
				s: 传入字符串
			Returns: 结果字符串
			Since: 2.0
		*/
		static auto capitalize(const std::string& s) -> std::string;
	};
}