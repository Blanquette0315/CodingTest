#include <iostream>
#include <string>
using namespace std;

// 펠린드롬(pailindrome) 이란 앞뒤를 뒤집어도 똑같은 문자열을 의미한다.
//
// 첫번 째 아이디어는 문자열의 최종 길이부터 슬라이딩 윈도우 기법으로 찾는 것이다.
// 처음에 17, 18번 케이스를 틀렸는데,
// 나는 ab일 경우 펠린드롬이 없다 생각해 0을 반환했는데,
// a나 b로 쪼개질 경우 본인을 뒤집어도 같기 때문에 사실상 문자 하나는 펠린드롬이었다.
// 때문에 1을 반환해주도록 만들었다.
// 
// 하지만 효율성 테스트에서 1번에서 시간 초과가 나와서 보다 효율적인 방법에 대해 생각해보게 되었다.
// 
// 생각이 안나서 질문글들을 살펴본 결과
// string.substr() 함수가 O(N)이라는 시간복잡도를 갖기 때문에
// 문자열을 분해하지 않고 직접 인덱스로 접근하는것이 훨씬 시간이 덜 든다는 것을 알았다.
// 
// 시간이 거의 2배 가량 차이가 난다고 한다.
//
// 정현이꺼 보니까 투 포인터를 이용한 풀이도 가능하고 훨씬 효율적이다.
// mid를 밀어주면서 찾는 방법..
// 
// 
// 
// XOR 비트 연산자로 생각해보기.
//


// 아래 코드는 substr()을 이용해 푼 것. 하지만 효율성 테스트 1번을 실패한다.

//bool findpailind(string str_SubString)
//{
//    int iLeftIdx = 0;
//    int iRightIdx = str_SubString.size() - 1;
//
//    while (iLeftIdx < iRightIdx)
//    {
//        if (str_SubString[iLeftIdx] != str_SubString[iRightIdx])
//            return false;
//
//        iLeftIdx++;
//        iRightIdx--;
//    }
//
//    return true;
//}
//
//int solution(string s)
//{
//    int answer = 1;
//
//    for (size_t i = s.length(); i > 1; --i)
//    {
//        for (size_t j = 0; j < s.length() + 1 - i; ++j)
//        {
//            string str_SubStrin = s.substr(j, i);
//            if (findpailind(str_SubStrin))
//            {
//                answer = str_SubStrin.length();
//                return answer;
//            }
//        }
//    }
//
//    return answer;
//}

bool findpailind(int LeftIdx, int RightIdx, const string& str_string)
{
    int iLeftIdx = LeftIdx;
    int iRightIdx = RightIdx;

    while (iLeftIdx < iRightIdx)
    {
        if (str_string[iLeftIdx] != str_string[iRightIdx])
            return false;

        iLeftIdx++;
        iRightIdx--;
    }

    return true;
}

int solution(string s)
{
    int answer = 1;

    for (size_t i = s.length(); i > 1; --i)
    {
        for (size_t j = 0; j < s.length() + 1 - i; ++j)
        {
            if (findpailind(j, j + i - 1 ,s))
            {
                answer = i;
                return answer;
            }
        }
    }

    return answer;
}

void main()
{
    int answer = solution("abddcba");

    int a = 0;

    return;
}