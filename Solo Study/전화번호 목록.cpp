#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 처음 풀때 정렬을 한 뒤, 단순히 2중 반복문을 통해 풀려했다. 실행하기 전에도 효율성 테스트에서 실패할 것이라 예상했던대로 실패했다.
// 그래서 반복 횟수를 더 줄이려고 생각해보니, 접두어이기 때문에 앞쪽부터 확인해 break 걸어 횟수를 줄여주었다.

bool solution(vector<string> phone_book) {
    bool answer = true;

    sort(phone_book.begin(), phone_book.end(), less<string>());

    for (int i = 0; i < phone_book.size(); ++i)
    {
        for (int j = i + 1; j < phone_book.size(); ++j)
        {
            if (phone_book[j].find(phone_book[i]) == 0)
                return false;
            else
              break;
        }
    }

    return answer;
}

// 동생 풀이법.. unordered_map을 잘 사용한 것 같다.
// 하지만 시간이 더오래 걸리는 단점이 있다.
// 
//#include <string>
//#include <vector>
//#include <unordered_map>
//
//using namespace std;
//
//bool solution(vector<string> phone_book) {
//    bool answer = true;
//    unordered_map<string, int> um;
//
//    for (int i = 0; i < phone_book.size(); i++) um.insert({ phone_book[i], i });
//
//    for (int i = 0; i < phone_book.size(); i++) {
//        for (int j = 0; j < phone_book[i].size(); j++) {
//            if (um.count(phone_book[i].substr(0, j))) {
//                answer = false;
//                return answer;
//            }
//        }
//    }
//
//    return answer;
//}

void main()
{
    //bool answer = solution(vector<string>{"12", "123", "1235", "567", "88"});
    bool answer = solution(vector<string>{"123", "456", "789"});
    int a = 0;
    return;
}