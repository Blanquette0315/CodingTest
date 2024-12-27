#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

void func(vector<int>& Input, vector<int>& Num, vector<bool>& vis, set<vector<int>>& Memo, int M, int k)
{
	if (k == M)
	{
		if (Memo.find(Num) == Memo.end())
		{
			Memo.insert(Num);

			for (int i = 0; i < Num.size(); ++i)
			{
				cout << Num[i] << ' ';
			}
			cout << '\n';
		}
		return;
	}

	for (int i = 0; i < Input.size(); ++i)
	{
		if (!vis[i])
		{
			Num[k] = Input[i];
			vis[i] = true;
			func(Input, Num, vis, Memo, M, k + 1);
			vis[i] = false;	
		}
	}
}

int main()
{
	int N = 0, M = 0;
	cin >> N >> M;

	vector<int> Input(N, 0);
	vector<int> Num(M, 0);
	vector<bool> vis(N, false);

	for (int i = 0; i < N; ++i)
	{
		cin >> Input[i];
	}

	sort(Input.begin(), Input.end(), less<int>());

	set<vector<int>> Memo;
	func(Input, Num, vis, Memo, M, 0);

	return 0;
}