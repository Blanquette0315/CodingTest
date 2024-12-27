#include <iostream>
#include <string>
#include <vector>

using namespace std;

//int main()
//{
//	vector<int> vec_alpha(26, 0);
//	string s;
//
//	cin >> s;
//
//	for (int i = 0; i < s.length(); ++i)
//	{
//		vec_alpha[s[i] - 97]++;
//	}
//
//	for (int i = 0; i < vec_alpha.size(); ++i)
//	{
//		cout << vec_alpha[i] << " ";
//	}
//
//	return 0;
//}

int main()
{
	string s;
	cin >> s;
	
	for (char i = 'a'; i <= 'z'; ++i)
	{
		int cnt = 0;
		for (int j = 0; j < s.length(); ++j)
		{
			if (i == s[j])
				cnt++;
		}

		cout << cnt << " ";
	}

	return 0;
}