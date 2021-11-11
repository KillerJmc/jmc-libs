#pragma once

#include <iostream>

namespace jmc 
{
	/*
		异常
		Since:  1.0
		Author: Jmc
	*/
	namespace exception 
	{
		/*
			运行时异常
		*/
		class runtime_exception : public std::exception
		{
		public:
			explicit runtime_exception(const std::string& _Message) : std::exception(_Message.c_str()) {
				// 初始化时打印异常信息
				std::cout << _Message << std::endl;
			}
		};
	}
}

