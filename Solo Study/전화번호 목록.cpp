#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// ó�� Ǯ�� ������ �� ��, �ܼ��� 2�� �ݺ����� ���� Ǯ���ߴ�. �����ϱ� ������ ȿ���� �׽�Ʈ���� ������ ���̶� �����ߴ���� �����ߴ�.
// �׷��� �ݺ� Ƚ���� �� ���̷��� �����غ���, ���ξ��̱� ������ ���ʺ��� Ȯ���� break �ɾ� Ƚ���� �ٿ��־���.

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

// ���� Ǯ�̹�.. unordered_map�� �� ����� �� ����.
// ������ �ð��� ������ �ɸ��� ������ �ִ�.
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