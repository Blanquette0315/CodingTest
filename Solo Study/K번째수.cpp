#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;

    for (int i = 0; i < commands.size(); ++i)
    {
        vector<int> newVector;
        int stIdx = commands[i][0] - 1;
        int endIdx = commands[i][1] - 1;
        int targetIdx = commands[i][2] - 1;

        for (int j = stIdx; j <= endIdx; ++j)
        {
            newVector.push_back(array[j]);
        }

        sort(newVector.begin(), newVector.end());

        answer.push_back(newVector[targetIdx]);
    }

    return answer;
}