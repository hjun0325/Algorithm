#include <iostream>
#include <queue>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::priority_queue<int, std::vector<int>, std::greater<int>> minPQ;
	std::priority_queue<int, std::vector<int>, std::less<int>> maxPQ;

	int N;
	int x;

	std::cin >> N;

	for (int i = 0; i < N; ++i)
	{
		std::cin >> x;

		if (i == 0)
		{
			maxPQ.push(x);
			std::cout << maxPQ.top() << "\n";
			continue;
		}

		if (i == 1 || minPQ.size() < maxPQ.size())
		{
			if (maxPQ.top() > x)
			{
				minPQ.push(maxPQ.top());
				maxPQ.pop();
				maxPQ.push(x);
			}
			else
			{
				minPQ.push(x);
			}
		}
		else
		{
			if (minPQ.top() > x)
			{
				maxPQ.push(x);
			}
			else
			{
				maxPQ.push(minPQ.top());
				minPQ.pop();
				minPQ.push(x);
			}
		}

		std::cout << maxPQ.top() << "\n";
	}

	return 0;
}