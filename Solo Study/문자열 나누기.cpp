#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;

    string str_Test = "";
    str_Test += s.at(0);
    s.erase(s.begin());

    while (true)
    {
        char cTarget = str_Test.at(0);

        int iSameCount = 0;
        int iDefCount = 0;

        for (size_t i = 0; i < str_Test.length(); ++i)
        {
            if (cTarget == str_Test.at(i))
                iSameCount++;
            else
                iDefCount++;
        }

        if (iSameCount == iDefCount)
        {
            answer++;

            if (!s.empty())
            {
                str_Test.clear();
                str_Test += s.at(0);
                s.erase(s.begin());
            }
            else
                return answer;
        }
        else
        {
            if (!s.empty())
            {
                str_Test += s.at(0);
                s.erase(s.begin());
            }
            else
                return ++answer;
        }
    }
}