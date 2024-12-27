#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

void func(vector<int>& input, vector<int>& num, set<vector<int>>& memo, int k)
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

	for (int i = 0; i < input.size(); ++i)
	{
		num[k] = input[i];
		func(input, num, memo, k + 1);
	}
}

int main()
{
	int N = 0, M = 0;
	cin >> N >> M;

	vector<int> input(N, 0);
	vector<int> num(M, 0);

	for (int i = 0; i < input.size(); ++i)
	{
		cin >> input[i];
	}

	sort(input.begin(), input.end(), less<int>());

	set<vector<int>> memo;

	func(input, num, memo, 0);

	return 0;
}