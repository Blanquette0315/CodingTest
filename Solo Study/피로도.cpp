#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// k가 5000까지 주어질 수 있고, dungeons는 최대 8개만 가질 수 있다.
// 이때, 던전을 모두 탐험할 경우의 수는 8*7*6*5*4*3*2*1 = 40,320 가지 이기 때문에
// 모든 경우의 수를 탐색해도 연산 비용이 크지 않다고 판단함.
// 
// 추가로 k가 5000까지 주어지고, 해당 k로 할 연산은 - 연산 밖에 없기 때문에
// int 자료형을 절대 넘을 일이 없다고 판단했다.
// 
// 때문에 굳이 dfs를 이용해 완전탐색을 하지 않고, next_permutation()을 이용해
// 모든 경우의 수를 탐색하며 던전을 가장 많이 방문할 수 있는 횟수를 구하도록 만들었다.
// 
// 실수는 =을 빼멱어서 갱신을 안해 문제를 틀렸었다.
//
// 해당 코드는 O(N^2)이다.
//

// 2024.05.10
//int solution(int k, vector<vector<int>> dungeons) {
//    int answer = -1;
//
//    sort(dungeons.begin(), dungeons.end());
//
//    do
//    {
//        int Cnt = k;
//        int Dgn_Cnt = 0;
//
//        for (size_t i = 0; i < dungeons.size(); ++i)
//        {
//            int req_fatigue = dungeons[i][0];
//            int use_fatigue = dungeons[i][1];
//
//            if (Cnt >= req_fatigue)
//            {
//                Cnt -= use_fatigue;
//                Dgn_Cnt++;
//            }
//            else
//                break;
//        }
//
//        answer = max(answer, Dgn_Cnt);
//
//    } while (next_permutation(dungeons.begin(), dungeons.end()));
//    
//    return answer;
//}


// 2024.12.30
int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;

    sort(dungeons.begin(), dungeons.end());

    do
    {
        int Fatigue = k;
        int cnt = 0;
        for (int i = 0; i < dungeons.size(); ++i)
        {
            if (Fatigue >= dungeons[i][0])
            {
                Fatigue -= dungeons[i][1];
                cnt++;
            }
            else
                break;
        }

        answer = max(answer, cnt);
    } while (next_permutation(dungeons.begin(), dungeons.end()));

    return answer;
}

void main()
{
    int answer = solution(80, vector<vector<int>>{ {80, 20}, { 50,40 }, { 30,10 }});

    return;
}