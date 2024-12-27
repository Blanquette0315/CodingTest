#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//string changeNum(int n, int target)
//{
//    string str = "";
//    int a = target;
//    int b = 0;
//
//    while (a != 0)
//    {
//        b = a % n;
//        a = a / n;
//        if (b < 10)
//            str.insert(0, to_string(b));
//        else
//        {
//            char B = 'A';
//            B += (b - 10);
//            str.insert(str.begin(), B);
//        }
//    }
//    
//    return str;
//}
//
//string solution(int n, int t, int m, int p) {
//    string answer = "";
//
//    string str_Number = "0";
//    int target_len = t * m;
//    int CurNumber = 0;
//    while (str_Number.length() < target_len)
//    {
//        CurNumber++;
//
//        str_Number += changeNum(n, CurNumber);
//    }
//
//    int idx = p - 1;
//    for (int i = 0; i < t; ++i)
//    {
//        answer += str_Number[idx];
//        idx += m;
//    }
//
//    return answer;
//}

// 풀는 시간이 길어서 짧게 풀 수 있도록 수정한 방법
string changeNum(int n, int target)
{
    char number[16] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };
    string str = "";
    int a = target;
    int b = 0;

    while (a != 0)
    {
        b = a % n;
        a = a / n;
        str += number[b];
    }

    reverse(str.begin(), str.end());
    return str;
}

string solution(int n, int t, int m, int p) {
    string answer = "";

    string str_Number = "0";
    int target_len = t * m;
    int CurNumber = 0;
    while (str_Number.length() < target_len)
    {
        CurNumber++;

        str_Number += changeNum(n, CurNumber);
    }

    int idx = p - 1;
    for (int i = 0; i < t; ++i)
    {
        answer += str_Number[idx];
        idx += m;
    }

    return answer;
}

void main()
{
    string answer = solution(2, 4, 2, 1);
    //string answer = solution(16, 16, 2, 1);

    int a = 0;

    return;
}