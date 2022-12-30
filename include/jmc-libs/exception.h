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
		private:
			std::string _message;

		public:
			explicit runtime_exception(const std::string& message) : _message(message) {
				// 初始化时打印异常信息
				std::cout << message << std::endl;
			}

			const char* what() const noexcept override {
				return _message.c_str();
			}
		};
	}
}

