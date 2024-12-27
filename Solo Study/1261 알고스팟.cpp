#include <iostream>
#include <vector>
#include <deque>
#include <cstdio>

using namespace std;

// dfs는 시간초과
// bfs는 됨
// 다익스트라 가능
// 0-1 bfs가 가장 효율적임.
// 
// 0-1 bfs는 공부할것. 
//


int N = 0, M = 0;

// 상 하 좌 우
int dir_Y[4] = { -1, 1, 0, 0 };
int dir_X[4] = { 0, 0, -1, 1 };

struct Info
{
	int x;
	int y;
	int sum;
};

void bfs(vector<vector<int>>& map, vector<vector<bool>>& visit)
{
	deque<Info> dq;
	dq.push_back({ 0,0,0 });
	visit[0][0] = true;

	while (!dq.empty())
	{
		Info cur_info = dq.front();
		dq.pop_front();

		int x = cur_info.x;
		int y = cur_info.y;
		int sum = cur_info.sum;

		if (y == N - 1 && x == M - 1)
		{
			cout << sum;
			return;
		}

		for (int i = 0; i < 4; ++i)
		{
			int nxt_x = x + dir_X[i];
			int nxt_y = y + dir_Y[i];

			if (nxt_x >= M || nxt_y >= N || nxt_x < 0 || nxt_y < 0)
				continue;
			if (visit[nxt_y][nxt_x])
				continue;

			visit[nxt_y][nxt_x] = true;
			if (map[nxt_y][nxt_x] == 1)
				dq.push_back({ nxt_x, nxt_y, sum + 1 });
			else
				dq.push_front({ nxt_x, nxt_y, sum });
		}
	}
	return;
}

int main()
{
	cin >> M >> N;

	vector<vector<int>> map(N, vector<int>(M, 0));
	vector<vector<bool>> visit(N, vector<bool>(M, false));

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			scanf_s("%1d", &map[i][j]);
			//cin >> map[i][j];
		}
	}

	bfs(map, visit);

	return 0;
}