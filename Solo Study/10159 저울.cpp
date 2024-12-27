#include <iostream>

using namespace std;

// 플로이드 와샬

int main()
{
	int N = 0, M = 0;
	bool adj[101][101] {};

	int idx_Y, idx_X;
	cin >> N >> M;
	for (size_t i = 0; i < M; ++i)
	{
		cin >> idx_Y >> idx_X;
		adj[idx_Y][idx_X] = true;
	}

	for (size_t k = 1; k <= N; ++k)
	{
		for (size_t i = 1; i <= N; ++i)
		{
			for (size_t j = 1; j <= N; ++j)
			{
				if (adj[i][k] && adj[k][j])
					adj[i][j] = true;
			}
		}
	}

	for (size_t i = 1; i <= N; ++i)
	{
		int cnt = 0;
		for (size_t j = 1; j <= N; ++j)
		{
			if (!adj[i][j] && !adj[j][i])
			{
				if (i == j)
					continue;

				cnt++;
			}
		}

		cout << cnt << endl;
	}

	return 0;
}