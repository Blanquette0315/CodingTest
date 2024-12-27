#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
	int N = 0, Target = 0;
	cin >> N >> Target;

	if (N == Target)
	{
		cout << 0;
		return 0;
	}

	vector<int> Memo(100001, 0);

	queue<int> Q;
	Q.push(N);
	Memo[N] = 0;

	while (Memo[Target] == 0)
	{
		int curpos = Q.front();
		Q.pop();

		vector<int> temp(3, 0);
		temp[0] = curpos - 1;
		temp[1] = curpos + 1;
		temp[2] = curpos * 2;

		for (int i = 0; i < 3; ++i)
		{if (temp[i] < 0 || temp[i] > 100000)
				continue;
			if (Memo[temp[i]] != 0)
				continue;

			Q.push(temp[i]);
			Memo[temp[i]] = Memo[curpos] + 1;
		}
	}

	cout << Memo[Target];

	return 0;
}