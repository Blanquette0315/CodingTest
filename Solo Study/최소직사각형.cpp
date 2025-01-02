#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;

    int max_X = 0;
    int max_Y = 0;

    for (int i = 0; i < sizes.size(); ++i)
    {
        if (sizes[i][0] < sizes[i][1])
        {
            swap(sizes[i][0], sizes[i][1]);
        }

        max_X = max(max_X, sizes[i][0]);
        max_Y = max(max_Y, sizes[i][1]);
    }

    answer = max_X * max_Y;

    return answer;
}