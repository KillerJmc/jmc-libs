export module jmclibs.concepts;

import "iostream";
import "algorithm";

export namespace jmc
{
	/*
		常用概念
		Since:  1.0
		Author: Jmc
	*/
	namespace concepts
	{
		/*
			判断一个类型是否为指针
			params:
				T: 一个类型
		*/
		template <typename T>
		concept is_pointer = std::is_pointer_v<T>;

		/*
			判断一个类型是否为迭代器
			params:
				T: 一个类型
		*/
		template <typename T>
		concept is_iterator = std::_Is_iterator_v<T>;

		/*
			判断一个类型是否能匹配其他多个类型中的任意一个
			params:
				_Ty: 一个类型
				_Types: 其他多个类型
		*/
		template <typename _Ty, typename... _Types>
		concept is_any_of = std::_Is_any_of_v<_Ty, _Types...>;

		/*
			判断是否为数字类型（包括整数和小数）
			params: 
				T: 被判断的类型
		*/
		template <typename T>
		concept is_num = is_any_of<T, 
			int, long, float, double, 
			long long, long double, 
			unsigned int, unsigned long, unsigned long long
		>;
	}
}