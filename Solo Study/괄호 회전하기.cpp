#include <string>
#include <vector>
#include <stack>
#include <map>

using namespace std;

bool check(string str, map<char, int> memo)
{
    stack<char> st = {};

    for (size_t j = 0; j < str.length(); ++j)
    {
        if ('(' == str[j] || '{' == str[j] || '[' == str[j])
        {
            st.push(str[j]);
        }
        else
        {
            if (st.empty())
                return false;
            
            if (memo.find(st.top())->second != memo.find(str[j])->second)
                return false;

            st.pop();
        }
    }

    if (st.empty())
        return true;
    else
        return false;
}

int solution(string s) {
    if (s.length() % 2 != 0)
        return 0;
    int answer = 0;
    
    map<char, int> memo = {};
    memo.insert({ '(', 0 });
    memo.insert({ ')', 0 });
    memo.insert({ '{', 1 });
    memo.insert({ '}', 1 });
    memo.insert({ '[', 2 });
    memo.insert({ ']', 2 });

    if (check(s, memo))
        answer++;

    for(int i = 1; i < s.length(); ++i)
    {
        char front = s.front();
        s.erase(0, 1);
        s += front;

        if(check(s, memo))
            answer++;
    }

    return answer;
}

void main()
{
    int answer = solution("[](){}");

    return;
}