#include <iostream>
#include <vector>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int testcase;
	std::cin >> testcase;

	for (int t = 0; t < testcase; t++)
	{
		int n;
		std::cin >> n;

		std::vector<int> coins;
		for (int i = 0; i < n; i++)
		{
			int coin;
			std::cin >> coin;
			coins.push_back(coin);
		}

		int m;
		std::cin >> m;

		std::vector<int> dp;
		dp.resize(10001);

		dp[0] = 1;
		for (auto coin : coins)
		{
			for (int i = coin; i <= m; i++)
			{
				dp[i] = dp[i] + dp[i - coin];
			}
		}

		std::cout << dp[m] <<"\n";
	}

	return 0;
}