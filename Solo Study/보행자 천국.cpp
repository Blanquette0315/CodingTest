#include <vector>

using namespace std;

// 이전에 풀었던 문제인 (아마도) 경주로 건설 문제와 유사하다고 생각한다.
// 결국 기록을 남길 때 방향이 추가되어 제약이 생기는게 동일하다 생각함.
// 
// 그때 다른 스터디원이 3차원 DP를 이용해 풀었었는데,
// 비슷하다고는 생각했지만 방법이 떠오르지 않아서 막막했음.
// 
// 그때 처럼 단순히 DIR를 기록해 풀을까 했지만 그건 너무 시간이 오래 걸릴 것 같아서 포기.
// 
// 이후 찾아보니 3차원 DP를 사용하고, 점화식을 찾아서 푸는 것이었음..
// 
// 점화식 자체는 떠올렸었지만, 이게 정상동작을 할까 고민만하다가 시간이 지나서 우선 해설을 참고해 풀음.
// 
// 점화식은
// 3차원 행렬 [방향 좌우, 상하 기준으로 size 2] [m] [n] 을 만들고,
// 이때 방향 기준 좌우로 이동한 것은 [0][][] 행렬에 기록하고
// 상하 기준으로 이동한 것은 [1][][] 행렬에 기록함.
// 
// 이때, [0][i + 1][j] += [0][i][j] + [1][i][j]가 된다.
// 마찬가지로 반대도 [1][i][j+ 1] += [0][i][j] + [1][i][j]
// 
// 한쪽으로만 이동이 가능할 떄는 [0][i + 1][j] += [0][i][j] 만 하게 하면 된다.
// 
// 
// 
// !!여전히 DP 점화식을 찾는게 쉽지 않아서 DP 관련 문제를 조금 많이 풀어봐야 할 것 같다.!!
//
// 경로 가지수 찾기 (수학)를 공부하면 더 좋을듯.
// 
// 
// vector가 그냥 배열보다 느리다. 참고.
//

int MOD = 20170805;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int m, int n, vector<vector<int>> city_map) {
    int answer = 0;

    // vector 추론도 가능!!!!!!!!!!
    // vector vec_DP(2, vector(m + 1, vector(n + 1, 0)));//       <-- 쩔어 이게 되네?
    vector<vector<vector<int>>> vec_DP(2, vector<vector<int>>(m + 1, vector<int>(n + 1, 0)));
    
    vec_DP[0][0][0] = 1;

    for (size_t i = 0; i < m; ++i)
    {
        for (size_t j = 0; j < n; ++j)
        {
            if (city_map[i][j] == 0)
            {
                vec_DP[0][i + 1][j] = (vec_DP[0][i + 1][j] + vec_DP[0][i][j] + vec_DP[1][i][j]) % MOD;
                vec_DP[1][i][j + 1] = (vec_DP[1][i][j + 1] + vec_DP[0][i][j] + vec_DP[1][i][j]) % MOD;
            }
            else if (city_map[i][j] == 2)
            {
                vec_DP[0][i + 1][j] = (vec_DP[0][i + 1][j] + vec_DP[0][i][j]) % MOD;
                vec_DP[1][i][j + 1] = (vec_DP[1][i][j + 1]+ vec_DP[1][i][j]) % MOD;
            }
        }
    }

    answer = (vec_DP[0][m - 1][n - 1] + vec_DP[1][m - 1][n - 1]) % MOD;

    return answer;
}

void main()
{
    int answer = solution(3, 6, vector<vector<int>>{ {0, 2, 0, 0, 0, 2}, { 0,0,2,0,1,0 }, { 1,0,0,2,2,0 }});

    return;
}