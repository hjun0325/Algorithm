#include <iostream>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N, M;

	std::cin >> N >> M;
	int* arr = new int[N + 1] { };

	for (int i = 1;i <= N;i++)
	{
		std::cin >> arr[i];
		arr[i] += arr[i - 1];
	}

	int i, j;
	for (int k = 0;k < M;k++)
	{
		std::cin >> i >> j;
		int result = arr[j] - arr[i - 1];
		std::cout << result << "\n";
	}
}