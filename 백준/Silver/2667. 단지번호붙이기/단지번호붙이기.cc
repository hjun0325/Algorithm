#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

int n;
std::vector<std::string> board;
std::vector<int> result;
int dist[100][100];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int cnt;

void dfs(int x, int y)
{
	cnt++;

	// 4방향 확인.
	for (int i = 0; i < 4; ++i)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		// 지도 밖으로 나가는지 체크
		if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;

		// 벽이거나 이미 방문했는지 체크
		if (board[nx][ny] == '0' || dist[nx][ny] > 0) continue;

		// 방문 표시
		dist[nx][ny] = 1;
		dfs(nx, ny);
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> n;

	board.resize(n);
	for (int i = 0; i < n; ++i)
	{
		std::cin >> board[i];
	}
	
	// 모든 구역 체크
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			// 집이 있는지, 아직 방문 안했는지 체크
			if (board[i][j] == '1' && dist[i][j] == 0)
			{
				cnt = 0;
				dist[i][j] = 1;
				dfs(i, j);
				result.push_back(cnt);
			}
		}
	}

	sort(result.begin(), result.end());

	std::cout << result.size() << "\n";
	for (int i = 0; i < result.size(); ++i)
	{
		std::cout << result[i] << '\n';
	}

	return 0;
}