#include <iostream>
#include <jmc-libs/all.h>
#include <gtest/gtest.h>

TEST(TimerTest, test)
{
	// 进行毫秒计时并打印计时结果
	jmc::timer::milli_timer([]() {
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}, true);
}