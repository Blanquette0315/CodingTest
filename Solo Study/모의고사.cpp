#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;

    vector<int> answerOne = { 1, 2, 3, 4, 5 };
    vector<int> answerTwo = { 2, 1, 2, 3, 2, 4, 2, 5 };
    vector<int> answerThree = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };

    vector<int> score = { 0, 0, 0 };
    int maxScore = 0;

    for (int i = 0; i < answers.size(); ++i)
    {
        if (answers[i] == answerOne[i % answerOne.size()])
            score[0]++;
        if (answers[i] == answerTwo[i % answerTwo.size()])
            score[1]++;
        if (answers[i] == answerThree[i % answerThree.size()])
            score[2]++;
    }
    maxScore = *max_element(score.begin(), score.end());

    for (int i = 0; i < score.size(); ++i)
    {
        if (maxScore == score[i])
            answer.push_back(i + 1);
    }

    return answer;
}