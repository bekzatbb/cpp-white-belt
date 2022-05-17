#include <iostream>
#include <string>
#include <vector>

using namespace std;

void MoveStrings(vector<string>& src, vector<string>& dst)
{
	for (const auto& i : src)
	{
		dst.push_back(i);
	}
	src.clear();
}

int main()
{
	vector<string> source = {"a", "b", "c"};
	vector<string> destination = {"z"};
	MoveStrings(source, destination);

	for (const auto& k : destination)
	{
		cout << k << " ";
	}

	return 0;
}