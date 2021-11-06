#include <iostream>
#include <vector>

namespace jmc {
	/*
		�ļ�����
		Since:  1.0
		Author: Jmc
	*/
	class file {
	public:
		/*
			�ж��ļ��Ƿ����
			Params:
				path: �ļ�·��
			Returns: �ļ��Ƿ����
		*/
		static bool exists(const std::string& path);

		/*
			�������ļ�
			Params:
				file_path: �ļ�·��
			Returns: �Ƿ񴴽��ɹ�
		*/
		static bool create_new_file(const std::string& file_path);

		/*
			�ݹ鴴���ļ���
			Params:
				dir_path: �ļ���·��
			Retruns: �Ƿ񴴽��ɹ�
		*/
		static bool create_directories(const std::string& dir_path);

		/*
			��ȡ�ļ����ݵ��ַ���
			Params:
				path: �ļ�·��
			Returns: �ļ�����
		*/
		static auto read(const std::string& path)->std::string;

		/*
			��ȡ�ļ������е��ַ���
			Params:
				path: �ļ�·��
			Returns: �ļ�����
		*/
		static auto lines(const std::string& path)->std::vector<std::string>;

		/*
			��ȡ�������ļ��������ֽڵ��б���
			Params:
				path: �ļ�·��
			Returns: �ַ��б�
		*/
		static auto read_binary(const std::string& path)->std::vector<char>;

		/*
			���ַ���д���ļ�
			Params:
				s:      Ҫд����ַ���
				path:   �ļ�·��
				append: �Ƿ���׷�ӷ�ʽд��
		*/
		static void out(const std::string& s, const std::string& path, bool append = false);

		/*
			���ֽ�����д���ļ�
			Params:
				bytes:  Ҫд����ֽ�����
				path:   �ļ�·��
				append: �Ƿ���׷�ӷ�ʽд��
		*/
		static void out_binary(const std::vector<char> bytes, const std::string& path, bool append = false);

		/*
			���ֽ�����д���ļ�
			Params:
				bytes:  Ҫд����ֽ�
				path:   �ļ�·��
				append: �Ƿ���׷�ӷ�ʽд��
		*/
		static void out_binary(const char* bytes, const std::string& path, bool append = false);
	};
}
