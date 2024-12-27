#include <string>
#include <vector>
#include <map>

using namespace std;

struct tNode
{
    bool bBEAM;
    bool bCOLUMN;
};

bool Check_SetBeam(int i_X, int i_Y, vector<vector<tNode>>& vec_Memo)
{
    if (i_Y > 0 && vec_Memo[i_X][i_Y - 1].bCOLUMN) return true; // 보의 왼쪽 아래가 기둥이면
    if (i_X < vec_Memo.size() && i_Y > 0 && vec_Memo[i_X + 1][i_Y - 1].bCOLUMN) return true; // 보의 오른쪽 아래가 기둥
    if (i_X > 0 && i_X < vec_Memo.size() && vec_Memo[i_X - 1][i_Y].bBEAM && vec_Memo[i_X + 1][i_Y].bBEAM) return true; // 양끝이 다른 보일 경우
    
    return false;
}

bool Check_SetColumn(int i_X, int i_Y, vector<vector<tNode>>& vec_Memo)
{
    if (i_Y == 0) return true; // 땅 위에 있을 때는 가능
    if (i_Y > 0 && vec_Memo[i_X][i_Y - 1].bCOLUMN) return true; // 다른 기둥 위
    if (i_X > 0 && vec_Memo[i_X - 1][i_Y].bBEAM) return true; // 보의 오른쪽 끝
    if (i_Y < vec_Memo.size() && vec_Memo[i_X][i_Y].bBEAM) return true; // 보의 왼쪽 끝

    return false;
}

bool Check_DelBeam(int i_X, int i_Y, vector<vector<tNode>>& vec_Memo)
{
    vec_Memo[i_X][i_Y].bBEAM = false;

    // 위에 기둥이 있을 때 설치가 가능한가? (각 각 보의 왼쪽 끝, 오른쪽 끝 기준)
    if (vec_Memo[i_X][i_Y].bCOLUMN && !Check_SetColumn(i_X, i_Y, vec_Memo))
        return  false;
    if (i_X < vec_Memo.size() && vec_Memo[i_X + 1][i_Y].bCOLUMN && !Check_SetColumn(i_X + 1, i_Y, vec_Memo))
        return false;

    // 다른 보와 연결 되어 있을 때 설치 가능한가?
    if (i_X > 0 && vec_Memo[i_X - 1][i_Y].bBEAM && !Check_SetBeam(i_X - 1, i_Y, vec_Memo))
        return false;
    if (i_X < vec_Memo.size() && vec_Memo[i_X + 1][i_Y].bBEAM && !Check_SetBeam(i_X + 1, i_Y, vec_Memo))
        return false;

    return true;
}

bool Check_DelColumn(int i_X, int i_Y, vector<vector<tNode>>& vec_Memo)
{
    vec_Memo[i_X][i_Y].bCOLUMN = false;

    // 위에 기둥이 있을 때, 설치가 가능한가?
    if (i_Y < vec_Memo.size() && vec_Memo[i_X][i_Y + 1].bCOLUMN
        && !Check_SetColumn(i_X, i_Y + 1, vec_Memo)) return false;

    // 위에 보가 있을 때, 설치가 가능한가 (각 각 오른쪽, 왼쪽)
    if (i_Y < vec_Memo.size() && vec_Memo[i_X][i_Y + 1].bBEAM
        && !Check_SetBeam(i_X, i_Y + 1, vec_Memo)) return false;
    if (i_X > 0 && i_Y < vec_Memo.size() && vec_Memo[i_X - 1][i_Y + 1].bBEAM
        && !Check_SetBeam(i_X - 1, i_Y + 1, vec_Memo)) return false;

    return true;
}


vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;

    // 설치 가능한 보드 만들기
    vector<vector<tNode>> vec_Memo(n + 1, vector<tNode>(n + 1));
    int b = vec_Memo.size();
    // 하나하나 수행
    int i_X = 0, i_Y = 0, i_Type = 0, i_Del = 0;
    for (size_t iFrameIdx = 0; iFrameIdx < build_frame.size(); ++iFrameIdx)
    {
        i_X     = build_frame[iFrameIdx][0];
        i_Y     = build_frame[iFrameIdx][1];
        i_Type  = build_frame[iFrameIdx][2];
        i_Del   = build_frame[iFrameIdx][3];

        switch (i_Type)
        {
        // 기둥
        case 0:
            // 삭제
            if (i_Del == 0)
            {
                if (!Check_DelColumn(i_X, i_Y, vec_Memo))
                {
                    vec_Memo[i_X][i_Y].bCOLUMN = true;
                }
            }
            // 추가
            else
            {
                if (Check_SetColumn(i_X, i_Y, vec_Memo))
                {
                    vec_Memo[i_X][i_Y].bCOLUMN = true;
                }
            }
            break;

        // 보
        case 1:
            // 삭제
            if (i_Del == 0)
            {
                if (!Check_DelBeam(i_X, i_Y, vec_Memo))
                {
                    vec_Memo[i_X][i_Y].bBEAM = true;
                }
            }
            // 추가
            else
            {
                if (Check_SetBeam(i_X, i_Y, vec_Memo))
                {
                    vec_Memo[i_X][i_Y].bBEAM = true;
                }
            }
            break;

        default:
            break;
        }
    }

    for (size_t i = 0; i < vec_Memo.size(); ++i)
    {
        for (size_t j = 0; j < vec_Memo.size(); ++j)
        {
            if (vec_Memo[i][j].bCOLUMN)
                answer.push_back({ (int)i, (int)j, 0 });
            if (vec_Memo[i][j].bBEAM)
                answer.push_back({ (int)i, (int)j, 1 });
        }
    }

    return answer;
}

void main()
{
    vector<vector<int>> answer = solution(5, vector<vector<int>>{ {1, 0, 0, 1}, { 1, 1, 1, 1 }, { 2, 1, 0, 1 }, { 2, 2, 1, 1 }, { 5, 0, 0, 1 }, { 5, 1, 0, 1 }, { 4, 2, 1, 1 }, { 3, 2, 1, 1 }});
    int a = 0;

    return;
}