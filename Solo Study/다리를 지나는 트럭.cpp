#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    deque<pair<int, int>> dq;
    stack<pair<int, int>> st;

    int cnt = 0;
    int st_size = 0;
    int total_w = 0;
    for (int i = 0; i < truck_weights.size(); ++i)
    {
        dq.push_back({ truck_weights[i], 0 });
    }

    while (!dq.empty())
    {
        cnt++;
        total_w = 0;

        for (int i = 0; i < st_size + 1; ++i)
        {
            if (dq.empty())
                break;
            auto temp = dq.front();
            total_w += temp.first;
            if (total_w > weight)
                break;

            dq.pop_front();
            temp.second++;
            st.push(temp);
        }

        st_size = st.size();

        while (!st.empty())
        {
            auto temp = st.top();
            if (temp.second < bridge_length)
                dq.push_front(temp);
            else
                st_size--;

            st.pop();
        }
    }

    answer = cnt + 1;

    return answer;
}

void main()
{
    int answer = solution(2, 10, vector<int>{7, 4, 5, 6});

    return;
}