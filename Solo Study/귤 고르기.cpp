#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// ���� unordered_map�� �Ƚᵵ
// map�� [] ������ �����ߴ�..
// �׸��� map�� [] ���۷����͸� ����� ��, Ű���� ������, �ڵ����� insert ���ش�.
// https://80000coding.oopy.io/8af406a3-b3b1-4f3f-b190-2937b23684ed
//
// �ϳ��ϳ� �ݺ��� ���鼭 ã�°� ���� �������̱� ������
// �ð��� �ʹ� �����ɸ��� ���Ƽ� ��������.
// 
// �׷��� �����Ѱ�, ������ �������� ������ ����,
// �ش� ������ �������� ������ ���ָ�,
// ������ ������ ���ͼ� Ȯ���ϸ�, ������ ���°� �ξ� �����غ�����.
// 
// ������ map�̳� unordered_map���� Ű�� ��, ���� �������Ͽ� ������ Ǯ����
// �׷��� �ð��� �� �ɸ��µ�, �ð��ʰ��� ���� ������ �� ȿ������ ����� ������ �����..
//

bool cmp(pair<int, int>& A, pair<int, int>& B)
{
    return A.second > B.second;
}

int solution(int k, vector<int> tangerine) {
    int answer = 0;

    unordered_map<int,int> memo = {};
    for (size_t i = 0; i < tangerine.size(); ++i)
    {
        // ���� ��ϵ��� �ʾҴٸ�, ������ش�.
        if (memo.find(tangerine[i]) == memo.end())
            memo.insert({ tangerine[i], 1 });
        else
            // ��ϵǾ� �ִٸ� �� 1����
            memo[tangerine[i]] += 1;
    }

    vector<pair<int, int>> vecMomo(memo.begin(), memo.end());
    sort(vecMomo.begin(), vecMomo.end(), cmp);

    int Idx = 0, cnt = 0;
    // �̰Ŵ� main�� case 2 �� ������. vector ���� �ε��� �������� ����
    /*while (cnt < k)
    {
        cnt += vecMomo[Idx].second;
        Idx++;
        answer++;
    }*/

    while (Idx < vecMomo.size())
    {
        if (cnt >= k)
            break;

        cnt += vecMomo[Idx].second;
        Idx++;
        answer++;
    }

    return answer;
}

void main()
{
    //int anwer = solution(6, vector<int>{1, 3, 2, 5, 4, 5, 2, 3});
    int anwer = solution(10, vector<int>{1});

    return;
}