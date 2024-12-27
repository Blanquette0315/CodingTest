#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

int solution(vector<vector<int> > land)
{
    int answer = 0;
    
    for (int i = 1; i < land.size(); ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            vector<int> temp = land[i - 1];
            temp[j] = -1;

            land[i][j] += *max_element(temp.begin(), temp.end());
        }
    }

    answer = *max_element(land[land.size() - 1].begin(), land[land.size() - 1].end());

    return answer;
}

void main()
{
    int answer = solution(vector<vector<int>>{ {5, 3, 2, 1}, { 8,7,6,5 }, { 1,2,3,4 } });
    return;
}