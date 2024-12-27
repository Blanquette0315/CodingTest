#include <string>
#include <vector>

using namespace std;

int StringToSeconds(string strtime)
{
    string hour = strtime.substr(0, 2);
    string min = strtime.substr(3, 2);
    string second = strtime.substr(6, 2);
    return stoi(hour) * 3600 + stoi(min) * 60 + stoi(second);
}

string SecondsToString(int Second)
{
    string time;
    int hour = Second / 3600;
    int min = (Second % 3600) / 60;
    int second = Second % 60;

    if (hour <= 9)
        time += "0";
    time += to_string(hour) + ":";
    if (min <= 9)
        time += "0";
    time += to_string(min) + ":";
    if (second <= 9)
        time += "0";
    time += to_string(second);

    return time;
}

string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "";

    int playtime = StringToSeconds(play_time);
    int  advtime = StringToSeconds(adv_time);



    return answer;
}

void main()
{
    string answer = solution("02:03:55", "00:14:15", vector<string>{"01:20:15-01:45:14", "00:40:31-01:00:00", "00:25:50-00:48:29", "01:30:59-01:53:29", "01:37:44-02:02:30"});

    return;
}