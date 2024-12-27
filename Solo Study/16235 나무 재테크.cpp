#include <iostream>
#include <vector>
#include <array>
#include <deque>

using namespace std;

void main()
{
	int N, M, K;

	array<array<int, 11>, 11> Yangbun;
	array<array<int, 11>, 11> S2D2Yangbun;
	deque<int> trees[11][11];

	int Dir_Y[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
	int Dir_X[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

	cin >> N >> M >> K;

	for (size_t i = 0; i < N; ++i)
	{
		for (size_t j = 0; j < N; ++j)
		{
			cin >> S2D2Yangbun[i][j];
			Yangbun[i][j] = 5;
		}
	}

	for (size_t i = 0; i < M; ++i)
	{
		int x, y, z;
		cin >> x >> y >> z;
		trees[x][y].push_back(z);
	}


	for (size_t Year = 0; Year < K; ++Year)
	{
		// 봄
		for (size_t i = 0; i <= N; ++i)
		{
			for (size_t j = 0; j <= N; ++j)
			{
				// 양분 먹고 나이 증가
				int k = 0;
				for (;k < trees[i][j].size(); ++k)
				{
					if (Yangbun[i][j] >= trees[i][j][k])
					{
						Yangbun[i][j] -= trees[i][j][k];
						trees[i][j][k]++;
					}
					else
						break;
				}

				// 여름
				// 죽은 나무가 있는 곳 양분 추가
				for (int p = trees[i][j].size() - 1; p >= k; --p)
				{
					Yangbun[i][j] += trees[i][j][p] / 2;
					trees[i][j].pop_back();
				}
			}
		}

		// 가을
		// 나무 번식
		for (size_t i = 1; i <= N; ++i)
		{
			for (size_t j = 1; j <= N; ++j)
			{
				if (trees[i][j].size() > 0)
				{
					for (size_t k = 0; k < trees[i][j].size(); ++k)
					{
						if (trees[i][j][k] % 5 == 0)
						{
							for (size_t q = 0; q < 8; ++q)
							{
								int nx = j + Dir_X[q];
								int ny = i + Dir_Y[q];
								if (nx < 1 || nx > N || ny < 1 || ny> N)
									continue;
								else
									trees[ny][nx].push_front(1); // 아가나무 추가
							}
						}
					}
				}
				// 겨울
				// 양분 추가
				Yangbun[i][j] += S2D2Yangbun[i][j];
			}
		}
	}


	int tree_cnt = 0;
	for (size_t i = 1; i <= N; ++i)
	{
		for (size_t j = 1; j <= N; ++j)
		{
			if (trees[i][j].size() > 0)
				tree_cnt += trees[i][j].size();
		}
	}

	cout << tree_cnt;
	return;
}