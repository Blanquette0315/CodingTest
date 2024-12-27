#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main()
{
	int N = 0;
	deque<int> dq;

	cin >> N;

	for (int i = 0; i < N + 1; ++i)
	{
		string input;
		getline(cin, input);

		if (input.find("push_back") != string::npos)
		{
			int X = stoi(input.substr(input.find(' ') + 1));
			dq.push_back(X);
		}
		else if (input.find("push_front") != string::npos)
		{
			int X = stoi(input.substr(input.find(' ') + 1));
			dq.push_front(X);
		}
		else if (input == "pop_front")
		{
			if (!dq.empty())
			{
				cout << dq.front() << endl;
				dq.pop_front();
			}
			else
				cout << -1 << endl;
		}
		else if (input == "pop_back")
		{
			if (!dq.empty())
			{
				cout << dq.back() << endl;
				dq.pop_back();
			}
			else
				cout << -1 << endl;
		}
		else if (input == "size")
		{
			cout << dq.size() << endl;
		}
		else if (input == "empty")
		{
			cout << (int)dq.empty() << endl;
		}
		else if (input == "front")
		{
			if (!dq.empty())
				cout << dq.front() << endl;
			else
				cout << -1 << endl;
		}
		else if (input == "back")
		{
			if (!dq.empty())
				cout << dq.back() << endl;
			else
				cout << -1 << endl;
		}
	}

	return 0;
}