#include <string>
#include <vector>
#include <queue>

using namespace std;

// 스킬 트리배열 최대 20, 스킬의 문자열 길이 최대 26
// 문자하나하나 확인한다 해도 20*26
// 어짜피 효율성 테스트도 없어서 완전 탐색도 넉넉할거 같았음..
// 
// 단순히 for문이랑 if문 써서 해봤는데 너무 난잡해지고, 꼬이는 문제가 발생함.
// 
// 때문에 우선순위 큐를 이용해서 하는 방법을 생각해봄.ㅇㅇ
//
// 우선순위 큐 정렬 
// less일때 꼬이는거 좀더 연구해보기.... ㅜㅜ
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
            // 만약 skill의 이번 인덱스 원소가 이번 검사하는 문장에 있다면,
            if (skill_trees[i].find(skill[j]) != string::npos)
            {
                // 인덱스와 스킬을 우선순위큐에 등록
                pq.push({ skill_trees[i].find(skill[j]), skill[j]});
            }
        }

        int cnt = 0;
        bool check = true;
        // 큐 순회하면서 조건 확인
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