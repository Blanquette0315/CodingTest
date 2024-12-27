#include <vector>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

// A,B,C 3
// BC
// A AAA AAB AAC AB ABA ABB ABC AC ACA ACB ACC B BA BAA BAB BAC BB BBA BBB BBC BC...

// A AA AAA AAAA AAAAA AAAAE AAAAI AAAAO AAAAU AAAE AAAEA AAAEE AAAEI AAAEO AAAEU

int solution(string word) {
    int answer = 0;

    string tempword = "";

    while (tempword != word)
    {
        answer++;
        string newword = "";
        stack<char> st;
        for (int i = 0; i < tempword.length(); ++i)
        {
            st.push(tempword[i]);
        }

        if (st.size() != 5)
        {
            while (!st.empty())
            {
                newword.push_back(st.top());
                st.pop();
            }
            newword.insert(newword.begin(), 'A');
            //newword += 'A';
        }
        else
        {
            bool is_upper = true;
            while (!st.empty())
            {
                if (is_upper)
                {
                    switch (st.top())
                    {
                    case 'A':
                        newword += 'E';
                        is_upper = false;
                        break;

                    case 'E':
                        newword += 'I';
                        is_upper = false;
                        break;

                    case 'I':
                        newword += 'O';
                        is_upper = false;
                        break;

                    case 'O':
                        newword += 'U';
                        is_upper = false;
                        break;

                    case 'U':
                        is_upper = true;
                        break;
                    }

                    st.pop();
                }
                else
                {
                    newword += st.top();
                    st.pop();
                }

            }
        }

        reverse(newword.begin(), newword.end());

        tempword = newword;
    }

    return answer;
}

void main()
{
    int answer = solution("I");
    //int answer = solution("AAAAE");

    int a = 0;

    return;
}