#include <string>
#include <iostream>
using namespace std;

int main()
{
	string str;
	cin >> str;

	std::size_t found_first = str.find("f");
	std::size_t found_second = str.find("f", found_first + 1);

	if (found_second != std::string::npos)
	{
		cout << found_second << endl;
	} else if (found_first != std::string::npos)
	{
		cout << -1 << endl;
	} else {
		cout << -2 << endl;
	}

	return 0;
}