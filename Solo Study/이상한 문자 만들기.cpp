#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";

    int cnt = 0;
    for (int i = 0; i < s.length(); ++i)
    {
        if (s[i] == ' ')
        {
            cnt = 0;
            answer += ' ';
            continue;
        }

        if (cnt % 2 == 0)
        {
            answer += toupper(s[i]);
        }
        else
        {
            answer += tolower(s[i]);
        }

        cnt++;
    }

    return answer;
}