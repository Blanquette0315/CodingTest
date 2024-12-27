#include <string>
#include <vector>
#include <math.h>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
	answer.resize(2);

	int a = 2;
	int b = (brown - 4) * -1;
	int c = 2 * yellow;

	// x1 = (-b + 루트(b^2 - 4ac)) / 2a
	int row = ((-1 * b) + sqrt(pow(b, 2) - (4 * (a * c)))) / (2 * a);
	// x2 = (-b - 루트(b^2 - 4ac)) / 2a
	int col = ((-1 * b) - sqrt(pow(b, 2) - (4 * (a * c)))) / (2 * a);

	if (row < col)
	{
		int temp = row;
		row = col;
		col = temp;
	}

	answer[0] = row + 2;
	answer[1] = col + 2;


    return answer;
}

void main()
{
    vector<int> answer = solution(10, 2);

    return;
}