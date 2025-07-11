#include <iostream>

int dp[101][100001]{};

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	int N; // 물품 수.
	int K; // 가능한 무게.
	std::cin >> N >> K;

	int W; // 물건의 무게.
	int V; // 물건의 가치.
	for (int i = 1; i <= N; i++)
	{
		std::cin >> W >> V;

		// 배낭의 무게 별 확인.
		for (int j = 1; j <= K; j++)
		{
			// 배낭의 무게보다 물건의 무게가 큰 경우.
			if (j < W)
			{
				dp[i][j] = dp[i - 1][j];
			}
			// 배낭의 무게보다 물건의 무게가 작거나 같은 경우.
			else
			{
				dp[i][j] = std::max(dp[i - 1][j], V + dp[i - 1][j - W]);
			}
		}
	}

	std::cout << dp[N][K];
}
