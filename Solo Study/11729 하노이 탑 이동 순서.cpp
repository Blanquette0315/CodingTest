#include <iostream>

using namespace std;

// 05:07

void move(int a, int b, int n)
{
	if (n == 1)
	{
		cout << a << ' ' << b << '\n';
		return;
	}
	move(a, 6 - a - b, n - 1);
	cout << a << ' ' << b << '\n';
	move(6 - a - b, b, n - 1);
}

int main()
{
	int n = 0;
	cin >> n;
	cout << (1 << n) - 1 << '\n';  // (1<<n) = 2^n
	move(1, 3, n);

	return 0;
}