#include <iostream>
#include<string>
#include <deque>
using namespace std;

int solution(string s)
{
    int answer = 1;

    if (s.length() % 2 != 0)
        return 0;

    deque<char> dq;
    dq.push_back(s[0]);

    for (size_t i = 1; i < s.length(); ++i)
    {
        if (!dq.empty() && dq.back() == s[i])
            dq.pop_back();
        else
            dq.push_back(s[i]);
    }

    if (dq.empty())
        answer = 1;
    else
        answer = 0;

    return answer;
}

void main()
{
    int answer = solution("baabaa");

    return;
}