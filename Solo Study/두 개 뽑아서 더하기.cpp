#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;

    set<int> st;

    for (int i = 0; i < numbers.size(); ++i)
    {
        for (int j = i + 1; j < numbers.size(); ++j)
        {
            int num = numbers[i] + numbers[j];

            if (st.find(num) == st.end())
            {
                st.insert(num);
                answer.push_back(num);
            }
        }
    }

    sort(answer.begin(), answer.end());

    return answer;
}