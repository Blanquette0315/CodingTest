#include <iostream>
#include <vector>

using namespace std;

// 동전 문제와 비슷한 대표적인 DP 문제.
// 이전에 풀었던 보석 도둑 문제가 생각났는데..
// 보석 도둑은 하나의 가방에 하나만 담을 수 있지만,
// 이 문제는 하나의 가방에 여러 물품을 담아 가치를 구하는 문제임.
//
// 가방과 가치라는 키워드 때문에 보석 도둑을 먼저 떠올렸던거 같다.
// -> 금방 아닌것은 알 수 있었지만..
//
// 
// memo  가방에 담을 수 있는 무게
// 
// 물
// 건
// 의
// 
// 개
// 수
// 
// 물건과 memo의 0을 비워두고 idx 1부터 진행하는 이유
// -> 이번 가방 무게의 최대 가치를 구해갈 때, N번째 물건을 담을 수 없다면,
//    이전 물건의 최대값을 그대로 가져와야 하는데, 첫 인덱스(1,1)부터
//    이전 물건의 최대값을 가져와야할 필요가 있기 때문임.
// 
//    분기 처리를 해도 괜찮지만 너무 지저분 해져서 저게 깔끔함.
// 
// 점화식
// 물건이 무거워서 담을 수 없을 때,
// DP[i - 1][k] => 이번 무게 중 이전 물건을 담았을 때의 가치를 가져와 기록.
// max(DP[i - 1][k = w[i]] + v[i], DP[i - 1][k])
// => 물건을 담을 수 있다면, 현재 물건의 가치와, 현재 물건을 담고 남은
//    무게 허용치를 채울 수 있는 것중 최대 가치를 더한 가치를 기록
//

int main()
{
	int N = 0, K = 0;
	vector<pair<int, int>> obj = {};
	obj.push_back({ 0, 0 });
	cin >> N >> K;
	for (size_t i = 0; i < N; ++i)
	{
		int W = 0, V = 0;
		cin >> W >> V;
		obj.push_back({ W, V });
	}

	vector<vector<int>> memo(N + 1, vector<int>(K + 1, 0));

	for (size_t j = 1; j <= K; ++j)
	{
		for (size_t i = 1; i <= N; ++i)
		{
			if (obj[i].first > j)
				memo[i][j] = memo[i - 1][j];
			else
				memo[i][j] = max(memo[i - 1][j - obj[i].first] + obj[i].second, memo[i - 1][j]);
		}
	}

	cout << memo[N][K];

	return 0;
}