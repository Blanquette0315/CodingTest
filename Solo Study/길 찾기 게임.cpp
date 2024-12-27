#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// ��¥�� �켱 ������ ���� ������ ��� Ʈ���� ����� ����
// �ش� Ʈ�� ������ �°� ������ �Ǳ� ������ ���� �� ���� ���� �Ǵ�.
// 
// �켱 ó���� ��� �־��� �迭�� �̿��� Ʈ���� ���� ������.
// ���� ���� ������ ���� ���� Ʈ���� �����ϴ� ���̰�,
// �ι� °�� �������� �ϰ� �;��� ���� map�� �̿��� ����̾��µ�
// map�� ���� ������ ���� �����ָ� �������� ������ ������.
// 
// �˻��ؼ� �����ϴٰ� ������ �ٸ� ���ο� �����ϰ� �; �ϴ� �ٸ� Ʈ�� ���� ����� �ֳ� ã�ƺ�.
//
// ���� ����ü�� Node�� �����, �ش� ������ �迭�� ���� �� ������ ��
// �ڽ� ������ �������ִ� ����̾���.
// 
// ��¥�� Ʈ�� ����°� ���ε�, �ؼ��� �������� �׳� ���� ǰ..
// 
// ������ ���߿� �ٽ� Ǯ�� ������.
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
    // ���� ��� �Ǵ��� x��ǥ�� �������� root�� �� Ŀ�� �Ѵ�.
    if (RootNode->i_X > ChildNode->i_X)
    {
        //��Ʈ�� ������ ���̸� �ٷ� �����ϰ�
        if (RootNode->pLeftNode == nullptr)
        {
            RootNode->pLeftNode = ChildNode;
            return;
        }
        // �ƴ϶��, ��Ʈ�� ���� ��尡 ��Ʈ�� ���� �������� �ٽ� Ž��
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
    // ������ ������� ��Ʈ�� ���ʺ��� �� �İ����, ���� ���������� �� �İ����.
    // ���� dfs�� ������ ���� �����ϰ� �����.
    if (RootNode == nullptr) return;
    vec_preOrder.push_back(RootNode->iVal);
    PreOrder(RootNode->pLeftNode, vec_preOrder);
    PreOrder(RootNode->pRightNode, vec_preOrder);
}

void PostOrder(tNode* RootNode, vector<int>& vec_postOrder)
{
    // ���� �ϱ�
    // �޿޿޿�.... ��尡 ������ return ������... �� return�̴ϱ� �ᱹ
    // �������� �� Ÿ�� �� ������尡 ����
    // ���� �ٽ� ������ �θ���ΰ��� ���� �ڽĳ�带 Ÿ��� ������带 ����
    // ��, ���� ��ȸ��~
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

    // �־��� ���ǿ� ���� ��Ʈ���� �Ʒ� �������� ������� ����
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