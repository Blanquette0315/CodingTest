#include <string>
#include <vector>

using namespace std;

bool check(int level, vector<int>& arrY)
{
    for (int i = 0; i < level; ++i)
    {
        if (arrY[i] == arrY[level]
            || abs(arrY[level] - arrY[i]) == level - i)
            return false;
    }
    return true;
}

void NQueen(int Y, vector<int>& arrY, int N, int& answer)
{
    if (Y == N)
        answer++;
    else
    {
        for (int i = 0; i < N; ++i)
        {
            arrY[Y] = i;
            if (check(Y, arrY))
                NQueen(Y + 1, arrY, N, answer);
        }
    }
}

int solution(int n) {
    int answer = 0;

    vector<int> arrY(n, 0);

    NQueen(0, arrY, n, answer);

    return answer;
}

void main()
{
    int answer = solution(4);


    return;
}