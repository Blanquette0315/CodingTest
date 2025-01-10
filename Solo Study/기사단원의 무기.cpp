#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int number, int limit, int power) {
    int answer = 0;

    for (int i = 1; i <= number; ++i)
    {
        int iCount = 0;
        int iForCount = (int)sqrt(i);
        for (int j = 1; j <= iForCount; ++j)
        {
            if (i % j == 0)
            {
                iCount += 2;

                if (i / j == j)
                {
                    iCount -= 1;
                }
            }
        }

        int iAtk = iCount;
        if (iAtk <= limit)
        {
            answer += iAtk;
        }
        else
        {
            answer += power;
        }
    }

    return answer;
}