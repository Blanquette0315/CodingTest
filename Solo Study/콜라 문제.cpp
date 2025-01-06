#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n) {
    int answer = 0;

    int left = 0;

    do
    {
        answer += n / a * b;
        left = n / a * b;
        left += n % a;
        n = left;

    } while (left >= a);

    return answer;
}