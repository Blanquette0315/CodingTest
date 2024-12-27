#include <string>
#include <vector>
#include <bitset>

using namespace std;

int solution(int n) {
    int answer = 0;

    int count = bitset<32>(n).count();

    int nxtnum = n;
    while (true)
    {
        nxtnum++;
        if (bitset<32>(nxtnum).count() == count)
            break;
    }

    answer = nxtnum;

    return answer;
}

void main()
{
    int answer = solution(78);

    return;
}