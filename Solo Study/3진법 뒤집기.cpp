#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n) {
    int answer = 0;

    int iQuotient = n;
    int iRemainder = 0;
    string str_num = "";

    while (iQuotient >= 3)
    {
        iRemainder = iQuotient % 3;
        iQuotient /= 3;
        str_num += (char)iRemainder;
    }
    str_num += (char)iQuotient;

    for (int i = str_num.length() - 1; i >= 0; --i)
    {
        int c = str_num.length() - (i + 1);
        answer += (int)str_num[i] * pow(3, c);
    }

    return answer;
}