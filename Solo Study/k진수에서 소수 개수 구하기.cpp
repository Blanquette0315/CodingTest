#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <sstream>

using namespace std;

string to_BassN(int n, int k)
{
    string number = "";

    int A = n;
    int B = 0;
    while (A != 0)
    {
        B = A % k;
        A = A / k;

        number += to_string(B);
    }

    reverse(number.begin(), number.end());
    return number;
}

int to_Decimal(string n, int k)
{
    int number = 0;

    reverse(n.begin(), n.end());

    for (int i = 0; i < n.length(); ++i)
    {
        number += stoi(string(1, n[i])) * pow(k, i);
    }

    return number;
}

bool is_Prime(int n)
{
    if (n == 0)
        return false;
    for (int i = 2; i <= n / 2; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

int solution(int n, int k) {
    int answer = 0;

    string kBassNum = to_BassN(n, k);

    string temp_str;
    istringstream ss(kBassNum);

    while (getline(ss, temp_str, '0'))
    {
        if (is_Prime(to_Decimal(temp_str, k)))
            answer++;
    }

    return answer;
}

void main()
{
    int answer = solution(110011, 10);

    return;
}