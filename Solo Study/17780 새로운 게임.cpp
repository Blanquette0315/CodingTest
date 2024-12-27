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
	// �̵��� ���⿡ ���� ���� �̵� ��ǥ ���ϱ�
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
	// ���� �Ű���.
	switch (board[nxt_i][nxt_j].first)
	{
		// ��� ������ ��
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

		// ���� ������ ��
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

		// �Ķ� ������ ��
	case 2:
		break;

	default:
		break;
	}
}

int main()
{
	// N�� �� ũ��, K�� �� ����
	int N = 0, K = 0;

	cin >> N >> K;

	// [i][j].first = ���� ����, second�� ���ǿ� �ִ� ����
	// N+2�� �ϴ� ������ OBB�� ���� �ʰ� �Ķ��� ���ǰ� �����ϴ� �����ϰ� �ϱ� ���� ��, �׵θ��� �Ķ�
	// ������ �⺻ ������ �Ķ����� �Ѵ�.
	vector<vector<pair<int, deque<int>>>> board(N + 2, vector<pair<int, deque<int>>>(N + 2, { 2, deque<int>() }));
	for (size_t i = 1; i <= N; ++i)
	{
		for (size_t j = 1; j <= N; ++j)
		{
			cin >> board[i][j].first;
		}
	}

	vector<pice> pices;

	// K���� �� ������� ��, ��, ������ ����
	// �̶� ��� ���� �ް� -1�� ���־�� ��. ���������� ���尡 0���� ������ �ƴ� 1���� ����
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
			// �ش� ���� �����̴� ��ü�� �ƴϸ�, �Ѱ���
			if (!pices[picenum].owner)
				continue;

			int cur_i = pices[picenum].i, cur_j = pices[picenum].j, nxt_i = 0, nxt_j = 0;
			// �̵��� ���⿡ ���� ���� �̵� ��ǥ ���ϱ�
			calNextIdx(cur_i, cur_j, nxt_i, nxt_j, pices[picenum].dir);

			// ���� �ű�� ���� ������ ��ü�� �ƴ϶� üũ
			// ���Ŀ� �����ϸ鼭 deque�� ���� ���ʰ��� �ٽ� true�� �� �� ����.
			pices[picenum].owner = false;

			// �̵��� ĭ�� �Ķ��� �ƴϸ�,
			if (board[nxt_i][nxt_j].first != 2)
			{
				move(board, pices, cur_i, cur_j, nxt_i, nxt_j);
			}
			// �Ķ��̸�
			else
			{
				// ���� ������
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
				// �ٽ� ������ ����� ���
				calNextIdx(cur_i, cur_j, nxt_i, nxt_j, pices[picenum].dir);

				// �ٽ� �̵��� ������ �Ķ��� �ƴϸ�, ������ �̵�
				if(board[nxt_i][nxt_j].first != 2)
					move(board, pices, cur_i, cur_j, nxt_i, nxt_j);
				else
					pices[picenum].owner = true;
			}

			/*pices[picenum].i = nxt_i;
			pices[picenum].j = nxt_j;*/

			// �Ű��� ĭ�� ���� 4�� �̻��� ���̸� ����� �� ������
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