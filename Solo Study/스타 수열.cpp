#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// ŵ

int solution(std::vector<int> a) {
    int answer = -1;

    // �־��� �� ������ ���� ����
    vector<int> vec_cnt(a.size());
    for (size_t i = 0; i < a.size(); ++i)
    {
        vec_cnt[a[i]]++;
    }

    for (size_t i = 0; i < vec_cnt.size(); ++i)
    {
        // �ش� �ε���(����)�� ������ ���ݱ��� ���� ���̺��� ������ �ʿ� ����.
        if (vec_cnt[i] <= answer)
            continue;

        int result = 0;
        for (int j = 0; j < a.size() - 1; ++j)
        {
            if (((a[j] == i) || (a[j + 1] == i)) && (a[j] != a[j + 1]))
            {
                result++;
                j++;
            }
        }

        answer = max(answer, result);
    }

    return answer * 2;
}

void main()
{
    int answer = solution(vector<int>{0, 3, 3, 0, 7, 2, 0, 2, 2, 0});

    return;
}