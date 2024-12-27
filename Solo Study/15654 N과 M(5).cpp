#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 03:42 03:50 -> 8

void func(vector<int>& vec_board, vector<int>& vec_Num, vector<bool>& vis, int M, int k)
{
	if (M == k)
	{
		for (int i = 0; i < vec_Num.size(); ++i)
		{
			cout << vec_Num[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 0; i < vec_board.size(); ++i)
	{
		if (!vis[i])
		{
			vis[i] = true;
			vec_Num[k] = vec_board[i];
			func(vec_board, vec_Num, vis, M, k + 1);
			vis[i] = false;
		}
	}
}

int main()
{
	int N = 0, M = 0;
	cin >> N >> M;
	
	vector<int> vec_board(N, 0);
	vector<bool> vis(N, false);
	vector<int> vec_Num(M, 0);

	for (int i = 0; i < N; ++i)
	{
		cin >> vec_board[i];
	}

	sort(vec_board.begin(), vec_board.end(), less<int>());

	func(vec_board, vec_Num, vis, M, 0);

	return 0;
}