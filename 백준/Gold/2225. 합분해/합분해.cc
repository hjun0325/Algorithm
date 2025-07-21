#include <iostream>
#include <cmath>

int dp[201][201];

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N, K;
	std::cin >> N >> K;

	for (int i = 1; i <= K; i++)
	{
		dp[1][i] = i;
	}

	for (int i = 2; i <= N; i++)
	{
		for (int j = 1; j <= K; j++)
		{
			dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % 1000000000;
		}
	}
	
	std::cout << dp[N][K];

	return 0;
}