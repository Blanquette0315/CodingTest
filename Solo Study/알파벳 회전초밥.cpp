#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    string A;
    string B;
    int answer = 1;

    cin >> A >> B;
    
    vector<int> vec_idx(B.length());

    for (size_t i = 0; i < B.length(); ++i)
    {
        vec_idx[i] = A.find(B[i]);
    }

    for (size_t i = 0; i < vec_idx.size() - 1; ++i)
    {
        if (vec_idx[i] >= vec_idx[i + 1])
        {
            answer++;
        }
    }

    cout << answer;

    return 0;
}