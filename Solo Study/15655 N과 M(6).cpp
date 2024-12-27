#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void func(vector<int>& Input, vector<int>& Num, int M, int loop_i, int k)
{
	if (k == M)
	{
		for (int i = 0; i < Num.size(); ++i)
		{
			cout << Num[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = loop_i; i < Input.size(); ++i)
	{
		Num[k] = Input[i];
		func(Input, Num, M, i + 1, k + 1);
	}
}

int main()
{
	int N = 0, M = 0;
	cin >> N >> M;

	vector<int> vec_Input(N, 0);
	vector<int> vec_Num(M, 0);

	for (int i = 0; i < N; ++i)
	{
		cin >> vec_Input[i];
	}

	sort(vec_Input.begin(), vec_Input.end(), less<int>());

	func(vec_Input, vec_Num, M, 0, 0);

	return 0;
}