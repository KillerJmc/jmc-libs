#pragma once

#include <iostream>

namespace jmc
{
	/*
		计时器
		Since:  1.0
		Author: Jmc
	*/
	class timer
	{
	public:
		/*
			毫秒计时器
			Params:
				f: 	需要计时的代码块
				print_result: 打印结果
			Returns: 执行代码块流逝的毫秒值
		*/
		template <typename _Func>
		static long milli_timer(_Func f, bool print_result = false)
		{
			auto start = std::clock();
			f();
			auto time = std::clock() - start;

			if (print_result)
			{
				printf("The running time is %ld ms.\n", time);
			}
			return time;
		}
	};
}