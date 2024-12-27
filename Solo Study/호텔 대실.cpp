#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(vector<string> A, vector<string> B)
{
    int iAhour = stoi(string(A[0].begin(), A[0].begin() + 2));
    int iAmin = stoi(string(A[0].end() - 2, A[0].end()));

    int iBhour = stoi(string(B[0].begin(), B[0].begin() + 2));
    int iBmin = stoi(string(B[0].end() - 2, B[0].end()));

    if (iAhour == iBhour)
    {
        return iAmin < iBmin;
    }
    else
    {
        return iAhour < iBhour;
    }
}

int solution(vector<vector<string>> book_time) {
    int answer = 0;

    vector<string> vecgroup = {};

    sort(book_time.begin(), book_time.end(), compare);

    for (size_t i = 0; i < book_time.size(); ++i)
    {
        bool bNeedGroup = true;
        int idx = -1;

        if (vecgroup.empty())
        {
            vecgroup.push_back(book_time[i][1]);
        }
        else
        {
            int iCheck_hour = stoi(string(book_time[i][0].begin(), book_time[i][0].begin() + 2));
            int iCheck_min = stoi(string(book_time[i][0].end() - 2, book_time[i][0].end()));

            for (size_t j = 0; j < vecgroup.size(); ++j)
            {
                int iGroup_hour = stoi(string(vecgroup[j].begin(), vecgroup[j].begin() + 2));
                int iGroup_min = stoi(string(vecgroup[j].end() - 2, vecgroup[j].end())) + 10;

                if (iGroup_min >= 60)
                {
                    iGroup_min -= 60;
                    iGroup_hour += 1;
                }

                if (iCheck_hour == iGroup_hour)
                {
                    if (iCheck_min >= iGroup_min)
                    {
                        bNeedGroup = false;
                        idx = j;
                        break;
                    }
                }
                else
                {
                    if (iCheck_hour > iGroup_hour)
                    {
                        bNeedGroup = false;
                        idx = j;
                        break;
                    }
                }
            }

            if (bNeedGroup)
            {
                vecgroup.push_back(book_time[i][1]);
            }
            else
            {
                vecgroup[idx] = book_time[i][1];
            }
        }
    }

    answer = vecgroup.size();

    return answer;
}