#include<iostream>
#include<vector>
#include<queue>

#define MAX_VTXS 300001

int n, m, k, x;
int dist[MAX_VTXS];
bool visited[MAX_VTXS];
std::vector<std::vector<int>> adj;
std::queue<int> q;

void bfs(int n)
{
	q.push(n);
	dist[n] = 0;
	visited[n] = true;

	while (!q.empty())
	{
		int now = q.front();
		q.pop();

		// 현재 헤더 포인터의 연결된 리스트 확인
		for (int i = 0; i < adj[now].size(); ++i)
		{
			// 방문했던 곳은 제외
			if (visited[adj[now][i]] == true) continue;

			q.push(adj[now][i]);
			dist[adj[now][i]] = dist[now] + 1;
			visited[adj[now][i]] = true;
		}
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	std::cin >> n >> m >> k >> x;

	adj.resize(n + 1);
	for (int i = 0; i < m; ++i)
	{
		int u, v;
		std::cin >> u >> v;

		adj[u].push_back(v);
	}

	bfs(x);

	bool none = true;
	for (int i = 1; i <= n; ++i)
	{
		if (dist[i] == k)
		{
			std::cout << i << "\n";
			none = false;
		}
	}
	
	if (none == true)
	{
		std::cout << "-1";
	}

	return 0;
}