#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> weak, vector<int> dist) {
    int answer = 0x3f3f3f3f;
    int w_size = weak.size();

    // 반시계 방향도 처리하기 위해 확장
    for (size_t i = 0; i < w_size - 1; ++i)
    {
        weak.push_back(weak[i] + n);
    }

    sort(dist.begin(), dist.end());

    for (size_t i = 0; i < w_size; ++i)
    {
        int iStart = weak[i];
        int iEnd = weak[i + w_size - 1];

        for
    }
    
    

    return answer;
}

void main()
{
    int answer = solution(12, vector<int>{1, 5, 6, 10 }, vector<int>{1, 2, 3, 4});

    return;
}