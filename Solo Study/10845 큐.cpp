#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main()
{
	int N;
	queue<int> qu;
	cin >> N;

	for (int i = 0; i < N + 1; ++i)
	{
		string input;
		getline(cin, input);

		if (input.find("push") != string::npos)
		{
			int X = stoi(input.substr(input.find(' ') + 1));
			qu.push(X);
		}
		else if (input == "pop")
		{
			if (!qu.empty())
			{
				cout << qu.front() << endl;
				qu.pop();
			}
			else
				cout << -1 << endl;
		}
		else if (input == "size")
		{
			cout << qu.size() << endl;
		}
		else if (input == "empty")
		{
			cout << (int)qu.empty() << endl;
		}
		else if (input == "front")
		{
			if (!qu.empty())
				cout << qu.front() << endl;
			else
				cout << -1 << endl;
		}
		else if (input == "back")
		{
			if (!qu.empty())
				cout << qu.back() << endl;
			else
				cout << -1 << endl;
		}
	}


	return 0;
}