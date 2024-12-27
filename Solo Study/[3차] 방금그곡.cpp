#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <regex>

using namespace std;

void Spelt_String(string _A, vector<string>& vec_string, char target)
{
    istringstream ss(_A);
    string Temp;

    while (getline(ss, Temp, target))
    {
        vec_string.push_back(Temp);
    }
}

int To_Min(string Time)
{
    vector<string> vec_temp;
    Spelt_String(Time, vec_temp, ':');

    int hour = stoi(vec_temp[0]);
    int min = stoi(vec_temp[1]);

    return min + (hour * 60);
}

int CulPlayTime(string Time_A, string Time_B)
{
    return To_Min(Time_B) - To_Min(Time_A);
}

bool compoare(string _A, string _B)
{
    vector<string> vec_temp_A;
    Spelt_String(_A, vec_temp_A, ',');
    vector<string> vec_temp_B;
    Spelt_String(_B, vec_temp_B, ',');

    int PlayTime_A = CulPlayTime(vec_temp_A[0], vec_temp_A[1]);
    int PlayTime_B = CulPlayTime(vec_temp_B[0], vec_temp_B[1]);

    return PlayTime_A > PlayTime_B;
}

string solution(string m, vector<string> musicinfos) {
    string answer = "(None)";

    stable_sort(musicinfos.begin(), musicinfos.end(), compoare);

    m = regex_replace(m, regex("C#"), "c");
    m = regex_replace(m, regex("D#"), "d");
    m = regex_replace(m, regex("F#"), "f");
    m = regex_replace(m, regex("G#"), "g");
    m = regex_replace(m, regex("A#"), "a");

    for (int i = 0; i < musicinfos.size(); ++i)
    {
        vector<string> vec_Temp;
        Spelt_String(musicinfos[i], vec_Temp, ',');
        int PlayTime = CulPlayTime(vec_Temp[0], vec_Temp[1]);
        vec_Temp[3] = regex_replace(vec_Temp[3], regex("C#"), "c");
        vec_Temp[3] = regex_replace(vec_Temp[3], regex("D#"), "d");
        vec_Temp[3] = regex_replace(vec_Temp[3], regex("F#"), "f");
        vec_Temp[3] = regex_replace(vec_Temp[3], regex("G#"), "g");
        vec_Temp[3] = regex_replace(vec_Temp[3], regex("A#"), "a");

        if (vec_Temp[3].length() < PlayTime)
        {
            while (vec_Temp[3].length() < PlayTime)
            {
                vec_Temp[3] += vec_Temp[3];
            }
        }
        else if (vec_Temp[3].length() > PlayTime)
        {
            vec_Temp[3] = vec_Temp[3].substr(0, PlayTime);
        }

        if (vec_Temp[3].find(m) != string::npos)
        {
            answer = vec_Temp[2];
            break;
        }
    }

    return answer;
}

void main()
{
    string answer = solution("CDCDF", { "13:50,14:02,WORLD,CDCDCDF" });

    int a = 0;

    return;
}