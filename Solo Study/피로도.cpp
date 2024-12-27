#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// k�� 5000���� �־��� �� �ְ�, dungeons�� �ִ� 8���� ���� �� �ִ�.
// �̶�, ������ ��� Ž���� ����� ���� 8*7*6*5*4*3*2*1 = 40,320 ���� �̱� ������
// ��� ����� ���� Ž���ص� ���� ����� ũ�� �ʴٰ� �Ǵ���.
// 
// �߰��� k�� 5000���� �־�����, �ش� k�� �� ������ - ���� �ۿ� ���� ������
// int �ڷ����� ���� ���� ���� ���ٰ� �Ǵ��ߴ�.
// 
// ������ ���� dfs�� �̿��� ����Ž���� ���� �ʰ�, next_permutation()�� �̿���
// ��� ����� ���� Ž���ϸ� ������ ���� ���� �湮�� �� �ִ� Ƚ���� ���ϵ��� �������.
// 
// �Ǽ��� =�� ���� ������ ���� ������ Ʋ�Ⱦ���.
//
// �ش� �ڵ�� O(N^2)�̴�.
//

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;

    sort(dungeons.begin(), dungeons.end());

    do
    {
        int Cnt = k;
        int Dgn_Cnt = 0;

        for (size_t i = 0; i < dungeons.size(); ++i)
        {
            int req_fatigue = dungeons[i][0];
            int use_fatigue = dungeons[i][1];

            if (Cnt >= req_fatigue)
            {
                Cnt -= use_fatigue;
                Dgn_Cnt++;
            }
            else
                break;
        }

        answer = max(answer, Dgn_Cnt);

    } while (next_permutation(dungeons.begin(), dungeons.end()));
    
    return answer;
}

void main()
{
    int answer = solution(80, vector<vector<int>>{ {80, 20}, { 50,40 }, { 30,10 }});

    return;
}