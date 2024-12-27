#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
	int N;
	stack<int> st;

	cin >> N;
	for (int i = 0; i < N + 1; ++i)
	{
		string input;
		getline(cin, input);
		
		if (input.find("push") != string::npos)
		{
			input = input.substr(input.find(' ') + 1);
			int X = stoi(input);
			st.push(X);
		}
		else if (input == "pop")
		{
			if (!st.empty())
			{
				cout << st.top() << endl;
				st.pop();
			}
			else
				cout << -1 << endl;
		}
		else if (input == "size")
		{
			cout << st.size() << endl;
		}
		else if (input == "empty")
		{
			cout << (int)st.empty() << endl;
		}
		else if (input == "top")
		{
			if (!st.empty())
				cout << st.top() << endl;
			else
				cout << -1 << endl;
		}
	}

	return 0;
}