#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool IsPalindrom(string w) 
{
	for (int i = 0; i < w.size() / 2 + 1; ++i)
	{
		if (w[i] != w[w.size() - i - 1])
		{
			return false;
		}
	}
	return true;
}

vector<string> PalindromFilter(vector<string> words, int minLength)
{
	vector<string> target;
	for (auto i : words)
	{
		if (IsPalindrom(i) && i.size() >= minLength)
		{
			target.push_back(i);
		}
	}
	return target;
}

// bool IsPalindrom(string w);
// vector<string> PalindromFilter(vector<string> words, int minLength);

int main()
{
	vector<string> input = {"weew", "bro", "code"};
	for (auto i : PalindromFilter(input, 4))
	{
		cout << i << " ";
	}
	return 0;
}