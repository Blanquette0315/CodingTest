#include <iostream>
#include <vector>
#include <set>

using namespace std;

// �������� ������ �����ߴ�������, ó�� ������ �����ϴµ� �ð��� �ɷȴ�.
// ������ ���÷� ���캸��, {1, 1, 4, 7, 9}��� ������ �־����� ��, �ش� ���� ������ ���� �� �ִ� �κ� �������� ���� �� ��� �����Ĵ� ������
// {1}, {1}, {4}, {7}, {9}, {1, 1}, {1, 4}, {4, 7}, {7, 9}, {9, 1}, {1, 1, 4}... ���� �κ� ������ ������ �ȴ�.
// �ش� �κ� ������ ��ҵ��� ���� 1, 1, 4, 7, 9, 2, 5, 21, 26... ���� �����Եȴ�.
// �̶�, ��ġ�� �ʴ� ������ ������ ���ϸ� �Ǵ� �����̴�.

int solution(vector<int> elements) {
    int answer = 0;

    vector<int> newelemets = elements;

    for (int i = 0; i < elements.size() - 1; ++i)
    {
        newelemets.push_back(elements[i]);
    }

    set<int> set1;
    for (int i = 1; i < elements.size() + 1; ++i)
    {
        int stidx = 0;
        while (stidx != elements.size())
        {
            int num = 0;
            for (int j = 0; j < i; ++j)
            {
                num += newelemets[stidx + j];
            }

            set1.insert(num);

            stidx++;
        }
    }

    answer = set1.size();

    return answer;
}

void main()
{
    int answer = solution({ 7, 9, 1, 1, 4 });

    int a = 0;

    return;
}