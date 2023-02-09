#include <gtest/gtest.h>

import "iostream";
import jmclibs.timer;

TEST(TimerTest, test)
{
	// 进行毫秒计时并打印计时结果
	jmc::timer::milli_timer([]() {
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}, true);
}
