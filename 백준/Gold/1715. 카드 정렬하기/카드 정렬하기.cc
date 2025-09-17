#include <iostream>
#include <queue>

//struct cmp
//{
//	bool operator()(int a, int b)
//	{
//		if (abs(a) == abs(b)) return a > b;
//		return abs(a) > abs(b);
//	}
//};

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::priority_queue<int, std::vector<int>, std::greater<int>> pq;

	int N;
	int x;
	int result = 0;

	std::cin >> N;

	for (int i = 0; i < N; ++i)
	{
		std::cin >> x;
		pq.push(x);
	}

	while (pq.size() != 1)
	{
		int x, y;

		x = pq.top();
		pq.pop();
		y = pq.top();
		pq.pop();

		result += x + y;
		pq.push(x + y);
	}

	std::cout << result;

	return 0;
}