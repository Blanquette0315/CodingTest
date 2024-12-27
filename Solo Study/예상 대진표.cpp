#include <iostream>

using namespace std;

// �׳� ������ ��Ģ�� ã�Ƽ� Ǭ ��������.
// ������ �� ã�ƺ��� 2�� ������ ���̱� ������ ��Ʈ ������ �̿��ϸ� �ξ� ������ ���� Ǯ �� �ִٴ� ���� �˰� �Ǿ���.
//
// (��Ʈ ���� Ǯ�� ����)
// https://mungto.tistory.com/205

int solution(int n, int a, int b)
{
    int answer = 0;

    while (true)
    {
        answer++;
         
        // ���� Ȯ��
        // ¦�� - Ȧ���� �� ����� 1���� Ȯ���ؾ���.
        // 2 - 1 ��, a b �� ���� 1 2�ΰ�.
        // 2 - 3 ��, a b �� ���� 2 3�ΰ�. (2 3�� ���� ����ϴ� ������ �ƴϱ� ������ �ѹ� �� �����ؾ���.)
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

        // a�� b ����
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