#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;

    map<int, int> Memo;

    for (int i = 0; i < s.length(); ++i)
    {
        if (Memo.find(s[i]) == Memo.end())
        {
            Memo.insert({ s[i], i });
            answer.push_back(-1);
        }
        else
        {
            answer.push_back(i - Memo.find(s[i])->second);
            Memo.find(s[i])->second = i;
        }
    }

    return answer;
}