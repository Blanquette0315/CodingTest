#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;

    vector<string> board;
    board.push_back("zero");
    board.push_back("one");
    board.push_back("two");
    board.push_back("three");
    board.push_back("four");
    board.push_back("five");
    board.push_back("six");
    board.push_back("seven");
    board.push_back("eight");
    board.push_back("nine");

    for (int i = 0; i < board.size(); ++i)
    {
        while (s.find(board[i]) != string::npos)
        {
            s.insert(s.find(board[i]), to_string(i));
            s.erase(s.find(board[i]), board[i].length());
        }
    }

    answer = stoi(s);

    return answer;
}