#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// 굳이 unordered_map을 안써도
// map의 [] 접근이 가능했다..
// 그리고 map의 [] 오퍼레이터를 사용할 때, 키값이 없으면, 자동으로 insert 해준다.
// https://80000coding.oopy.io/8af406a3-b3b1-4f3f-b190-2937b23684ed
//
// 하나하나 반복문 돌면서 찾는게 제일 직관적이긴 하지만
// 시간이 너무 오래걸릴거 같아서 문제였음.
// 
// 그러다 생각한게, 정수를 기준으로 갯수를 세고,
// 해당 개수를 기준으로 정렬을 해주면,
// 개수가 많은거 부터서 확인하면, 가지수 세는게 훨씬 간단해보였음.
// 
// 때문에 map이나 unordered_map으로 키를 수, 값을 개수로하여 정렬해 풀었음
// 그래도 시간이 좀 걸리는데, 시간초과는 나지 않지만 더 효율적인 방법이 없을지 고민중..
//

bool cmp(pair<int, int>& A, pair<int, int>& B)
{
    return A.second > B.second;
}

int solution(int k, vector<int> tangerine) {
    int answer = 0;

    unordered_map<int,int> memo = {};
    for (size_t i = 0; i < tangerine.size(); ++i)
    {
        // 아직 등록되지 않았다면, 등록해준다.
        if (memo.find(tangerine[i]) == memo.end())
            memo.insert({ tangerine[i], 1 });
        else
            // 등록되어 있다면 값 1증가
            memo[tangerine[i]] += 1;
    }

    vector<pair<int, int>> vecMomo(memo.begin(), memo.end());
    sort(vecMomo.begin(), vecMomo.end(), cmp);

    int Idx = 0, cnt = 0;
    // 이거는 main의 case 2 때 오류남. vector 없는 인덱스 접근으로 인해
    /*while (cnt < k)
    {
        cnt += vecMomo[Idx].second;
        Idx++;
        answer++;
    }*/

    while (Idx < vecMomo.size())
    {
        if (cnt >= k)
            break;

        cnt += vecMomo[Idx].second;
        Idx++;
        answer++;
    }

    return answer;
}

void main()
{
    //int anwer = solution(6, vector<int>{1, 3, 2, 5, 4, 5, 2, 3});
    int anwer = solution(10, vector<int>{1});

    return;
}