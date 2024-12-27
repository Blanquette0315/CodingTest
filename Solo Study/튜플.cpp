#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    s.erase(s.begin(), s.begin() + 1);
    s.erase(s.rfind('}'), 1);

    unordered_map<int, int> Memo;

    while (!s.empty())
    {
        string substr = s.substr(s.find('{') + 1, s.find('}') - 1);
        s.erase(s.find('{'), s.find('}') + 1);

        if(s[0] == ',')
            s.erase(s.begin(), s.begin() + 1);

        while (!substr.empty())
        {
            string str_num = substr.substr(0, substr.find(','));
            if (substr.find(',') == string::npos)
                substr.clear();
            else
                substr.erase(0, substr.find(',') + 1);

            Memo[stoi(str_num)]++;
        }
    }

    vector<pair<int, int>> vec_Memo(Memo.begin(), Memo.end());

    sort(vec_Memo.begin(), vec_Memo.end(), [](pair<int, int> first, pair<int, int> second) -> bool
        {
            return first.second > second.second;
        });

    for (size_t i = 0; i < vec_Memo.size(); ++i)
        answer.push_back(vec_Memo[i].first);

    return answer;
}

void main()
{
    vector<int> answer = solution("{{2},{2,1},{2,1,3},{2,1,3,4}}");

    return;
}