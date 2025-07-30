#include <iostream>

int dp[201];
int children[201];

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N;
	std::cin >> N;

	for (int i = 0; i < N; i++)
	{
		std::cin >> children[i];
	}

	dp[0] = 1;
	int max = 0;
	for (int i = 0; i < N; i++)
	{
		dp[i] = 1;
		for (int j = i - 1; j >= 0; j--)
		{
			if (children[i] > children[j] && dp[j] >= dp[i])
			{
				dp[i] = dp[j] + 1;
			}
		}
		if (max < dp[i])
		{
			max = dp[i];
		}
	}

	std::cout << N - max;

	return 0;
}