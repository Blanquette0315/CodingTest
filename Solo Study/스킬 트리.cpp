#include <string>
#include <vector>
#include <queue>

using namespace std;

// ��ų Ʈ���迭 �ִ� 20, ��ų�� ���ڿ� ���� �ִ� 26
// �����ϳ��ϳ� Ȯ���Ѵ� �ص� 20*26
// ��¥�� ȿ���� �׽�Ʈ�� ��� ���� Ž���� �˳��Ұ� ������..
// 
// �ܼ��� for���̶� if�� �Ἥ �غôµ� �ʹ� ����������, ���̴� ������ �߻���.
// 
// ������ �켱���� ť�� �̿��ؼ� �ϴ� ����� �����غ�.����
//
// �켱���� ť ���� 
// less�϶� ���̴°� ���� �����غ���.... �̤�
//

//struct cmp {
//    bool operator()(pair<int, char>& A, pair<int, char>& B)
//    {
//        return A.first < B.first;
//    }
//};

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    
    for (size_t i = 0; i < skill_trees.size(); ++i)
    {
        priority_queue<pair<int, char>, vector<pair<int,char>>, greater<pair<int, char>>> pq{};
        //priority_queue<pair<int, char>> pq{};

        for (size_t j = 0; j < skill.length(); ++j)
        {
            // ���� skill�� �̹� �ε��� ���Ұ� �̹� �˻��ϴ� ���忡 �ִٸ�,
            if (skill_trees[i].find(skill[j]) != string::npos)
            {
                // �ε����� ��ų�� �켱����ť�� ���
                pq.push({ skill_trees[i].find(skill[j]), skill[j]});
            }
        }

        int cnt = 0;
        bool check = true;
        // ť ��ȸ�ϸ鼭 ���� Ȯ��
        while (!pq.empty())
        {
            pair<int, char> pq_top = pq.top();
            pq.pop();

            if (skill[cnt] != pq_top.second)
                check = false;

            cnt++;
        }

        if (check)
            answer++;
    }

    return answer;
}

void main()
{
    int answer = solution("CBD", vector<string>{"BACDE", "CBADF", "AECB", "BDA"});
    //int answer = solution("CBDK", vector<string>{"CB", "CXYB", "BD", "AECD", "ABC", "AEX", "CDB", "CBKD", "IJCB", "LMDK"});

    return;
}




//int solution(string skill, vector<string> skill_trees) {
//    int answer = 0;
//
//    for (size_t i = 0; i < skill_trees.size(); ++i)
//    {
//        bool bcnt = true;
//        bool prevnpos = false;
//        int prevIdx = string::npos;
//        int Idx = 0;
//        while (Idx < skill.length())
//        {
//            if (skill_trees[i].find(skill[Idx]) != string::npos)
//            {
//                prevIdx = skill_trees[i].find(skill[Idx]);
//                Idx++;
//                break;
//            }
//            else
//            {
//                bcnt = false;
//                goto EXIT;
//            }
//
//            Idx++;
//        }
//
//        for (;Idx < skill.length(); ++Idx)
//        {
//            if (skill_trees[i].find(skill[Idx]) != string::npos)
//            {
//                if (prevIdx > skill_trees[i].find(skill[Idx]))
//                {
//                    bcnt = false;
//                    break;
//                }
//            }
//            else
//            {
//                if (!prevnpos)
//                    prevnpos = true;
//                else
//                {
//                    bcnt = false;
//                    break;
//                }
//            }
//        }
//
//    EXIT:
//        if (bcnt)
//            answer++;
//    }
//
//    return answer;
//}