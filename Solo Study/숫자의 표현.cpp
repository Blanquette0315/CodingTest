#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;

    for (int i = 1; i <= n; ++i)
    {
        int sum = 0;
        for (int j = i; j <= n; ++j)
        {
            if (sum <= n)
                sum += j;
            else
                break;

            if (sum == n)
                answer++;
        }
    }

    return answer;
}

void main()
{
    int answer = solution(15);

    return;
}