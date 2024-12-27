#include <string>
#include <vector>


// https://school.programmers.co.kr/questions/25161
// �����ؼ� ��ȭ���� ������ Ǯ��.
//
// ������ DP ������ �ϳ�����, ���ؿ��� ����.
// 
// https://www.acmicpc.net/problem/2293
// ���� ���ؿ����� �Ž����� ���� 
//

using namespace std;

int solution(int n, vector<int> money) {
    int answer = 0;

    vector<int> vec_Memo(n + 1, 0);
    vec_Memo[0] = 1;

    for (size_t i = 0; i < money.size(); ++i)
    {
        for (size_t j = money[i]; j < n + 1; ++j)
        {
            vec_Memo[j] += vec_Memo[j - money[i]];
        }
    }

    answer = vec_Memo.back();

    return answer;
}

void main()
{
    int answer = solution(5, vector<int>{1, 2, 5});

    return;
}