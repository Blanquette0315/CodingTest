#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <math.h>

using namespace std;

int hour_to_min(string time)
{
    /*int hour = stoi(time.substr(0, 2));
    int min = stoi(time.substr(time.find(":") + 1, 2));

    min += hour * 60;

    return min;*/

    return stoi(time.substr(0, 2)) * 60 + stoi(time.substr(time.find(":") + 1, 2));
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;

    unordered_map<string, int> Memo;
    unordered_map<string, int> Memo_In;

    for (int i = 0; i < records.size(); ++i)
    {
        int time = hour_to_min(records[i].substr(0, records[i].find(" ")));
        records[i].erase(0, records[i].find(" ") + 1);
        string number = records[i].substr(0, records[i].find(" "));
        records[i].erase(0, records[i].find(" ") + 1);
        string type = records[i].substr(0, records[i].find(" "));

        if (type == "IN")
        {
            Memo_In.insert({ number, time });
        }
        else
        {
            Memo[number] += (time - Memo_In[number]);
            Memo_In.erase(number);
        }
    }

    int end_time = hour_to_min(string("23:59"));

    while (!Memo_In.empty())
    {
        string number = Memo_In.begin()->first;
        int time = Memo_In.begin()->second;

        Memo[number] += end_time - time;

        Memo_In.erase(number);
    }

    vector<pair<string,int>> vec_Memo(Memo.begin(), Memo.end());
    sort(vec_Memo.begin(), vec_Memo.end());
    
    for (int i = 0; i < vec_Memo.size(); ++i)
    {
        int fee = fees[1];
        vec_Memo[i].second -= fees[0];
        if (vec_Memo[i].second > 0)
        {
            int a = ceil((float)vec_Memo[i].second / (float)fees[2]);
            fee += a * fees[3];
        }

        answer.push_back(fee);
    }


    return answer;
}

void main()
{
    vector<int> answer = solution(vector<int>{180, 5000, 10, 600}, vector<string>{"05:34 5961 IN", "06:00 0000 IN", "06:34 0000 OUT", "07:59 5961 OUT", "07:59 0148 IN", "18:59 0000 IN", "19:09 0148 OUT", "22:59 5961 IN", "23:00 5961 OUT"});
    // vector<int> answer = solution(vector<int>{120, 0, 60, 591}, vector<string>{"16:00 3961 IN", "16:00 0202 IN", "18:00 3961 OUT", "18:00 0202 OUT", "23:58 3961 IN"});
    // vector<int> answer = solution(vector<int>{1, 461, 1, 10}, vector<string>{"00:00 1234 IN"});


    return;
}