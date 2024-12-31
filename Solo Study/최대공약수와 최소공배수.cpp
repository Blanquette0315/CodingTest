#include <string>
#include <vector>

using namespace std;

int gcd(int a, int b)
{
    int c = -1;
    int result = 0;
    do
    {
        if (a > b)
        {
            c = a % b;
            a = c;
            result = b;
        }
        else
        {
            c = b % a;
            b = c;
            result = a;
        }

    } while (c != 0);
    
    return result;
}

int lcm(int a, int b)
{
    return (a * b) / gcd(a, b);
}

vector<int> solution(int n, int m) {
    vector<int> answer;

    answer.push_back(gcd(n, m));
    answer.push_back(lcm(n, m));

    return answer;
}