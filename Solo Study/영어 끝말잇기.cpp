#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    answer.resize(2);

    set<string> set{};

    set.insert(words[0]);

    int person_cnt = 2;
    int turn_cnt = 1;
    for (size_t i = 1; i < words.size(); ++i)
    {
        if (person_cnt > n)
        {
            person_cnt = 1;
            turn_cnt++;
        }

        // set에 등록이 되어있으면 안됨.
        // 또 끝말잇기가 안된다면,
        if (set.find(words[i]) != set.end()
            || words[i].front() != words[i - 1].back())
        {
            answer[0] = person_cnt;
            answer[1] = turn_cnt;
            return answer;
        }

        // 등록
        set.insert(words[i]);
        person_cnt++;
    }

    answer[0] = 0;
    answer[1] = 0;

    return answer;
}

void main()
{
    vector<int> answer = solution(3, vector<string>{"tank", "kick", "know", "wheel", "land", "dream", "mother", "robot", "tank"});

    return;
}