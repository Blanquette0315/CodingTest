#include <string>
#include <vector>
#include <set>

using namespace std;

// 만약, 1, 1, 4, 7, 7, 5 라는 롤케이크가 주어진다면,
// A는   1, 1, 2, 3, 3, 4 로 나타낼 수 있고,
// 
//       5, 7, 7, 4, 1, 1 (B는 뒤쪽을 갖기 때문에 뒤집어줌.)
// B는   1, 2, 2, 3, 4, 4 로 나타낼 수 있다.
// 
// 만약 케이크를 다음과 같이 자른다면,
// 1, 1, 4, 7 | 7, 5
// 
// A는 1, 1, 4, 7로 총 3개의 토핑이고, A누적합 배열의 3번째 인덱스이다.
// B는 7, 5로 총 2개의 토핑이고, B누적합 배열의 2번째 인덱스다.  
// 
// 이처럼 A와 B의 각 상황에 따른 토핑 수 배열을 만들고 그를 이용해 문제를 풀면 됐었다.
// 
// 누적합을 이렇게 사용할 생각을 전혀 떠올리지 못해서 참신했다.
// 
// 또, 토핑이 총 10,000가지가 주어질 수 있는데
// bool 배열로 만들면.. 되겠지만 그보다는 set으로 키값으로 바로 찾아 검사할 수 있도록 하는것도
// 좋아보여서 그렇게 구현했다.
// (비트로도 해볼까 했는데 생각해보니 10,000자리 비트수는 좀..)
//

bool InsertTopping(set<int>& set_Memo, int iTopping)
{
    if (set_Memo.find(iTopping) == set_Memo.end())
    {
        set_Memo.insert(iTopping);
        return true;
    }
    
    return false;
}

int solution(vector<int> topping) {
    int answer = 0;

    set<int> setMemo_Topping_A;
    set<int> setMemo_Topping_B;
    vector<int> vec_Person_A;
    vector<int> vec_Person_B;

    int iMaxIdx = topping.size() - 1;
    int iTopCount_A = 0, iTopCount_B = 0;
    for (size_t i = 0; i < topping.size(); ++i)
    {
        if (InsertTopping(setMemo_Topping_A, topping[i]))
        {
            iTopCount_A++;
        }
        vec_Person_A.push_back(iTopCount_A);

        if (InsertTopping(setMemo_Topping_B, topping[iMaxIdx - i]))
        {
            iTopCount_B++;
        }vec_Person_B.push_back(iTopCount_B);
    }

    for (size_t j = 0; j < iMaxIdx; ++j)
    {
        if (vec_Person_A[j] == vec_Person_B[iMaxIdx -j - 1])
            answer++;
    }

    return answer;
}

void main()
{
    //int answer = solution(vector<int>{1, 2, 1, 3, 1, 4, 1, 2});
    int answer = solution(vector<int>{1, 1, 4, 7, 7, 5});

    int a = 0;

    return;
}