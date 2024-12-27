#include <iostream>
#include <vector>
#include <unordered_set>
#include <stack>

using namespace std;

// SCC 문제였다.
// 어렵다.. 다시 봐야할 문제
// 
// https://storyofvector7.tistory.com/44
// https://velog.io/@namsh1125/타잔-알고리즘
// 
// https://blog.encrypted.gg/499
// 

void hasCycle(vector<bool>& visit, vector<bool>& done, vector<int>& Memo, int idx, int& cnt)
{
	visit[idx] = true;
	int nxtIdx = Memo[idx];

	if (!visit[nxtIdx])
		hasCycle(visit, done, Memo, nxtIdx, cnt);
	else if (!done[nxtIdx])
	{
		for (int i = nxtIdx; i != idx; i = Memo[i])
			cnt++;
		cnt++;
	}
	done[idx] = true;
}

int main()
{
	int T = 0;

	cin >> T;

	vector<vector<int>> Memo(T, vector<int>(0, 0));

	for (size_t i = 0; i < T; ++i)
	{
		int size = 0;
		cin >> size;
		Memo[i].resize(size + 1);
		for (size_t j = 1; j < size + 1; ++j)
		{
			cin >> Memo[i][j];
		}
	}

	for (size_t i = 0; i < T; ++i)
	{
		vector<bool> visit(Memo[i].size(), false);
		vector<bool> done(Memo[i].size(), false);
		int cnt = 0;
		for (size_t j = 1; j < Memo[i].size(); ++j)
		{
			if (!visit[j])
			{
				hasCycle(visit, done, Memo[i], j, cnt);
			}
		}

		cout << Memo[i].size() - cnt - 1 << endl;;
	}

	return 0;
}