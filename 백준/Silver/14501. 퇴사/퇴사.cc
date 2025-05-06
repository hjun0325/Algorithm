#include <iostream>
#include <vector>

int main()
{
	int N;
	std::cin >> N;

	std::vector<int> dp(N + 1);
	std::vector<int> T(N + 1);
	std::vector<int> P(N + 1);
	int max = 0;

	for (int i = 0; i < N; i++) {
		std::cin >> T[i] >> P[i];
	}

	for (int i = 0;i <= N;i++)
	{
		dp[i] = dp[i] > max ? dp[i] : max;
		if (i + T[i] <= N)
		{
			dp[i + T[i]] = dp[T[i] + i] > P[i] + dp[i] ? dp[T[i] + i] : P[i] + dp[i];
		}
		max = dp[i] > max ? dp[i] : max;
	}

	std::cout << max;
}