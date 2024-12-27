#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 문제를 보자 마자 치킨집 수만큼 idx 배열을 만들어 next_permutation을 이용해
// 모든 경우의 수를 탐색하면 좋을 것 같았다.
// 
// 하지만 다른 문제에서 특정 배열에서 next_permutation을 하면서 단순히
// 부분만 보고 싶다고 앞쪽만 확인하면, 모든 경우의 수를 체크하지 못해서 어떻게 해야할지
// 감이 안왔다.
// ex) [0,1,2,3,4,5]이고, 이 중 검사할 사이즈가 3이면,
// next_permutation() 후 0,1,2 인덱스만 확인하면 안된다는 것.
//
// 찾아보니 [0,1,2,3,4,5]가 아니라
// [0,0,1,1,1]로 세팅해두고, next_permutation을 이용하면,
// 원하는 경우의 수를 뽑을 수 있었다.
// 
// 해당 방법을 떠올리지 못한게 문제였다....
//

int main()
{
	int N = 0, M = 0;
	
	cin >> N >> M;

	vector<pair<int, int>> Home;
	vector<pair<int, int>> Mart;

	for (size_t i = 0; i < N; ++i)
	{
		for (size_t j = 0; j < N; ++j)
		{
			int Type = 0;
			cin >> Type;

			if (Type == 1)
				Home.push_back({ i,j });
			else if(Type == 2)
				Mart.push_back({ i,j });
		}
	}

	// next_permutation을 사용해 모든 가지수를 탐색하기 위한 배열 준비
	vector<int> Select(Mart.size() - M, 0);
	Select.insert(Select.end(), M, 1);

	int Minsum = 0x3f3f3f3f;;
	do
	{
		int sum = 0;
		for (size_t i = 0; i < Home.size(); ++i)
		{
			int MinDistance = 0x3f3f3f3f;
			for (size_t j = 0; j < Mart.size(); ++j)
			{
				if (Select[j] == 1)
				{
					int Distance = abs(Home[i].first - Mart[j].first) + abs(Home[i].second - Mart[j].second);
					MinDistance = min(MinDistance, Distance);
				}
			}

			sum += MinDistance;
		}

		Minsum = min(Minsum, sum);

	} while (next_permutation(Select.begin(), Select.end()));

	cout << Minsum;

	return 0;
}