#include <iostream>
#include <math.h>

// Âü°í
// https://ahgus89.github.io/algorithm/Harmonic-Lemma/

using namespace std;

int main()
{
	int n = 0;
	cin >> n;

	unsigned long long result = n != 1 ? n + 1 : 1;
	for (unsigned long long i = 2, j = 0; i < n; i = j + 1)
	{
		j = (n - 1) / ((n - 1) / i);
		result += (j - i + 1) * (1 + ((n - 1) / i));
	}

	cout << result;

	return 0;
}

//int main()
//{
//	int n = 0;
//	cin >> n;
//
//	unsigned long long loop = 1 + ((n - 1) / 2);
//	unsigned long long result = (n - loop) * 2 + 1;
//	for (unsigned long long i = 1; i < loop; ++i)
//	{
//		result += 1 + ((n - 1) / i);
//	}
//
//	cout << result;
//
//	return 0;
//}

//int main()
//{
//	int n = 0;
//	cin >> n;
//
//	unsigned long long loop = ceil((float)n / (float)2);
//	unsigned long long result = (n - ceil((float)n / (float)2)) * 2 + 1;
//	for (unsigned long long i = 1; i < loop; ++i)
//	{
//		result += ceil((float)n / (float)i);
//	}
//
//	cout << result;
//	
//	return 0;
//}