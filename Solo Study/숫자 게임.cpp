#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// ó������ �ܼ��� ������ �� ��, 2�� �ݺ������� ������ �˻����ָ鼭,
// �ܼ��� break ó�������� �ð� ���⵵�� ���̷� �ߴ�.
// 
// ������, ȿ���� �׽�Ʈ�� ��������, vector�� erase()���� �ð��� �����ɸ������� ��� ������ ��.
// �ֳ��ϸ�, vector�� Ư�� ���Ұ� �������� �ڿ����� ���ܿ;��ϱ� ������.
// 
// ������ bool���� �̿��� vsist ó���� ���������� ����� �����ߴ�.
// 
// �Ƹ� vector�� earse�� �ܼ��� �޸� �̵��� �̷������ ���̱� ������ ����� �׷��� ũ�� ���� �� �ִ�.
// 
// �ᱹ 2�� �ݺ��� ���°� ��ü�� ������ ������
// 
// upper_bound�� �̿��� Ǯ�� �Ǿ���.
// �Ƹ� upper_bound ��ü�� �̺� Ž���̶� �ݺ��� ������ �ݺ��� �����°� ���� �ξ� ȿ�����̱��ϴ�.
//

//int solution(vector<int> A, vector<int> B) {
//    int answer = 0;
//    sort(A.begin(), A.end(), greater<int>());
//    sort(B.begin(), B.end());
//
//    for (size_t AIdx = 0; AIdx < A.size(); ++AIdx)
//    {
//        for (vector<int>::iterator BIter = B.begin(); BIter != B.end(); ++BIter)
//        {
//            if (A[AIdx] < *BIter)
//            {
//                answer++;
//                B.erase(BIter);
//                break;
//            }
//        }
//    }
//
//    return answer;
//}

int solution(vector<int> A, vector<int> B) {
    int answer = 0;

    sort(A.begin(), A.end(), greater<int>());
    sort(B.begin(), B.end());

    for (size_t AIdx = 0; AIdx < A.size(); ++AIdx)
    {
        auto BIter = upper_bound(B.begin(), B.end(), A[AIdx]);
        if(BIter != B.end()
            && A[AIdx] < *BIter)
        {
            answer++;
            B.erase(BIter);
        }
    }

    return answer;
}

void main()
{

    int answer = solution(vector<int>{5, 1, 3, 7}, vector<int>{2, 2, 6, 8});

    int a = 0;

    return;
}