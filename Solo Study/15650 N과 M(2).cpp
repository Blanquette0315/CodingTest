#include <iostream>
#include <vector>

using namespace std;

// 02:44 03:06 => 22

void func(vector<int>& vecNum, vector<bool>& vis, int N, int M, int loop_i, int k)
{
	if (k == M)
	{
		for (int i = 0; i < vecNum.size(); ++i)
		{
			cout << vecNum[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = loop_i; i <= N; ++i)
	{
		if (!vis[i - 1])
		{
			vecNum[k] = i;
			vis[i - 1] = true;
			func(vecNum, vis, N, M, i, k + 1);
			vis[i - 1] = false;
		}
	}
}

int main()
{
	int N = 0, M = 0;
	cin >> N >> M;

	vector<int> vecNum(M, 0);
	vector<bool> vis(N, false);

	func(vecNum, vis, N, M, 1, 0);

	return 0;
}