#include <iostream>
#include <string>
using namespace std;

// �縰���(pailindrome) �̶� �յڸ� ����� �Ȱ��� ���ڿ��� �ǹ��Ѵ�.
//
// ù�� ° ���̵��� ���ڿ��� ���� ���̺��� �����̵� ������ ������� ã�� ���̴�.
// ó���� 17, 18�� ���̽��� Ʋ�ȴµ�,
// ���� ab�� ��� �縰����� ���� ������ 0�� ��ȯ�ߴµ�,
// a�� b�� �ɰ��� ��� ������ ����� ���� ������ ��ǻ� ���� �ϳ��� �縰����̾���.
// ������ 1�� ��ȯ���ֵ��� �������.
// 
// ������ ȿ���� �׽�Ʈ���� 1������ �ð� �ʰ��� ���ͼ� ���� ȿ������ ����� ���� �����غ��� �Ǿ���.
// 
// ������ �ȳ��� �����۵��� ���캻 ���
// string.substr() �Լ��� O(N)�̶�� �ð����⵵�� ���� ������
// ���ڿ��� �������� �ʰ� ���� �ε����� �����ϴ°��� �ξ� �ð��� �� ��ٴ� ���� �˾Ҵ�.
// 
// �ð��� ���� 2�� ���� ���̰� ���ٰ� �Ѵ�.
//
// �����̲� ���ϱ� �� �����͸� �̿��� Ǯ�̵� �����ϰ� �ξ� ȿ�����̴�.
// mid�� �о��ָ鼭 ã�� ���..
// 
// 
// 
// XOR ��Ʈ �����ڷ� �����غ���.
//


// �Ʒ� �ڵ�� substr()�� �̿��� Ǭ ��. ������ ȿ���� �׽�Ʈ 1���� �����Ѵ�.

//bool findpailind(string str_SubString)
//{
//    int iLeftIdx = 0;
//    int iRightIdx = str_SubString.size() - 1;
//
//    while (iLeftIdx < iRightIdx)
//    {
//        if (str_SubString[iLeftIdx] != str_SubString[iRightIdx])
//            return false;
//
//        iLeftIdx++;
//        iRightIdx--;
//    }
//
//    return true;
//}
//
//int solution(string s)
//{
//    int answer = 1;
//
//    for (size_t i = s.length(); i > 1; --i)
//    {
//        for (size_t j = 0; j < s.length() + 1 - i; ++j)
//        {
//            string str_SubStrin = s.substr(j, i);
//            if (findpailind(str_SubStrin))
//            {
//                answer = str_SubStrin.length();
//                return answer;
//            }
//        }
//    }
//
//    return answer;
//}

bool findpailind(int LeftIdx, int RightIdx, const string& str_string)
{
    int iLeftIdx = LeftIdx;
    int iRightIdx = RightIdx;

    while (iLeftIdx < iRightIdx)
    {
        if (str_string[iLeftIdx] != str_string[iRightIdx])
            return false;

        iLeftIdx++;
        iRightIdx--;
    }

    return true;
}

int solution(string s)
{
    int answer = 1;

    for (size_t i = s.length(); i > 1; --i)
    {
        for (size_t j = 0; j < s.length() + 1 - i; ++j)
        {
            if (findpailind(j, j + i - 1 ,s))
            {
                answer = i;
                return answer;
            }
        }
    }

    return answer;
}

void main()
{
    int answer = solution("abddcba");

    int a = 0;

    return;
}