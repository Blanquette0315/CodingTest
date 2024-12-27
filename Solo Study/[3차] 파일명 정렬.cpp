#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// sort()를 사용하면 틀린다.
// 이유는 sort()는 원소의 순서를 보장해주지 않기 때문이다.
// 즉, 이번 문제에서는 Amg05.Png, Amg1.png, Amg01.png 가 있다면, 정렬했을 때 동일한 것인 Amg1.png, Amg01.png의 순서가 보장되지 않는다는 것이다.
// 음.. 왜인지 몰라도 길이가 짧은 배열에서는 순위가 보장되는데, 길어질 경우 보장되지 않는것 같다.
// 때문에 stable_sort()를 이용해 주어야 한다.
// 속도적인 측면에서는 sort()가 stable_sort()보다 훨씬 빠르다.

// https://gamedevforever.com/318

bool compare(string _A, string _B)
{
    string HEAD_A, HEAD_B, NUMBER_A, NUMBER_B, TAIL_A, TAIL_B;

    bool Find_Head = false, Find_Num = false;
    int idx = 0;
    while (idx < _A.length())
    {
        if (!Find_Head)
        {
            if (isalpha(_A[idx]))
            {
                HEAD_A += toupper( _A[idx]);
                idx++;
            }
            else if (_A[idx] == ' ' || _A[idx] == '-' || _A[idx] == '.')
            {
                HEAD_A += _A[idx];
                idx++;
            }
            else
                Find_Head = true;
        }
        else if (Find_Head && !Find_Num)
        {
            if (NUMBER_A.length() < 5 && _A[idx] >= '0' && _A[idx] <= '9')
            {
                NUMBER_A += _A[idx];
                idx++;
            }
            else
                Find_Num = true;
        }
        else if (Find_Head && Find_Num)
        {
            TAIL_A += _A[idx];
            idx++;
        }
    }

    Find_Head = false;
    Find_Num = false;
    idx = 0;

    while (idx < _B.length())
    {
        if (!Find_Head)
        {
            if (isalpha(_B[idx]))
            {
                HEAD_B += toupper(_B[idx]);
                idx++;
            }
            else if (_B[idx] == ' ' || _B[idx] == '-' || _B[idx] == '.')
            {
                HEAD_B += _B[idx];
                idx++;
            }
            else
                Find_Head = true;
        }
        else if (Find_Head && !Find_Num)
        {
            if (NUMBER_B.length() < 5 && _B[idx] >= '0' && _B[idx] <= '9')
            {
                NUMBER_B += _B[idx];
                idx++;
            }
            else
                Find_Num = true;
        }
        else if (Find_Head && Find_Num)
        {
            TAIL_B += _B[idx];
            idx++;
        }
    }

    if (HEAD_A != HEAD_B)
        return HEAD_A < HEAD_B;
    else
    {
        int num_A = stoi(NUMBER_A);
        int num_B = stoi(NUMBER_B);
        if (num_A != num_B)
            return num_A < num_B;
        else
        {
            return false;
        }
    }
}

vector<string> solution(vector<string> files) {
    vector<string> answer;

    stable_sort(files.begin(), files.end(), compare);
    answer = files;

    return answer;
}

void main()
{
    vector<string> answer = solution({ "A500001", "A50000" });
    //vector<string> answer = solution({ "F-5 Freedom Fighter", "B-50 Superfortress", "A-10 Thunderbolt II", "F-14 Tomcat" });

    return;
}