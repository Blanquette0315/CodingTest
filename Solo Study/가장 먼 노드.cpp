#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

// ó���� ������ ���ڸ��� ���� ����̳� ���� ����Ʈ�� �����, ���� Ʈ���� ����� Ȯ���� �ʿ䰡 ���ٰ� ������.
// ���� Ž�� ����� DFS�� BFS�� ����� ��������� ����ߴµ�,
// BFS�� ��� �ᱹ �׷����� Level ������ ����Ǳ� ������ ������ Level�� ��ġ���ִ� ������ ���� �Ÿ� ����� ������ ��.
// ������� �����ϴ� �� ���� ������ �Ǿ��µ�... ��
// 
// ���� ����Ʈ�� ���� ����߿����� ���� ����Ʈ�� �޸� ����� �� �ΰ�, �Ϸ� �ϴ� �۾����� �˸´� �����ؼ� ä��.
// 
// ���� �������� BFS�� ���������,
// ���� ��尡 �߰ߵǸ� iCount�� �������ִ� ������� ®� ������ �Ǿ���.
// 
// ���� �Ÿ� ��带 ã�� ������ ������ ���� ���� �߿����� ���� ���� Level�� ��ġ���ִ� ���鸸 ������ �����־�� ��.
// ������ iDistance�� �߰��� ������ Ǯ���־���.
// �ش� ������ �� �������� �ʾƼ� �ð��� ���� �� �ɷ���.
//

// ��~~~~~~~~~~~~~~ ���� ���!
// queue 2���� ����ϸ�, �Ÿ� ��� �� ����!
// 
// �̷��� ����ϸ� ���� ����Ʈ�� ����� ���� �ɵ�?
// unordered_map<int, pair<vector<int>, pair<int,bool>>>
//

struct tNodeInfo
{
    int iNode;
    int iDistance;
};

int BFS(vector<vector<int>>& vec_adj, vector<bool>& vec_visit)
{
    int iDistance = 0;

    map<int,int> map_Distance;
    queue<tNodeInfo> qu;
    qu.push({1, 0});
    vec_visit[1] = true;

    while (!qu.empty())
    {
        bool bCheck = false;
        tNodeInfo tNode = qu.front();
        qu.pop();
       
        iDistance = tNode.iDistance;
        for (size_t i = 0; i < vec_adj[tNode.iNode].size(); ++i)
        {
            int iNextNode = vec_adj[tNode.iNode][i];

            if (vec_visit[iNextNode])
                continue;

            qu.push({ iNextNode, tNode.iDistance + 1 });
            bCheck = true;
            vec_visit[iNextNode] = true;
        }

        if (!bCheck)
        {
            if (map_Distance.find(tNode.iDistance) == map_Distance.end())
                map_Distance.insert(make_pair(tNode.iDistance, 1));
            else
                map_Distance.find(tNode.iDistance)->second += 1;
        }
    }

    return map_Distance.find(iDistance)->second;
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;

    vector<bool> vec_visit(n + 1, false);
    vector<vector<int>> vec_adj(n + 1, vector<int>());

    for (size_t i = 0; i < edge.size(); ++i)
    {
        vec_adj[edge[i][0]].push_back(edge[i][1]);
        vec_adj[edge[i][1]].push_back(edge[i][0]);
    }

    answer = BFS(vec_adj, vec_visit);

    return answer;
}

void main()
{
    int answer = solution(6, vector<vector<int>>{ {3, 6}, { 4, 3 }, { 3,2 }, { 1,3 }, { 1, 2 }, { 2, 4 }, { 5,2 }});

    return;
}


// queue 2���� �� Ǯ��
int BFS(vector<vector<int>>& vec_adj, vector<bool>& vec_visit)
{
    int iCount = 0;

    queue<int> q, p;
    q.push(1);
    vec_visit[1] = true;

    while (!q.empty())
    {
        iCount = 0;

        while (!q.empty())
        {
            int iNode = q.front();
            q.pop();

            iCount++;

            for (size_t i = 0; i < vec_adj[iNode].size(); ++i)
            {
                int iNextNode = vec_adj[iNode][i];

                if (vec_visit[iNextNode])
                    continue;

                p.push(iNextNode);
                vec_visit[iNextNode] = true;
            }
        }

        if (!p.empty())
            q.swap(p);
    }

    return iCount;
}