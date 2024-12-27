#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

void func(vector<int>& input, vector<int>& num, set<vector<int>>& memo, int loop_i, int k)
{
	if (k == num.size())
	{
		if (memo.find(num) == memo.end())
		{
			memo.insert(num);
			for (int i = 0; i < num.size(); ++i)
			{
				cout << num[i] << ' ';
			}
			cout << '\n';
		}
		return;
	}

	for (int i = loop_i; i < input.size(); ++i)
	{
		num[k] = input[i];
		func(input, num, memo, i + 1, k + 1);
	}
}

int main()
{
	int N = 0, M = 0;
	cin >> N >> M;

	vector<int> input(N, 0);
	vector<int> num(M, 0);

	for (int i = 0; i < N; ++i)
	{
		cin >> input[i];
	}

	sort(input.begin(), input.end(), less<int>());

	set<vector<int>> Memo;

	func(input, num, Memo, 0, 0);

	return 0;
}