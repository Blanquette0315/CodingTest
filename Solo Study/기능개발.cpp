#include <string>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

// 처음에 보고 앞에서 부터 순차적으로 완료된 것까지 하루에 배포니까 queue를 사용하면 되겠다 떠올림.
// 처음에는 주어진 프로그래스와 인덱스만 있으면 될 것이라 생각해서 pair<int,int>로 만듦.
// 
// 이후 while문으로 루프를 짰는데, 이때 루프카운트가 없으면, 사이클을 1회 돌았는지 확인이 안되는 문제가 발생
// 사이클 1회는 하루가 지났다는 것이기 때문에 그때부터 다시 앞부터 출시가 가능한지를 다시 판단할 수 있어서 필요함.
// 
// 때문에 구조체를 활용해 노드를 만들어 필요한 멤버인 프로그래스와 인덱스 그리고 루프카운트를 담아주도록 만듦.
// 
// 30분 정도 걸림.
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

// 이전에 풀었던 방법이 아이디어가 매우 좋았어서 아쉬워서 문제점을 수정함.
// 해당 아이디어는 주어진 프로그래스가 완료되려면 몇 일이 걸리냐에 중점을 두고 푼 아이디어다.
// 심지어 조건이 앞에서부터 처리해야하기 때문에 단순 for문으로 배열을 한번만 순회해도 해를 구할 수 있다.
// 
// 이걸 어캐 생각했누..
// 
// 아무튼 안된 이유는
//  iday = (int)ceil((100 - progresses[i]) / speeds[i]);
// 때문이었는데,
// progresses[]와 speed[]의 값이 int 자료형이기 때문에
// (100 - progresses[i]) / speeds[i]의 결과가 float으로 계산된 것이 아니라 int값으로 형변환 되어버려
// 결과 값이 내림이 되어버린게 문제였다.
// 
// 즉, 이미 내림으로 구해진 해를 다시 올림해버리니까 문제였던 것.
// 올림으로 풀려고 올림을 썼는데, 내림처리가 되고 있었던 것.
// 때문에 ceil에 넣어주기전 float으로 계산결과를 받도록 변경해 주었다.
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