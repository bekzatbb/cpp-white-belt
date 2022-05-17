#include <iostream>
#include <vector>
using namespace std;

void Reverse(vector<int>& v) {
	int swap = 0;
	for (int i = 0; i < v.size() / 2; i++)
	{
		swap = v[i];
		v[i] = v[v.size() - 1 -i];
		v[v.size() - 1 - i] = swap;
	}
}

int main()
{
	vector<int> numbers = {1, 5, 3, 4, 2};
	for (auto i : numbers)
	{
		cout << i << ' ';
	}
	cout << "\n";
	Reverse(numbers);
	for (auto i : numbers)
	{
		cout << i << ' ';
	}

	return 0;
}