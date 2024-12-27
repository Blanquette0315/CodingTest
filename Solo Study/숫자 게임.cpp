#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 처음에는 단순히 정렬을 한 뒤, 2중 반복문으로 조건을 검사해주면서,
// 단순히 break 처리만으로 시간 복잡도를 줄이려 했다.
// 
// 하지만, 효율성 테스트에 떨어져서, vector의 erase()에서 시간이 오래걸리나보다 라는 생각을 함.
// 왜냐하면, vector의 특정 원소가 지워지면 뒤에꺼를 땡겨와야하기 때문에.
// 
// 때문에 bool값을 이용한 vsist 처리로 변경했으나 결과는 동일했다.
// 
// 아마 vector의 earse는 단순히 메모리 이동이 이루어지는 것이기 때문에 비용이 그렇게 크지 않을 수 있다.
// 
// 결국 2중 반복을 도는것 자체가 문제로 보여서
// 
// upper_bound를 이용해 풀게 되었다.
// 아마 upper_bound 자체가 이분 탐색이라 반복문 내에서 반복을 돌리는것 보다 훨씬 효율적이긴하다.
//

//int solution(vector<int> A, vector<int> B) {
//    int answer = 0;
//    sort(A.begin(), A.end(), greater<int>());
//    sort(B.begin(), B.end());
//
//    for (size_t AIdx = 0; AIdx < A.size(); ++AIdx)
//    {
//        for (vector<int>::iterator BIter = B.begin(); BIter != B.end(); ++BIter)
//        {
//            if (A[AIdx] < *BIter)
//            {
//                answer++;
//                B.erase(BIter);
//                break;
//            }
//        }
//    }
//
//    return answer;
//}

int solution(vector<int> A, vector<int> B) {
    int answer = 0;

    sort(A.begin(), A.end(), greater<int>());
    sort(B.begin(), B.end());

    for (size_t AIdx = 0; AIdx < A.size(); ++AIdx)
    {
        auto BIter = upper_bound(B.begin(), B.end(), A[AIdx]);
        if(BIter != B.end()
            && A[AIdx] < *BIter)
        {
            answer++;
            B.erase(BIter);
        }
    }

    return answer;
}

void main()
{

    int answer = solution(vector<int>{5, 1, 3, 7}, vector<int>{2, 2, 6, 8});

    int a = 0;

    return;
}