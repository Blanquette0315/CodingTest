#include <iostream>
#include <vector>
#include <set>

using namespace std;

// 수학적인 지식이 부족했던것인지, 처음 문제를 이해하는데 시간이 걸렸다.
// 문제의 예시로 살펴보면, {1, 1, 4, 7, 9}라는 수열이 주어졌을 때, 해당 원형 수열로 만들 수 있는 부분 수열들의 합이 총 몇개가 나오냐는 것으로
// {1}, {1}, {4}, {7}, {9}, {1, 1}, {1, 4}, {4, 7}, {7, 9}, {9, 1}, {1, 1, 4}... 으로 부분 수열이 나오게 된다.
// 해당 부분 수열의 요소들의 합은 1, 1, 4, 7, 9, 2, 5, 21, 26... 으로 나오게된다.
// 이때, 겹치지 않는 수들의 개수를 구하면 되는 문제이다.

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