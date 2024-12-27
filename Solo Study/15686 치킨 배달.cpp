#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ������ ���� ���� ġŲ�� ����ŭ idx �迭�� ����� next_permutation�� �̿���
// ��� ����� ���� Ž���ϸ� ���� �� ���Ҵ�.
// 
// ������ �ٸ� �������� Ư�� �迭���� next_permutation�� �ϸ鼭 �ܼ���
// �κи� ���� �ʹٰ� ���ʸ� Ȯ���ϸ�, ��� ����� ���� üũ���� ���ؼ� ��� �ؾ�����
// ���� �ȿԴ�.
// ex) [0,1,2,3,4,5]�̰�, �� �� �˻��� ����� 3�̸�,
// next_permutation() �� 0,1,2 �ε����� Ȯ���ϸ� �ȵȴٴ� ��.
//
// ã�ƺ��� [0,1,2,3,4,5]�� �ƴ϶�
// [0,0,1,1,1]�� �����صΰ�, next_permutation�� �̿��ϸ�,
// ���ϴ� ����� ���� ���� �� �־���.
// 
// �ش� ����� ���ø��� ���Ѱ� ��������....
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

	// next_permutation�� ����� ��� �������� Ž���ϱ� ���� �迭 �غ�
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