#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;

    map<char, int> map_Key;

    for (int i = 0; i < keymap.size(); ++i)
    {
        for (int j = 0; j < keymap[i].size();++j)
        {
            if (map_Key.find(keymap[i][j]) == map_Key.end())
            {
                map_Key.insert({ keymap[i][j], j + 1 });
            }
            else
            {
                if (map_Key.find(keymap[i][j])->second > j + 1)
                {
                    map_Key.find(keymap[i][j])->second = j + 1;
                }
            }
        }
    }

    for (int i = 0; i < targets.size(); ++i)
    {
        bool none = false;
        int cnt = 0;
        for (int j = 0; j < targets[i].size(); ++j)
        {
            if (map_Key.find(targets[i][j]) == map_Key.end())
            {
                none = true;
                break;
            }
            else
            {
                cnt += map_Key.find(targets[i][j])->second;
            }
        }

        if (none)
        {
            answer.push_back(-1);
            none = false;
            continue;
        }
        else
        {
            answer.push_back(cnt);
        }
    }

    return answer;
}

void main()
{
    vector<int> answer = solution({ "ABACD", "BCEFD" }, { "ABCD", "AABB" });

    return;
}