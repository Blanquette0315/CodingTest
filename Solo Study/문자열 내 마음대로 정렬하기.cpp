#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const string& A, const string& B, int n)
{
    if (A[n] == B[n])
    {
        return A < B;
    }

    return A[n] < B[n];
}

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;

    sort(strings.begin(), strings.end(),
        [&n](const string& a, const string& b)
        {
            return compare(a, b, n);
        });

    answer = strings;

    return answer;
}