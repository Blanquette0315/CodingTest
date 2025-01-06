#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> food) {
    string answer = "";

    string strTemp;
    for (int i = 1; i < food.size(); ++i)
    {
        for (int j = 0; j < food[i] / 2; ++j)
        {
            strTemp += to_string(i);
        }
    }

    answer += strTemp + '0';
    reverse(strTemp.begin(), strTemp.end());
    answer += strTemp;

    return answer;
}