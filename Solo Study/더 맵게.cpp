#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;

    priority_queue<int, vector<int>, greater<int>> qu;
    for (int i = 0; i < scoville.size(); ++i)
    {
        qu.push(scoville[i]);
    }

    while (qu.top() < K)
    {
        if (qu.size() < 2)
        {
            answer = -1;
            break;
        }
        int Scov_frs = qu.top();
        qu.pop();
        int Scov_sec = qu.top();
        qu.pop();

        qu.push(Scov_frs + (Scov_sec * 2));
        answer++;
    }

    return answer;
}

void main()
{
    int answer = solution({ 1, 1, 2, 2, 6 }, 4);

    return;
}