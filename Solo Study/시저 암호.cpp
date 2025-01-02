#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = s;

    for (int i = 0; i < s.length(); ++i)
    {
        if (s[i] != ' ')
        {
            int temp = answer[i] + n;

            if (islower(s[i]))
            {
                if (temp > 'z')
                    answer[i] = char(temp - int('z' + 1 - 'a'));
                else
                    answer[i] += n;
            }
            else if (isupper(s[i]))
            {
                if (temp > 'Z')
                    answer[i] = char(temp - int('Z' + 1 - 'A'));
                else
                    answer[i] += n;
            }
        }
    }

    return answer;
}