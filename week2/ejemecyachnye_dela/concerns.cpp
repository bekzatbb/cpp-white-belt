#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	int Q;
	cin >> Q;

	vector<vector<string>> diary(31);
	int month_num = 0;
	string command;
	int i;
	string s;

	for (int k = 0; k < Q; ++k)
	{
		cin >> command;
		if (command == "ADD") 
		{
			cin >> i >> s;
			--i;
			diary[i].push_back(s);
		} else if (command == "DUMP")
		{
			cin >> i;
			--i;
			cout << diary[i].size() << " ";
			for (auto j : diary[i])
			{
				cout << j << " ";
			}
			cout << endl;
		} else if (command == "NEXT") {
			if (diary.size() == 31 && month_num % 12 == 0)
			{
				vector<vector<string>> new_diary(28);
				for (int l = 0; l < 28; ++l)
				{
					new_diary[l] = diary[l];
				}
				for (int l = 28; l < 31; ++l)
				{
					new_diary[27].insert(end(new_diary[27]), begin(diary[l]) , end(diary[l]));
				}
				diary = new_diary;
			} else if (diary.size() == 31 && (month_num % 12 == 6 || month_num % 12 == 11)) 
			{

			} else if (diary.size() == 31 && month_num % 12 != 0)
			{
				diary[29].insert(end(diary[29]), begin(diary[30]), end(diary[30]));
				diary.resize(30);
			} else if (diary.size() == 28 || diary.size() == 30)
			{
				diary.resize(31);
			}
			++month_num;
		}
	}

	return 0;
}