#include <string>
#include <vector>

using namespace std;

// 단순한 DFS 문제.
// 20분 걸림.
// 근데 짠 코드가 별로 아름답지 못함..
//

int iCount = 0;

void dfs(int i_Idx, int i_result, int itarget, vector<int>& vec_number)
{
    int iVal = vec_number[i_Idx];
    int iResult_P = i_result + iVal;
    int iResult_M = i_result - iVal;

    if (i_Idx + 1 >= vec_number.size())
    {
        if (iResult_P == itarget)
            iCount++;
        if (iResult_M == itarget)
            iCount++;
    }
    else
    {
        dfs(i_Idx + 1, iResult_P, itarget, vec_number);
        dfs(i_Idx + 1, iResult_M, itarget, vec_number);
    }

    return;
}

int solution(vector<int> numbers, int target) {
    int answer = 0;

    dfs(0, 0, target, numbers);

    answer = iCount;

    return answer;
}

void main()
{
    int answer = solution(vector<int>{1, 1, 1, 1, 1}, 3);

    return;
}