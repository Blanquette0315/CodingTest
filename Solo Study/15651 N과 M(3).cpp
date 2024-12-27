#include <iostream>
#include <vector>

using namespace std;

// 03:12 03:23 => 10

void func(vector<int>& vec_Num, int N, int M, int k)
{
	if (k == M)
	{
		for (int i = 0; i < vec_Num.size(); ++i)
		{
			cout << vec_Num[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 1; i <= N; ++i)
	{
		vec_Num[k] = i;
		func(vec_Num, N, M, k + 1);
	}
}

int main()
{
	int N = 0, M = 0;
	cin >> N >> M;

	vector<int> vec_Num(M, 0);
	func(vec_Num, N, M, 0);


	return 0;
}