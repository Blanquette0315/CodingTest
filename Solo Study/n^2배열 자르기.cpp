#include <string>
#include <vector>

using namespace std;

void Change_Idx(pair<int, int>& Idx, int n)
{
    if (Idx.second == n - 1)
    {
        Idx.second = 0;
        Idx.first++;
    }
    else
    {
        Idx.second++;
    }
}

int make_num(pair<int, int>& Idx, int n)
{
    int result = 0;

    if (Idx.first > Idx.second)
        result = Idx.first + 1;
    else
        result = Idx.second + 1;

    Change_Idx(Idx, n);

    return result;
}

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer;

    pair<int, int> StartIdx = { left / n, left % n };

    answer.push_back(make_num(StartIdx, n));

    for (int i = 0; i < right - left; ++i)
    {
        answer.push_back(make_num(StartIdx, n));
    }

    return answer;
}

void main()
{
    vector<int> answer = solution(3, 2, 5);

    return;
}