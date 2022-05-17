#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int x;
	cin >> x;
	string str;

	do {
		if (x & 1)
		{
			str += "1";
		} else {
			str += "0";
		}
		x >>= 1;
	} while (x);

	std::reverse(str.begin(), str.end());
	cout << str;

	return 0;
}