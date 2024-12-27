#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 두 번째로 생각한 방법은 문자열 앞부터 K+1번 Idx까지 접근해, 그 중 가장 큰수를 찾고,
// 그 앞쪽 인덱스들을 지워주면 되겠다는 생각을 했다.
// 
// 때문에 iterator로 범위를 잡아 max_element를 이용해 구간중 최대값이 제일 처음 나오는 인덱스를
// 받아서 그 부분까지 삭제해가며 풀어주었다.
// 
// 12번 케이스만 틀렸었는데,
// iter + k가 number.end()일 경우 범위를 벗어나 잘못된 주소에 접근하기 때문에 문제가 되었다.
// 

string solution(string number, int k) {
    string answer = "";
    
    string::iterator iter = number.begin();
    while (k > 0)
    {
        // iter ~ iter + k + 1까지 구간 중 가장 큰수가 제일 처음 나오는 곳 iter 반환
        string::iterator newiter = max_element(iter, iter + k + 1);

        // 만약, iter가 newiter와 같다는 것은 가장 큰 수가 제일 앞이라는 것이기 때문에
        // iter를 1 증가시켜준뒤 다시 검사한다.
        if (iter == newiter)
            iter++;
        // 그렇지 않다면, iter부터 newiter까지 원소를 지워준 뒤, 해당 갯수만큼 k를 빼준다.
        else
        {
            // iter - newiter는 -갯수가 반환된다.
            k += iter - newiter;
            number.erase(iter, newiter);
        }
        // 만약, iter + k가 enditer라면, iter부터 끝까지 지워준뒤, k=0으로 바꿔 while문을
        // 빠져나온다.
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



// next_permutation으로 조합을 모두 검사하는것까지는 좋았으나..
// 제한 조건이 number가 1,000,000 이하인줄 알았는데, 해당 수가 자리수여서
// 문자열을 수로 변경하는게 매우 부적절하다는 것을 알게되었다..
// 또 조합수가 너무 많아서 시간 초과가 발생 한다.

string solution(string number, int k) {
    string answer = "";

    // next_permutation()으로 조합을 구하기 위한 vector 준비
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