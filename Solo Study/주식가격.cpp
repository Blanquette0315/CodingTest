#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size(), 0);

    stack<pair<int, int>> st;
    st.push({ prices.back(), 0 });

    for (int i = prices.size() - 2; i >= 0; --i)
    {
        int cnt = 0;
        while (!st.empty()
            && st.top().first >= prices[i])
        {
            cnt += st.top().second;
            st.pop();
        }
        answer[i] = cnt + 1;
        st.push({ prices[i], cnt + 1 });
    }

    return answer;
}

void main()
{
    //vector<int> answer = solution(vector<int>{1, 2});
    vector<int> answer = solution(vector<int>{1, 2, 3, 2, 3});

    return;
}