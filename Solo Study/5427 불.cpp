#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

// 02 : 49 03 : 18 = 29

int main()
{
	int k = 0, w = 0, h = 0;
	cin >> k;

	int dx[4] = { 0, 0, -1, 1 };
	int dy[4] = { -1, 1, 0, 0 };

	for (int loopcnt = 0; loopcnt < k; ++loopcnt)
	{
		cin >> w >> h;
		vector<string> board(h, "");
		vector<vector<int>> vis1(h, vector<int>(w, 0));
		vector<vector<int>> vis2(h, vector<int>(w, 0));

		queue<pair<int, int>> Q1;
		queue<pair<int, int>> Q2;

		bool is_escpae = false;

		for (int i = 0; i < h; ++i)
		{
			cin >> board[i];
			for (int j = 0; j < w; ++j)
			{
				if (board[i][j] == '*')
				{
					Q2.push({ i, j });
					vis2[i][j] = 1;
				}
				else if (board[i][j] == '@')
				{
					Q1.push({ i, j });
					vis1[i][j] = 1;
				}
			}
		}

		while (!Q2.empty())
		{
			auto cur_pos = Q2.front();
			Q2.pop();

			for (int dir = 0; dir < 4; ++dir)
			{
				int nx = cur_pos.first + dx[dir];
				int ny = cur_pos.second + dy[dir];

				if (nx < 0 || nx >= h || ny < 0 || ny >= w)
					continue;
				if (vis2[nx][ny] > 0 || board[nx][ny] == '#')
					continue;

				Q2.push({ nx, ny });
				vis2[nx][ny] = vis2[cur_pos.first][cur_pos.second] + 1;
			}
		}

		while (!Q1.empty() && !is_escpae)
		{
			auto cur_pos = Q1.front();
			Q1.pop();

			for (int dir = 0; dir < 4; ++dir)
			{
				int nx = cur_pos.first + dx[dir];
				int ny = cur_pos.second + dy[dir];

				if (nx < 0 || nx >= h || ny < 0 || ny >= w)
				{
					cout << vis1[cur_pos.first][cur_pos.second] << endl;
					is_escpae = true;
					break;
				}
				if (vis1[nx][ny] > 0 || board[nx][ny] == '#')
					continue;
				if (vis2[nx][ny] != 0 &&
					vis2[nx][ny] <= vis1[cur_pos.first][cur_pos.second] + 1)
					continue;

				Q1.push({ nx, ny });
				vis1[nx][ny] = vis1[cur_pos.first][cur_pos.second] + 1;
			}
		}

		if(!is_escpae)
			cout << "IMPOSSIBLE" << endl;
	}

	return 0;
}