#include <string>
#include <vector>
#include <set>

using namespace std;

// ����, 1, 1, 4, 7, 7, 5 ��� ������ũ�� �־����ٸ�,
// A��   1, 1, 2, 3, 3, 4 �� ��Ÿ�� �� �ְ�,
// 
//       5, 7, 7, 4, 1, 1 (B�� ������ ���� ������ ��������.)
// B��   1, 2, 2, 3, 4, 4 �� ��Ÿ�� �� �ִ�.
// 
// ���� ����ũ�� ������ ���� �ڸ��ٸ�,
// 1, 1, 4, 7 | 7, 5
// 
// A�� 1, 1, 4, 7�� �� 3���� �����̰�, A������ �迭�� 3��° �ε����̴�.
// B�� 7, 5�� �� 2���� �����̰�, B������ �迭�� 2��° �ε�����.  
// 
// ��ó�� A�� B�� �� ��Ȳ�� ���� ���� �� �迭�� ����� �׸� �̿��� ������ Ǯ�� �ƾ���.
// 
// �������� �̷��� ����� ������ ���� ���ø��� ���ؼ� �����ߴ�.
// 
// ��, ������ �� 10,000������ �־��� �� �ִµ�
// bool �迭�� �����.. �ǰ����� �׺��ٴ� set���� Ű������ �ٷ� ã�� �˻��� �� �ֵ��� �ϴ°͵�
// ���ƺ����� �׷��� �����ߴ�.
// (��Ʈ�ε� �غ��� �ߴµ� �����غ��� 10,000�ڸ� ��Ʈ���� ��..)
//

bool InsertTopping(set<int>& set_Memo, int iTopping)
{
    if (set_Memo.find(iTopping) == set_Memo.end())
    {
        set_Memo.insert(iTopping);
        return true;
    }
    
    return false;
}

int solution(vector<int> topping) {
    int answer = 0;

    set<int> setMemo_Topping_A;
    set<int> setMemo_Topping_B;
    vector<int> vec_Person_A;
    vector<int> vec_Person_B;

    int iMaxIdx = topping.size() - 1;
    int iTopCount_A = 0, iTopCount_B = 0;
    for (size_t i = 0; i < topping.size(); ++i)
    {
        if (InsertTopping(setMemo_Topping_A, topping[i]))
        {
            iTopCount_A++;
        }
        vec_Person_A.push_back(iTopCount_A);

        if (InsertTopping(setMemo_Topping_B, topping[iMaxIdx - i]))
        {
            iTopCount_B++;
        }vec_Person_B.push_back(iTopCount_B);
    }

    for (size_t j = 0; j < iMaxIdx; ++j)
    {
        if (vec_Person_A[j] == vec_Person_B[iMaxIdx -j - 1])
            answer++;
    }

    return answer;
}

void main()
{
    //int answer = solution(vector<int>{1, 2, 1, 3, 1, 4, 1, 2});
    int answer = solution(vector<int>{1, 1, 4, 7, 7, 5});

    int a = 0;

    return;
}