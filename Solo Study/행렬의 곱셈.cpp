#include <string>
#include <vector>

using namespace std;

// 1 4   3 3  (a1[0][0] * a2[0][0] + a1[0][1] * a2[1][0]) (a1[0][0] * a2[1][0] + a1[0][1] * a2[1][1])
// 3 2   3 3  (a1[1][0] * a2[0][0] + a1[1][1] * a2[1][0]) (a1[1][0])
// 4 1        15 15

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer(arr1.size(), vector<int>(arr2[0].size(), 0));

    for (int i = 0; i < answer.size(); ++i)
    {
        for (int j = 0; j < answer[0].size(); ++j)
        {
            for (int k = 0; k < arr1[0].size(); ++k)
            {
                answer[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }

    return answer;
}

void main()
{
    vector<vector<int>> answer = solution({{1, 4}, {3, 2}, {4, 1}}, {{3, 3}, {3, 3}});

    int a = 0;

    return;
}