#include <iostream>

namespace jmc {
	namespace exception {
		/*
			����ʱ�쳣
			Since:  1.0
			Author: Jmc
		*/
		class runtime_exception : public std::exception
		{
		public:
			explicit runtime_exception(const std::string& _Message) : std::exception(_Message.c_str()) {
				// ��ʼ��ʱ��ӡ�쳣��Ϣ
				std::cout << _Message << std::endl;
			}
		};
	}
}

