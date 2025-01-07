#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    string answer = "";

    vector<int> month = { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    vector<string> day = { "THU", "FRI", "SAT", "SUN", "MON", "TUE", "WED" };

    int calday = b;
    for (int i = 1; i < a; ++i)
    {
        calday += month[i];
    }

    calday %= 7;

    answer = day[calday];

    return answer;
}