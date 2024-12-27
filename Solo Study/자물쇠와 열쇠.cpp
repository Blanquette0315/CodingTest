#include <string>
#include <vector>

using namespace std;

// �迭 ȸ���� ���� �� �����ִ� ��α�
// https://velog.io/@danbibibi/2%EC%B0%A8%EC%9B%90-%EB%B0%B0%EC%97%B4%EC%97%90%EC%84%9C-90%EB%8F%84-%ED%9A%8C%EC%A0%84-%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98
//
// �θ�Ʈ ����
// 
// ����� Ǯ�̴� Lock�� ������ ã��, ���� �迭�� ȸ���ϸ�, idx�� ����ϰ� �ִٰ�.
// ���߿� Lock�� ������ �ϳ��� Key�� �ϳ��� ��� �����ؼ� �������� �ο��� �ٸ� Ű�� ������ �Ÿ��� �̿��� Lock���� ã�Ƽ� ���� Ǯ����.
// 
//


// ȸ���ϴ� �Լ�
void Rotate_Vector(vector<vector<int>>& vec_Target){
    vector<vector<int>> vec_Temp(vec_Target.size(), vector<int>(vec_Target[0].size(), 0));

    for (size_t i = 0; i < vec_Target.size(); ++i)
    {
        for (size_t j = 0; j < vec_Target.size(); ++j)
        {
            // �ð� ���� 90�� ȸ���� r���� 5-1-r ���� �Ȱ�, c���� c���� �ȴ�.
            vec_Temp[i][j] = vec_Target[vec_Target.size() - j - 1][i];
        }
    }
    vec_Target.swap(vec_Temp);
}

// ���忡 �ڹ��� ���� ä���
void make_board(vector<vector<int>>& Board, vector<vector<int>>& lock, int i_KeySize, int& i_Point)
{
    // ���� ����
    int iBoardSize = lock.size() + 2 * (i_KeySize - 1);
    Board.resize(iBoardSize, vector<int>(iBoardSize, 2));

    // ä���
    int i_LockIdx_X = 0, i_LockIdx_Y = 0;
    for (int iBoardIdx_X = i_KeySize - 1; iBoardIdx_X < iBoardSize - (i_KeySize - 1); ++iBoardIdx_X, ++i_LockIdx_X)
    {
        for (int iBoardIdx_Y = i_KeySize - 1; iBoardIdx_Y < iBoardSize - (i_KeySize - 1); ++iBoardIdx_Y, ++i_LockIdx_Y)
        {
            Board[iBoardIdx_X][iBoardIdx_Y] = lock[i_LockIdx_X][i_LockIdx_Y];
            if (Board[iBoardIdx_X][iBoardIdx_Y] == 0)
            {
                i_Point++;
            }
        }
        i_LockIdx_Y = 0;
    }
}

int Sum_Key_And_Lock(int i_Start_X, int i_Start_Y, vector<vector<int>>& vec_Key, vector<vector<int>>& vec_Board)
{
    int iIdx_X = 0, iIdx_Y = 0, iCheck = 0;
    for (int x = i_Start_X; x < i_Start_X + vec_Key.size(); ++x, ++iIdx_X)
    {
        for (int y = i_Start_Y; y < i_Start_Y + vec_Key.size(); ++y, ++iIdx_Y)
        {
            if (vec_Board[x][y] == 1 && vec_Key[iIdx_X][iIdx_Y] == 1)
                return -1;
            if (vec_Board[x][y] == 0 && vec_Key[iIdx_X][iIdx_Y] == 0)
                return -1;
            if (vec_Board[x][y] == 0 && vec_Key[iIdx_X][iIdx_Y] == 1)
                iCheck++;
        }
        iIdx_Y = 0;
    }

    return iCheck;
}

bool move_board(vector<vector<int>>& vec_Key, vector<vector<int>> vec_Lock, vector<vector<int>>& vec_Board, int& iPoint)
{
    for (int iRCount = 0; iRCount < 4; ++iRCount)
    {
        for (int i = 0; i < vec_Key.size() + vec_Lock.size() - 1; ++i)
        {
            for (int j = 0; j < vec_Key.size() + vec_Lock.size() - 1; ++j)
            {
                int Result = Sum_Key_And_Lock(i, j, vec_Key, vec_Board);
                if (Result == iPoint)
                    return true;
            }
        }

        Rotate_Vector(vec_Key);
    }
    return false;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = false;

    int Point = 0;
    vector<vector<int>> vec_Board;

    make_board(vec_Board, lock, key.size(), Point);
    answer = move_board(key, lock, vec_Board, Point);

    return answer;
}

void main()
{
    bool answer = solution(vector<vector<int>>{ {0, 0, 0}, { 1,0,0 }, { 0,1,1 }}, vector<vector<int>>{ {1, 1, 1}, { 1,1,0 }, { 1,0,1 }});

    return;
}