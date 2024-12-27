#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// �� ��°�� ������ ����� ���ڿ� �պ��� K+1�� Idx���� ������, �� �� ���� ū���� ã��,
// �� ���� �ε������� �����ָ� �ǰڴٴ� ������ �ߴ�.
// 
// ������ iterator�� ������ ��� max_element�� �̿��� ������ �ִ밪�� ���� ó�� ������ �ε�����
// �޾Ƽ� �� �κб��� �����ذ��� Ǯ���־���.
// 
// 12�� ���̽��� Ʋ�Ⱦ��µ�,
// iter + k�� number.end()�� ��� ������ ��� �߸��� �ּҿ� �����ϱ� ������ ������ �Ǿ���.
// 

string solution(string number, int k) {
    string answer = "";
    
    string::iterator iter = number.begin();
    while (k > 0)
    {
        // iter ~ iter + k + 1���� ���� �� ���� ū���� ���� ó�� ������ �� iter ��ȯ
        string::iterator newiter = max_element(iter, iter + k + 1);

        // ����, iter�� newiter�� ���ٴ� ���� ���� ū ���� ���� ���̶�� ���̱� ������
        // iter�� 1 ���������ص� �ٽ� �˻��Ѵ�.
        if (iter == newiter)
            iter++;
        // �׷��� �ʴٸ�, iter���� newiter���� ���Ҹ� ������ ��, �ش� ������ŭ k�� ���ش�.
        else
        {
            // iter - newiter�� -������ ��ȯ�ȴ�.
            k += iter - newiter;
            number.erase(iter, newiter);
        }
        // ����, iter + k�� enditer���, iter���� ������ �����ص�, k=0���� �ٲ� while����
        // �������´�.
        if (iter + k == number.end())
        {
            number.erase(iter, number.end());
            k = 0;
        }
    }

    answer = number;

    return answer;
}

void main()
{
    string answer = solution("333222111", 3);

    return;
}



// next_permutation���� ������ ��� �˻��ϴ°ͱ����� ��������..
// ���� ������ number�� 1,000,000 �������� �˾Ҵµ�, �ش� ���� �ڸ�������
// ���ڿ��� ���� �����ϴ°� �ſ� �������ϴٴ� ���� �˰ԵǾ���..
// �� ���ռ��� �ʹ� ���Ƽ� �ð� �ʰ��� �߻� �Ѵ�.

string solution(string number, int k) {
    string answer = "";

    // next_permutation()���� ������ ���ϱ� ���� vector �غ�
    vector<bool> Select(number.length() - k, false);
    Select.insert(Select.end(), k, true);

    string MaxNum = "0";
    do
    {
        string Temp;

        for (size_t i = 0; i < Select.size(); ++i)
        {
            if (!Select[i])
                Temp += number[i];
        }

        MaxNum = max(MaxNum, Temp);

    } while (next_permutation(Select.begin(), Select.end()));

    answer = MaxNum;

    return answer;
}