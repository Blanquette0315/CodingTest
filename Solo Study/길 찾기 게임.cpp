#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 어짜피 우선 순위나 후위 순위의 경우 트리만 만들고 나면
// 해당 트리 구조에 맞게 돌리면 되기 때문에 문제 될 것은 없다 판단.
// 
// 우선 처음에 어떻게 주어진 배열을 이용해 트리를 만들까를 생각함.
// 가장 먼저 떠오른 것은 직접 트리를 구현하는 것이고,
// 두번 째로 생각나고 하고 싶었던 것은 map을 이용한 방법이었는데
// map의 정렬 기준을 직접 정해주면 가능하지 않을까 생각함.
// 
// 검색해서 공부하다가 오늘은 다른 공부에 집중하고 싶어서 일단 다른 트리 구성 방법이 있나 찾아봄.
//
// 보니 구조체로 Node를 만들고, 해당 노드들을 배열에 담은 뒤 정렬한 뒤
// 자식 노드들을 연결해주는 방식이었음.
// 
// 어짜피 트리 만드는게 다인데, 해설을 봐버려서 그냥 보고 품..
// 
// 때문에 나중에 다시 풀어 봐야함.
//

struct tNode
{
    int iVal;
    int i_X;
    int i_Y;
    tNode* pLeftNode;
    tNode* pRightNode;
};

bool compare(tNode a, tNode b)
{
    if (a.i_Y == b.i_Y)
        return a.i_X < b.i_X;
    else
        return a.i_Y > b.i_Y;
}

void Make_Tree(tNode* RootNode, tNode* ChildNode)
{
    // 왼쪽 노드 판단은 x좌표를 기준으로 root가 더 커야 한다.
    if (RootNode->i_X > ChildNode->i_X)
    {
        //루트의 왼쪽이 널이면 바로 연결하고
        if (RootNode->pLeftNode == nullptr)
        {
            RootNode->pLeftNode = ChildNode;
            return;
        }
        // 아니라면, 루트의 왼쪽 노드가 루트일 때를 기준으로 다시 탐색
        Make_Tree(RootNode->pLeftNode, ChildNode);
    }
    else
    {
        if (RootNode->pRightNode == nullptr)
        {
            RootNode->pRightNode = ChildNode;
            return;
        }
        Make_Tree(RootNode->pRightNode, ChildNode);
    }
}

void PreOrder(tNode* RootNode, vector<int>& vec_preOrder)
{
    // 전위의 순서대로 루트의 왼쪽부터 쭉 파고들어가고, 이후 오른쪽으로 쭉 파고들어간다.
    // 보통 dfs를 진행할 때와 동일하게 진행됨.
    if (RootNode == nullptr) return;
    vec_preOrder.push_back(RootNode->iVal);
    PreOrder(RootNode->pLeftNode, vec_preOrder);
    PreOrder(RootNode->pRightNode, vec_preOrder);
}

void PostOrder(tNode* RootNode, vector<int>& vec_postOrder)
{
    // 후위 니까
    // 왼왼왼왼.... 노드가 리프라 return 오른쪽... 후 return이니까 결국
    // 왼쪽으로 쭉 타고 들어간 리프노드가 담기고
    // 이후 다시 리프의 부모노드로가서 우측 자식노드를 타고들어가 리프노드를 남김
    // 즉, 후위 순회다~
    if (RootNode == nullptr) return;
    PostOrder(RootNode->pLeftNode, vec_postOrder);
    PostOrder(RootNode->pRightNode, vec_postOrder);
    vec_postOrder.push_back(RootNode->iVal);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;

    vector<tNode> vec_Tree;
    for (size_t i = 0; i < nodeinfo.size(); ++i)
    {
        int x = nodeinfo[i][0];
        int y = nodeinfo[i][1];
        int iVal = i + 1;
        vec_Tree.push_back({ iVal, x, y, nullptr, nullptr });
    }

    // 주어진 조건에 따라 루트부터 아래 레벨들의 순서대로 정렬
    sort(vec_Tree.begin(), vec_Tree.end(), compare);

    for (size_t i = 1; i < vec_Tree.size(); ++i)
    {
        Make_Tree(&vec_Tree[0], &vec_Tree[i]);
    }

    vector<int> vec_preOrder;
    PreOrder(&vec_Tree[0], vec_preOrder);

    vector<int> vec_postOrder;
    PostOrder(&vec_Tree[0], vec_postOrder);

    answer.push_back(vec_preOrder);
    answer.push_back(vec_postOrder);

    return answer;
}

void main()
{
    vector<vector<int>> a = solution(vector<vector<int>>{ {5, 3}, { 11,5 }, { 13,3 }, { 3, 5 }, { 6,1 }
    , { 1,3 }, { 8, 6 }, { 7,2 }, { 2, 2 }});

    return;
}