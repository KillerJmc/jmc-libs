#include <iostream>

namespace jmc {
	/*
		�ַ�������
		Since:  1.0
		Author: Jmc
	*/
	class str {
	public:
		/*
			���ַ���תΪ��д
			Params:
				s: �����ַ���
			Returns: ����ַ���
		*/
		static auto to_upper_case(const std::string& s)->std::string;

		/*
			���ַ���תΪСд
			Params:
				s: �����ַ���
			Returns: ����ַ���
		*/
		static auto to_lower_case(const std::string& s)->std::string;
	};
}