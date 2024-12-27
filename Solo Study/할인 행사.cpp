#include <iostream>
#include <vector>
#include <map>

using namespace std;

// unordered_map을 처음에 사용했는데, 그때는 코어 덤프가 났었다.
// 왜 그러는지 조사를 해보아야 할 것 같다.
// 또 처음에 테스트 케이스 11번만 틀렸었는데, 1일차 부터 가입을 했을 시, 10일간 할인품목에 모두 포함되기 때문에 처음부터 검사하는 부분이 포함 되어야 한다.

// 중복되는 코드가 많아서 함수화를 했다.

bool Inspection(vector<string>& want, vector<int>& number, map<string, int>& memo)
{
    for (int j = 0; j < want.size(); ++j)
    {
        if (memo.find(want[j]) == memo.end() || number[j] > memo.find(want[j])->second)
        {
            return false;
        }
    }

    return true;
}

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;

    map<string, int> memo;
    for (int i = 0; i < 10; ++i)
    {
        if (memo.find(discount[i]) == memo.end())
            memo.insert(make_pair(discount[i], 1));
        else
            memo.find(discount[i])->second++;
    }

    if (Inspection(want, number, memo))
        answer++;

    for (int i = 10; i < discount.size(); ++i)
    {
        memo.find(discount[i - 10])->second--;

        if (memo.find(discount[i]) == memo.end())
            memo.insert(make_pair(discount[i], 1));
        else
            memo.find(discount[i])->second++;

        if (Inspection(want, number, memo))
            answer++;
    }

    return answer;
}

void main()
{
    int answer = solution({ "apple"}, {10}, { "banana", "banana", "banana", "banana", "banana", "banana", "banana", "banana", "banana", "banana" });

    int a = 0;

    return;
}