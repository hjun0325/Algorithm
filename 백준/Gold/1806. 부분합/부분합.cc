#include <iostream>
#include <queue>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int n, s;
	std::cin >> n >> s;

	int value;
	int possibleSum = 0;
	std::vector<int> sequence;
	for (int i = 0; i < n; ++i)
	{
		std::cin >> value;
		possibleSum += value;
		sequence.push_back(value);
	}

	if (possibleSum < s)
	{
		std::cout << "0";
		return 0;
	}

	int left = 0, right = 0;
	int maxSum = sequence[0];
	int result = n;
	while (true)
	{
		if (maxSum >= s)
		{
			result = (right - left + 1 < result) ? (right - left + 1) : result;
			maxSum -= sequence[left];
			left += 1;
		}
		else
		{
			right += 1;
			if (right == n) break;

			maxSum += sequence[right];
		}

		if (result == 1)
		{
			break;
		}
	}

	std::cout << result;
	
	return 0;
}