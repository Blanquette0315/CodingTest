#include <string>
#include <vector>
#include <stack>

using namespace std;

// max_element로 풀어보려고 했으나, 문제를 다시 보니 뒤에서 큰수중 가장 가까운 수를 push_back을 해주어야 해서
// 풀수 없다고 생각했다.
// 
// 시간 관련으로 이진 탐색도 고려해보았으나, 이분 탐색은 정렬이되어 있어야하는데, 정렬을 못하는 상황이라 안된다 판단.
//

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    answer.resize(numbers.size());
    stack<int> st = {};

    for (int i = numbers.size() - 1; i >= 0; --i)
    {
        while (!st.empty())
        {
            int inum = st.top();
            if (numbers[i] < inum)
            {
                st.push(numbers[i]);
                answer[i] = inum;
                break;
            }
            else
            {
                st.pop();
            }

            if (st.empty())
            {
                st.push(numbers[i]);
                answer[i] = -1;
            }
        }
    }

    return answer;
}

void main()
{
    vector<int> answer = solution(vector<int>{9, 1, 5, 3, 6, 2});

    return;
}


//vector<int> solution(vector<int> numbers) {
//    vector<int> answer;
//
//    for (int i = 0; i < numbers.size(); ++i)
//    {
//        bool check = false;
//        for (int j = i + 1; j < numbers.size(); ++j)
//        {
//            if (numbers[i] < numbers[j])
//            {
//                answer.push_back(numbers[j]);
//                check = true;
//                break;
//            }  
//        }
//
//        if (!check)
//            answer.push_back(-1);
//
//        check = false;
//    }
//
//    return answer;
//}