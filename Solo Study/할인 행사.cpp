#include <iostream>
#include <vector>
#include <map>

using namespace std;

// unordered_map�� ó���� ����ߴµ�, �׶��� �ھ� ������ ������.
// �� �׷����� ���縦 �غ��ƾ� �� �� ����.
// �� ó���� �׽�Ʈ ���̽� 11���� Ʋ�Ⱦ��µ�, 1���� ���� ������ ���� ��, 10�ϰ� ����ǰ�� ��� ���ԵǱ� ������ ó������ �˻��ϴ� �κ��� ���� �Ǿ�� �Ѵ�.

// �ߺ��Ǵ� �ڵ尡 ���Ƽ� �Լ�ȭ�� �ߴ�.

bool Inspection(vector<string>& want, vector<int>& number, map<string, int>& memo)
{
    for (int j = 0; j < want.size(); ++j)
    {
        if (memo.find(want[j]) == memo.end() || number[j] > memo.find(want[j])->second)
        {
            return false;
        }
    }

    return true;
}

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;

    map<string, int> memo;
    for (int i = 0; i < 10; ++i)
    {
        if (memo.find(discount[i]) == memo.end())
            memo.insert(make_pair(discount[i], 1));
        else
            memo.find(discount[i])->second++;
    }

    if (Inspection(want, number, memo))
        answer++;

    for (int i = 10; i < discount.size(); ++i)
    {
        memo.find(discount[i - 10])->second--;

        if (memo.find(discount[i]) == memo.end())
            memo.insert(make_pair(discount[i], 1));
        else
            memo.find(discount[i])->second++;

        if (Inspection(want, number, memo))
            answer++;
    }

    return answer;
}

void main()
{
    int answer = solution({ "apple"}, {10}, { "banana", "banana", "banana", "banana", "banana", "banana", "banana", "banana", "banana", "banana" });

    int a = 0;

    return;
}