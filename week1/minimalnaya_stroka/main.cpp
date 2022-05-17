#include <string>
#include <algorithm>
#include <array>
#include <iostream>

int main()
{
	std::array<std::string, 3> mas;
	for (auto& str : mas)
	{
		std::cin >> str;
	}
	std::cout << *std::min_element(mas.begin(), mas.end()) << std::endl;

	return 0;
}