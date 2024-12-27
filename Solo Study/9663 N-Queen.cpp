#include <iostream>
#include <vector>

using namespace std;

void func(vector<bool>& vis1, vector<bool>& vis2, vector<bool>& vis3, int cur, int& cnt)
{
	if (cur == vis1.size())
	{
		cnt++;
		return;
	}

	for (int i = 0; i < vis1.size(); ++i)
	{
		if (vis1[i] || vis2[i + cur] || vis3[cur - i + vis1.size() - 1])
			continue;

		vis1[i] = true;
		vis2[i + cur] = true;
		vis3[cur - i + vis1.size() - 1] = true;
		func(vis1, vis2, vis3, cur + 1, cnt);
		vis1[i] = false;
		vis2[i + cur] = false;
		vis3[cur - i + vis1.size() - 1] = false;
	}
}

int main()
{
	int N = 0;
	cin >> N;

	vector<bool> vis1(N, false);
	vector<bool> vis2(N + N - 1, false);
	vector<bool> vis3(N + N - 1, false);
	int cnt = 0;

	func(vis1, vis2, vis3, 0, cnt);

	cout << cnt;

	return 0;
}