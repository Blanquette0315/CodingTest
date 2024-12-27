#include <iostream>
#include <vector>

using namespace std;

int main() {

    int n = 0;
    cin >> n;

    vector<int> vec_x(n);
    vector<int> vec_y(n);

    for (size_t i = 0; i < n; ++i)
    {
        cin >> vec_x[i] >> vec_y[i];
    }

    return 0;
}