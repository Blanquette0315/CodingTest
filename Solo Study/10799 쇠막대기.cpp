#include <iostream>
#include <string>
#include <stack>

using namespace std;

// 2 : 26

int main()
{
	string str_Input;
	cin >> str_Input;

	stack<char> st;
	int answer = 0;
	bool Prev_Open = false;
	for (int i = 0; i < str_Input.length(); ++i)
	{
		if (str_Input[i] == '(')
		{
			st.push('(');
			Prev_Open = true;
		}

		else if (str_Input[i] == ')')
		{
			if (!st.empty() && st.top() == '(')
			{
				st.pop();

				if (Prev_Open)
					answer += st.size();

				else
					answer += 1;

				Prev_Open = false;
			}
		}
	}

	cout << answer;

	return 0;
}