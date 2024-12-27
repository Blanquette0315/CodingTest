//트리 위의 게임
//시간 제한 : 1 초
//정점 N개의 트리에서 두 사람이 게임을 진행하려 한다.
//각 정점은 1번부터 N번 까지 번호가 매겨져 있고 루트노드는 1번 노드이다.
//게임은 서로 턴을 번갈아 가며 진행되고 트리 위에 놓을 수 있는 말과 함께 진행된다.
//두 사람의 점수는 모두 0점으로 시작한다.
//
//각 턴마다 두 사람은 다음과 같은 작업을 반복한다.
//
//현재 말이 놓여 있는 정점의 번호만큼 자신의 점수에 더한다.
//현재 말이 놓여 있는 정점의 자식 정점이 없다면 그대로 게임을 종료한다.
//자식 정점이 존재한다면 자식 정점 중 원하는 자식 정점으로 말을 옮긴다.
//게임이 종료되었을 때 선공의 점수가 후공의 점수보다 높거나 같다면 선공이 승리하고 아니라면 후공이 승리한다.
//두 사람이 최적으로 플레이할 때, 처음 말이 놓여져 있는 정점의 번호에 따라 선공이 이기는지 후공이 이기는지 구해보자.
//
//
//
//
//
//외부에서 작성한 코드를 복사 및 붙여넣기 시, 정확한 코드 작성 시간 산정이 힘들어 수상 과정에서 불이익이 발생할 수 있습니다.이는 운영진 측에서 확인이 가능한 사항이므로, 모든 코드는 엘리스 플랫폼 내에서 작성을 부탁드립니다.
//
//
//또한, ChatGPT나 생성 AI, 외부 API 사용 시 수상에서 불이익을 받을 수 있다는 점도 같이 참고 부탁드립니다.
//
//==================================================================================================
//
//입력
//첫째 줄에 정점의 수 N이 주어진다.
//1≤N≤100000
//둘째 줄부터 N−1개의 줄에 간선을 나타내는 정수 u, v가 주어진다.
//1≤u, v≤N
//이는 u번 정점과 v번 정점을 잇는 간선이 존재한다는 뜻이다.
//
//==================================================================================================
//
//출력
//N개의 줄에 걸쳐 정답을 출력한다.
//i번째 줄에는 말의 시작위치가 i번 정점일 때의 결과를 출력한다.
//선공이 이긴다면 1을 후공이 이긴다면 0을 출력한다.

// https://code-challenge.elice.io/courses/95930/lectures/738999/lecturepages/20391344/


#include <iostream>
#include <vector>

using namespace std;

//// pair : { Player_Score, Other_Score }
//pair<int, int> dfs(int Node, int cnt, vector<vector<int>>& List_adj, vector<pair<int, int>>& answer, vector<bool>& visited)
//{
//    visited[Node] = true;
//    cnt++;
//    pair<int, int> Score;
//    bool Is_Leef = true;
//
//    for (int i = 0; i < List_adj[Node].size(); ++i)
//    {
//        int NxtNode = List_adj[Node][i];
//        if (visited[NxtNode] != true)
//        {
//            Is_Leef = false;
//            auto ret = dfs(NxtNode, cnt, List_adj, answer, visited);
//
//            // min
//            if (cnt % 2 == 0)
//            {
//                if (Score.second < ret.second)
//                    Score = ret;
//            }
//            //max
//            else
//            {
//                if (Score.first < ret.first)
//                    Score = ret;
//            }
//        }
//    }
//
//    //Leef Node
//    if (Is_Leef)
//    {
//        answer[Node].first = 1;
//        answer[Node].second = cnt;
//        // min
//        if (cnt % 2 == 0)
//            return { Node, 0 };
//        //max
//        else
//            return { 0, Node };
//    }
//
//    if (answer[Node].second < cnt)
//    {
//        // PlayerWin
//        if (Score.first >= Score.second)
//            answer[Node].first = 1;
//        else
//            answer[Node].first = 0;
//
//        answer[Node].second = cnt;
//    }
//
//    // min
//    if (cnt % 2 == 0)
//        Score.first += Node;
//    //max
//    else
//        Score.second += Node;
//
//    return Score;
//}

// pair : cnt, { Player_Score, Other_Score }
pair<int, pair<int, int>> dfs(int Node, vector<vector<int>>& List_adj, vector<pair<int, int>>& answer, vector<bool>& visited)
{
    visited[Node] = true;
    pair<int, pair<int, int>> Score;
    bool Is_Leef = true;

    for (int i = 0; i < List_adj[Node].size(); ++i)
    {
        int NxtNode = List_adj[Node][i];
        if (visited[NxtNode] != true)
        {
            Is_Leef = false;
            auto ret = dfs(NxtNode, List_adj, answer, visited);

            if (ret.first > Score.first)
            {
                Score = ret;
            }
            else if (ret.first == Score.first)
            {
                // min
                if (ret.first % 2 == 0)
                {
                    if (Score.second.first < ret.second.first)
                        Score = ret;
                }
                //max
                else
                {
                    if (Score.second.second < ret.second.second)
                        Score = ret;
                }
            }
        }
    }

    //Leef Node
    if (Is_Leef)
    {
        answer[Node].first = 1;
        
        return { 0, { Node, 0 } };
    }

    int temp = Score.second.first;
    Score.second.first = Score.second.second + Node;
    Score.second.second = temp;
    Score.first++;

    // PlayerWin
    if (Score.second.first >= Score.second.second)
        answer[Node].first = 1;
    else
        answer[Node].first = 0;

    return Score;
}

int main() {
 
    int NodeCnt = 0;
    cin >> NodeCnt;
    NodeCnt += 1;
    vector<vector<int>> List_adj(NodeCnt, vector<int>{});
    vector<pair<int, int>> answer(NodeCnt, { 0, 0 }); // first : Win/Loss, second : Temp_Level
    vector<bool> visited(NodeCnt, false);
    for (int i = 2; i < NodeCnt; ++i)
    {
        int Node_A = 0, Node_B = 0;
        cin >> Node_A >> Node_B;

        List_adj[Node_A].push_back(Node_B);
        List_adj[Node_B].push_back(Node_A);
    }


    dfs(1, List_adj, answer, visited);

    for (int i = 1; i < answer.size(); ++i)
    {
        cout << answer[i].first << endl;
    }

    return 0;
}