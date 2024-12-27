#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
	while (true)
	{
		string str_Sentence;
		getline(cin, str_Sentence);

		if (str_Sentence == ".")
			break;

		bool Is_Sentence = true;
		stack<char> st;
		for (int i = 0; i < str_Sentence.length(); ++i)
		{
			if (Is_Sentence)
			{
				if (str_Sentence[i] == '(')
					st.push('(');
				else if (str_Sentence[i] == '[')
					st.push('[');
				else if (str_Sentence[i] == ')')
				{
					if (st.empty())
						Is_Sentence = false;
					else
					{
						if (st.top() == '(')
						{
							st.pop();
						}
						else
						{
							Is_Sentence = false;
						}
					}
				}
				else if (str_Sentence[i] == ']')
				{
					if (st.empty())
						Is_Sentence = false;
					else
					{
						if (st.top() == '[')
						{
							st.pop();
						}
						else
						{
							Is_Sentence = false;
						}
					}
				}
				else if (str_Sentence[i] == '.')
				{
					if (st.empty())
					{
						Is_Sentence = true;
						cout << "yes" << endl;
					}
					else
					{
						Is_Sentence = true;
						cout << "no" << endl;
					}
				}
			}
			else
			{
				if (str_Sentence[i] == '.')
				{
					Is_Sentence = true;
					cout << "no" << endl;
					while (!st.empty())
						st.pop();
				}
			}
		}
	}

	return 0;
}