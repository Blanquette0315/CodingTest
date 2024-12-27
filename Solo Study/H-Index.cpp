#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// https://dev-musa.tistory.com/entry/%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%A8%B8%EC%8A%A4-%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-Level-2-H-Index-%EC%BD%94%ED%8B%80%EB%A6%B0
//
// 이거 문제가 좀 그렇다.. 에바임..
//

int solution(vector<int> citations) {
    int answer = 0;

    // 0, 1, 3, 5, 6
    sort(citations.begin(), citations.end());

    int n = citations.size();

    for (size_t i = 0; i < citations.size(); ++i)
    {
        if (citations[i] >= n)
            break;
        else
            n--;
    }

    answer = n;

    return answer;
}

void main()
{
    int answer = solution(vector<int>{3, 0, 6, 1, 5});

    return;
}