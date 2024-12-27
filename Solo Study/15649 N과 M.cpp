#include <iostream>
#include <vector>

using namespace std;

void Find_Sequence(vector<int>& vecNum, vector<bool>& vis, int n, int m, int k)
{
	if (k == m)
	{
		for (int i = 0; i < m; ++i)
		{
			cout << vecNum[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 0; i < vis.size(); ++i)
	{
		if (!vis[i])
		{
			vecNum[k] = i + 1;
			vis[i] = true;
			Find_Sequence(vecNum, vis, n, m, k + 1);
			vis[i] = false;
		}
	}
}

int main()
{
	int N = 0, M = 0;
	cin >> N >> M;

	vector<int> vecNum(M, 0);
	vector<bool> vis(N, false);

	Find_Sequence(vecNum, vis, N,  M, 0);

	return 0;
}