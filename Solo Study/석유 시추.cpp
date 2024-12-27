#include <string>
#include <vector>
#include <queue>
#include <set>

using namespace std;

// ó���� ���ڸ��� Y�� �������� �� ĭ�� �˻��ϴٰ� �������� ������, bfs�� �̿��� Ž���� �ش� �������� ���� ���ϸ� �ɰ� ���Ҵ�.
// �����غ� ���� bfs�� �Ź� ������ �ʿ䰡 ���� ������ �������� ������ ���� ������ ����صδ� �Ͱ�,
// ���� ���������� ���� ���������� �����ؾ� �Ѵٴ� ���̴�.
// 
// ������ Memo�� ����� ���� ID�� �ο��ؼ� �� ���������� ������ ID�� �ֵ��� �����ߴ�.
// 
// ����, BFS�� �̿��� Ž���� ��ģ �� Ž������ ã�� ��� ��带 �ٽ� ��ȸ�� ���� ID�� �־��־� Memo�� ä����.
//

//              ��  ��  ��  ��
int Dir_X[4] = { 0, 0, -1, 1 };
int Dir_Y[4] = { -1, 1, 0, 0 };

int oilNum = 0;

void bfs(vector<vector<pair<int, int>>>& Memo, vector<vector<int>>& land, queue<pair<int, int>>& qu)
{
    queue<pair<int, int>> oilqu;
    oilqu.push(qu.front());
    Memo[qu.front().first][qu.front().second].first = oilNum;
    int cnt = 1;

    while (!qu.empty())
    {
        auto Idx = qu.front();
        qu.pop();

        for (int i = 0; i < 4; ++i)
        {
            int Nxt_Y = Idx.first + Dir_Y[i];
            int Nxt_X = Idx.second + Dir_X[i];

            // OOB, ���� Idx�� �湮������ �ִ���, ���� Idx�� ���� ��������
            if (Nxt_Y < 0 || Nxt_Y >= Memo.size() || Nxt_X < 0 || Nxt_X >= Memo[0].size())
                continue;
            if (-1 != Memo[Nxt_Y][Nxt_X].first)
                continue;
            if (1 != land[Nxt_Y][Nxt_X])
                continue;

            qu.push({ Nxt_Y, Nxt_X });
            oilqu.push({ Nxt_Y, Nxt_X });
            Memo[Nxt_Y][Nxt_X].first = oilNum;
            cnt++;
        }
    }

    // memo ä���
    // ã�� �ش� �������� ���� idx�� �ٽ� �����ذ���, cnt�� ����ص�.
    while (!oilqu.empty())
    {
        auto Idx = oilqu.front();
        oilqu.pop();

        Memo[Idx.first][Idx.second].second = cnt;
    }

    // ���� bfs�� ���ؼ� ���� ID�� 1����.
    oilNum++;

    return;
}

int solution(vector<vector<int>> land) {
    int answer = 0;

    // memo�� first�� id, second�� ���� ����
    vector<vector<pair<int, int>>> Memo(land.size(), vector<pair<int, int>>(land[0].size(), { -1, 0 }));

    for (size_t j = 0; j < land[0].size(); ++j)
    {
        int oilcnt = 0;
        set<int> set_oilnum = {};
        for (size_t i = 0; i < land.size(); ++i)
        {
            // Ȯ���� Ÿ���� �����϶�,
            if (land[i][j] == 1)
            {
                // ���� �湮���� �ʾҴٸ�, BFS�� Ž������
                if (-1 == Memo[i][j].first)
                {
                    queue<pair<int, int>> qu;
                    qu.push({ i, j });

                    bfs(Memo, land, qu);

                    set_oilnum.insert(Memo[i][j].first);
                    oilcnt += Memo[i][j].second;
                }
                // bfs Ž���� �����߾�����,
                else
                {
                    // �̹� ����� ���ϰ����̸� �ѱ�
                    if (set_oilnum.find(Memo[i][j].first) != set_oilnum.end())
                        continue;

                    set_oilnum.insert(Memo[i][j].first);
                    oilcnt += Memo[i][j].second;
                }
            }
        }

        answer = max(answer, oilcnt);
    }

    return answer;
}


//int Dir_X[4] = { 0, 0, -1, 1 };
//int Dir_Y[4] = { -1, 1, 0, 0 };
//
//int oilID = 0;
//
//void bfs(vector<vector<pair<int, int>>>& Memo, vector<vector<int>>& land, queue<pair<int, int>>& qu)
//{
//    queue<pair<int, int>> oilqu;
//    oilqu.push(qu.front());
//    Memo[qu.front().first][qu.front().second].first = oilID;
//    int cnt = 1;
//
//    while (!qu.empty())
//    {
//        auto Idx = qu.front();
//        qu.pop();
//
//        for (int i = 0; i < 4; ++i)
//        {
//            int Nxt_Y = Idx.first + Dir_Y[i];
//            int Nxt_X = Idx.second + Dir_X[i];
//
//            // OOB, ���� Idx�� �湮������ �ִ���, ���� Idx�� ���� ��������
//            if (Nxt_Y < 0 || Nxt_Y >= Memo.size() || Nxt_X < 0 || Nxt_X >= Memo[0].size())
//                continue;
//            if (-1 != Memo[Nxt_Y][Nxt_X].first)
//                continue;
//            if (1 != land[Nxt_Y][Nxt_X])
//                continue;
//
//            qu.push({ Nxt_Y, Nxt_X });
//            oilqu.push({ Nxt_Y, Nxt_X });
//            Memo[Nxt_Y][Nxt_X].first = oilID;
//            cnt++;
//        }
//    }
//
//    // memo ä���
//    // ã�� �ش� �������� ���� idx�� �ٽ� �����ذ���, cnt�� ����ص�.
//    while (!oilqu.empty())
//    {
//        auto Idx = oilqu.front();
//        oilqu.pop();
//
//        Memo[Idx.first][Idx.second].second = cnt;
//    }
//
//    // ���� bfs�� ���ؼ� ���� ID�� 1����.
//    oilID++;
//
//    return;
//}
//
//int solution(vector<vector<int>> land) {
//    int answer = 0;
//
//    // memo�� first�� id, second�� ���� ����
//    vector<vector<pair<int, int>>> Memo(land.size(), vector<pair<int, int>>(land[0].size(), { -1, 0 }));
//
//    for (size_t j = 0; j < land[0].size(); ++j)
//    {
//        int oilcnt = 0;
//        set<int> set_oilnum = {};
//        for (size_t i = 0; i < land.size(); ++i)
//        {
//            // Ȯ���� Ÿ���� �����϶�,
//            if (land[i][j] == 1)
//            {
//                // ���� �湮���� �ʾҴٸ�, BFS�� Ž������
//                if (-1 == Memo[i][j].first)
//                {
//                    queue<pair<int, int>> qu;
//                    qu.push({ i, j });
//
//                    bfs(Memo, land, qu);
//                }
//
//                // bfs Ž���� �����߾�����,
//                // �̹� ����� ���ϰ����̸� �ѱ�
//                if (set_oilnum.find(Memo[i][j].first) != set_oilnum.end())
//                    continue;
//
//                set_oilnum.insert(Memo[i][j].first);
//                oilcnt += Memo[i][j].second;
//            }
//        }
//
//        answer = max(answer, oilcnt);
//    }
//
//    return answer;
//}

void main()
{
    int answer = solution(vector<vector<int>>{ {0, 0, 0, 1, 1, 1, 0, 0}, { 0, 0, 0, 0, 1, 1, 0, 0 }, { 1, 1, 0, 0, 0, 1, 1, 0 }, { 1, 1, 1, 0, 0, 0, 0, 0 }, { 1, 1, 1, 0, 0, 0, 1, 1 }});

    return;
}