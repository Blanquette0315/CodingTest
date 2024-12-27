#include <string>
#include <vector>
#include <set>

// ũ�罺�� �˰����� �������� ���� ������ ����, �ش� �����
// �׷��� ã�� �׷��� �������� ã�� ����� ���ø�.
// �ش� �׷��� ������ ã�°� uion-find ����ε�, �� �̸��� �� ó�� �˾���.
// 
// �ƹ�ư ���Ͽ� ���ε带 �̿��ؼ� ������ Ǯ���µ�,
// ó���� ������ �׷� ������ �� ��, GetParnet�� Ÿ��Ÿ�� �ö� �ֻ��� �θ��带 Ȯ���ϴ°� �ƴ϶�
// �ܼ��� vec_Group�� �ִ� ����� ���� �θ�θ� ������ �����߾���.
// 
// ���� �ش� �κ��� ����������,
// �׷��� ���� ��, �̹� �Ǽ��� �ϰ� �־ 7,9���� Ʋ�Ⱦ���.
// 
//  0, 1, 2, 3
//  0, 1, 1, 0
// �϶�, 2�� 3�� �������� �� vector ������ ������ ���� �߾���.
// 
// 0, 1, 2, 3
// 0, 1, 0, 0
// ������ 1���� 2�� ����� �θ� ���谡 ���� �������� ���� ������ ����, 1�� �ƴ϶� 2�� ��ȯ �Ǿ���.
// 
// ������ �ǰ� �Ϸ���
// 0, 1, 2, 3
// 0, 0, 1, 0
// �̿��� �ϱ� ������ ���� ����� �ֻ��� �θ��� �޸� �����ؼ�
// �ű⿡ �θ� �׷�� ��ġ�ǵ��� ����� �ذ��� �־���.
// 
// ���Ͽ� ���ε带 �� �� �ڻ��� �� �� �־ ���Ҵ�.
// 
// 
// =======================
// ��� ���Ͽ� ���ε带 �̿����� �ʾƵ� DFS�� Ǯ�� �ִ�.
// �����̰� § �ڵ尡 �̷��µ�,
// ���� ������ �湮�ϸ鼭 visit ó�����ذ��� �ϴٰ� ������ �����, �׷� ī��Ʈ�� ������Ű��,
// ���� DFS ���� ���� ���� �湮���� ���� ���� �� ���� ���� ���� Ȯ���ϸ� �ȴ�.
// �ش� ����� �ڵ尡 �� ª�� ������ ���� Ǯ �� ���� �� ����.
// �ű�ٰ� �־��� ��� ������ 200������ �����̱� ������ �ð��� �γ��� �� ����.
//

using namespace std;

// �ش� ����� ����� �ֻ��� �θ� ã��
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
    // �׷� �����
    for (size_t i = 0; i < computers.size(); ++i)
    {
        vec_Group.push_back(i);
    }

    // �׷� ����
    for (size_t i = 0; i < computers.size(); ++i)
    {
        for (size_t j = i + 1; j < computers[0].size(); ++j)
        {
            if (computers[i][j] == 0)
                continue;

            int iGroupA = GetParents(vec_Group, vec_Group[i]);
            int iGroupB = GetParents(vec_Group, vec_Group[j]);
            // A�� B�� �̹� ���� �ֻ��� �θ� ������ �ִٸ�, ���� �Ұ���
            if (iGroupA == iGroupB)
                continue;
            // ������ A�� B�� �ֻ��� �θ� �ٸ��ٸ�, ���� ����
            else
            {
                // A�� B�� �ϳ��� �׷����� ����
                if (iGroupA < iGroupB)
                    vec_Group[GetParents(vec_Group, j)] = iGroupA;
                else if (iGroupA > iGroupB)
                    vec_Group[GetParents(vec_Group, i)] = iGroupB;
            }
        }
    }

    // �ϼ��� �׷� ���� ��ȸ
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