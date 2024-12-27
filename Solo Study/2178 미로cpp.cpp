#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

int main()
{
	int N = 0, M = 0;
	cin >> N >> M;

	vector<vector<int>> board(N, vector<int>(M, 0));
	vector<vector<int>> vis(N, vector<int>(M, 0));
	int dx[4] = { 0, 0, -1, 1 };
	int dy[4] = { 1, -1, 0, 0, };

	for (int i = 0; i < N; ++i)
	{
		string input;
		cin >> input;
		for (int j = 0; j < M; ++j)
		{
			board[i][j] = stoi(input.substr(j, 1));
		}
	}

	queue<pair<int, int>> Q;
	vis[0][0] = 1;
	Q.push({ 0, 0 });

	while (!Q.empty())
	{
		auto cur_pos = Q.front();
		Q.pop();

		for (int dir = 0; dir < 4; ++dir)
		{
			int X = cur_pos.first + dx[dir];
			int Y = cur_pos.second + dy[dir];

			if (X < 0 || X >= N || Y < 0 || Y >= M)
				continue;
			if (vis[X][Y] != 0 || board[X][Y] == 0)
				continue;

			vis[X][Y] = vis[cur_pos.first][cur_pos.second] + 1;
			Q.push({ X, Y });
		}
	}

	cout << vis[N - 1][M - 1];

	return 0;
}