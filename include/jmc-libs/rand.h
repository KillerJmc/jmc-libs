#pragma once

#include <iostream>

namespace jmc 
{
	/*
		随机数类
		Since: 1.0
		Author: Jmc
	*/
	class rand 
	{
	private:
		/*
			初始化随机数种子
		*/
		static void init_seed();

	public:
		/*
			获取一个随机数
			Params:
				min_inclusive：最小值（包含）
				max_inclusive：最大值（包含）
			Returns: 满足条件的随机数
		*/
		static int next_int(int min_inclusive, int max_inclusive);

		/*
			获取一个随机数，最小值默认为0
			Params:
				max_inclusive：最大值（包含）
			Returns: 满足条件的随机数
		*/
		static int next_int(int max_inclusive);
	};
}