#include <string>
#include <algorithm>
#include <vector>

using namespace std;

// 그냥 단순히 A와 B의 앞자리 부터 비교하는 로직을 제일 먼저 떠올렸고,
// 이전에는 다르게 풀었으니 한번 이 로직으로 풀어보자 생각함. (30분 뻘짓..)
// 
// 9, 999 일 때,
// 54, 5455 일 때, 등등.. 고려할 사항이 너무 많았음.
// 
// 심지어 string -> 비교할 자릿수를 index로 접근해 다시 int로 변경하는게 너무 번잡해보였다.
// 사실 어짜피 한자리 수이기 때문에 -48을 해줘도 괜찮지만
// 번잡한걸 떠나서 그냥 고려할게 많았음.
// -> 귀찮어..
// 
// 때문에 기존과 같게 A와 B를 이용해 만들수 있는 두 가지 수 중 크고 작은 것으로 정렬을 해주었다.
//
// 오랜만에 풀어서 11번 케이스?였나만 틀리는게 당황스러웠는데,
// 이부분은 확인해보니 0, 0, 0, 0일 때, 답이 "0"으로 나오지 않고, "0000"으로 나오는게 문제였다.
// 문제가 좀 그릏네..
//
// 새로운 시도 30분(실패) + 기존 방법 10분

bool compare(int i_A, int i_B)
{
    string str_Num_A = to_string(i_A);
    string str_Num_B = to_string(i_B);

    int i_Num_AB = stoi(str_Num_A + str_Num_B);
    int i_Num_BA = stoi(str_Num_B + str_Num_A);

    return i_Num_AB > i_Num_BA;
}

string solution(vector<int> numbers) {
    string answer = "";

    sort(numbers.begin(), numbers.end(), compare);

    for (size_t iNumIdx = 0; iNumIdx < numbers.size(); ++iNumIdx)
    {
        answer += to_string(numbers[iNumIdx]);
    }

    if (answer[0] == '0')
        answer = "0";

    return answer;
}

void test(int&& i_A)
{
    ++i_A;
}

void main()
{
    //string answer = solution(vector<int>{6, 10, 2});
    string answer = solution(vector<int>{999, 9, 12, 1213});

    int a = 0;

    return;
}