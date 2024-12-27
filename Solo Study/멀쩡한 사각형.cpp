#include <cmath>
using namespace std;

// �ִ� ������� ����� Ǯ����ϴ� ����.. ���� ����..

typedef long long ll;

int gcd(int& w, int& h)
{
    int c;
    while (h != 0)
    {
        c = w % h;
        w = h;
        h = c;
    }

    return w;
}

long long solution(int w, int h) {
    long long answer = 1;

    answer = (ll)w * (ll)h - (w + h);
    answer += gcd(w, h);

    return answer;
}

void main()
{
    long long answer = solution(7, 3);

    return;
}


// Ʋ��

//long long CalSquare(int w, int h, int cnt)
//{
//    long long result = 0;
//    int new_w = w / 2;
//    int new_h = h / 2;
//
//    if (new_w < 1 && new_h < 1)
//        return 0;
//
//    result = CalSquare(new_w, new_h, cnt + 1);
//
//    result += new_w * new_h * pow(2, cnt);
//
//    return result;
//}
//
//long long solution(int w, int h) {
//    long long answer = 1;
//
//    answer = CalSquare(w, h, 1);
//
//    return answer;
//}