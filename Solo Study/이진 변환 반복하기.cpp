#include <string>
#include <vector>
#include <bitset>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;

    int loof_cnt = 0, zero_cnt = 0;

    while (s != "1")
    {
        int one_cnt = bitset<150000>(s).count();
        zero_cnt += s.length() - one_cnt;
        loof_cnt++;

        s = bitset<150000>(one_cnt).to_string();

        s.erase(0, s.find("1"));
    }

    answer.push_back(loof_cnt);
    answer.push_back(zero_cnt);

    return answer;
}

void main()
{
    vector<int> answer = solution("110010101001");

    return;
}