#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;

    map<string, int> map_table;

    char Word = 'A';
    int Idx = 1;
    while (Word != 'Z' + 1)
    {
        map_table.insert({ string(1, Word), Idx});
        Idx++;
        Word++;
    }

    int nxt_Idx = 0;
    string c = string(1, msg[nxt_Idx]);
    bool Is_Last = false;
    while (true)
    {
        bool Is_Find = false;
        string w = "";
        do
        {
            w += c;
            if (map_table.find(w) == map_table.end())
            {
                answer.push_back(map_table.find(w.substr(0, w.length() - 1))->second);
                map_table.insert({ w, Idx++ });
                Is_Find = true;
            }
            else
            {
                if (nxt_Idx == msg.length() - 1)
                {
                    Is_Last = true;
                    break;
                }
                else
                {
                    c = string(1, msg[++nxt_Idx]);
                }
            }
        } while (!Is_Find);

        if (Is_Last)
        {
            answer.push_back(map_table.find(w)->second);
            break;
        }
    }

    return answer;
}

void main()
{
    vector<int> answer = solution("KAKAO");

    int a = 0;

    return;
}