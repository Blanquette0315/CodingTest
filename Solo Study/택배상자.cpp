#include <string>
#include <vector>
#include <stack>

using namespace std;

// 문제 설명이 왜 이래... 

//int solution(vector<int> order) {
//    int answer = 0;
//
//    stack<int> st;
//    
//    for (int i = 1; i < order.size(); ++i)
//    {
//        st.push(i);
//        while (!st.empty() && st.top() == order[answer])
//        {
//            st.pop();
//            answer++;
//        }
//    }
//
//    return answer;
//}

int solution(vector<int> order) {
    int answer = 0;

    stack<int> st;
    int num = 1;
    for (int i = 0; i < order.size(); ++i)
    {
        if (num <= order[i])
        {
            for (int j = num; j < order[i]; ++j)
            {
                st.push(num);
                num++;
            }
            num++;
            answer++;
        }
        else
        {
            if (!st.empty() && st.top() == order[i])
            {
                st.pop();
                answer++;
            }
            else
                break;
        }
    }

    return answer;
}

void main()
{
    int answer = solution({ 4,3,1,2,5 });

    return;
}