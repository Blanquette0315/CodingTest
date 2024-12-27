#include <string>
#include <vector>

using namespace std;

// ���� �׷����� �ᱹ n�� ������ = n-1�� ����� ������ + n-2�� ����� ������
// �̴�.
// 
// ������ 1, 2, 3�� �������� ���� ���ư��� ���� ���� �� ���� �� ���Ҵ�.
// ����� �����ֱ⸸ �ϸ� �ǰ�, N�� �ִ� 2000�̱� ������ �ӵ��� ������ ������ ���ٴ� �Ǵ��� �Ͽ���.
// 
// ��Ģ�������� ���� �Ź� 1,234,567�� �������� ������ �ʰ�, �� �������� ������ �����־ ������.
// 
// ������� 3�� �ε������� �����ϵ��� ����°� ��������.. �ϴ� �̷��� �����ߴ�.
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