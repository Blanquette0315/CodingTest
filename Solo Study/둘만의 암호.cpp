#include <string>
#include <vector>

using namespace std;

string solution(string s, string skip, int index) {
	string answer = "";

	for (size_t i = 0; i < s.length(); ++i)
	{
		int num = 0;
		while (true)
		{
			num++;
			if (s.at(i) == *"z")
				s.at(i) = *"a";
			else
				s.at(i) += 1;

			if (skip.find(s.at(i)) != string::npos)
			{
				num--;
			}

			if (num == index)
				break;
		}
	}

	answer = s;

	return answer;
}