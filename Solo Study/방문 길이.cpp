#include <string>
#include <set>
using namespace std;

int solution(string dirs) {
    int answer = 0;

    set<string> Memo;

    int curPos_X = 5, curPos_Y = 5;

    for (int i = 0; i < dirs.length(); ++i)
    {
        char Dir = dirs[i];
        int change_X = curPos_X, change_Y = curPos_Y;

        switch (Dir)
        {
        case 'U':
            change_Y += 1;
            break;

        case 'D':
            change_Y -= 1;
            break;

        case 'R':
            change_X += 1;
            break;

        case 'L':
            change_X -= 1;
            break;
        }

        if ((change_X >= 0 && change_X < 11)
            && (change_Y >= 0 && change_Y < 11))
        {
            string TempKey1 = to_string(curPos_X) + to_string(curPos_Y) + to_string(change_X) + to_string(change_Y);
            string TempKey2 = to_string(change_X) + to_string(change_Y) + to_string(curPos_X) + to_string(curPos_Y);

            if ((Memo.find(TempKey1) == Memo.end()) && (Memo.find(TempKey2) == Memo.end()))
            {
                Memo.insert(TempKey1);
                Memo.insert(TempKey2);
                answer++;
            }

            curPos_X = change_X;
            curPos_Y = change_Y;
        }
    }

    return answer;
}

void main()
{
    int answer = solution("LULLLLLLU");

    int a = 0;

    return;
}