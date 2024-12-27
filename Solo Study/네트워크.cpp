#include <string>
#include <vector>
#include <set>

// 크루스컬 알고리즘을 공부했을 때가 생각이 나서, 해당 방식중
// 그룹을 찾아 그룹을 기준으로 찾는 방법을 떠올림.
// 해당 그룹을 관리해 찾는게 uion-find 기법인데, 이 이름을 또 처음 알았음.
// 
// 아무튼 유니온 파인드를 이용해서 문제를 풀었는데,
// 처음에 마지막 그룹 개수를 샐 때, GetParnet로 타고타고 올라 최상위 부모노드를 확인하는게 아니라
// 단순히 vec_Group에 있는 노드의 본인 부모로만 돌려서 실패했었음.
// 
// 이후 해당 부분을 수정했지만,
// 그룹을 만들 때, 이미 실수를 하고 있어서 7,9번이 틀렸었다.
// 
//  0, 1, 2, 3
//  0, 1, 1, 0
// 일때, 2와 3을 연결했을 때 vector 갱신을 다음과 같이 했었다.
// 
// 0, 1, 2, 3
// 0, 1, 0, 0
// 때문에 1번과 2번 노드의 부모 관계가 완전 깨져버려 최종 개수를 샐때, 1이 아니라 2가 반환 되었다.
// 
// 연결을 옳게 하려면
// 0, 1, 2, 3
// 0, 0, 1, 0
// 이여야 하기 때문에 본인 노드의 최상위 부모쪽 메모에 접근해서
// 거기에 부모를 그룹과 일치되도록 만들어 해결해 주었다.
// 
// 유니온 파인드를 좀 더 자새히 알 수 있어서 좋았다.
// 
// 
// =======================
// 사실 유니온 파인드를 이용하지 않아도 DFS로 풀수 있다.
// 강현이가 짠 코드가 이랬는데,
// 앞쪽 노드부터 방문하면서 visit 처리를해가며 하다가 연결이 끊기면, 그룹 카운트를 증가시키고,
// 다음 DFS 시작 노드는 아직 방문하지 않은 노드들 중 가장 작은 값을 확인하면 된다.
// 해당 방법이 코드가 더 짧게 나오고 쉽게 풀 수 있을 것 같다.
// 거기다가 주어진 노드 개수도 200까지가 제한이기 때문에 시간도 널널할 것 같다.
//

using namespace std;

// 해당 노드의 연결된 최상위 부모 찾기
int GetParents(vector<int>& vec_Group, int iTarget)
{
    if (vec_Group[iTarget] == iTarget)
        return iTarget;
    else
        return GetParents(vec_Group, vec_Group[iTarget]);
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;

    vector<int> vec_Group;
    // 그룹 만들기
    for (size_t i = 0; i < computers.size(); ++i)
    {
        vec_Group.push_back(i);
    }

    // 그룹 연결
    for (size_t i = 0; i < computers.size(); ++i)
    {
        for (size_t j = i + 1; j < computers[0].size(); ++j)
        {
            if (computers[i][j] == 0)
                continue;

            int iGroupA = GetParents(vec_Group, vec_Group[i]);
            int iGroupB = GetParents(vec_Group, vec_Group[j]);
            // A와 B가 이미 같은 최상위 부모를 가지고 있다면, 연결 불가능
            if (iGroupA == iGroupB)
                continue;
            // 연결할 A와 B가 최상위 부모가 다르다면, 연결 가능
            else
            {
                // A와 B를 하나의 그룹으로 연결
                if (iGroupA < iGroupB)
                    vec_Group[GetParents(vec_Group, j)] = iGroupA;
                else if (iGroupA > iGroupB)
                    vec_Group[GetParents(vec_Group, i)] = iGroupB;
            }
        }
    }

    // 완성된 그룹 갯수 조회
    int iCount = 0;
    set<int> Set_Group;
    for (size_t i = 0; i < vec_Group.size(); ++i)
    {
        if (Set_Group.find(GetParents(vec_Group, vec_Group[i])) == Set_Group.end())
        {
            Set_Group.insert(GetParents(vec_Group, vec_Group[i]));
            iCount++;
        }
    }

    answer = iCount;

    return answer;
}


void main()
{
    //int answer = solution(3, vector<vector<int>>{ {1, 1, 0}, { 1,1,0 }, { 0,0,1 }});
    int answer = solution(4, vector<vector<int>>{ {1, 0, 0, 1}, { 0, 1, 1, 0 }, { 0,1,1,1 }, {1, 0, 1, 1}});

    return;
}