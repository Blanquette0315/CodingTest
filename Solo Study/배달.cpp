#include <iostream>
#include <vector>

using namespace std;

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;

    int INF = 0x3f3f3f3f;
    vector<vector<int>> graph(N + 1, vector<int>(N + 1, INF));

    for (int i = 0; i < road.size(); ++i)
    {
        graph[road[i][0]][road[i][1]] = min(graph[road[i][0]][road[i][1]], road[i][2]);
        graph[road[i][1]][road[i][0]] = min(graph[road[i][1]][road[i][0]], road[i][2]);
    }

    for (int i = 0; i < graph.size(); ++i)
    {
        graph[i][i] = 0;
    }

    for (int f = 1; f < N + 1; f++)
    {
        for (int i = 1; i < graph.size(); ++i)
        {
            for (int j = 1; j < graph.size(); ++j)
            {
                graph[i][j] = min(graph[i][j], graph[i][f] + graph[f][j]);
            }
        }
    }

    for (int i = 1; i < graph.size(); ++i)
    {
        if (graph[1][i] <= K)
            answer++;
    }

    return answer;
}

void main()
{
    int answer = solution(5, vector<vector<int>>{ {1, 2, 1}, { 2, 3, 3 }, { 5, 2, 2 }, { 1, 4, 2 }, { 5, 3, 1 }, { 5, 4, 2 }}, 3);
    /*int answer = solution(6, vector<vector<int>>{
        {1, 2, 1}, { 1, 3, 2 }, { 2, 3, 2 }, { 3, 4, 3 }, { 3, 5, 2 }, { 3, 5, 3 }, { 5, 6, 1 }},
        4);*/

    return;
}