#include <iostream>
#include <unordered_map>
#include <queue>

using namespace std;

// ó������ BFS �̿��� ���� Ž���� �ϸ鼭 Memo�ذ��� �ǰڴ� ������.
// ������ ����ߴ���� ���� �ð��� �ʹ� �����ɷ��� �Ұ�������.
// 
// ��Ե� �������� ��Ģ�� ã�����غ��ٰ�
// �����غ��� 2�� ������ �ִ� ��ŭ �ִ��� ������, -1�� ���� �ٽ� ¦���� �ٲ� ��, �ٽ� 2�� �������ָ� �ȴٴ� ���� Ȯ���ߴ�.
//
// 
// ã�ƺ��� ��Ʈ ������ �ɰ��� �����ϴ� ����� �����Ѵ�.
// ��, 2�������� ǥ������ ��, 1�� �κ��� ���ϱ�(jump)�� ���� ���̱� ������ 1�� ������ �����ָ� �ȴ�.
// 
// 10������ 2������ ��ȯ�� ��, 2�� ������ �������� 0�� ����ϰ�, �������� 1�̸� 1�� ����ϸ� ����Ǳ� ����.
// �Ųٷ� �����غ���, �ּ������� ������ �ϸ鼭 �ڷ���Ʈ�� ����� ���ϴ� ���� ����� �Ͱ� �����ϴ�.
// 
// �����Ϸ� �������� �������ִ� �Լ��� �����ϴµ�,
// gcc �����Ϸ� ȯ���̳�, msvc ȯ���̳Ŀ� ���� �Լ����� �ٸ��ٴ� ���� �����ؾ� �Ѵ�.
// msvc�� __popcnt()
// gcc�� __builtin_popcount() �̴�.
//                              �� �ش� �Լ��� C++20���� ����� bit�ȿ� �ִ� �޼ҵ��̴�.
//                                  ���� unsigned int �ڷ����� ���ؼ��� �����Ѵ�.
// �ش� �Լ����� ��Ʈ������ 1�� ������ ���� ��ȯ���ش�.
// ��Ʈ���� ���꿡�� �ַ� ���ȴٰ� �Ѵ�.
//

// bfs�� Ǯ���� ��.
//int solution(int n)
//{
//    int ans = 0;
//    
//    if (n == 1)
//        return 1;
//
//    // idx pair<jump, tel>
//    unordered_map<int, pair<int, int>> Memo;
//    queue<int> qu;
//
//    // 2���� ���� �ּҴ� ���� 1ȸ�� �ڷ���Ʈ 1ȸ
//    Memo.insert({ 2, {1, 1} });
//    qu.push(2);
//
//    while (!qu.empty())
//    {
//        int num = qu.front();
//        qu.pop();
//        int jump_cnt = Memo[num].first;
//        int tel_cnt = Memo[num].second;
//        int jump = num + 1;
//        int tel = num * 2;
//
//        if (jump <= n)
//        {
//            // jump�� ���� ���ڰ� ���ٸ�, �ٷ� ���
//            if (Memo.find(jump) == Memo.end())
//            {
//                Memo.insert({ jump, {jump_cnt + 1,tel_cnt} });
//                qu.push(jump);
//            }
//            else
//            {
//                if (Memo[jump].first > jump_cnt + 1)
//                {
//                    Memo[jump].first = jump_cnt + 1;
//                    Memo[jump].second = tel_cnt;
//                    qu.push(jump);
//                }
//            }
//        }
//        
//        if (tel <= n)
//        {
//            // tel�� ���� ���ڰ� ���ٸ�, �ٷ� ���
//            if (Memo.find(tel) == Memo.end())
//            {
//                Memo.insert({ tel, {jump_cnt, tel_cnt + 1} });
//                qu.push(tel);
//            }
//            else
//            {
//                if (Memo[tel].first > jump_cnt)
//                {
//                    Memo[tel].first = jump_cnt;
//                    Memo[tel].second = tel_cnt + 1;
//                    qu.push(tel);
//                }
//            }
//        }
//    }
//
//    ans = Memo[n].first;
//
//    return ans;
//}

// ������ ������ ¥�� �ڵ�
//#include <iostream>
//using namespace std;
//
//int solution(int n)
//{
//    int ans = 0;
//
//    while (n != 0)
//    {
//        if (n % 2 == 0)
//            n /= 2;
//        else
//        {
//            n--;
//            ans++;
//        }
//    }
//
//    return ans;
//}

// bitset�� �̿��� ¥�� �ڵ�
// 32��Ʈ�� 0 ~ 4,294,967,295���� ǥ���� �����ϱ� ������ 10���̸� 32��Ʈ�� ��Ƶ� ����ϴ�
#include <iostream>
#include <bitset>
using namespace std;

int solution(int n)
{
    int ans = 0;

    bitset<32> bitnum(n);
    // count()�� ��Ʈ ���� 1�� ������ ��ȯ�Ѵ�.
    //ans = bitnum.count();

    // ��ȸ�ϸ鼭 ���� üũ,
    // �̶�, [0]������ ���� ��, ��, 1,0�� ����ϴ� ��Ʈ���� ������.
    for (size_t i = 0; i < 32; ++i)
    {
        if (bitnum[i] == 1)
            ans++;
    }

    return ans;
}

void main()
{
    int answer = solution(5000);

    return;
}