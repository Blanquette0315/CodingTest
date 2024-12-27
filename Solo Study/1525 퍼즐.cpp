#include <iostream>
#include <string>
#include <queue>
#include <set>

using namespace std;

//				╩С  го  аб  ©Л
int Dir_X[4] = { 0, 0, -1, 1 };
int Dir_Y[4] = { -1, 1, 0, 0 };

int bfs(set<string>& memo, string str)
{
	queue<pair<string, int>> qu;
	qu.push({ str, 0 });

	while (!qu.empty())
	{
		auto curState = qu.front();
		string curString = curState.first;
		int cnt = curState.second;
		qu.pop();

		if (curString == "123456780")
			return cnt;

		int zero = curString.find('0');
		int x = zero / 3, y = zero % 3;

		for (int i = 0; i < 4; ++i)
		{
			int nxt_x = x + Dir_X[i];
			int nxt_y = y + Dir_Y[i];

			if (nxt_x < 0 || nxt_x >= 3 || nxt_y < 0 || nxt_y >= 3)
				continue;

			string temp = curString;

			swap(temp[3 * x + y], temp[3 * nxt_x + nxt_y]);

			if (memo.find(temp) == memo.end())
			{
				memo.insert(temp);
				qu.push({ temp, cnt + 1 });
			}
		}
	}

	return -1;
}

int main()
{
	string str = "";
	str.resize(9);

	for (size_t i = 0; i < 9; ++i)
	{
		cin >> str[i];
	}

	set<string> memo;
	cout << bfs(memo, str);

	return 0;
}