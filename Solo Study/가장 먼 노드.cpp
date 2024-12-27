#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

// 처음에 문제를 보자마자 인접 행렬이나 인접 리스트로 만들면, 굳이 트리를 만들어 확인할 필요가 없다고 생각함.
// 이후 탐색 방법을 DFS와 BFS중 어느걸 사용할지를 고민했는데,
// BFS의 경우 결국 그래프의 Level 단위로 진행되기 때문에 마지막 Level에 위치해있는 노드들이 최장 거리 노드라는 생각을 함.
// 여기까지 생각하는 건 정말 빠르게 되었는데... 쩝
// 
// 인접 리스트와 인접 행렬중에서는 인접 리스트가 메모리 비용이 더 싸고, 하려 하는 작업에도 알맞다 생각해서 채택.
// 
// 위를 바탕으로 BFS를 만들었지만,
// 리프 노드가 발견되면 iCount를 증가해주는 방식으로 짰어서 문제가 되었음.
// 
// 최장 거리 노드를 찾는 문제기 때문에 리프 노드들 중에서도 가장 깊은 Level에 위치해있는 노드들만 개수를 세어주어야 함.
// 때문에 iDistance를 추가해 문제를 풀어주었음.
// 해당 내용이 잘 떠오르지 않아서 시간이 조금 더 걸렸음.
//

// 개~~~~~~~~~~~~~~ 좋은 방법!
// queue 2개를 사용하면, 거리 계산 쌉 가능!
// 
// 이렇게 사용하면 인접 리스트좀 깔끔히 정리 될듯?
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


// queue 2개로 한 풀이
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