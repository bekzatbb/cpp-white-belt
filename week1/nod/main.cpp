#include <string>
#include <iostream>
using namespace std;

int NOD(int a, int b)
{
	while(a > 0 && b > 0) {
		if (a > b)
		{
			a %= b;
		} else {
			b %= a;
		}
	}

	return a + b;
}

int main()
{
	int x, y;
	cin >> x >> y;
	cout << NOD(x, y) << endl;

	return 0;
}