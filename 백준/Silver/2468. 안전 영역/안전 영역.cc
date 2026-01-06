#include<iostream>
#include<vector>

int n;
int max;
int cnt;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
std::vector<std::vector<int>> grid;
std::vector<std::vector<bool>> visited;

void dfs(int nn, int x, int y)
{
	// 4방향 확인.
	for (int i = 0; i < 4; ++i)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
		if (grid[nx][ny] <= nn || visited[nx][ny] == true) continue;

		visited[nx][ny] = true;
		dfs(nn, nx, ny);
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	std::cin >> n;

	grid.resize(n, std::vector<int>(n));
	visited.resize(n, std::vector<bool>(n, false));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			std::cin >> grid[i][j];
		}
	}

	// 높이 별로 dfs를 실행.
	for (int i = 0; i <= 100; ++i)
	{
		cnt = 0;
		visited.clear();
		visited.resize(n, std::vector<bool>(n, false));

		// 그리드 별로 dfs를 실행
		for (int j = 0; j < n; ++j)
		{
			for (int k = 0; k < n; ++k)
			{
				// 방문한 적 없고, 높이가 높은 곳
				if (grid[j][k] > i && visited[j][k] == false)
				{
					cnt++;
					visited[j][k] = true;

					dfs(i, j, k);
				}
			}
		}

		if (max < cnt)
		{
			max = cnt;
		}
	}

	std::cout << max;

	return 0;
}