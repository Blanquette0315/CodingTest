#include <iostream>

using namespace std;

// 그냥 간단히 규칙을 찾아서 푼 문제였다.
// 하지만 더 찾아보니 2로 나누는 것이기 때문에 비트 연산을 이용하면 훨씬 빠르고 쉽게 풀 수 있다는 것을 알게 되었다.
//
// (비트 연산 풀이 참고)
// https://mungto.tistory.com/205

int solution(int n, int a, int b)
{
    int answer = 0;

    while (true)
    {
        answer++;
         
        // 정답 확인
        // 짝수 - 홀수를 한 결과가 1인지 확인해야함.
        // 2 - 1 즉, a b 가 각각 1 2인것.
        // 2 - 3 즉, a b 가 각각 2 3인것. (2 3은 서로 대결하는 구도가 아니기 때문에 한번 더 진행해야함.)
        if (a % 2 == 0)
        {
            if(a - b == 1)
            {
                break;
            }
        }
        else
        {
            if (b - a == 1)
            {
                break;
            }
        }

        // a와 b 갱신
        if (a % 2 == 0)
            a /= 2;
        else
            a = a / 2 + 1;

        if (b % 2 == 0)
            b /= 2;
        else
            b = b / 2 + 1;
    }

    return answer;
}

void main()
{
    int answer = solution(8, 4, 7);

    return;
}