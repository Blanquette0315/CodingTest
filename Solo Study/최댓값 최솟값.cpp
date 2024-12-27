#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    s += ' ';

    int imax = -0x3f3f3f3f;;
    int imin = 0x3f3f3f3f;;

    /*while (s.find(' ') != string::npos)
    {
        string str_num = s.substr(0, s.find(' '));
        int num = stoi(str_num);

        imax = max(imax, num);
        imin = min(imin, num);

        s.erase(0, s.find(' ') + 1);
    }*/

    while (!s.empty())
    {
        string str_num = s.substr(0, s.find(' '));
        int num = stoi(str_num);

        imax = max(imax, num);
        imin = min(imin, num);
        
        s.erase(s.rfind(' '));
    }


    answer = to_string(imin) + ' ' + to_string(imax);

    return answer;
}

void main()
{
    string answer = solution("1 2 3 4");
}