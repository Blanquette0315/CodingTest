#include <string>
#include <algorithm>
#include <map>

using namespace std;

// 처음에 vector로 다중 집합을 만들다 개수를 세는 쪽에있어서는 map이 더 편해보여서 바꾸는 과정에서 시간이 조금 걸렸다.
// 또 그게 아니더라도 코드양이 길다보니 시간이 오래걸렸던 것 같다..

void make_set(map<string, int>& str_map, string target)
{
    for (int i = 0; i < target.length() - 1; ++i)
    {
        if (isalpha(target[i]) && isalpha(target[i + 1]))
        {
            string str = "";
            str.push_back(toupper(target[i]));
            str.push_back(toupper(target[i + 1]));

            if (str_map.find(str) == str_map.end())
                str_map.insert({ str, 1 });
            else
                str_map.find(str)->second++;
        }
    }
}

int Intersection(map<string, int>& map_A, map<string, int>& map_B)
{
    int count = 0;

    for (map<string, int>::iterator iter = map_A.begin(); iter != map_A.end(); ++iter)
    {
        if (map_B.find(iter->first) != map_B.end())
        {
            if (map_B.find(iter->first)->second < iter->second)
                count += map_B.find(iter->first)->second;
            else
                count += iter->second;
        }
    }

    return count;
}

int Set_Count(map<string, int>& map_A)
{
    int count = 0;

    for (map<string, int>::iterator iter = map_A.begin(); iter != map_A.end(); ++iter)
    {
        count += iter->second;
    }

    return count;
}

int solution(string str1, string str2) {
    int answer = 0;

    map<string, int> map_set_A, map_set_B;

    make_set(map_set_A, str1);
    make_set(map_set_B, str2);

    int i_Inter = Intersection(map_set_A, map_set_B);
    int i_Union = (Set_Count(map_set_A) - i_Inter) + Set_Count(map_set_B);

    int i_Jaccard = 0;

    if (i_Inter == 0 && i_Union == 0)
        i_Jaccard = 65536;
    else
        i_Jaccard = (float)i_Inter / (float)i_Union * 65536;

    answer = i_Jaccard;

    return answer;
}

void main()
{
    //int answer = solution("FRANCE", "french");
    int answer = solution("aa1+aa2", "AAAA12");

    return;
}