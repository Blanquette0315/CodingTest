#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

//int Factorial(int n)
//{
//    int result = 1;
//    for (int i = 1; i <= n; ++i)
//        result *= i;
//
//    return result;
//}
//
//int Permutation(int n, int r)
//{
//    // nPr = n! / (n - r)!
//    return Factorial(n) / Factorial(n - r);
//}
//
//int Combination(int n, int r)
//{
//    //return Permutation(n, r) / Factorial(r);
//    return Factorial(n) / (Factorial(r) * Factorial(n - r));
//}
//
//int solution(vector<vector<string>> clothes) {
//    int answer = 1;
//
//    unordered_map<string, int> Memo;
//
//    for (int i = 0; i < clothes.size(); ++i)
//    {
//        Memo[clothes[i][1]]++;
//    }
//
//    unordered_map<string, int>::iterator iter = Memo.begin();
//    for (; iter != Memo.end(); ++iter)
//    {
//        int n = iter->second;
//        // nC0 + nC1
//        answer *= n + Combination(n, 0);
//    }
//
//    // 아무것도 고르지 않았을 경우의 수를 빼줌.
//    return answer - 1;
//}

int solution(vector<vector<string>> clothes) {
    int answer = 1;

    unordered_map<string, int> Memo;

    for (int i = 0; i < clothes.size(); ++i)
        Memo[clothes[i][1]]++;

    unordered_map<string, int>::iterator iter = Memo.begin();

    for (; iter != Memo.end(); ++iter)
        answer *= (iter->second + 1);

    return answer - 1;
}

void main()
{
    int answer = solution(vector<vector<string>>{ {"yellow_hat", "headgear"}, { "blue_sunglasses", "eyewear" }, { "green_turban", "headgear" }});

    return;
}