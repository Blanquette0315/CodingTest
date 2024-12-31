using namespace std;

long long solution(int price, int money, int count)
{
    long long answer = -1;

    long long pay = 0;
    for (int i = 1; i <= count; ++i)
    {
        pay += price * i;
    }

    if (pay > money)
        answer = pay - money;
    else
        answer = 0;

    return answer;
}