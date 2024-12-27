#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(vector<int>& a, vector<int>& b)
{
    for (int i = 10; i >= 0; --i)
    {
        if (a[i] != b[i])
            return a[i] > b[i];
    }

    return false;
}

vector<int> solution(int n, vector<int> info) {
    vector<int> answer;

    pair<int, vector<int>> max_pair{-1, vector<int>{-1} };

    // 칸막이 생성
    vector<int> vec_Permutation(n + 10);
    fill(vec_Permutation.begin() + n, vec_Permutation.end(), 1);

    // 칸막이 갱신
    do
    {
        vector<int> arrow(info.size(), 0);

        int cnt = n;
        int score_A = 0, score_R = 0, score_T = 0;

        for (int i = 0; i < info.size(); ++i)
        {
            // 칸막이가 쳐져있지 않다면,
            if (!vec_Permutation[i])
            {
                arrow[i] = info[i] + 1;
                cnt -= arrow[i];

                score_R += (10 - i);
            }
            else
            {
                if (info[i] != 0)
                    score_A += (10 - i);
            }
        }

        if (cnt < 0)
            continue;
        else if (cnt > 0)
            arrow[10] += cnt;

        score_T = score_R - score_A;
        
        // 정답 갱신
        if (score_T > 0)
        {
            if (max_pair.first == -1)
                max_pair = { score_T, arrow };
            else
            {
                if (score_T > max_pair.first)
                {
                    max_pair = { score_T, arrow };
                }
                else if (score_T == max_pair.first)
                {
                    if(compare(arrow, max_pair.second))
                        max_pair = { score_T, arrow };
                }
            }
        }

    } while (next_permutation(vec_Permutation.begin(), vec_Permutation.end()));

    answer = max_pair.second;

    return answer;
}

void main()
{
    vector<int> answer = solution(9, vector<int>{0, 0, 1, 2, 0, 1, 1, 1, 1, 1, 1});

    return;
}