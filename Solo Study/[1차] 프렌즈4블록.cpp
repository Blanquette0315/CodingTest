#include <string>
#include <vector>
#include <queue>

using namespace std;

// 기본적으로 슬라이딩 윈도우 기법을 가장 먼저 떠올려서 해당 기법으로 풀어봄.
// 반복을 많이 수행해서 시간초과나 효율성 테스트를 실패할 줄 알았는데 그렇지 않아서 신기했음.
// 1시간 정도 걸렸는데, 구현하는게 오랜만이라 좀 걸림..
//

enum class POS_TYPE
{
    LEFT_TOP,
    RIGHT_TOP,
    LEFT_DOWN,
    RIGHT_DOWN,
    END
};

int POS_X[static_cast<int>(POS_TYPE::END)] = {0, 1, 0, 1};
int POS_Y[static_cast<int>(POS_TYPE::END)] = {0, 0, 1, 1};

// 슬라이딩 윈도우로 확인하는 함수
bool Is_FBlock(int i_X, int i_Y, vector<string>& vec_Board)
{
    if (vec_Board[i_X][i_Y] == vec_Board[i_X + 1][i_Y]
        && vec_Board[i_X][i_Y] == vec_Board[i_X][i_Y + 1]
        && vec_Board[i_X][i_Y] == vec_Board[i_X + 1][i_Y + 1])
        return true;
    else
        return false;
}

void CheckFBlock(int i_X, int i_Y, vector<vector<bool>>& vec_Check, queue<pair<int, int>>& qu_del_list, int& iCount)
{
    for (size_t i = 0; i < static_cast<int>(POS_TYPE::END); ++i)
    {
        if (!vec_Check[i_X + POS_X[i]][i_Y + POS_Y[i]])
        {
            vec_Check[i_X + POS_X[i]][i_Y + POS_Y[i]] = true;
            qu_del_list.push({ i_X + POS_X[i], i_Y + POS_Y[i] });
            iCount += 1;
        }
    }
}

// 슬라이딩 윈도우 후 확인한 것 삭제하는 함수
void Del_Block(vector<string>& vec_Board, queue<pair<int, int>>& qu_del_list, vector<vector<bool>>& vec_Check)
{
    while (!qu_del_list.empty())
    {
        auto Idx = qu_del_list.front();
        qu_del_list.pop();

        vec_Board[Idx.first][Idx.second] = ' ';
        
        for (int i = Idx.first; i > 0; i--)
        {
            swap(vec_Board[i][Idx.second], vec_Board[i - 1][Idx.second]);
            swap(vec_Check[i][Idx.second], vec_Check[i - 1][Idx.second]);
        }
    }
}

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    vector<vector<bool>> vec_Check(board.size(), vector<bool>(board[0].length(), false));
    queue<pair<int, int>> qu_DelList;

    int iCount = 0;
    bool bWhile = true;
    while (bWhile)
    {
        bWhile = false;
        for (size_t YIdx = 0; YIdx < m - 1; ++YIdx)
        {
            for (size_t XIdx = 0; XIdx < n - 1; ++XIdx)
            {
                if (board[YIdx][XIdx] == ' ')
                    continue;

                if (Is_FBlock(YIdx, XIdx, board))
                {
                    CheckFBlock(YIdx, XIdx, vec_Check, qu_DelList, iCount);
                    bWhile = true;
                }
            }
        }
        Del_Block(board, qu_DelList, vec_Check);
    }

    answer = iCount;

    return answer;
}

void main()
{
    int answer = solution(4, 5, vector<string>{"CCBDE", "AAADE", "AAABF", "CCBBF"});


    return;
}