#include <string>
#include <vector>
#include <queue>
#include <set>

using namespace std;

// 처음에 보자마자 Y축 방향으로 각 칸을 검사하다가 석유층을 만나면, bfs를 이용해 탐색해 해당 석유층의 값을 구하면 될거 같았다.
// 생각해볼 점은 bfs를 매번 진행할 필요가 없기 때문에 석유층을 만나면 석유 갯수를 기록해두는 것과,
// 같은 석유층에서 나온 석유인지를 구분해야 한다는 점이다.
// 
// 때문에 Memo를 만들어 석유 ID를 부여해서 각 석유층마다 별도의 ID를 주도록 구현했다.
// 
// 또한, BFS를 이용해 탐색을 마친 후 탐색으로 찾은 모든 노드를 다시 순회해 값과 ID를 넣어주어 Memo를 채웠다.
//

//              상  하  좌  우
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

            // OOB, 다음 Idx를 방문한적이 있는지, 다음 Idx의 값이 석유인지
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

    // memo 채우기
    // 찾은 해당 석유방의 석유 idx에 다시 접근해가며, cnt를 기록해둠.
    while (!oilqu.empty())
    {
        auto Idx = oilqu.front();
        oilqu.pop();

        Memo[Idx.first][Idx.second].second = cnt;
    }

    // 다음 bfs를 위해서 석유 ID를 1증가.
    oilNum++;

    return;
}

int solution(vector<vector<int>> land) {
    int answer = 0;

    // memo의 first는 id, second는 석유 갯수
    vector<vector<pair<int, int>>> Memo(land.size(), vector<pair<int, int>>(land[0].size(), { -1, 0 }));

    for (size_t j = 0; j < land[0].size(); ++j)
    {
        int oilcnt = 0;
        set<int> set_oilnum = {};
        for (size_t i = 0; i < land.size(); ++i)
        {
            // 확인한 타일이 석유일때,
            if (land[i][j] == 1)
            {
                // 아직 방문하지 않았다면, BFS로 탐색진행
                if (-1 == Memo[i][j].first)
                {
                    queue<pair<int, int>> qu;
                    qu.push({ i, j });

                    bfs(Memo, land, qu);

                    set_oilnum.insert(Memo[i][j].first);
                    oilcnt += Memo[i][j].second;
                }
                // bfs 탐색을 진행했었으면,
                else
                {
                    // 이미 계산한 오일공간이면 넘김
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
//            // OOB, 다음 Idx를 방문한적이 있는지, 다음 Idx의 값이 석유인지
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
//    // memo 채우기
//    // 찾은 해당 석유방의 석유 idx에 다시 접근해가며, cnt를 기록해둠.
//    while (!oilqu.empty())
//    {
//        auto Idx = oilqu.front();
//        oilqu.pop();
//
//        Memo[Idx.first][Idx.second].second = cnt;
//    }
//
//    // 다음 bfs를 위해서 석유 ID를 1증가.
//    oilID++;
//
//    return;
//}
//
//int solution(vector<vector<int>> land) {
//    int answer = 0;
//
//    // memo의 first는 id, second는 석유 갯수
//    vector<vector<pair<int, int>>> Memo(land.size(), vector<pair<int, int>>(land[0].size(), { -1, 0 }));
//
//    for (size_t j = 0; j < land[0].size(); ++j)
//    {
//        int oilcnt = 0;
//        set<int> set_oilnum = {};
//        for (size_t i = 0; i < land.size(); ++i)
//        {
//            // 확인한 타일이 석유일때,
//            if (land[i][j] == 1)
//            {
//                // 아직 방문하지 않았다면, BFS로 탐색진행
//                if (-1 == Memo[i][j].first)
//                {
//                    queue<pair<int, int>> qu;
//                    qu.push({ i, j });
//
//                    bfs(Memo, land, qu);
//                }
//
//                // bfs 탐색을 진행했었으면,
//                // 이미 계산한 오일공간이면 넘김
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