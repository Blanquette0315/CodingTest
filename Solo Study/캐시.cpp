#include <string>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;

    if (cacheSize == 0)
    {
        return cities.size() * 5;
    }

    list<string> lst;
    for (int i = 0; i < cities.size(); ++i)
    {
        bool Is_miss = true;
        transform(cities[i].begin(), cities[i].end(), cities[i].begin(), ::toupper);

        for (list<string>::iterator iter = lst.begin(); iter != lst.end(); ++iter)
        {
            if (cities[i] == *iter)
            {
                string str_temp = *iter;
                lst.erase(iter);
                lst.push_front(str_temp);

                answer += 1;
                Is_miss = false;
                break;
            }
        }

        if (Is_miss)
        {
            if (lst.size() == cacheSize)
            {
                lst.pop_back();
                lst.push_front(cities[i]);
            }
            else if (lst.size() < cacheSize)
            {
                lst.push_front(cities[i]);
            }
            
            answer += 5;
        }
    }

    return answer;
}

void main()
{
    int answer = solution(3, { "Jeju", "Pangyo", "Seoul", "NewYork", "LA", "Seoul", "Pangyo", "Seoul", "NewYork", "Seoul" });

    int a = 0;

    return;
}