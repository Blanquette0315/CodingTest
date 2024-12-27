#include <iostream>
#include <unordered_map>
#include <queue>

using namespace std;

// 처음에는 BFS 이용해 완전 탐색을 하면서 Memo해가면 되겠다 생각함.
// 하지만 우려했던대로 수행 시간이 너무 오래걸려서 불가능했음.
// 
// 어떻게든 수학적인 규칙을 찾으려해보다가
// 생각해보니 2로 나눌수 있는 만큼 최대한 나누고, -1을 해줘 다시 짝수로 바꾼 뒤, 다시 2로 나누어주면 된다는 것을 확인했다.
//
// 
// 찾아보니 비트 단위로 쪼개어 생각하는 방법이 존재한다.
// 즉, 2진법으로 표현했을 때, 1인 부분은 더하기(jump)로 사용된 것이기 때문에 1의 개수를 세어주면 된다.
// 
// 10진수를 2진수로 변환할 때, 2를 나누어 떨어지면 0을 기록하고, 나머지가 1이면 1을 기록하며 진행되기 때문.
// 거꾸로 생각해보면, 최소한으로 점프를 하면서 텔레포트를 사용해 원하는 수를 만드는 것과 동일하다.
// 
// 컴파일러 단위에서 제공해주는 함수가 존재하는데,
// gcc 컴파일러 환경이냐, msvc 환경이냐에 따라 함수명이 다르다는 점을 주의해야 한다.
// msvc는 __popcnt()
// gcc는 __builtin_popcount() 이다.
//                              ㄴ 해당 함수는 C++20부터 적용된 bit안에 있는 메소드이다.
//                                  또한 unsigned int 자료형에 대해서만 동작한다.
// 해당 함수들은 비트단위로 1의 개수를 세어 반환해준다.
// 비트단위 연산에서 주로 사용된다고 한다.
//

// bfs로 풀었던 것.
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
//    // 2까지 가는 최소는 점프 1회와 텔레포트 1회
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
//            // jump로 만든 숫자가 없다면, 바로 등록
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
//            // tel로 만든 숫자가 없다면, 바로 등록
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

// 공식을 세워서 짜본 코드
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

// bitset을 이용해 짜본 코드
// 32비트가 0 ~ 4,294,967,295까지 표현이 가능하기 때문에 10억이면 32비트로 잡아도 충분하다
#include <iostream>
#include <bitset>
using namespace std;

int solution(int n)
{
    int ans = 0;

    bitset<32> bitnum(n);
    // count()는 비트 단위 1의 개수를 반환한다.
    //ans = bitnum.count();

    // 순회하면서 직접 체크,
    // 이때, [0]접근은 가장 뒤, 즉, 1,0을 담당하는 비트부터 접근함.
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