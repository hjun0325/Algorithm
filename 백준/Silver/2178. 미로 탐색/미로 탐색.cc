#include<iostream>
#include<vector>
#include<string>
#include<queue>

int n, m;
std::vector<std::string> board;
int dist[100][100];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

void bfs(int startX, int startY)
{
	std::queue<std::pair<int, int>> q;
	q.push({ startX, startY });
	dist[startX][startY] = 1;

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		// 4방향 확인.
		for (int i = 0; i < 4; ++i)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			// 지도 밖으로 나가는지 체크
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

			// 벽이거나 이미 방문했는지 체크
			if (board[nx][ny] == '0' || dist[nx][ny] > 0) continue;

			q.push({ nx,ny });
			dist[nx][ny] = dist[x][y] + 1;
		}
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> n >> m;

	board.resize(n);
	for (int i = 0; i < n; ++i)
	{
		std::cin >> board[i];
	}
	bfs(0, 0);
	
	std::cout << dist[n - 1][m - 1];
	return 0;
}