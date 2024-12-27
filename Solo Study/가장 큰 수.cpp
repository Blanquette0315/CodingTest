#include <string>
#include <algorithm>
#include <vector>

using namespace std;

// �׳� �ܼ��� A�� B�� ���ڸ� ���� ���ϴ� ������ ���� ���� ���÷Ȱ�,
// �������� �ٸ��� Ǯ������ �ѹ� �� �������� Ǯ��� ������. (30�� ����..)
// 
// 9, 999 �� ��,
// 54, 5455 �� ��, ���.. ����� ������ �ʹ� ������.
// 
// ������ string -> ���� �ڸ����� index�� ������ �ٽ� int�� �����ϴ°� �ʹ� �����غ�����.
// ��� ��¥�� ���ڸ� ���̱� ������ -48�� ���൵ ��������
// �����Ѱ� ������ �׳� ����Ұ� ������.
// -> ������..
// 
// ������ ������ ���� A�� B�� �̿��� ����� �ִ� �� ���� �� �� ũ�� ���� ������ ������ ���־���.
//
// �������� Ǯ� 11�� ���̽�?������ Ʋ���°� ��Ȳ�������µ�,
// �̺κ��� Ȯ���غ��� 0, 0, 0, 0�� ��, ���� "0"���� ������ �ʰ�, "0000"���� �����°� ��������.
// ������ �� �אk��..
//
// ���ο� �õ� 30��(����) + ���� ��� 10��

bool compare(int i_A, int i_B)
{
    string str_Num_A = to_string(i_A);
    string str_Num_B = to_string(i_B);

    int i_Num_AB = stoi(str_Num_A + str_Num_B);
    int i_Num_BA = stoi(str_Num_B + str_Num_A);

    return i_Num_AB > i_Num_BA;
}

string solution(vector<int> numbers) {
    string answer = "";

    sort(numbers.begin(), numbers.end(), compare);

    for (size_t iNumIdx = 0; iNumIdx < numbers.size(); ++iNumIdx)
    {
        answer += to_string(numbers[iNumIdx]);
    }

    if (answer[0] == '0')
        answer = "0";

    return answer;
}

void test(int&& i_A)
{
    ++i_A;
}

void main()
{
    //string answer = solution(vector<int>{6, 10, 2});
    string answer = solution(vector<int>{999, 9, 12, 1213});

    int a = 0;

    return;
}