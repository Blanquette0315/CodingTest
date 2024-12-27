#include <iostream>
#include <vector>

using namespace std;

void func(vector<int>& vec_Num, int N, int M, int loop_i, int k)
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

	for (int i = loop_i; i <= N; ++i)
	{
		vec_Num[k] = i;
		func(vec_Num, N, M, i, k + 1);
	}
}

int main()
{
	int N = 0, M = 0;
	cin >> N >> M;
	
	vector<int> vec_Num(M, 0);
	func(vec_Num, N, M, 1, 0);

	return 0;
}