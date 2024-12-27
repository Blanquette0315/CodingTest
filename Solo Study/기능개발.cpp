#include <string>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

// ó���� ���� �տ��� ���� ���������� �Ϸ�� �ͱ��� �Ϸ翡 �����ϱ� queue�� ����ϸ� �ǰڴ� ���ø�.
// ó������ �־��� ���α׷����� �ε����� ������ �� ���̶� �����ؼ� pair<int,int>�� ����.
// 
// ���� while������ ������ ®�µ�, �̶� ����ī��Ʈ�� ������, ����Ŭ�� 1ȸ ���Ҵ��� Ȯ���� �ȵǴ� ������ �߻�
// ����Ŭ 1ȸ�� �Ϸ簡 �����ٴ� ���̱� ������ �׶����� �ٽ� �պ��� ��ð� ���������� �ٽ� �Ǵ��� �� �־ �ʿ���.
// 
// ������ ����ü�� Ȱ���� ��带 ����� �ʿ��� ����� ���α׷����� �ε��� �׸��� ����ī��Ʈ�� ����ֵ��� ����.
// 
// 30�� ���� �ɸ�.
//

struct tNode
{
    int iCurProgress;
    int iIdx;
    int iLoofCount;

    tNode(int i_Progress, int i_Idx, int i_Loof)
        : iCurProgress(i_Progress)
        , iIdx(i_Idx)
        , iLoofCount(i_Loof) {}
};

vector<int> solution(vector<int> progresses, vector<int> speeds)
{
    vector<int> answer;
    queue<tNode> q;

    for (size_t i = 0; i < progresses.size(); ++i)
    {
        q.push(tNode(progresses[i], i, 0));
    }

    int iPrevLoofCount = -1;
    bool bCheck = false;
    while (!q.empty())
    {
        auto iCurNode = q.front();
        q.pop();

        int iNewProgress = iCurNode.iCurProgress + speeds[iCurNode.iIdx];
        int iCurLoofCount = iCurNode.iLoofCount;

        if (iPrevLoofCount != iCurLoofCount)
        {
            if (100 <= iNewProgress)
            {
                bCheck = true;
                answer.push_back(1);
            }
            else
            {
                q.push(tNode(iNewProgress, iCurNode.iIdx, iCurLoofCount + 1));
            }

            iPrevLoofCount = iCurLoofCount;
        }
        else
        {
            if (100 <= iNewProgress && bCheck)
            {
                answer.back() += 1;
            }
            else
            {
                q.push(tNode(iNewProgress, iCurNode.iIdx, iCurLoofCount + 1));
                bCheck = false;
            }
        }
    }

    return answer;
}

void main()
{
    vector<int> answer = solution(vector<int>{99, 96, 94}, vector<int>{1, 3, 4});

    int a = 0;

    return;
}

// ������ Ǯ���� ����� ���̵� �ſ� ���Ҿ �ƽ����� �������� ������.
// �ش� ���̵��� �־��� ���α׷����� �Ϸ�Ƿ��� �� ���� �ɸ��Ŀ� ������ �ΰ� Ǭ ���̵���.
// ������ ������ �տ������� ó���ؾ��ϱ� ������ �ܼ� for������ �迭�� �ѹ��� ��ȸ�ص� �ظ� ���� �� �ִ�.
// 
// �̰� ��ĳ �����ߴ�..
// 
// �ƹ�ư �ȵ� ������
//  iday = (int)ceil((100 - progresses[i]) / speeds[i]);
// �����̾��µ�,
// progresses[]�� speed[]�� ���� int �ڷ����̱� ������
// (100 - progresses[i]) / speeds[i]�� ����� float���� ���� ���� �ƴ϶� int������ ����ȯ �Ǿ����
// ��� ���� ������ �Ǿ������ ��������.
// 
// ��, �̹� �������� ������ �ظ� �ٽ� �ø��ع����ϱ� �������� ��.
// �ø����� Ǯ���� �ø��� ��µ�, ����ó���� �ǰ� �־��� ��.
// ������ ceil�� �־��ֱ��� float���� ������� �޵��� ������ �־���.
// 

//vector<int> solution(vector<int> progresses, vector<int> speeds) {
//    vector<int> answer;
//
//    int imaxday = 0;
//
//    for (size_t i = 0; i < progresses.size(); ++i)
//    {
//        int iday = 0;
//        iday = (int)ceil((float)(100 - progresses[i]) / speeds[i]);
//
//        if (imaxday < iday)
//        {
//            imaxday = iday;
//            answer.push_back(1);
//        }
//        else
//        {
//            answer.back() += 1;
//        }
//    }
//
//    return answer;
//}