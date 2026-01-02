#include<iostream>
#include<vector>
#include<string>
#include<queue>

#define MAX 100001

int n, k;
int visited[MAX] = {};

int bfs(int n, int k)
{
	std::queue<int> nq;
	nq.push(n);
	visited[n] = 0;

	while (true)
	{
		int current = nq.front();
		nq.pop();

		if (current == k) break;

		int minus = current - 1;
		int plus = current + 1;
		int multi = current * 2;

		if (plus < MAX && visited[plus] == 0)
		{
			nq.push(plus);
			visited[plus] = visited[current] + 1;
		}
		if (minus >= 0 && visited[minus] == 0)
		{
			nq.push(minus);
			visited[minus] = visited[current] + 1;
		}
		if (multi < MAX && visited[multi] == 0)
		{
			nq.push(multi);
			visited[multi] = visited[current] + 1;
		}
	}

	return visited[k];
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> n >> k;
	
	std::cout << bfs(n, k);
	
	return 0;
}