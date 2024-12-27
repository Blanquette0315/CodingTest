#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

// 06:36 06:52

void func(const vector<int>& input, vector<bool>& vis, vector<int>& arr, set<vector<int>>& memo, int& num, int& cnt, int k, int m)
{
	if (k == m)
	{
		if (num == 0)
		{
			cnt++;
		}

		return;
	}

	for (int i = 0; i < input.size(); ++i)
	{
		if (!vis[i])
		{
			num += input[i];
			vis[i] = true;
			func(input, vis, num, cnt, k + 1, m);
			num -= input[i];
			vis[i] = false;
		}
	}
}

int main()
{
	int N = 0, S = 0;
	cin >> N >> S;

	vector<int> input(N, 0);
	vector<bool> vis(N, false);
	int num = 0;
	int cnt = 0;

	for (int i = 0; i < input.size(); ++i)
	{
		cin >> input[i];
	}

	sort(input.begin(), input.end(), less<int>());

	for (int i = 1; i < input.size() + 1; ++i)
	{
		vector<int> arr(i, 0);
		set<vector<int>> memo;
		num = 0;
		func(input, vis, arr, memo, num, cnt, 0, i);
	}

	cout << cnt;

	return 0;
}