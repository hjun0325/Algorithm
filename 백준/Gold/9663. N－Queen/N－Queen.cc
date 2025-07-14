#include <iostream>
#include <cmath>

int N, result = 0;
int rows[16];

bool Check(int row)
{
	for (int i = 1; i < row; i++)
	{
		// 체크할 행의 열 위치와 비교할 행의 열 위치가 같은 경우 false.
		if(rows[row]==rows[i])
		{
			return false;
		}
		// (체크할 행의 열)과 (비교할 행의 열) 차이와
		// (체크할 행)과 (비교할 행)의 차이가 같은 경우 대각선에 위치한다 false.
		if (abs(rows[row] - rows[i]) == (row - i))
		{
			return false;
		}
	}

	return true;
}

void BackTraking(int row)
{
	if (row == N + 1)
	{
		result ++;
		return;
	}

	for (int i = 1; i <= N; ++i)
	{
		rows[row] = i;

		// 해당 위치에 놓은 퀸이 유효한지 확인.
		// 유효하면 다음 행.
		// 유효하지 않으면 해당 행에 다음 열로 이동.
		if (Check(row))
		{
			BackTraking(row + 1);
		}
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N;

	BackTraking(1);

	std::cout << result;
}
