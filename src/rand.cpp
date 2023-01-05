#include <iostream>
#include <mutex>
#include <jmc-libs/rand.h>
#include <jmc-libs/exception.h>


namespace jmc 
{
	// Modified by GinShio in 2022.12.20
	// Add thread safe
	namespace
	{
		::std::once_flag inited;
	}

	// Modified by GinShio in 2022.12.20
	// Add thread safe
	void rand::init_seed()
	{
		::std::call_once(inited, [](){ ::srand(static_cast<unsigned int>(::time(nullptr))); });
	}

	int rand::next_int(int min_inclusive, int max_inclusive)
	{
		init_seed();

		if (min_inclusive < 0 || max_inclusive < 0 || max_inclusive < min_inclusive) {
			throw exception::runtime_exception("jmc::rand::next_int: illegal arguments");
		}

		return std::rand() % (max_inclusive - min_inclusive + 1) + min_inclusive;
	}

	int rand::next_int(int max_inclusive)
	{
		init_seed();

		if (max_inclusive < 0)
		{
			throw exception::runtime_exception("jmc::rand::next_int: max value needs to be greater than 0!");
		}

		return next_int(0, max_inclusive);
	}
}
