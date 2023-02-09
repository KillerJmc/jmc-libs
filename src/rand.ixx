export module jmclibs.rand;

import jmclibs.exception;
import "iostream";
import "mutex";
import "ctime";

namespace jmc 
{
	// Modified by GinShio in 2022.12.20
	// Add thread safe
	namespace
	{
		::std::once_flag inited;
	}

	/*
		随机数类
		Since: 1.0
		Author: Jmc
	*/
	export class rand
	{
	private:
		/*
			初始化随机数种子
		*/
		static void init_seed()
		{
			// Modified by GinShio in 2022.12.20
			// Add thread safe
			::std::call_once(inited, []() { ::srand(static_cast<unsigned int>(::_time64(nullptr))); });
		}

	public:
		/*
			获取一个随机数
			Params:
				min_inclusive：最小值（包含）
				max_inclusive：最大值（包含）
			Returns: 满足条件的随机数
		*/
		static int next_int(int min_inclusive, int max_inclusive)
		{
			init_seed();

			if (min_inclusive < 0 || max_inclusive < 0 || max_inclusive < min_inclusive) {
				throw exception::runtime_exception("jmc::rand::next_int: illegal arguments");
			}

			return std::rand() % (max_inclusive - min_inclusive + 1) + min_inclusive;
		}

		/*
			获取一个随机数，最小值默认为0
			Params:
				max_inclusive：最大值（包含）
			Returns: 满足条件的随机数
		*/
		static int next_int(int max_inclusive)
		{
			init_seed();

			if (max_inclusive < 0)
			{
				throw exception::runtime_exception("jmc::rand::next_int: max value needs to be greater than 0!");
			}

			return next_int(0, max_inclusive);
		}
	};
}