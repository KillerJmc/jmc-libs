#include <iostream>
#include <jmc-all>

using std::cout;
using std::endl;

int main()
{
	double a[] = { 1, 2, 3, 4, 5, 6 };
	// pass in a head ptr and an tail ptr
	cout << jmc::container::to_string(a, a + 6) << endl;

	std::vector v = { 1, 2, 3 };
	// pass in a begin iterator and a end iterator
	cout << jmc::container::to_string(v.begin(), v.end()) << endl;

	std::vector v2 = { 'a', 'b', 'c' };
	// pass in a container
	cout << jmc::container::to_string(v2) << endl;

	// multiple basic types 
	std::vector v3 = { "aaa", "bbb", "ccc" };
	cout << jmc::container::to_string(v3) << endl;

	std::vector<std::string> v4 = { "ddd", "eee", "fff" };
	cout << jmc::container::to_string(v4) << endl;

	std::vector<const char*> v5 = { "ggg", "hhh", "iii" };
	cout << jmc::container::to_string(v5) << endl;

	std::vector<bool> v6 = { true, false, true };
	cout << jmc::container::to_string(v6) << endl;

	// pass in a complicated type
	std::vector<std::pair<int, int>> v7 = { { 1, 2 }, { 3, 4 }, { 5, 6 } };
	cout << jmc::container::to_string(v7, [](const auto& p) {
		return std::to_string(p.first) + " -> " + std::to_string(p.second);
	}) << endl;

	std::vector<std::pair<int, int>> v8 = { { 1, 2 }, { 3, 4 }, { 5, 6 } };
	// cause exception: complicated type without passing to_string_func parameter
	// cout << jmc::container::to_string(v8) << endl;

	char c = 'a';
	// invalid container type char
	// cout << jmc::container::to_string(c) << endl;
}