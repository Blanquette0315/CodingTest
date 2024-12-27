#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
	long long answer = 0;
	int N = 0, K = 0;

	vector<pair<int, int>> jewerly;
	vector<int> bag;

	priority_queue<int> pq;

	cin >> N >> K;
	jewerly.resize(N);
	bag.resize(K);
	for (int i = 0; i < N; ++i)
	{
		cin >> jewerly[i].first >> jewerly[i].second;
	}

	for (int i = 0; i < K; ++i)
	{
		cin >> bag[i];
	}

	sort(jewerly.begin(), jewerly.end());
	sort(bag.begin(), bag.end());

	int jewerly_idx = 0;
	for (size_t i = 0; i < K; ++i)
	{
		int bagWight = bag[i];

		for (; jewerly_idx < N; ++jewerly_idx)
		{
			// 가방 허용 무게를 넘으면 루프 탈출
			if (bagWight < jewerly[jewerly_idx].first)
				break;

			pq.push(jewerly[jewerly_idx].second);
		}

		if(!pq.empty())
		{
			answer += pq.top();
			pq.pop();
		}
	}

	cout << answer;

	return 0;
}