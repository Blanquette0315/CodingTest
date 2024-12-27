#include <string>
#include <vector>
#include <stack>

using namespace std;

// max_element�� Ǯ����� ������, ������ �ٽ� ���� �ڿ��� ū���� ���� ����� ���� push_back�� ���־�� �ؼ�
// Ǯ�� ���ٰ� �����ߴ�.
// 
// �ð� �������� ���� Ž���� ����غ�������, �̺� Ž���� �����̵Ǿ� �־���ϴµ�, ������ ���ϴ� ��Ȳ�̶� �ȵȴ� �Ǵ�.
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