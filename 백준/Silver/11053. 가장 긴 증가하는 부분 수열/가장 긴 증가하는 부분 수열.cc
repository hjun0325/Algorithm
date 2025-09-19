#include <iostream>
#include <queue>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int n;
	std::cin >> n;
	
	std::vector<int> arr = std::vector<int>(n + 1);
	std::vector<int> dp;
	arr[0] = 0;
	dp.push_back(0);

	for (int i = 1; i < n + 1; i++)
	{
		std::cin >> arr[i];
	}

	for (int i = 1; i < n + 1; i++)
	{
		if (dp.back() < arr[i])
		{
			dp.push_back(arr[i]);
		}
		else
		{
			int lowerbound = lower_bound(dp.begin(), dp.end(), arr[i]) - dp.begin();
			dp[lowerbound] = arr[i];
		}
	}

	std::cout << dp.size()-1 << "\n";
	return 0;
}