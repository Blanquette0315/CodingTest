#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
	int N = 0, M = 0;
	cin >> N >> M;

	vector<vector<int>> board(M, vector<int>(N, 0));
	vector<vector<int>> vis(M, vector<int>(N, 0));
	queue<pair<int, int>> Q;
	int dx[4] = { 0, 0, -1, 1 };
	int dy[4] = { 1, -1, 0, 0 };

	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> board[i][j];

			if (board[i][j] == 1)
			{
				Q.push({ i, j });
				vis[i][j] = 1;
			}
			else if (board[i][j] == -1)
				vis[i][j] = -1;
		}
	}

	while (!Q.empty())
	{
		auto cur_pos = Q.front();
		Q.pop();

		for (int dir = 0; dir < 4; ++dir)
		{
			int X = cur_pos.first + dx[dir];
			int Y = cur_pos.second + dy[dir];

			if (X < 0 || X >= M || Y < 0 || Y >= N)
				continue;
			if (board[X][Y] != 0)
				continue;

			if (vis[X][Y] == 0 || vis[X][Y] > vis[cur_pos.first][cur_pos.second] + 1)
			{
				vis[X][Y] = vis[cur_pos.first][cur_pos.second] + 1;
				Q.push({ X,Y });
			}
		}
	}

	bool Is_Fail = false;
	int day = 0;
	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (vis[i][j] == 0)
			{
				Is_Fail = true;
				break;
			}
			
			day = max(day, vis[i][j]);
		}
	}

	if (Is_Fail)
		cout << -1;
	else
		cout << day - 1;

	return 0;
}