#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;

    map<string, string> map_User;
    vector<pair<string,string>> vec_Record;
    for (int i = 0; i < record.size(); ++i)
    {
        string str_IO = record[i].substr(0, record[i].find(' '));
        record[i].erase(0, record[i].find(' ') + 1);
        string str_UID = "";
        string str_NickName = "";
        if (record[i].find(' ') != string::npos)
        {
            str_UID = record[i].substr(0, record[i].find(' '));
            record[i].erase(0, record[i].find(' ') + 1);
            str_NickName = record[i];
        }
        else
            str_UID = record[i];

        if (str_IO == "Enter")
        {
            if (map_User.find(str_UID) == map_User.end())
            {
                map_User.insert({ str_UID, str_NickName });
            }
            else
            {
                if (map_User.find(str_UID)->second != str_NickName)
                    map_User.find(str_UID)->second = str_NickName;
            }
            vec_Record.push_back({ str_UID, "E" });
        }
        else if (str_IO == "Leave")
        {
            vec_Record.push_back({ str_UID, "L" });
        }
        else if (str_IO == "Change")
        {
            map_User.find(str_UID)->second = str_NickName;
        }
    }

    for (int i = 0; i < vec_Record.size(); ++i)
    {
        string str_Output = map_User.find(vec_Record[i].first)->second;
        if (vec_Record[i].second == "E")
        {
            str_Output += "님이 들어왔습니다.";
        }
        else if (vec_Record[i].second == "L")
        {
            str_Output += "님이 나갔습니다.";
        }
        answer.push_back(str_Output);
    }

    return answer;
}

void main()
{
    vector<string> answer = solution({ "Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan" });

    int a = 0;

    return;
}