#include <iostream>
#include <rand.h>
#include <exception.h>

namespace jmc 
{
	bool rand::inited = false;

	void rand::init_seed()
	{
		if (!inited)
		{
			std::srand((unsigned int) std::time(nullptr));
		}
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