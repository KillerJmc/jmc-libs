#pragma once

#include <iostream>
#include <string>
#include <format>
#include <functional>
#include <concepts.hpp>
#include <exception.h>

namespace jmc 
{
	/*
		数组操作类
		Since:  1.0
		Author: Jmc
	*/
	class container 
	{
	public:
		/*
			把容器转化为字符串
			Params: 
				begin: 初始迭代器或数组头指针
				end:   结束迭代器或数组尾指针
			Returns: 结果字符串
		*/
		template <concepts::is_iterator _Ptr_Or_Interator>
		static std::string to_string(const _Ptr_Or_Interator begin,
			                         const _Ptr_Or_Interator end,
			                         const std::function<std::string(const decltype(*begin)&)>& to_string_func = nullptr)
		{
			if (begin == end)
			{
				return "[]";
			}

			std::string res = "[ ";
			for (auto it = begin; it != end; it++)
			{
				to_string_func ? res += to_string_func(*it) : res += transfer(*it);

				if (it != end - 1)
				{
					res += ", ";
				}
			}

			return res += " ]";
		}

		/*
			把容器转化为字符串
			Params:
				container: 具有开始和结束迭代器的容器
			Returns: 结果字符串
		*/
		template <typename _Container>
		static std::string to_string(const _Container& c,
			                         const std::function<std::string(const decltype(*c.begin())&)>& to_string_func = nullptr)
			requires requires { c.begin(); c.end(); }
		{
			return to_string(c.begin(), c.end(), to_string_func);
		}

	private:
		/*
 			把数字转化为字符串
			Params: 
				num: 数字
			Returns: 结果字符串
		*/
		static auto transfer(const concepts::is_num auto& num) -> std::string
		{
			return std::to_string(num);
		}

		/*
			把布尔值转化为字符串
			Params: 
				b: 布尔值
			Returns: 结果字符串
		*/
		static auto transfer(const bool& b) -> std::string
		{
			return b ? "true" : "false";
		}

		/*
			字符串类型不转换，直接返回本身 
			Params:
				s: 字符串
			Returns: 自身
		*/
		template <concepts::is_any_of<char, const char*, std::string> _Char_Sequence>
		static auto transfer(const _Char_Sequence& s) -> const _Char_Sequence&
		{ 
			return s;
		}

		/*
			复杂类型且没有传入to_string函数的，就抛出异常
			Params: 
				e: 其他类型
		*/
		static auto transfer(const auto& e) -> std::string
		{
			throw exception::runtime_exception(std::format(
				"jmc::array::to_string: complicated type \"{}\" without passing \"to_string_func\" parameter."
					, typeid(decltype(e)).name()
			));
		}
	};
}