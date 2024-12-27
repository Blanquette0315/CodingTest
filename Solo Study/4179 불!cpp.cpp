#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <tuple>

using namespace std;

// 5 : 48 6 : 30

//int main()
//{
//	int R = 0, C = 0;
//	cin >> R >> C;
//
//	vector<string> board(R, "");
//	vector<vector<vector<int>>> vis(2, vector<vector<int>>(R, vector<int>(C, 0)));
//	
//	int dx[4] = { 0, 0, -1, 1 };
//	int dy[4] = { 1, -1, 0, 0 };
//
//	pair<int, int> J_pos = { 0, 0 };
//	queue<tuple<char, int, int>> Q;
//
//	for (int i = 0; i < R; ++i)
//	{
//		cin >> board[i];
//		for (int j = 0; j < board[i].length(); ++j)
//		{
//			if (board[i][j] == '#')
//			{
//				vis[1][i][j] = 1;
//			}
//			else if (board[i][j] == 'J')
//			{
//				J_pos = { i, j };
//			}
//			else if (board[i][j] == 'F')
//			{
//				vis[1][i][j] = 1;
//				Q.push({'F', i, j});
//			}
//		}
//	}
//
//	Q.push({'J', J_pos.first, J_pos.second});
//	vis[0][J_pos.first][J_pos.second] = 1;
//
//	bool Is_Fin = false;
//	while (!Q.empty())
//	{
//		if (Is_Fin)
//			break;
//
//		auto cur_Pos = Q.front();
//		Q.pop();
//
//		for(int dir = 0; dir < 4; ++dir)
//		{
//			int X = get<1>(cur_Pos) + dx[dir];
//			int Y = get<2>(cur_Pos) + dy[dir];
//
//			if (get<0>(cur_Pos) == 'F')
//			{
//				if (X < 0 || X >= R || Y < 0 || Y >= C)
//					continue;
//				if (vis[1][X][Y] == 1 || board[X][Y] == '#')
//					continue;
//
//				vis[1][X][Y] = 1;
//				Q.push({ 'F', X, Y });
//			}
//			else if (get<0>(cur_Pos) == 'J')
//			{
//				if (X < 0 || X >= R || Y < 0 || Y >= C)
//				{
//					J_pos = { get<1>(cur_Pos), get<2>(cur_Pos) };
//					Is_Fin = true;
//					break;
//				}
//				if (vis[0][X][Y] != 0 || board[X][Y] == '#' || vis[1][X][Y] == 1)
//					continue;
//
//				vis[0][X][Y] = vis[0][get<1>(cur_Pos)][get<2>(cur_Pos)] + 1;
//				Q.push({ 'J', X, Y });
//			}
//		}
//	}
//
//	if (Is_Fin)
//		cout << vis[0][J_pos.first][J_pos.second];
//	else
//		cout << "IMPOSSIBLE";
//
//	return 0;
//}

int main()
{
	int R = 0, C = 0;
	cin >> R >> C;

	vector<string> board(R, "");
	vector<vector<vector<int>>> vis(2, vector<vector<int>>(R, vector<int>(C, 0)));

	queue<pair<int, int>> Q1;
	queue<pair<int, int>> Q2;

	int dx[4] = { 0, 0, -1, 1 };
	int dy[4] = { 1, -1, 0, 0 };

	for (int i = 0; i < R; ++i)
	{
		cin >> board[i];
		for (int j = 0; j < C; ++j)
		{
			if (board[i][j] == 'J')
			{
				Q1.push({ i, j });
				vis[0][i][j] = 1;
			}
			else if (board[i][j] == 'F')
			{
				Q2.push({ i, j });
				vis[1][i][j] = 1;
			}
		}
	}

	while (!Q2.empty())
	{
		auto cur_pos = Q2.front();
		Q2.pop();

		for (int dir = 0; dir < 4; ++dir)
		{
			int X = cur_pos.first + dx[dir];
			int Y = cur_pos.second + dy[dir];

			if (X < 0 || X >= R || Y < 0 || Y >= C)
				continue;
			if (vis[1][X][Y] != 0 || board[X][Y] == '#')
				continue;

			vis[1][X][Y] = vis[1][cur_pos.first][cur_pos.second] + 1;
			Q2.push({ X,Y });
		}
	}

	while (!Q1.empty())
	{
		auto cur_pos = Q1.front();
		Q1.pop();

		for (int dir = 0; dir < 4; ++dir)
		{
			int X = cur_pos.first + dx[dir];
			int Y = cur_pos.second + dy[dir];

			if (X < 0 || X >= R || Y < 0 || Y >= C)
			{
				cout << vis[0][cur_pos.first][cur_pos.second];
				return 0;
			}
			if (vis[0][X][Y] > 0 || board[X][Y] == '#')
				continue;
			if (vis[1][X][Y] != 0 && vis[1][X][Y] <= vis[0][cur_pos.first][cur_pos.second] + 1)
				continue;

			vis[0][X][Y] = vis[0][cur_pos.first][cur_pos.second] + 1;
			Q1.push({ X,Y });
		}
	}

	cout << "IMPOSSIBLE";

	return 0;
}