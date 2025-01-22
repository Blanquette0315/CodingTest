#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;

    for (int i = 0; i < babbling.size(); ++i)
    {
        int flag = 0;
        bool check = true;
        for (int j = 0; j < babbling[i].length(); ++j)
        {
            if (babbling[i].substr(j, 3) == "aya" && flag != 1)
            {
                flag = 1;
                j += 2;
            }
            else if (babbling[i].substr(j, 2) == "ma" && flag != 2)
            {
                flag = 2;
                j += 1;
            }
            else if (babbling[i].substr(j, 3) == "woo" && flag != 3)
            {
                flag = 3;
                j += 2;
            }
            else if (babbling[i].substr(j, 2) == "ye" && flag != 4)
            {
                flag = 4;
                j += 1;
            }
            else
            {
                check = false;
                break;
            }
        }
        if (check)
            answer++;
    }


    return answer;
}