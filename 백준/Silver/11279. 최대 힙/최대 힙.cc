#include <iostream>
#include <queue>


int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::priority_queue<int> pq;

	int N;
	int x;

	std::cin >> N;

	for (int i = 0; i < N; ++i)
	{
		std::cin >> x;
		if (x == 0)
		{
			if (pq.size() == 0)
			{
				std::cout << "0\n";
			}
			else
			{
				std::cout << pq.top() << "\n";
				pq.pop();
			}
		}
		else
		{
			pq.push(x);
		}
	}

	return 0;
}