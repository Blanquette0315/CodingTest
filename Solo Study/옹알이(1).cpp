#include <string>
#include <vector>

using namespace std;

// 2�� �ݺ��� �ִ� Ƚ�� = 15 * 4 = 60�� ����
//

int solution(vector<string> babbling) {
    int answer = 0;

    vector<string> word = { "aya", "ye", "woo", "ma" };
    
    for (size_t j = 0; j < babbling.size(); ++j)
    {
        string tmepstr = babbling[j];
        for (size_t i = 0; i < word.size(); ++i)
        {
            // �� �� �ִ� �ܾ �ִٸ�, 
            if (babbling[j].find(word[i]) != string::npos)
            {
                // �����
                if(tmepstr.find(word[i]) != string::npos)
                    tmepstr.erase(tmepstr.find(word[i]), word[i].length());
            }
        }

        // ��� 4���� ���� Ž���� ���ƴٸ�, ���� ���� �ִ��� Ȯ��
        if (tmepstr.empty())
            answer++;
    }
    

    return answer;
}

void main()
{
    int answer = solution(vector<string>{"wyeoo"});
    //int answer = solution(vector<string>{"ayaye", "uuuma", "ye", "yemawoo", "ayaa"});

    return;
}