#include <iostream>
#include <vector>

using namespace std;

// 아아아아아아아ㅏ아아 거지같은 문제야

// 1부터 위 아래 오른쪽 왼쪽
int Dir_Y[5] = {0, -1, 1, 0, 0};
int Dir_X[5] = { 0, 0, 0, 1, -1 };

struct Shark
{
	int dir;
	int speed;
	int scale;
	int r;
	int c;
};

vector<Shark> Sharks[102][102];

int changeDir(int d)
{
	if (d == 1)
		return 2;
	if (d == 2)
		return 1;
	if (d == 3)
		return 4;
	if (d == 4)
		return 3;
}

int main()
{
	int R = 0, C = 0, M = 0;

	cin >> R >> C >> M;

	for (size_t i = 0; i < M; ++i)
	{
		Shark* ptr_shark = new Shark;
		int r, c, s, d, z;
		cin >> r >> c >> s >> d >> z;

		if (d == 1 || d == 2)
			s %= (R - 1) * 2;
		else if(d == 3 || d == 4)
			s %= (C - 1) * 2;

		Sharks[r][c].push_back({ d, s, z, r, c });
	}

	if (M == 0)
		cout << 0;

	int cnt = 0;
	for (int i = 1; i <= C; ++i)
	{
		// 1. 땅에 가까운 상어 잡기
		for (size_t j = 1; j <= R; ++j)
		{
			if (!Sharks[j][i].empty())
			{
				cnt += Sharks[j][i].front().scale;
				Sharks[j][i].pop_back();
				break;
			}
		}

		vector<Shark> newSharks[102][102];
		// 2. 상어들 이동 및 잡아 먹기
		for (int r = 1; r <= R; ++r)
		{
			for (int c = 1; c <= C; ++c)
			{
				if (Sharks[r][c].empty())
					continue;

				Shark& nowShark = Sharks[r][c].front();
				int& now_r = nowShark.r;
				int& now_c = nowShark.c;
				int nowspeed = nowShark.speed;
				int& nowdir = nowShark.dir;

				while (nowspeed--)
				{
					int nr = now_r + Dir_Y[nowdir];
					int nc = now_c + Dir_X[nowdir];

					if (nr < 1 || nc < 1 || nr >R || nc>C)
						nowdir = changeDir(nowdir);

					now_r += Dir_Y[nowdir];
					now_c += Dir_X[nowdir];
				}


			}
		}
	}

	return 0;
}