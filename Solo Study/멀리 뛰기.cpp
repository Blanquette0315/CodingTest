#include <string>
#include <vector>

using namespace std;

// 직접 그려보니 결국 n의 가지수 = n-1을 만드는 가지수 + n-2을 만드는 가지수
// 이다.
// 
// 때문에 1, 2, 3을 기준으로 더해 나아가면 답을 구할 수 있을 것 같았다.
// 계속해 더해주기만 하면 되고, N은 최대 2000이기 때문에 속도가 느리지 않을거 같다는 판단을 하였다.
// 
// 사칙연산으로 인해 매번 1,234,567을 마지막에 나누지 않고, 각 가지수에 나눠서 더해주어도 괜찮다.
// 
// 원래라면 3번 인덱스부터 시작하도록 만드는건 별로지만.. 일단 이렇게 구현했다.
//

long long solution(int n) {
    long long answer = 0;

    if (n == 1)
        return 1;
    else if (n == 2)
        return 2;
    else if (n == 3)
        return 3;

    vector<int> Memo(n + 1);

    Memo[0] = 0;
    Memo[1] = 1;
    Memo[2] = 2;
    Memo[3] = 3;

    for (int i = 4; i < Memo.size(); ++i)
    {
        Memo[i] = (Memo[i - 1] + Memo[i - 2]) % 1234567;
    }

    answer = Memo.back();

    return answer;
}

void main()
{
    long long answer = solution(4);

    return;
}