#include <iostream>
#include <vector>

int arr[1025][1025];
int dp[1025][1025];

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N;
	std::cin >> N;
	int M;
	std::cin >> M;

	int num = 0;
	for (int i = 1; i <= N;i++)
	{
		for (int j = 1; j <= N;j++)
		{
			std::cin >> num;
			arr[i][j] = arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1] + num;
		}
	}

	int x1, y1;
	int x2, y2;
	int result = 0;

	for (int i = 0;i < M;i++)
	{
		std::cin >> x1 >> y1 >> x2 >> y2;

		result = arr[x2][y2] - arr[x1 - 1][y2] - arr[x2][y1 - 1] + arr[x1 - 1][y1 - 1];
		std::cout << result << "\n";
	}
}