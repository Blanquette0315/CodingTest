#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// 시간 복잡도 O(nm)

int main()
{
	int n, m;
	cin >> n >> m;

	vector<vector<int>> board(n, vector<int>(m, 0));
	vector<vector<bool>> visit(n, vector<bool>(m, false));
	queue<pair<int, int>> Q;
	int dx[4] = {0, 0, -1, 1}; // 상하좌우
	int dy[4] = {1, -1, 0, 0};

	int Cnt = 0, width = 0;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (!visit[i][j] && board[i][j] == 1)
			{
				visit[i][j] = true;
				Q.push({ i, j });
				int TempWidth = 1;
				Cnt++;

				while (!Q.empty())
				{
					auto cur_pos = Q.front();
					Q.pop();

					for (int dir = 0; dir < 4; ++dir)
					{
						int X = cur_pos.first + dx[dir];
						int Y = cur_pos.second + dy[dir];

						if (X < 0 || X >= n || Y < 0 || Y >= m)
							continue;

						if (visit[X][Y] || board[X][Y] == 0)
							continue;

						visit[X][Y] = true;
						Q.push({ X, Y });
						TempWidth++;
					}

					width = max(width, TempWidth);
				}
			}
		}
	}

	cout << Cnt << endl << width;

	return 0;
}