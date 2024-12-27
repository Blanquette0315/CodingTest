#include <iostream>
#include <vector>

using namespace std;

int CulNewStationCount(int i_Length, int i_w)
{
    if (i_Length > 0)
    {
        if (i_Length % (2 * i_w + 1) == 0)
            return i_Length / (2 * i_w + 1);
        else
            return (i_Length / (2 * i_w + 1)) + 1;
    }

    return 0;
}

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    int iLength = 0;

    iLength = stations[0] - w - 1;
    answer += CulNewStationCount(iLength, w);

    for (size_t i = 0; i < stations.size() - 1; ++i)
    {
        iLength = (stations[i + 1] - w) - (stations[i] + w + 1);
        answer += CulNewStationCount(iLength, w);
    }

    iLength = n - (stations.back() + w + 1) + 1;
    answer += CulNewStationCount(iLength, w);


    return answer;
}

void main()
{
    int answer = solution(11, vector<int>{4, 11}, 1);
    //int answer = solution(16, vector<int>{9}, 2);


    return;
}


//int CulNewStationCount(int i_Length, int i_w)
//{
//    if (i_Length % (2 * i_w + 1) == 0)
//        return i_Length / (2 * i_w + 1);
//    else
//        return (i_Length / (2 * i_w + 1)) + 1;
//}


//int solution(int n, vector<int> stations, int w)
//{
//    int answer = 0;
//
//    vector<int> vec_lenth;
//    if (stations[0] - w - 1 > 0)
//        vec_lenth.push_back(stations[0] - w - 1);
//
//    for (size_t i = 0; i < stations.size() - 1; ++i)
//    {
//        vec_lenth.push_back((stations[i + 1] - w) - (stations[i] + w + 1));
//    }
//
//    if (stations.back() + w < n)
//        vec_lenth.push_back(n - (stations.back() + w));
//
//    for (size_t i = 0; i < vec_lenth.size(); ++i)
//    {
//        if (vec_lenth[i] % (2 * w + 1) == 0)
//            answer += vec_lenth[i] / (2 * w + 1);
//        else
//            answer += (vec_lenth[i] / (2 * w + 1)) + 1;
//    }
//
//    return answer;
//}