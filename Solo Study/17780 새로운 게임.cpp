#include <iostream>
#include <vector>
#include <deque>

using namespace std;

enum class Dir
{
	None,
	Right,
	Left,
	Up,
	Down,
	End
};

struct pice
{
	int i;
	int j;
	Dir dir;
	bool owner;
};

void calNextIdx(const int& cur_i, const int& cur_j, int& nxt_i, int& nxt_j, Dir dir)
{
	nxt_i = cur_i;
	nxt_j = cur_j;
	// 이동할 방향에 따른 다음 이동 좌표 구하기
	switch (dir)
	{
	case Dir::Right:
			nxt_j++;
		break;

	case Dir::Left:
			nxt_j--;
		break;

	case Dir::Up:
			nxt_i--;
		break;

	case Dir::Down:
			nxt_i++;
		break;

	default:
		break;
	}
}

void move(vector<vector<pair<int, deque<int>>>>& board, vector<pice>& pices, const int& cur_i, const int& cur_j, int& nxt_i, int& nxt_j)
{
	// 말을 옮겨줌.
	switch (board[nxt_i][nxt_j].first)
	{
		// 흰색 발판일 때
	case 0:
		while (!board[cur_i][cur_j].second.empty())
		{
			board[nxt_i][nxt_j].second.push_back(board[cur_i][cur_j].second.front());
			board[cur_i][cur_j].second.pop_front();
		}
		pices[board[nxt_i][nxt_j].second.front()].owner = true;
		pices[board[nxt_i][nxt_j].second.front()].i = nxt_i;
		pices[board[nxt_i][nxt_j].second.front()].j = nxt_j;
		break;

		// 빨간 발판일 때
	case 1:
		while (!board[cur_i][cur_j].second.empty())
		{
			board[nxt_i][nxt_j].second.push_back(board[cur_i][cur_j].second.back());
			board[cur_i][cur_j].second.pop_back();
		}

		pices[board[nxt_i][nxt_j].second.front()].owner = true;
		pices[board[nxt_i][nxt_j].second.front()].i = nxt_i;
		pices[board[nxt_i][nxt_j].second.front()].j = nxt_j;
		break;

		// 파란 발판일 때
	case 2:
		break;

	default:
		break;
	}
}

int main()
{
	// N이 판 크기, K가 말 개수
	int N = 0, K = 0;

	cin >> N >> K;

	// [i][j].first = 발판 색상, second는 발판에 있는 말들
	// N+2로 하는 이유는 OBB를 하지 않고 파란색 발판과 동일하다 생각하게 하기 위해 즉, 테두리는 파랑
	// 때문에 기본 색상은 파랑으로 한다.
	vector<vector<pair<int, deque<int>>>> board(N + 2, vector<pair<int, deque<int>>>(N + 2, { 2, deque<int>() }));
	for (size_t i = 1; i <= N; ++i)
	{
		for (size_t j = 1; j <= N; ++j)
		{
			cin >> board[i][j].first;
		}
	}

	vector<pice> pices;

	// K개의 말 순서대로 행, 열, 방향을 받음
	// 이때 행과 열을 받고 -1을 해주어야 함. 문제에서는 보드가 0부터 시작이 아닌 1부터 시작
	for (int cnt = 0; cnt < K; ++cnt)
	{
		int i = 0, j = 0, dir = 0;
		cin >> i >> j >> dir;

		pices.push_back(pice{ i, j, (Dir)dir, true });
		board[i][j].second.push_front(cnt);
	}

	int a = 0;

	int turn = 1;
	while (turn <= 1000)
	{
		for (size_t picenum = 0; picenum < K; ++picenum)
		{
			// 해당 말이 움직이는 주체가 아니면, 넘겨줌
			if (!pices[picenum].owner)
				continue;

			int cur_i = pices[picenum].i, cur_j = pices[picenum].j, nxt_i = 0, nxt_j = 0;
			// 이동할 방향에 따른 다음 이동 좌표 구하기
			calNextIdx(cur_i, cur_j, nxt_i, nxt_j, pices[picenum].dir);

			// 말을 옮기기 전에 본인을 주체가 아니라 체크
			// 이후에 진행하면서 deque의 가장 앞쪽것을 다시 true로 해 줄 것임.
			pices[picenum].owner = false;

			// 이동할 칸이 파랑이 아니면,
			if (board[nxt_i][nxt_j].first != 2)
			{
				move(board, pices, cur_i, cur_j, nxt_i, nxt_j);
			}
			// 파랑이면
			else
			{
				// 방향 뒤집기
				switch (pices[picenum].dir)
				{
				case Dir::Right:
					pices[picenum].dir = Dir::Left;
					break;
				case Dir::Left:
					pices[picenum].dir = Dir::Right;
					break;
				case Dir::Up:
					pices[picenum].dir = Dir::Down;
					break;
				case Dir::Down:
					pices[picenum].dir = Dir::Up;
					break;
				default:
					break;
				}
				// 다시 방향을 뒤집어서 계산
				calNextIdx(cur_i, cur_j, nxt_i, nxt_j, pices[picenum].dir);

				// 다시 이동할 발판이 파랑이 아니면, 실제로 이동
				if(board[nxt_i][nxt_j].first != 2)
					move(board, pices, cur_i, cur_j, nxt_i, nxt_j);
				else
					pices[picenum].owner = true;
			}

			/*pices[picenum].i = nxt_i;
			pices[picenum].j = nxt_j;*/

			// 옮겨진 칸에 말이 4개 이상이 쌓이면 턴출력 후 마무리
			if (board[nxt_i][nxt_j].second.size() >= 4)
			{
				cout << turn;
				return 0;
			}
		}

		turn++;
	}

	cout << -1;

	return 0;
}