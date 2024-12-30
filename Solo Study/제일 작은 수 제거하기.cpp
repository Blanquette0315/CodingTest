#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;

    if (arr.size() == 1)
        answer.push_back(-1);
    else
    {
        int minNum = 0x3f3f3f3f;
        int idx = 0;
        for (int i = 0; i < arr.size(); ++i)
        {
            minNum = min(minNum, arr[i]);
            if (minNum == arr[i])
            {
                idx = i;
            }
        }

        arr.erase(arr.begin() + idx);
        answer = arr;
    }

    return answer;
}