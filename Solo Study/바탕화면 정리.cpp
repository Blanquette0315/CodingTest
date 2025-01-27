#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
	vector<int> answer = { -1, -1, 0, 0 };

	for (size_t i = 0; i < wallpaper.size(); ++i)
	{
		size_t find = wallpaper[i].find('#');

		if (find != string::npos)
		{
			if (answer[0] == -1)
				answer[0] = i;
			if (answer[1] == -1)
				answer[1] = find;

			answer[0] = min((int)i, answer[0]);
			answer[1] = min((int)find, answer[1]);
			answer[2] = max((int)i, answer[2]);
			answer[3] = max((int)find, answer[3]);
		}

		while (true)
		{
			find = wallpaper[i].find('#', find + 1);
			if (find != string::npos)
			{
				if (answer[0] == -1)
					answer[0] = i;
				if (answer[1] == -1)
					answer[1] = find;

				answer[0] = min((int)i, answer[0]);
				answer[1] = min((int)find, answer[1]);
				answer[2] = max((int)i, answer[2]);
				answer[3] = max((int)find, answer[3]);
			}
			else
				break;
		}
	}

	answer[2] += 1;
	answer[3] += 1;

	return answer;
}