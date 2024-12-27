#include <string>
#include <vector>

using namespace std;

// 2중 반복시 최대 횟수 = 15 * 4 = 60번 ㅇㅇ
//

int solution(vector<string> babbling) {
    int answer = 0;

    vector<string> word = { "aya", "ye", "woo", "ma" };
    
    for (size_t j = 0; j < babbling.size(); ++j)
    {
        string tmepstr = babbling[j];
        for (size_t i = 0; i < word.size(); ++i)
        {
            // 할 수 있는 단어가 있다면, 
            if (babbling[j].find(word[i]) != string::npos)
            {
                // 지우기
                if(tmepstr.find(word[i]) != string::npos)
                    tmepstr.erase(tmepstr.find(word[i]), word[i].length());
            }
        }

        // 언어 4개에 대한 탐색을 마쳤다면, 남은 글자 있는지 확인
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